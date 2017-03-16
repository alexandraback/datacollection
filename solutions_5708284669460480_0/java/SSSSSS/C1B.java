import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Pattern;

/**
 * Created by szeyiu on 5/10/15.
 */
public class C1B {

    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(new FileInputStream(new File("2.in"))));
        BufferedWriter w = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File("2.out"))));
        int T = Integer.valueOf(r.readLine());
        C1B c1B = new C1B();
        for(int i=0; i<T; ++i){
            String line = r.readLine();
            String[] splt = line.split(" ");
            int K = Integer.valueOf(splt[0]);
            int L = Integer.valueOf(splt[1]);
            int S = Integer.valueOf(splt[2]);
            String kb = r.readLine();
            String tar = r.readLine();
            double rst = c1B.solve(kb, tar, S);
            int c = i+1;
            w.write("Case #" + c + ": " + rst + "\n");
        }
        w.flush();
        w.close();
        r.close();
    }

    public double solve(String kb, String tar, int s){
        List<String> allString = new ArrayList<String>();
        dfs(kb,s, 0, new ArrayList<Character>(), allString);
        int maxBanana = -1;
        int sum = 0;
        for(int i=0; i<allString.size(); ++i){
            int occ = find(allString.get(i), tar);
            sum += occ;
            if(occ>maxBanana) maxBanana=occ;
        }
        //System.out.println(sum+"\t"+maxBanana);
        double rst = 1.0*sum/allString.size();
        //System.out.println(allString.size());
        rst = maxBanana - rst;
        return rst;
    }

    private int find(String s, String tar){
        /*int m = tar.length();
        int n = s.length();
        for(int i=0; i<n-m; ++i){

        }*/
        /*return s.split(Pattern.quote(tar), -1).length - 1;*/
        int count = 0;
        int index = 0;
        while(index + tar.length() <= s.length()) {
            if(s.substring(index, index+tar.length()).equals(tar)) {
                count++;
            }
            index++;
        }
        return count;
    }

    private void dfs(String kb, int s, int start, List<Character> path, List<String> rst){
        if(start==s){
            StringBuilder sb = new StringBuilder();
            for(char ch: path){
                sb.append(ch);
            }
            rst.add(sb.toString());
            return;
        }
        for(int i=0; i<kb.length(); ++i){
            path.add(kb.charAt(i));
            dfs(kb, s, start + 1, path, rst);
            path.remove(path.size()-1);
        }
    }
}
