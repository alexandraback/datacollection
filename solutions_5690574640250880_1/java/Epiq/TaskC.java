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

public class TaskC {

    static String PROBLEM_NAME = "C";
    
    private static boolean canWinBy1Click(int R, int C, int M, char[][] grid) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                grid[i][j] = '.';
            }
        }
        int free = R * C - M;
        
        if (free == 0) {
            return false;
        }
        
        if (free == 1) {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    grid[i][j] = '*';
                }
            }
            grid[0][0] = 'c';
            return true;
        }
        
        if (R == 1 || C == 1) {
            grid[0][0] = 'c';
            int t = Math.max(R, C);
            for (int i = t - M; i < t; i++) {
                if (R == 1) {
                    grid[0][i] = '*';
                } else {
                    grid[i][0] = '*';
                }
            }
            return true;
        }
        
        if (free >= 4) {
            grid[0][0] = 'c';
            int left = M;
            
            for (int i = R - 1; i >= 2 && left > 0; i--) {
                for (int j = C - 1; j >= 2 && left > 0; j--) {
                    grid[i][j] = '*';
                    left--;
                }
            }
            
            if (left % 2 != 0) {
                // Take one out, if it's ok
                if (R > 2 && C > 2 && free > 8) {
                    grid[2][2] = '.';
                    left++;
                } else {
                    return false;
                }
            }
            
            // Fill first 2 rows
            for (int i = C - 1; i >= 3 && left > 0; i--) {
                grid[0][i] = grid[1][i] = '*';
                left -= 2;
            }
            
            // Fill first 2 columns
            for (int i = R - 1; i >= 3 && left > 0; i--) {
                grid[i][0] = grid[i][1] = '*';
                left -= 2;
            }
            
            if (C > 2 && left > 0) {
                grid[0][2] = grid[1][2] = '*';
                left -= 2;
            }
            
            if (R > 2 && left > 0) {
                grid[2][0] = grid[2][1] = '*';
                left -= 2;
            }
            
            return true;
        }
        
        return false;
    }
    
    public static void solve(InputReader fin, PrintWriter fout) {
        int T = fin.nextInt();
        
        for (int test = 1; test <= T; test++) {
            int R = fin.nextInt();
            int C = fin.nextInt();
            int M = fin.nextInt();
            
            char[][] grid = new char[R][C];
            fout.printf("Case #%d:\n", test);
            if (canWinBy1Click(R, C, M, grid)) {
                for (int i = 0; i < R; i++) {
                    for (int j = 0; j < C; j++) {
                        fout.printf("%c", grid[i][j]);
                    }
                    fout.println();
                }
            } else {
                fout.println("Impossible");
            }
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

        solve(in, out);

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