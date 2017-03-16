import java.util.*;
import java.io.*;
public class c {
    public static trie t;
    public static String s;
    public static short[][][] memo;
    public static void main(String[] args) throws IOException{
        Scanner br = new Scanner(new File("c.in"));
        Scanner br2 = new Scanner(new File("dic.txt"));
        String[] words = new String[521196];
        int max = 0;
        int pos = 0;
        t = new trie(false, pos);
        pos++;
        for(int i = 0;i<words.length;i++){
            String cur = br2.next();
            trie temp = t;
            for(int j = 0;j<cur.length();j++){
                int let = cur.charAt(j)-'a';
                boolean end = (j == cur.length()-1);
                if(temp.next[let] == null){
                    temp.next[let] = new trie(end, pos);
                    pos++;
                    temp = temp.next[let];
                }
                else{
                    if(end){
                        temp.next[let].end = end;
                    }
                    temp = temp.next[let];
                }
            }
        }
        PrintWriter out = new PrintWriter(new File("c.out"));
        memo = new short[6][50][pos];
        int tt = br.nextInt();
        for(int c = 1;c<=tt;c++){
            s = br.next();
            for(int i = 0;i<6;i++){
                for(int j = 0;j<s.length();j++){
                    Arrays.fill(memo[i][j], (short)-1);
                }
            }
            out.println("Case #"+c+": "+go(5, 0, t));
        }
        out.close();
    }
    public static short go(int last, int pos, trie cur){
        if(last > 5){
            last = 5;
        }
        if(pos == s.length() && cur.end){
            return 0;
        }
        else if(pos == s.length()){
            return (short)(s.length()+10);
        }
        if(memo[last][pos][cur.index] != -1){
            return memo[last][pos][cur.index];
        }
        short ans = (short)(s.length()+10);
        if(cur.end){
            ans = go(last, pos, t);
        }
        if(cur.next[s.charAt(pos)-'a'] != null)
            ans = (short)Math.min(ans, go(last+1, pos+1, cur.next[s.charAt(pos)-'a']));
        if(last == 5){
            for(int i = 0;i<26;i++){
                if(cur.next[i] != null){
                    ans = (short)Math.min(ans, 1+go(1, pos+1, cur.next[i]));
                }
            }
        }
        return memo[last][pos][cur.index] = ans;
    }
    public static class trie{
        trie[] next;
        boolean end;
        int index;
        public trie(boolean a, int b){
            end = a;
            next = new trie[26];
            index  = b;
        }
    }
}
