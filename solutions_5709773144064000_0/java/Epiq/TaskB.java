package googlecodejam;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class TaskB {

    static String PROBLEM_NAME = "B";
    
    private static double shortest(double C, double F, double X) {
        double time = X / 2;
        
        double sum = 0;
        for (int i = 1; i <= X; i++) { // <= 100000
            sum += C / (2 + (i - 1) * F);
            
            time = Math.min(time, sum + X / (2 + i * F));
        }
        
        return time;
    }
    
    public static void solve(InputReader fin, PrintWriter fout) {
        int T = fin.nextInt();
        
        for (int test = 1; test <= T; test++) {
            double C = fin.nextDouble();
            double F = fin.nextDouble();
            double X = fin.nextDouble();
            
            fout.printf("Case #%d: %.7f\n", test, shortest(C, F, X));
        }
    }
    
    public static void main(String[] args) throws IOException {
        FileInputStream  fis = new FileInputStream ("data/" + PROBLEM_NAME + ".in");
        FileOutputStream fos = new FileOutputStream("data/" + PROBLEM_NAME + ".out");
        
//        InputStream inputStream = System.in;
//        OutputStream outputStream = System.out;
        InputStream inputStream = fis;
        OutputStream outputStream = fos;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        TaskB.solve(in, out);

        out.close();
    }
    
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
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
        
        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public String nextLine() {
            try {
                return reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}