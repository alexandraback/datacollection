import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

/**
 * Created by naik on 30.04.16.
 */
public class A {

    static String ABC[] = new String[]{
            "ZERO", "TWO", "SIX", "EIGHT", "SEVEN", "FIVE", "THREE","FOUR", "ONE", "NINE"};
    static Map<String,Integer> map = new HashMap<>();

    public static void main(String[] args) throws IOException {
        FastScanner s = new FastScanner(true);
        int T = s.nextInt();
        map.put("ZERO",0);
        map.put("ONE",1);
        map.put("TWO",2);
        map.put("THREE",3);
        map.put("FOUR",4);
        map.put("FIVE",5);
        map.put("SIX",6);
        map.put("SEVEN",7);
        map.put("EIGHT",8);
        map.put("NINE",9);
        FileWriter writer = new FileWriter("A.small.txt");
        for (int i = 0; i < T; i++) {
            String result = "Case #" + (i + 1) + ": " + calc(s.nextToken());
            System.out.println(result);
            writer.write(result + "\n");
        }
        writer.close();
    }

    static String calc(String line){
        int arr[] = new int[255];
        int len = line.length();

        for (char ch : line.toCharArray()) {
            arr[(int)ch]++;
        }

        List<Integer> list = new ArrayList<>();

        for (int i=0; i <ABC.length;i++) {
            String word = ABC[i];
            loop:while(true) {
                for (char ch : word.toCharArray()) {
                    if (arr[(int) ch] == 0) {
                        break loop;
                    }
                }
                for (char ch : word.toCharArray()) {
                    arr[(int) ch]--;
                }
                list.add(map.get(word));
            }
        }

        Collections.sort(list);
        StringBuilder sb = new StringBuilder();
        for (Integer integer : list) {
            sb.append(integer);
        }
        return sb.toString();
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
