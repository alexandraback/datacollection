package codejam.y2016.round1.subroundC;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.*;

/**
 * @author Max Myslyvtsev
 * @since 4/30/16
 */
public class C {

    public static void main(String[] args) throws Exception {
        //Scanner in = new Scanner(new FileInputStream("/Users/max/Work/Source/foobar/src/main/resources/input.txt"));
        Scanner in = new Scanner(new FileInputStream("/Users/max/Downloads/C-small-attempt5.in"));
        PrintStream out = new PrintStream(new FileOutputStream("/Users/max/Work/Source/foobar/src/main/resources/output.txt"));
        int T = in.nextInt();
        in.nextLine();
        for (int t = 1; t <= T; t++) {
            int J = in.nextInt();
            int P = in.nextInt();
            int S = in.nextInt();
            int K = in.nextInt();
            String a = new C(K).solveOut(J, P, S);
            String answ = "Case #" + t + ": " + a;
            out.println(answ);
            System.out.println(answ);
        }
    }

    int K;
    int usedSingle = 0;
    Map<Integer, Integer> usedJP = new HashMap<>();
    Map<Integer, Integer> usedJS = new HashMap<>();
    Map<Integer, Integer> usedPS = new HashMap<>();

    public C(int k) {
        K = k;
    }

    Map<Integer, List<int[]>> cache = new HashMap<>();

    private List<int[]> solve(int J, int P, int S) {
        List<int[]> res = new ArrayList<>();
        for (int j = 1; j <= J; j++) {
            for (int p = 1; p <= P; p++) {
                for (int s = 1; s <= S; s++) {
                    if (useOnce(j, p, s)) {
                        res.add(new int[]{j,p,s});
                    }
                }
            }
        }
        return res;
    }

    private List<int[]> solveBF(int J, int P, int S) {
        List<int[]> cached = cache.get(usedSingle);
        if (cached != null) {
            return cached;
        }
        List<int[]> res = new ArrayList<>();
        for (int j = 1; j <= J; j++) {
            for (int p = 1; p <= P; p++) {
                for (int s = 1; s <= S; s++) {
                    if (useOnce(j, p, s)) {
                        List<int[]> curRes = solveBF(J, P, S);
                        curRes.add(new int[]{j,p,s});
                        if (curRes.size() > res.size()) {
                            res = curRes;
                        }
                        unuseOnce(j, p, s);
                    }
                }
            }
        }
        cache.put(usedSingle, res);
        return res;
    }

    private String solveOut(int J, int P, int S) {
        /*List<int[]> resBF = solveBF(J, P, S);
        List<int[]> res = solve(J, P, S);
        if (resBF.size() != res.size()) {
            throw new RuntimeException("PIZDA");
        }
        return printRes(resBF)+"\n"+printRes(res);*/

        /*List<int[]> res = solve(J, P, S);
        return printRes(res);*/

        List<int[]> resBF = solveBF(J, P, S);
        return printRes(resBF);
    }

    private String printRes(List<int[]> res) {
        StringBuilder sb = new StringBuilder();
        sb.append(res.size());
        for (int[] item : res) {
            sb.append("\n")
                    .append(item[0]).append(" ")
                    .append(item[1]).append(" ")
                    .append(item[2]);
        }
        return sb.toString();
    }

    private boolean useOnce(int j, int p, int s) {
        int mask = mask(j, p, s);
        if ((usedSingle & mask) > 0) {
            return false;
        }

        int hashAll = hash(j, p, s);
        int hashJP = hash(j, p, NONE);
        int hashJS = hash(j, NONE, s);
        int hashPS = hash(NONE, p, s);
        Integer countJP = usedJP.get(hashJP);
        if (countJP == null) {
            countJP = 0;
        }
        Integer countJS = usedJS.get(hashJS);
        if (countJS == null) {
            countJS = 0;
        }
        Integer countPS = usedPS.get(hashPS);
        if (countPS == null) {
            countPS = 0;
        }
        if (countJP < K && countJS < K && countPS < K) {
            countJP++;
            countJS++;
            countPS++;
            usedJP.put(hashJP, countJP);
            usedJS.put(hashJS, countJS);
            usedPS.put(hashPS, countPS);

            usedSingle |= mask;

            return true;
        } else {
            return false;
        }
    }

    private void unuseOnce(int j, int p, int s) {
        int mask = mask(j, p, s);
        //int hashAll = hash(j, p, s);
        int hashJP = hash(j, p, NONE);
        int hashJS = hash(j, NONE, s);
        int hashPS = hash(NONE, p, s);
        Integer countJP = usedJP.get(hashJP);
        if (countJP == null) {
            countJP = 0;
        }
        Integer countJS = usedJS.get(hashJS);
        if (countJS == null) {
            countJS = 0;
        }
        Integer countPS = usedPS.get(hashPS);
        if (countPS == null) {
            countPS = 0;
        }
        usedJP.put(hashJP, countJP-1);
        usedJS.put(hashJS, countJS-1);
        usedPS.put(hashPS, countPS-1);
        usedSingle &= (~mask);
    }


    static final int NONE = 15;
    private static int hash(int j, int p, int s) {
        int q = (((j << 7) + p) << 7) + s;
        return q;
    }

    private static int mask(int j, int p, int s) {
        int q = (j-1)*100+(p-1)*10+(s-1);
        return q;
    }

}
