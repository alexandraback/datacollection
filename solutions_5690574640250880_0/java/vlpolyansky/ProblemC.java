import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

public class ProblemC {

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.UK);
        new ProblemC();
    }

    private BufferedReader in = null;
    private PrintWriter out = null;
    private StringTokenizer tok = new StringTokenizer("");
    private String fileName = "C-small-attempt5";

    public ProblemC() throws Exception {
        init();
        solve();
        in.close();
        out.close();
    }

    private void solve() throws Exception {
        int T = nextInt();
        nexttest:
        for (int ii = 0; ii < T; ++ii) {
            int r = nextInt();
            int c = nextInt();
            int m = nextInt();
            out.printf("Case #%d:\n", ii + 1);
            if (r == 1) {
                out.print("c");
                for (int i = 0; i < c - m - 1; ++i) {
                    out.print(".");
                }
                for (int i = 0; i < m; ++i) {
                    out.print("*");
                }
                out.println();
            } else if (c == 1) {
                out.println("c");
                for (int i = 0; i < r - m - 1; ++i) {
                    out.println(".");
                }
                for (int i = 0; i < m; ++i) {
                    out.println("*");
                }
            } else if (m == r * c - 1) {
                out.print("c");
                for (int i = 1; i < c; ++i) {
                    out.print("*");
                }
                out.println();
                for (int i = 1; i < r; ++i) {
                    for (int j = 0; j < c; ++j) {
                        out.print("*");
                    }
                    out.println();
                }
            } else {
                int ok = r * c - m;
                if (r == 2) {
                    if (ok % 2 == 1 || ok == 2) {
                        out.println("Impossible");
                    } else {
                        for (int l = 0; l < 2; ++l) {
                            for (int i = 0; i < ok / 2; ++i) {
                                out.print(l == 0 && i == 0 ? "c" : ".");
                            }
                            for (int i = ok / 2; i < c; ++i) {
                                out.print("*");
                            }
                            out.println();
                        }
                    }
                } else if (c == 2) {
                    if (ok % 2 == 1 || ok == 2) {
                        out.println("Impossible");
                    } else {
                        for (int i = 0; i < ok / 2; ++i) {
                            out.println(i == 0 ? "c." : "..");
                        }
                        for (int i = ok / 2; i < r; ++i) {
                            out.println("**");
                        }
                    }
                } else if (ok < 4 || ok == 5 || ok == 7) {
                    out.println("Impossible");
                } else {
                    boolean[][] ans = new boolean[r][c];
                    if (ok % 2 == 0) {
                        for (int x = 0; x < c && ok > 0; ++x, ok -= 2) {
                            ans[0][x] = ans[1][x] = true;
                        }
                        for (int y = 2; y < r && ok > 0; ++y, ok -= 2) {
                            ans[y][0] = ans[y][1] = true;
                        }
                        for (int x = 2; x < c; ++x) {
                            for (int y = 2; y < r && ok > 0; ++y, ok--) {
                                ans[y][x] = true;
                            }
                        }
                    } else {
                        for (int i = 0; i < 3; ++i) {
                            for (int j = 0; j < 3; ++j, ok--) {
                                ans[i][j] = true;
                            }
                        }
                        for (int x = 3; x < c && ok > 0; ++x, ok -= 2) {
                            ans[0][x] = ans[1][x] = true;
                        }
                        for (int y = 3; y < r && ok > 0; ++y, ok -= 2) {
                            ans[y][0] = ans[y][1] = true;
                        }
                        if (ok > 0) {
                            ans[2][2] = false;
                            ok++;
                        }
                        for (int x = 2; x < c; ++x) {
                            for (int y = 2; y < r && ok > 0; ++y, ok--) {
                                ans[y][x] = true;
                            }
                        }
                    }
                    for (int i = 0; i < r; ++i) {
                        for (int j = 0; j < c; ++j) {
                            out.print(i == 0 && j == 0 ? 'c' : (ans[i][j] ? '.' : '*'));
                        }
                        out.println();
                    }
                }
            }
        }
    }


    private void init() throws FileNotFoundException {
        if (fileName.equals("#Console")) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        } else if (fileName.equals("#IOtxt")) {
            in = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
        } else {
            in = new BufferedReader(new FileReader(fileName + ".in"));
            out = new PrintWriter(fileName + ".out");
        }
    }


    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }


    private String nextToken() throws IOException {
        while (!tok.hasMoreTokens()) {
            String s = in.readLine();
            if (s == null) {
                return null;
            }
            tok = new StringTokenizer(s);
        }
        return tok.nextToken();
    }

}
            