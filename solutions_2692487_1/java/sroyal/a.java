import java.util.*;
import java.io.*;
public class a {
    public static int[] sizes;
    public static HashMap<String, Integer> memo;
    public static void main(String[] args) throws IOException{
        Scanner br = new Scanner(new File("a.in"));
        PrintWriter out = new PrintWriter(new File("a.out"));
        int t = br.nextInt();
        for(int c = 1;c<=t;c++){
            int size = br.nextInt();
            int n = br.nextInt();
            sizes = new int[n];
            for(int i = 0;i<n;i++){
                sizes[i] = br.nextInt();
            }
            Arrays.sort(sizes);
            memo = new HashMap<String, Integer>();
            out.println("Case #"+c+": "+go(0, size));
        }
        out.close();
    }
    public static int go(int pos, int size){
        if(pos == sizes.length){
            return 0;
        }
        String key = pos+" "+size;
        if(memo.containsKey(key)){
            return memo.get(key);
        }
        if(size > sizes[pos]){
            int ans = go(pos+1, size+sizes[pos]);
            memo.put(key, ans);
            return ans;
        }
        else{
            int ans = 1+go(pos+1, size);
            if(size != 1)
                ans = Math.min(ans, 1+go(pos, size+size-1));
            memo.put(key, ans);
            return ans;
        }
    }
}
