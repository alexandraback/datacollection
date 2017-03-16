import java.io.*;
import java.util.*;

public class A {

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }

    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        A solver = new A();
        solver.solve(1, in, out);
        out.close();
    }

    private static void removeDig(Map<Character, Integer> chMap, String dig_name, int times){
        for(Character c : dig_name.toCharArray()) {
            chMap.put(c, chMap.get(c) - times);
        }
    }

    private static void minimize(int[] arr, int st){
        for(int i = st; i < arr.length; i++) {
            if (arr[i] == -1) {
                arr[i] = 0;
            }
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int tn = in.nextInt();
//        String [] dig = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
//        Map<Character, Set<Integer>> setDig = new HashMap<>();
//        for (int i = 0; i < 10; i++) {
//            for (Character c : dig[i].toCharArray()) {
//                if (!setDig.containsKey(c)) {
//                    setDig.put(c,new HashSet<Integer>());
//                }
//                setDig.get(c).add(i);
//            }
//        }
//
//        for (Map.Entry<Character, Set<Integer>> c : setDig.entrySet()) {
//            System.out.print(c.getKey() + ": ");
//            for (Integer num : c.getValue()) {
//                System.out.print(num + ", ");
//            }
//            System.out.println();
//        }


        for (int ti = 0; ti < tn; ti++) {
            int j = in.nextInt();
            int p = in.nextInt();
            int s = in.nextInt();
            int k = in.nextInt();
            //k = Math.min(k, s);
            int res = j * p * k;
            int [][][] c = new int[j+1][p+1][s+1];
            int [][] jp = new int[j+1][p+1];
            int [][] js = new int[j+1][s+1];
            int [][] ps = new int[p+1][s+1];
            res = 0;
            List<String> rs = new ArrayList<>();
            for(int i = 1; i <= j; i++) {
                for(int d = 1; d <= p; d++) {
                    int cnt = 0;
                    if (jp[i][d] < k)
                    for(int z = 1; z <= s && jp[i][d] < k; z++) {
                        if (js[i][z] < k && ps[d][z] < k) {
                            rs.add(i + " " + d + " " + z);
                            js[i][z]++;
                            ps[d][z]++;
                            jp[i][d]++;
                            res++;
                            cnt++;
                        }
                    }

                }

            }


            System.out.println("Case #" + (ti + 1) + ": " + res);
//            System.out.println(j + " " + p + " " + s + " " + k);
            for (String ss : rs)
                System.out.println(ss);
//            for(int i = 1; i <= j; i++) {
//                for(int d = 1; d <= p; d++) {
//                    int cnt = 0;
//                    for(int z = d; z <= s && cnt < k; z++) {
//                        System.out.println(i + " " + d + " " + z);
//                        cnt++;
//                    }
//
//                }
//
//            }






        }
    }

}


