import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

/**
 * Created by naik on 01.05.16.
 */
public class C {
    public static void main(String[] args) throws IOException {
        FastScanner s = new FastScanner(true);
        int T = s.nextInt();
        FileWriter writer = new FileWriter("C.small.txt");
        for (int i = 0; i < T; i++) {
            String result = "Case #" + (i + 1) + ": " + calc(s) + "\n";
            System.out.print(result);
            writer.write(result);
        }
        writer.close();
    }

    static int calc(FastScanner s){
        int N = s.nextInt();
        Set<String> used = new HashSet<>();
        Map<String, Integer> map = new HashMap<>();
        List<String> list1 = new ArrayList<>();
        List<String> list2 = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            String a = s.nextToken();
            String b = s.nextToken();
            list1.add(a);
            list2.add(b);
            String key = a + " " + b;
            if(used.contains(key)) continue;
            used.add(key);
            used.add(b + " " + a);
            increase(map, a);
            increase(map, b);
        }
        used = new HashSet<>();
        int ans = 0;
        for (int i = 0; i < N; i++) {
            String a = list1.get(i);
            String b = list2.get(i);
            String key = a + " " + b;
            if(used.contains(key)) continue;
            used.add(key);
            used.add(b + " " + a);
            Integer val1 = map.get(a);
            Integer val2 = map.get(b);
            if(val1 != null && val1 > 1 && val2 != null && val2 > 1){
                decrease(map, a);
                decrease(map, b);

                ans++;
            }

        }
        return ans;
    }

    static void increase(Map<String,Integer> map,String key){
        Integer value = map.get(key);
        if(value == null){
            value = 0;
        }
        map.put(key, ++value);
    }

    static void decrease(Map<String,Integer> map,String key){
        Integer value = map.get(key);
        map.put(key, --value);
    }

    static void _(Object...args){
        System.err.println(Arrays.deepToString(args));
    }

    public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            init();
        }

        public FastScanner(String name) {
            init(name);
        }

        public FastScanner(boolean isOnlineJudge) {
            if (!isOnlineJudge || System.getProperty("ONLINE_JUDGE") != null) {
                init();
            } else {
                init("input.txt");
            }
        }

        private void init() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        private void init(String name) {
            try {
                br = new BufferedReader(new FileReader(name));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

        public long nextLong() {
            return Long.parseLong(nextToken());
        }

        public double nextDouble() {
            return Double.parseDouble(nextToken());
        }

    }
}
