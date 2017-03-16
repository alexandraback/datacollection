
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author ehsan
 */
public class MineSweeper3 {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner in = new Scanner(new File("/home/ehsan/Downloads/csmall11.in"));
        //Scanner in = new Scanner(new File("/home/ehsan/Documents/Copy/Programming/CodeJam/CJamApril14/src/test"));
        int n_tests = in.nextInt();
        MineSweeper[] tests = new MineSweeper[n_tests];
        for (int i = 0; i < n_tests; i++) {
            int R = in.nextInt();
            int C = in.nextInt();
            int M = in.nextInt();
            tests[i] = new MineSweeper(R, C, M);
        }
        BufferedWriter bw = new BufferedWriter(new FileWriter("/home/ehsan/results.txt"));
        int count = 0, ccount = 0;
        for (int i = 0; i < n_tests; i++) {
            String ans = tests[i].fill();
            String vans = "";
            if (ans.contains("Impossible")) {
                ans = tests[i].recursive();
                MineSweeper t = new MineSweeper(tests[i].C, tests[i].R, tests[i].M);
                vans = t.recursive();                
                
                if (ans.contains("Impossible")) {
                   if (!vans.contains(("Impossible"))) {
                       ans = tests[i].rotate(vans);
                   }
                }
                
            }
            
            if (ans.contains("Impossible"))
                count++;
            else
                if (!tests[i].verify(ans))
                    ccount++;
            System.out.println("Case #" + (i + 1) + ":\n" + ans);                        
            bw.write("Case #" + (i + 1) + ":\n" + ans + "\n");
        }
        System.out.println(count + " " + ccount);
        bw.close();
    }

    static class MineSweeper {

        int R, C, M;

        MineSweeper(int R, int C, int M) {
            this.R = R;
            this.C = C;
            this.M = M;
        }

        String rotate(String s) {
            String[] a = s.split("\n");
            String x = "";
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    x = x + a[j].charAt(i);
                }
                if (i < R - 1) {
                    x = x + "\n";
                }
            }
            return x;
        }

        String fill() {
            int F = R * C - M;
            if (F == 1) {
                String s = "";
                for (int r = 0; r < R; r++) {
                    for (int c = 0; c < C; c++) {
                        s = s + "*";
                    }
                    if (r < R - 1) {
                        s = s + "\n";
                    }
                }
                return "c" + s.substring(1);
            }
            if (R == 1) {
                String s = "";
                for (int i = 0; i < C; i++) {
                    if (i < F) {
                        s = s + '.';
                    } else {
                        s = s + '*';
                    }
                }
                return "c" + s.substring(1);
            }
            if (C == 1) {
                String s = "";
                for (int i = 0; i < R; i++) {
                    if (i < F) {
                        s = s + ".";
                    } else {
                        s = s + "*";
                    }
                    if (i < R - 1) {
                        s = s + "\n";
                    }
                }
                return "c" + s.substring(1);
            }
            if (F == 2 || F == 3) {
                return "Impossible";
            }
            for (int ar = 2; ar < R + 1; ar++) {
                for (int ac = 2; ac < C + 1; ac++) {
                    for (int ad = 0; ad < ac; ad++) {
                        if (ad == 1 || ar == R) {
                            continue;
                        }
                        if (ar * ac + ad == F) {
                            String s = "";
                            for (int i = 0; i < R; i++) {
                                for (int j = 0; j < C; j++) {
                                    if (i < ar && j < ac || i == ar && j < ad) {
                                        s += ".";
                                    } else {
                                        s += "*";
                                    }
                                }
                                if (i < R - 1) {
                                    s += "\n";
                                }
                            }
                            return "c" + s.substring(1);
                        }
                    }
                }
            }
            return "Impossible";
        }

        String recursive() {
            int maxd = R > C ? R : C;
            width = new int[maxd];
            height = new int[maxd];
            tF = R * C - M;
            if (!nextW(0)) {
                return "Impossible";
            } else {
                return makeFinal();
            }
        }

        String makeFinal() {
            int pos = 0;
            String s = "";
            while (width[pos] > 0) {
                int w = width[pos];
                int h = height[pos];
                String rect = rect(w, h);
                if (pos == 0) {
                    s = s + "c" + rect.substring(1);
                } else {
                    s = s + rect;
                }
                if (pos < width.length - 1) {
                    if (width[pos + 1] > 0) {
                        s = s + "\n";
                    }
                }
                pos++;
                if (pos == width.length - 1) {
                    break;
                }
            }
            return s;
        }

        String rect(int w, int h) {
            String s = "";
            for (int r = 0; r < h; r++) {
                for (int c = 0; c < C; c++) {
                    if (c < w) {
                        s = s + ".";
                    } else {
                        s = s + "*";
                    }
                }
                if (r < h - 1) {
                    s = s + "\n";
                }
            }
            return s;
        }

        boolean nextW(int pos) {
            if (pos == width.length && count != tF) {
                return false;
            }
            if (pos == 0) {
                for (int w = 2; w < C + 1; w++) {
                    width[pos] = w;
                    if (nextH(pos)) {
                        return true;
                    }
                }
            } else {
                int prev_w = width[pos - 1];
                for (int w = 2; w < prev_w; w++) {
                    width[pos] = w;
                    if (nextH(pos)) {
                        return true;
                    }
                }
            }
            width[pos] = 0;
            return false;
        }

        boolean nextH(int pos) {
            int hmin = 1;
            if (pos == 0) {
                hmin = 2;
            }
            for (int h = hmin; h < R + 1; h++) {
                height[pos] = h;
                sum_h += h;
                count += h * width[pos];
                if (count > tF || sum_h > R) {
                    count -= h * width[pos];
                    height[pos] = 0;
                    sum_h -= h;
                    return false;
                }
                if (count == tF) {
                    return true;
                }
                if (nextW(pos + 1)) {
                    return true;
                }
                count -= h * width[pos];
                sum_h -= h;
                height[pos] = 0;
            }
            return false;
        }
        int[] width, height;
        int count = 0, sum_h = 0;
        int tF = 0;        
    
        boolean verify(String s) {
            String[] a = s.split("\n");
            int[][] ints = new int[R][C];
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    ints[i][j] = a[i].charAt(j) != '*' ? 0 : 1;
                }
            }
            flood(ints, 0, 0);
            int cp = 0, cm = 0;
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (ints[i][j] == -1) cm++;
                    else cp++;
                }
            }
            if (cm + cp != R * C) return false;
            if (cp != M) return false;
            return true;
        }
        private void flood(int[][] x, int r, int c) {
            if (r < 0 || r > R - 1 || c < 0 || c > C - 1) return;
            if (x[r][c] != 0) return;
            x[r][c] = -1;
            for (int i = r - 1; i < r + 2; i++) {
                for (int j = c - 1; j < c + 2; j++) {
                    if (i == r && j == c) continue;
                    flood(x, i, j);
                }
            }
        }
    }
    
    
    
}
