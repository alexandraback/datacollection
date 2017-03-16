import java.util.*;
import java.io.*;

public class c {
    boolean isUnique(Map<String, Integer> map, String key) {
        if(!map.containsKey(key)) {
            map.put(key, 0); 
            return true;
        } 
        map.put(key, map.get(key) + 1);
        return false;
    } 
    int find(String[] first, String[] second) {
        int r = 0, n = first.length;
        
    a:  for(int i = 0; i < (1 << n); ++i ) {
            Map<String, Integer> firstCount = new HashMap<>();
            Map<String, Integer> secondCount = new HashMap<>();
            int count = 0;
            for(int j = 0; j < n; ++j) {
                if(((i >> j) & 1) == 1) {
                    boolean isValidFirst = isUnique(firstCount, first[j]);     
                    boolean isValidSecond = isUnique(secondCount, second[j]);     
                    if(!isValidFirst && !isValidSecond) {
                        continue a; 
                    }
                } 
            }
                
            for(int j = 0; j < n; ++j) {
                if(((i >> j) & 1) == 0) {
                    if(firstCount.containsKey(first[j]) && secondCount.containsKey(second[j])) {
                        ++count; 
                    } else {
                        continue a; 
                    }
                }  
            } 

            r = Math.max(r, count);
        }
        return r;
    }

    private void solve() throws IOException {
        int T = nextInt();

        for(int cas = 1; cas <= T; ++cas) {
            int n = nextInt();
            String[] first = new String[n];
            String[] second = new String[n];
            for(int i = 0; i < n; ++i) {
                first[i] = next();
                second[i] = next();
            }

            int r = find(first, second);

            System.out.println(String.format("Case #%d: %d", cas, r));
        }
    }

    static void debug(Object...o) {
        System.err.println(Arrays.deepToString(o));
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String s = br.readLine();
            if(s != null) {
                st = new StringTokenizer(s);
            }
        }
        if(st.hasMoreTokens()) {
            return st.nextToken();
        } else {
            return null;
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    String nextLine(){
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }

    private void run(String filename) throws IOException {
        br = new BufferedReader(new FileReader(filename));
        //br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        //out = new PrintWriter(filename + ".out");
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        String filename = args[0].endsWith(".in") ? args[0] : "c.in";

        new c().run(filename);
    }
}
