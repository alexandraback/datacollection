package c2014_c;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class Z3_2 {

    public static void main(String[] args) throws Exception {
        FileWriter fw = new FileWriter("C:\\output.txt");
        BufferedWriter out = new BufferedWriter(fw);
        //String pathname = "C:\\tests\\2014\\z3.txt";
        String pathname = "C:\\Users\\YC14rp1\\Downloads\\C-small-attempt3.in";
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\D-large.in";
        Scanner scanner = new Scanner(new File(pathname));
        int tn = scanner.nextInt();
        scanner.nextLine();
        for (int ti = 1; ti <= tn; ti++) {
            int r = scanner.nextInt();
            int c = scanner.nextInt();
            int m = scanner.nextInt();
            String s;
            s = "Case #" + ti + ": ";
            int[][] map = new int[r][c];
            System.out.println(s + " " + r + " " + c + " " + m);
            out.write(s);
            out.write("\n");
            boolean flag = false;
            if (m == r * c - 1) {
                for (int i = 0; i < r - 1; i++) {
                    for (int j = 0; j < c; j++) {
                        map[i][j] = 1;
                    }
                }
                for (int j = 0; j < c - 1; j++) {
                    map[r - 1][j] = 1;
                }
                map[r - 1][c - 1] = 2;
            } else if (c == 1) {
                for (int i = 0; i < m; i++) {
                    map[i][0] = 1;
                }
                map[m][0] = 0;
                map[m + 1][0] = 2;
                for (int i = m + 2; i < r - 1; i++) {
                    map[i][0] = 0;
                }
            } else if (r == 1) {
                for (int i = 0; i < m; i++) {
                    map[0][i] = 1;
                }
                map[0][m] = 0;
                map[0][m + 1] = 2;
                for (int i = m + 2; i < c - 1; i++) {
                    map[0][i] = 0;
                }
            } else if ((r * c - m < 4) || (r * c - m == 5) || (r * c - m == 7)) {
                flag = true;
                s = "Impossible\n";
                System.out.println();
                out.write(s);
            } else if (r * c - m == 9) {
                if ((r < 3) || (c < 3)) {
                    flag = true;
                    s = "Impossible\n";
                    System.out.println();
                    out.write(s);
                } else {
                    int k = 0;
                    for (int i = 0; i < r; i++) {
                        if (i < r - 3) {
                            for (int j = 0; j < c; j++) {
                                map[i][j] = 1;
                            }
                        } else if (i < r - 1) {
                            for (int j = 0; j < c; j++) {
                                if (j < c - 3) {
                                    map[i][j] = 1;
                                } else {
                                    map[i][j] = 0;
                                }
                            }
                        } else if (i == r - 1) {
                            for (int j = 0; j < c; j++) {
                                if (j < c - 3) {
                                    map[r - 1][j] = 1;
                                } else {
                                    if (j == c - 1) {
                                        map[r - 1][j] = 2;
                                    } else {
                                        map[r - 1][j] = 0;
                                    }
                                }
                            }
                        }
                    }
                }
            } else if (r * c - m == 11) {
                if ((r < 3) || (c < 3)) {
                    flag = true;
                    s = "Impossible\n";
                    System.out.println();
                    out.write(s);
                } else {
                    if (r > 3) {
                        for (int i = 0; i < r - 4; i++) {
                            for (int j = 0; j < c; j++) {
                                map[i][j] = 1;
                            }
                        }
                        for (int j = 0; j < c; j++) {
                            if (j < c - 2) {
                                map[r - 4][j] = 1;
                            } else {
                                map[r - 4][j] = 0;
                            }
                        }
                        for (int i = r - 3; i <= r - 2; i++) {
                            for (int j = 0; j < c; j++) {
                                if (j < c - 3) {
                                    map[i][j] = 1;
                                } else {
                                    map[i][j] = 0;
                                }
                            }
                        }
                        for (int j = 0; j < c; j++) {
                            if (j < c - 3) {
                                map[r - 1][j] = 1;
                            } else {
                                if (j == c - 1) {
                                    map[r - 1][j] = 2;
                                } else {
                                    map[r - 1][j] = 0;
                                }
                            }
                        }
                    } else {
                        for (int i = 0; i < c - 4; i++) {
                            for (int j = 0; j < r; j++) {
                                map[j][i] = 1;
                            }
                        }
                        for (int j = 0; j < r-2; j++) {
                                map[j][c - 4] = 1;
                        }
                        for (int i = c - 3; i <= c - 2; i++) {
                            for (int j = 0; j < r; j++) {
                                if (j < r - 3) {
                                    map[j][i] = 1;
                                }
                            }
                        }
                        for (int j = 0; j < r; j++) {
                            if (j < r - 3) {
                                map[j][c - 1] = 1;
                            } else {
                                if (j == r - 1) {
                                    map[j][c - 1] = 2;
                                }
                            }
                        }
                    }
                }
            } else {
                if (m % c < c - 1) {
                    int k = 0;
                    for (int i = 0; i < r; i++) {
                        if (i < r - 2) {
                            for (int j = 0; j < c; j++) {
                                if (k < m) {
                                    map[i][j] = 1;
                                    k++;
                                } else {
                                    map[i][j] = 0;
                                }
                            }
                        } else if (i == r - 2) {
                            double k1;
                            if (k < m) {
                                if ((m - k) % 2 == 0) {
                                    k1 = (m - k) / 2;
                                } else {
                                    k1 = (m - k + 1) / 2;
                                    //System.out.println("test");
                                }
                            } else {
                                k1 = -1;
                            }
                            for (int j = 0; j < c; j++) {
                                if (j < k1 && j < c - 2) {
                                    map[r - 2][j] = 1;
                                } else {
                                    if (i == r - 1 && j == c - 1) {
                                        map[r - 2][j] = 2;
                                    } else {
                                        map[r - 2][j] = 0;
                                    }
                                }
                            }
                        } else if (i == r - 1) {
                            double k1;
                            if (k < m) {
                                if ((m - k) % 2 == 0) {
                                    k1 = (m - k) / 2;
                                } else {
                                    k1 = (m - k - 1) / 2;
                                }
                            } else {
                                k1 = -1;
                            }
                            for (int j = 0; j < c; j++) {
                                if (j < k1 && j < c - 2) {
                                    map[r - 1][j] = 1;
                                    k++;
                                } else {
                                    if (i == r - 1 && j == c - 1) {
                                        map[r - 1][j] = 2;
                                    } else {
                                        map[r - 1][j] = 0;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    int k = 0;
                    for (int i = 0; i < c - 2; i++) {
                        for (int j = 0; j < r; j++) {
                            if (k < m) {
                                if (!(k == m - 1 && j == r - 2)) {
                                    map[j][i] = 1;
                                    k++;
                                } else {
                                    break;
                                }
                            } else {
                                map[j][i] = 0;
                            }
                        }
                    }
                    double k1 = (m - k) / 2;
                    for (int j = 0; j < r; j++) {
                        if (j < k1 && j < r - 2) {
                            map[j][c - 2] = 1;
                        } else {
                            map[j][c - 2] = 0;
                        }
                    }
                    for (int j = 0; j < r; j++) {
                        if (j < k1 && j < r - 2) {
                            map[j][c - 1] = 1;
                            k++;
                        } else {
                            if (j == r - 1) {
                                map[j][c - 1] = 2;
                            } else {
                                map[j][c - 1] = 0;
                            }
                        }
                    }


                }
            }
            if (!flag) {
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        s = map[i][j] == 1 ? "*" : (map[i][j] == 2 ? "c" : ".");
                        System.out.print(s);
                        out.write(s);
                    }
                    s = "\n";
                    System.out.print(s);
                    out.write(s);
                }
                int[][] cnt = new int[r][c];
                int cc = 0;
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        if (map[i][j] == 1) {
                            cc++;
                        }
                        if (i > 0 && j > 0 && map[i - 1][j - 1] == 1) {
                            cnt[i][j]++;
                        }
                        if (i > 0 && map[i - 1][j] == 1) {
                            cnt[i][j]++;
                        }
                        if (i > 0 && j < c - 1 && map[i - 1][j + 1] == 1) {
                            cnt[i][j]++;
                        }
                        if (j > 0 && map[i][j - 1] == 1) {
                            cnt[i][j]++;
                        }
                        if (j < c - 1 && map[i][j + 1] == 1) {
                            cnt[i][j]++;
                        }
                        if (i < r - 1 && j > 0 && map[i + 1][j - 1] == 1) {
                            cnt[i][j]++;
                        }
                        if (i < r - 1 && map[i + 1][j] == 1) {
                            cnt[i][j]++;
                        }
                        if (i < r - 1 && j < c - 1 && map[i + 1][j + 1] == 1) {
                            cnt[i][j]++;
                        }
                    }
                }
                /*for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        s = String.valueOf(cnt[i][j]);
                        System.out.print(s);
                        out.write(s);
                    }
                    s = "\n";
                    System.out.print(s);
                    out.write(s);
                } */
                if (cc != m) {
                    System.out.println("PIZDEZ");
                }
                x:
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        if (map[i][j] != 1) {
                            if (cnt[i][j] > 0) {
                                int k = 0;
                                if (i > 0 && j > 0 && cnt[i - 1][j - 1] == 0) {
                                    k++;
                                }
                                if (i > 0 && cnt[i - 1][j] == 0) {
                                    k++;
                                }
                                if (i > 0 && j < c - 1 && cnt[i - 1][j + 1] == 0) {
                                    k++;
                                }
                                if (j > 0 && cnt[i][j - 1] == 0) {
                                    k++;
                                }
                                if (j < c - 1 && cnt[i][j + 1] == 0) {
                                    k++;
                                }
                                if (i < r - 1 && j > 0 && cnt[i + 1][j - 1] == 0) {
                                    k++;
                                }
                                if (i < r - 1 && cnt[i + 1][j] == 0) {
                                    k++;
                                }
                                if (i < r - 1 && j < c - 1 && cnt[i + 1][j + 1] == 0) {
                                    k++;
                                }
                                if (k == 0 && r * c != m + 1) {
                                    System.out.println("ZHOPA" + i + " " + j);
                                    break x;
                                }
                            }
                        }
                    }
                }
            }
        }
        out.close();
    }

}
