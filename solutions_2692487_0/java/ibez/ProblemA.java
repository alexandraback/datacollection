package round1b;

import java.io.*;
import java.util.*;


public class ProblemA {
    
    private static final boolean DEBUG = true;
    private static final String INPUT_FILE = "input.txt";
    private static final String OUTPUT_FILE = "output.txt";
    
    public static void main(String[] args) {
        try {
            //InputStream inputStream = System.in;
            InputStream inputStream = new FileInputStream(INPUT_FILE);
            //OutputStream outputStream = System.out;
            OutputStream outputStream = new FileOutputStream(OUTPUT_FILE);
            InputReader in = new InputReader(inputStream);
            PrintWriter out = new PrintWriter(outputStream);
            
            (new ProblemA()).solve(1, in, out);
            
            out.close();
        } catch (Throwable ex) {
            ex.printStackTrace();
        }
    }
    
    public void solve(int testCase, InputReader in, PrintWriter out) {
        int T = in.nextInt();
        for (int test = 1; test <= T; ++test) {
            int A = in.nextInt();
            int N = in.nextInt();
            int[] motes = new int[N];
            for (int i = 0; i < N; ++i) {
                motes[i] = in.nextInt();
            }
            
            Arrays.sort(motes);
            debug(Arrays.toString(motes));
            
            int maxMote = motes[N - 1];
            
            int resultWithRemovals = Integer.MAX_VALUE;
            int resultWithoutRemovals = 0;
            
            int i = 0;
            if (A > 1) {
                while (i < N) {
                    if (A > maxMote) {
                        break;
                    }
                    if (A > motes[i]) {
                        A += motes[i];
                    } else {
                        resultWithRemovals = Math.min(resultWithRemovals,
                                resultWithoutRemovals + (N - i));
                        while (A <= motes[i]) {
                            A += (A - 1);
                            resultWithoutRemovals++;
                        }
                        A += motes[i];
                    }
                    
                    i++;
                }
            } else {
                resultWithRemovals = N;
                resultWithoutRemovals = Integer.MAX_VALUE;
            }
            
            int result = Math.min(resultWithRemovals, resultWithoutRemovals);
            
            out.println("Case #" + test + ": " + result);
        }
    }
    
    private static class InputReader {
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
    
        public void close() {
            try {
                reader.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        
    }

    private static void debug(String str) {
        if (DEBUG) {
            System.out.println(str);
        }
    }
    
    private static void debug(int value) {
        if (DEBUG) {
            System.out.println("" + value);
        }
    }
    
    private static void debug(Object[] arr) {
        if (DEBUG) {
            System.out.println(Arrays.toString(arr));
        }
    }
    
    private static void debug(Object obj) {
        if (DEBUG) {
            System.out.println(obj.toString());
        }
    }

}