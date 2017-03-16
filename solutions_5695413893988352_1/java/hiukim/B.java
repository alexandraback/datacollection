import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.*;

public class B {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;

    long bestDiff;
    int[] bestC;
    int[] bestJ;
    long bestValueC;
    long bestValueJ;
    long[] mul;
    public void task() throws IOException {
        String[] S = reader.readLine().split(" ");
        int[] C = new int[S[0].length()];
        int[] J = new int[S[1].length()];
        for (int i = 0; i < S[0].length(); i++) {
            if (S[0].charAt(i) == '?') {
                C[i] = -1;
            } else {
                C[i] = Character.getNumericValue(S[0].charAt(i));
            }
        }
        for (int i = 0; i < S[1].length(); i++) {
            if (S[1].charAt(i) == '?') {
                J[i] = -1;
            } else {
                J[i] = Character.getNumericValue(S[1].charAt(i));
            }
        }

        mul = new long[C.length];
        mul[C.length - 1] = 1;
        for (int i = C.length - 2; i >= 0; i--) {
            mul[i] = mul[i+1] * 10;
        }

        // up larger
        bestDiff = Long.MAX_VALUE / 2;
        compute(C, J, true);
        compute(J, C, false);
//        out.println(bestDiff + ", " + bestValueC + ", " + bestValueJ);
        String ansC = Long.toString(bestValueC);
        String ansJ = Long.toString(bestValueJ);
        int miss = C.length - ansC.length();
        for (int i = 0; i < miss; i++) {
            ansC = "0" + ansC;
        }
        miss = C.length - ansJ.length();
        for (int i = 0; i < miss; i++) {
            ansJ = "0" + ansJ;
        }

        out.println(ansC + " " + ansJ);

        /*

        bestDiff = Long.MAX_VALUE / 2;
        go(C, J, new int[C.length], new int[C.length], 0);

//        out.println(bestDiff + ", " + Arrays.toString(bestC) + ", " + Arrays.toString(bestJ));
        for (int i = 0; i < C.length; i++) {
            out.print(bestC[i]);
        }
        out.print(" ");
        for (int i = 0; i < C.length; i++) {
            out.print(bestJ[i]);
        }
        out.println();
        */
    }

    public void compute(int[] C, int[] J, boolean firstC) {
        long cum = 0;
        for (int i = 0; i < C.length; i++) {
            boolean both = C[i] != -1 && J[i] != -1;
            if (both && J[i] > C[i]) {
                break;
            }

            if (J[i] != 9 && C[i] != 0) {
                long maxJ = 0;
                long minC = 0;
                if (C[i] == -1 && J[i] == -1) {
                    maxJ = 0;
                    minC = 1;
                } else if (C[i] != -1) {
                    minC = C[i];
                    maxJ = J[i] == -1? minC - 1: J[i];
                } else if (J[i] != -1) {
                    maxJ = J[i];
                    minC = C[i] == -1? maxJ + 1: C[i];
                } else {
                    throw new RuntimeException();
                }
                maxJ *= mul[i];
                minC *= mul[i];

                for (int j = i+1; j < C.length; j++) {
                    minC += mul[j] * (C[j] == -1? 0: C[j]);
                    maxJ += mul[j] * (J[j] == -1? 9: J[j]);
                }
                long diff = (minC - maxJ);

                long valueC = firstC? cum + minC: cum + maxJ;
                long valueJ = firstC? cum + maxJ: cum + minC;

                if (diff < bestDiff
                        || (diff == bestDiff && valueC < bestValueC)
                        || (diff == bestDiff && valueC == bestValueC && valueJ < bestValueJ)) {
                    bestDiff = diff;
                    bestValueC = valueC;
                    bestValueJ = valueJ;
                }
            }

            // can equal
            if (both && C[i] > J[i]) {
                break;
            }
            if (C[i] == -1 && J[i] == -1) {
                cum += 0;
            } else if (C[i] != -1) {
                cum += C[i] * mul[i];
            } else if (J[i] != -1) {
                cum += J[i] * mul[i];
            }

            if (i == C.length - 1) {
                bestDiff = cum;
                bestValueC = cum;
                bestValueJ = cum;
            }
        }
    }

