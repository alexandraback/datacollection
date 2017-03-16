/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package minesweepermaster;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

/**
 *
 * @author martin
 */
public class MinesweeperMaster {
    
    private static final String IMPOSSIBLE = "Impossible";

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        String fileName;
        if (args.length < 1) {
            fileName = "/mnt/SSD180/GCJ/2014_Qualif/C/MyTest.txt";
        } else {
            fileName = args[0];
        }
        TestCase[] tcs = readTestCases(new File(fileName));
        for (int i = 0; i < tcs.length; i++) {
            String y = getPlay(tcs[i]);
            System.out.println("Case #"+(i+1)+":\n"+y);
        }
    }

    private static TestCase[] readTestCases(File file) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(file));
        String line = br.readLine(); // Number of test cases
        int n = Integer.parseInt(line);
        //System.err.println("Have "+n+" test cases.");
        TestCase[] testCases = new TestCase[n];
        for (int i = 0; i < n; i++) {
            TestCase tc = new TestCase();
            line = br.readLine();
            int pos = 0;
            int pos2 = line.indexOf(' ', pos);
            tc.R = Integer.parseInt(line.substring(pos, pos2));
            pos = pos2 + 1;
            pos2 = line.indexOf(' ', pos);
            tc.C = Integer.parseInt(line.substring(pos, pos2));
            pos = pos2 + 1;
            tc.M = Integer.parseInt(line.substring(pos));
            testCases[i] = tc;
        }
        return testCases;
    }

    private static String getPlay(TestCase testCase) {
        int R = testCase.R;
        int C = testCase.C;
        int M = testCase.M;
        int V = R*C - M;    // volne pozice
        int K = Math.min(R, C); // kratka strana
        
        if (V < 1) {
            return IMPOSSIBLE;
        }
        
        // Print play:
        StringBuilder sb = new StringBuilder();
        if (K == 1) {
            play1(R, C, M, V, sb);
        } else if (K == 2) {
            if (V != 1 && ((V % 2) == 1 || V < 4)) {
                return IMPOSSIBLE;
            } else {
                play2(R, C, M, V, sb);
            }
        } else {
            if (V != 1 && (V < 4 || !checkV(V))) {
                return IMPOSSIBLE;
            } else {
                play(R, C, M, V, sb);
            }
        }
        return sb.toString();
    }

    private static void play1(int R, int C, int M, int V, StringBuilder sb) {
        String sep = (R == 1) ? "" : "\n";
        sb.append('c');
        sb.append(sep);
        for (int i = 1; i < V; i++) {
            sb.append('.');
            sb.append(sep);
        }
        for (int i = 0; i < M; i++) {
            sb.append('*');
            sb.append(sep);
        }
        if (sep.length() > 0) {
            sb.delete(sb.length() - sep.length(), sb.length());
        }
    }

    private static void play2(int R, int C, int M, int V, StringBuilder sb) {
        int r = V/2;
        int m = M/2;
        sb.append('c');
        if (R == 2) {
            for (int i = 1; i < r; i++) {
                sb.append('.');
            }
            for (int i = 0; i < m; i++) {
                sb.append('*');
            }
            sb.append('\n');
            for (int i = 0; i < r; i++) {
                sb.append('.');
            }
            if (V == 1) m++;
            for (int i = 0; i < m; i++) {
                sb.append('*');
            }
        } else {
            if (V > 1) {
                sb.append('.');
            } else {
                sb.append('*');
            }
            for (int i = 1; i < r; i++) {
                sb.append("\n..");
            }
            for (int i = 0; i < m; i++) {
                sb.append("\n**");
            }
        }
    }
    
    // In 3x3 and bigger
    private static boolean checkV(int V) {
        if ((V % 2) == 0) {
            return true;
        }
        if ((V % 3) == 0) {
            return true;
        }
        if (V == 5 || V == 7) {
            return false;
        }
        return true;
        /*
        if ((V % 3) == 2) {
            return true;
        }
        return false;
        */
    }

    // In 3x3 and bigger
    private static void play(int R, int C, int M, int V, StringBuilder sb) {
        sb.append('c');
        if (V == 1) {
            for (int r = 0; r < R; r++) {
                for (int c = 0; c < C; c++) {
                    if (r == 0 && c == 0) {
                        continue;
                    }
                    sb.append('*');
                }
                if (r < (R-1)) {
                    sb.append('\n');
                }
            }
        } else if (V == 4) {
            for (int r = 0; r < R; r++) {
                for (int c = 0; c < C; c++) {
                    if (r == 0 && c == 0) {
                        continue;
                    }
                    if (r <= 1 && c <= 1) {
                        sb.append('.');
                    } else {
                        sb.append('*');
                    }
                }
                if (r < (R-1)) {
                    sb.append('\n');
                }
            }
        } else {
            int[][] field = createField(R, C, M, V);
            if (field == null) {
                sb.delete(0, sb.length());
                sb.append(IMPOSSIBLE);
                return ;
            }
            for (int r = 0; r < R; r++) {
                for (int c = 0; c < C; c++) {
                    if (r == 0 && c == 0) {
                        continue;
                    }
                    int f = field[r][c];
                    if (f == 0) {
                        sb.append('.');
                    } else {
                        sb.append('*');
                    }
                }
                if (r < (R-1)) {
                    sb.append('\n');
                }
            }
        }
            /*
        } else if ((V % 2) == 0) {
            
        } else if ((V % 3) == 0) {
            
        } else if ((V % 3) == 2) {
            
        }
            */
    }

    // At least 3x3 and V == 6 || V >= 8
    private static int[][] createField(int R, int C, int M, int V) {
        int[][] field = new int[R][C];
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                field[r][c] = -1; // Unknown
            }
        }
        field[0][0] = 0; // initially revealed
        int K = Math.min(R, C);
        boolean longRows = (K == R); // C >= R
        int blockWidth = K;
        int emptyLines = V/K;
        if (emptyLines < 2) {
            blockWidth = V/2;
            emptyLines = 2;
        }
        int rest = V - blockWidth*emptyLines;
        if (rest == 1 && blockWidth == 2 || emptyLines == 2) {
            // unsolvable, choose blockWidth = 3
            blockWidth = 3;
            emptyLines = V/blockWidth;
            if (emptyLines < 2) {  // will not happen when V >= 6
                return null;
            }
            rest = V - blockWidth*emptyLines;
        }
        boolean addExtraMine = false;
        if (rest == 1) {
            // There can not be one lonely
            rest = 2;
            addExtraMine = true;
        }
        if (longRows) {
            // empty lines are columns
            for (int r = 0; r < blockWidth; r++) {
                for (int c = 0; c < emptyLines; c++) {
                    field[r][c] = 0;
                }
            }
            for (int r = 0; r < rest; r++) {
                field[r][emptyLines] = 0;
            }
        } else {
            for (int r = 0; r < emptyLines; r++) {
                for (int c = 0; c < blockWidth; c++) {
                    field[r][c] = 0;
                }
            }
            for (int c = 0; c < rest; c++) {
                field[emptyLines][c] = 0;
            }
        }
        if (addExtraMine) {
            if (longRows) {
                field[blockWidth - 1][emptyLines - 1] = 1;
            } else {
                field[emptyLines - 1][blockWidth - 1] = 1;
            }
        }
        return field;
    }

    private static class TestCase {
        int R, C, M;
    }
    
}
