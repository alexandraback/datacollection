import java.io.*;
import java.util.HashMap;
import java.util.Scanner;

/**
 * Created by @vlfom.
 */
public class GoogleCJC {
    public static void inc(HashMap<Integer, Integer> hm, int key) {
        if (!hm.containsKey(key)) {
            hm.put(key, 1);
        }
        else {
            hm.put(key, hm.get(key) + 1);
        }
    }

    public static void main (String... args) throws FileNotFoundException {
        int[] jp, js, ps;
        //Scanner sc = new Scanner(System.in);
        //PrintWriter pw = new PrintWriter(System.out);
        Scanner sc = new Scanner(new FileInputStream(new File("input.txt")));
        PrintWriter pw = new PrintWriter(new FileOutputStream(new File("output.txt")));
        int T, T_;
        int J, P, S, K, j, p, s, total, ind, bad, cnt;
        T = sc.nextInt();
        for (T_ = 1; T_ <= T; ++T_) {
            System.out.println(T_);

            int best_cnt = 0, best_mask = 0;
            pw.print("Case #" + T_ + ": ");
            //System.out.println("Case #" + T_ + ": ");
            J = sc.nextInt();
            P = sc.nextInt();
            S = sc.nextInt();
            K = sc.nextInt();
            total = J * P * S;
            for (int mask = (1<<total) - 1; mask >= 1; mask--) {
                bad = 0;
                cnt = 0;

                jp = new int[100];
                js = new int[100];
                ps = new int[100];

                ind = 0;
                for (j = 1; j <= J; ++j) {
                    for (p = 1; p <= P; ++p) {
                        for (s = 1; s <= S; ++s) {
                            //System.out.println((mask & (1<<ind)) + " " + mask + " " + (1<<ind));
                            if ((mask & (1<<ind)) > 0) {
                                cnt += 1;
                                jp[j*10 + p] += 1;
                                js[j*10 + s] += 1;
                                ps[p*10 + s] += 1;
                                if (jp[j*10 + p] > K) {
                                    bad = 1;
                                    break;
                                }
                                if (js[j*10 + s] > K) {
                                    bad = 1;
                                    break;
                                }
                                if (ps[p*10 + s] > K) {
                                    bad = 1;
                                    break;
                                }
                            }
                            ind += 1;
                        }
                        if (bad == 1)
                            break;
                    }
                    if (bad == 1)
                        break;
                }

                if (bad == 0 && cnt > best_cnt) {
                    best_cnt = cnt;
                    best_mask = mask;
                    //System.out.println(best_cnt);
                    if (best_cnt == total)
                        break;
                }
            }

            pw.println(best_cnt);
            //System.out.println(best_cnt);
            ind = 0;
            for (j = 1; j <= J; ++j) {
                for (p = 1; p <= P; ++p) {
                    for (s = 1; s <= S; ++s) {
                        if ((best_mask & (1<<ind)) > 0) {
                            pw.println(j + " " + p + " " + s);
                            //System.out.println(j + " " + p + " " + s);
                        }
                        ind += 1;
                    }
                }
            }
        }
        sc.close();
        pw.close();
    }
}