    public void go(int[] C, int[] J, int[] ansC, int[] ansJ, int cur) {
        boolean isLarger = false;
        for (int i = 0; i < cur; i++) {
            if (ansC[i] > ansJ[i]) {
                isLarger = true;
                break;
            }
        }
        if (isLarger) {

        }
    }

    public void _go (int[] C, int [] J, int[] ansC, int[] ansJ, int cur) {
        if (cur == C.length) {
            long valueC = 0;
            long valueJ = 0;
            long mul = 1L;
            for (int i = 0; i < C.length; i++) {
                valueC += 1L * ansC[C.length - 1 - i] * mul;
                valueJ += 1L * ansJ[C.length - 1 - i] * mul;
                mul *= 10;
            }

            long diff = Math.abs(valueC - valueJ);
            if (diff < bestDiff
                || (diff == bestDiff && valueC < bestValueC)
                || (diff == bestDiff && valueC == bestValueC && valueJ < bestValueJ)) {
                bestDiff = diff;
                bestValueJ = valueJ;
                bestValueC = valueC;
                bestC = ansC.clone();
                bestJ = ansJ.clone();
            }

            return;
        }

        ArrayList<Integer> possibleC = new ArrayList<Integer>();
        ArrayList<Integer> possibleJ = new ArrayList<Integer>();
        if (C[cur] == -1) {
            for (int j = 0; j <= 9; j++) {
                possibleC.add(j);
            }
        } else {
            possibleC.add(C[cur]);
        }
        if (J[cur] == -1) {
            for (int j = 0; j <= 9; j++) {
                possibleJ.add(j);
            }
        } else {
            possibleJ.add(J[cur]);
        }

        for (int c: possibleC) {
            for (int j: possibleJ) {
                ansC[cur] = c;
                ansJ[cur] = j;
                go(C, J, ansC, ansJ, cur+1);
            }
        }


        /*
        if (C[cur] == -1 && J[cur] == -1) {
            ansC[cur] = 0;
            ansJ[cur] = 0;
            go (C, J, ansC, ansJ, cur+1);

            ansC[cur] = 0;
            ansJ[cur] = 1;
            go (C, J, ansC, ansJ, cur+1);

            ansC[cur] = 1;
            ansJ[cur] = 0;
            go (C, J, ansC, ansJ, cur+1);
        } else if (C[cur] == -1) {
            if (J[cur] > 0) {
                ansC[cur] = J[cur] - 1;
                ansJ[cur] = J[cur];
                go(C, J, ansC, ansJ, cur + 1);
            }

            ansC[cur] = J[cur];
            ansJ[cur] = J[cur];
            go (C, J, ansC, ansJ, cur+1);

            if (J[cur] < 9) {
                ansC[cur] = J[cur] + 1;
                ansJ[cur] = J[cur];
                go(C, J, ansC, ansJ, cur + 1);
            }

        } else if (J[cur] == -1) {
            if (C[cur] > 0) {
                ansC[cur] = C[cur];
                ansJ[cur] = C[cur] - 1;
                go(C, J, ansC, ansJ, cur + 1);
            }

            ansC[cur] = C[cur];
            ansJ[cur] = C[cur];
            go(C, J, ansC, ansJ, cur + 1);

            if (C[cur] < 9) {
                ansC[cur] = C[cur];
                ansJ[cur] = C[cur] + 1;
                go(C, J, ansC, ansJ, cur + 1);
            }

        } else {
            ansC[cur] = C[cur];
            ansJ[cur] = J[cur];
            go (C, J, ansC, ansJ, cur+1);
        }
        */
    }
        
	public void solve() throws IOException {
		int T = nextInt();
		for(int t = 1; t <= T; t++){
			out.print("Case #" + (t) + ": ");
			task();
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new B().run();
	}
	
	public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            out = new PrintWriter(System.out);
            solve();
            reader.close();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

}
