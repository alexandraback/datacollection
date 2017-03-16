
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B {
    static class P {
        public String one;
        public String two;
        public P(String one, String two) {
            this.one = one;
            this.two = two;
        }
    }
    static BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st = new StringTokenizer("");

    public static void main(String[] args) throws Exception {
        int T = readInt();
        int caseN = 1;
        while (T-- > 0) {
            System.out.print("Case #" + (caseN++) + ": ");
            int B = readInt();
            long M = readLong();
            long max_val = 1 << (B-2);
            if(max_val < M) {
                System.out.println("IMPOSSIBLE");
            } else {
                System.out.println("POSSIBLE");
                boolean[][] AM = new boolean[B][B];

                for(int i = 0; i < B; i++) {
                    for (int j = i+1; j < B; j++) {
                        AM[i][j] = true;
                    }
                }

                String bitsToRemove = Long.toBinaryString(max_val - M);
                for(int i = 0; i < bitsToRemove.length(); i++) {

                    if(bitsToRemove.charAt(bitsToRemove.length()-1-i) == '1') {
                        AM[0][B-2-i] = false;
                    }
                }


                for(int i = 0; i < B; i++) {
                    for (int j = 0; j < B; j++) {
                        System.out.print(AM[i][j] ? '1' : '0');
                    }
                    System.out.println();
                }
            }


        }
    }


    // Read next input-token as string.
    static String readString() throws Exception {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(stdin.readLine());
        }
        return st.nextToken();
    }

    // Read next input-token as integer.
    static int readInt() throws Exception {
        return Integer.parseInt(readString());
    }

    // Read next input-token as integer.
    static long readLong() throws Exception {
        return Long.parseLong(readString());
    }

}

