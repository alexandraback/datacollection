import java.util.*;
public class C {
    static Scanner s;
    public static void main(String[] args) {
        s = new Scanner(System.in);
        int n = s.nextInt();
        for (int i = 1; i <= n; i++) {
            System.out.printf("Case #%d:\n", i);
            solve();
        }
    }

    public static void solve() {
        int R = s.nextInt();
        int C = s.nextInt();
        int M = s.nextInt();
        if (M == R * C - 1) {
            for (int i = 0; i < R; i++) {
                StringBuilder sb = new StringBuilder();
                for (int j = 0; j < C; j++) {
                    if (i == 0 && j == 0) sb.append("c");
                    else sb.append("*");
                }
                System.out.println(sb);
            }
            return;
        }
        if (R == 1 || C == 1) {
            if (M > R * C - 1) {
                System.out.println("Impossible");
                return;
            }
            if (R == 1) {
                StringBuilder sb = new StringBuilder();
                sb.append("c");
                for (int i = 0; i < C - 1 - M; i++) {
                    sb.append(".");
                }
                for (int i = 0; i < M; i++) {
                    sb.append("*");
                }
                System.out.println(sb.toString());
                return;
            } else {
                System.out.println("c");
                for (int i = 0; i < R - 1 - M; i++) {
                    System.out.println(".");
                }
                for (int i = 0; i < M; i++) {
                    System.out.println("*");
                }
                return;
            }
        }

        if (R == 2 || C == 2) {
            if (M % 2 == 1 || M > R*C - 4) {
                System.out.println("Impossible");
            } else {
                if (R == 2) {
                    int K = M;
                    StringBuilder sb = new StringBuilder();
                    for (int i = 0; i < C; i++) {
                        if (i < K/2) {
                            sb.append("*");
                            M--;
                        } else sb.append(".");
                    }
                    System.out.println(sb);
                    sb = new StringBuilder();
                    for (int i = 0; i < C; i++) {
                        if (i < K/2) {
                            sb.append("*");
                            M--;
                        } else if (i == C-1) sb.append("c");
                        else sb.append(".");
                    }
                    System.out.println(sb);
                } else {
                    for (int i = 0; i < R; i++) {
                        if (i == R-1) System.out.println(".c");
                        else if (M == 0) System.out.println("..");
                        else {
                            System.out.println("**");
                            M -= 2;
                        }
                    }
                }
                if (M != 0) System.out.println("WTF!");
            }
            return;
        } else if (M > R*C - 4 || M == R*C - 7 || M == R*C - 5) {
            System.out.println("Impossible");
            return;
        }

        if (M == R*C - 4) {
            for (int i = 0; i < R; i++) {
                StringBuilder sb = new StringBuilder();
                for (int j = 0; j < C; j++) {
                    if (i == R-1 && j == C-1) {
                        sb.append("c");
                    } else if (i >= R-2 && j >= C-2) {
                        sb.append(".");
                    } else {
                        sb.append("*");
                    }
                }
                System.out.println(sb);
            }
            return;
        }

        boolean lol = true;
        boolean flag = false;
        int K = 0;
        int L = 0;
        for (int i = 0; i < R; i++) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < C; j++) {
                if (i == R-1 && j == C-1) {
                    sb.append("c");
                } else if (i >= R-2 && j >= C-2) {
                    sb.append(".");
                } else {
                    if (M == 0) {
                        sb.append(".");
                    } else {
                        if (i == R-3 && j >= C-3) {
                            if (flag) {
                                sb.append(".");
                                if (j == C-1) flag = false;
                            } else {
                                if (M%2 == 0) {
                                    sb.append(".");
                                    flag = true;
                                } else {
                                    sb.append("*");
                                    M--;
                                    flag = false;
                                }
                            }
                        } else if (i == R-2) {
                            if (lol) {
                                lol = false;
                                K = M - M/2;
                                L = M - K;
                            }
                            if (K == 0) {
                                sb.append(".");
                            } else {
                                sb.append("*");
                                K--;
                                M--;
                            }
                        } else if (i == R-1) {
                            if (L == 0) {
                                sb.append(".");
                            } else {
                                sb.append("*");
                                L--;
                                M--;
                            }
                        } else {
                            if (j >= C-2) {
                                if (j == C-2 && M == 1) {
                                    flag = true;
                                    sb.append(".");
                                } else if (flag) {
                                    sb.append(".");
                                    if (j == C-1) flag = false;
                                } else {
                                    sb.append("*");
                                    M--;
                                }
                            } else {
                                sb.append("*");
                                M--;
                            }
                        }
                    }
                }
            }
            System.out.println(sb);
        }
        if (M != 0) System.out.println("WTF?!");
    }
}
