import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

/**
 * Created by naik on 30.04.16.
 */
public class B {

    static Map<Integer, List<String>> preMap;

    public static void main(String[] args) throws IOException {
        FastScanner s = new FastScanner(true);
        preMap = new HashMap<>();
        for (int i = 1; i <= 3; i++) {
            preMap.put(i, getList(i));
        }
        int T = s.nextInt();
        FileWriter writer = new FileWriter("B.small.txt");
        for (int i = 0; i < T; i++) {

            String result = "Case #" + (i + 1) + ": " + calc(s.nextToken(), s.nextToken()) + "\n";
            System.out.print(result);
            writer.write(result);
        }
        writer.close();
    }

    static String calc(String a,String b){
        int len = a.length();
        List<String> list = preMap.get(len);
        String ans = "";
        int min = Integer.MAX_VALUE;
        for (String word : list) {
            if(match(word, a)){
                int i1 = Integer.parseInt(word);
                for (String word2 : list) {
                    if(match(word2, b)){
                        int i2 = Integer.parseInt(word2);
                        int key = Math.abs(i2 - i1);
                        if(key < min){
                            min = key;
                            ans = word + " " + word2;
                        }
                    }
                }
            }
        }
        return ans;
    }

    static boolean match(String value, String pattern){
        for (int i = 0; i < value.length(); i++) {
            if(pattern.charAt(i) != '?' && value.charAt(i) != pattern.charAt(i)){
                return false;
            }
        }
        return true;
    }

    static List<String> getList(int size){
        char abc[] = new char[10];
        for (int i = 0; i < 10; i++) {
            abc[i] = (char) ('0' + i);
        }
        int arr[] = new int[size];
        List<String> list = new ArrayList<>();
        outer: while(true){
            StringBuilder sb = new StringBuilder();
            for (int i : arr) {
                sb.append("" + i);
            }
            list.add(sb.toString());
            int i = size - 1;
            while(arr[i] == abc.length - 1){
                arr[i] = 0;
                i--;
                if(i < 0)break outer;
            }
            arr[i]++;
        }
        return list;
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
