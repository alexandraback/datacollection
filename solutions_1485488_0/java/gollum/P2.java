package googleJamCode;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;

/**
 * 
 * @author gollum1er
 */
public class P2 {

    private String chemin = "/media/REDARMY/gollum/P2/";

    public Integer moveNDigits(Integer nb, Integer nbDigitsToMove) {
        String strNb = nb.toString();
        String res =
            strNb.substring(strNb.length() - nbDigitsToMove, strNb.length()) +
                strNb.substring(0, strNb.length() - nbDigitsToMove);
        return Integer.parseInt(res);
    }

    public List<Integer> findAllPermutationsWithDigits(Integer nb, Integer nbDigitsToMove, Integer min, Integer max) {
        List<Integer> resListTmp = new ArrayList<Integer>();
        Integer tmpRes = this.moveNDigits(nb, nbDigitsToMove);
        if (tmpRes > nb && tmpRes >= min && tmpRes <= max) {
            resListTmp.add(tmpRes);
        }
        Set set = new HashSet();
        set.addAll(resListTmp);
        ArrayList resList = new ArrayList(set);
        return resList;
    }

    public List<Integer> findAllPermutations(Integer nb, Integer min, Integer max) {
        String strNb = nb.toString();
        List<Integer> resListTmp = new ArrayList<Integer>();
        for (int i = 1; i < strNb.length(); i++) {
            List<Integer> resListTmp2 = this.findAllPermutationsWithDigits(nb, i, min, max);
            resListTmp.addAll(resListTmp2);
        }
        Set set = new HashSet();
        set.addAll(resListTmp);
        ArrayList resList = new ArrayList(set);
        return resList;
    }

    public Integer findRes(int min, int max) {
        Integer res = 0;
        for (int i = min; i < max + 1; i++) {
            List<Integer> tmpList = this.findAllPermutations(i, min, max);
            res += tmpList.size();
        }
        return res;
    }

    // lecture pour le fichier de recherche
    public List readFile(String nFichier) {
        List<String> res = new ArrayList<String>();
        String nomFichier = chemin + nFichier;
        try {
            BufferedReader in = new BufferedReader(new FileReader(nomFichier));
            // String line = in.readLine();
            String line;
            while ((line = in.readLine()) != null) {
                res.add(line);
            }
            in.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return res;
    }

    // écrit le résultat des trie
    public void writeFile(List content, String nFichier) {
        String nomFichier = chemin + nFichier;
        try {
            PrintWriter out = new PrintWriter(new FileWriter(nomFichier));
            Iterator it = content.iterator();
            int cpt = 1;
            while (it.hasNext()) {
                String str = (String) it.next();
                out.println("Case #" + cpt + ": " + str);
                System.out.println("Case #" + cpt + ": " + str);
                cpt++;
            }
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String args[]) {
        P2 pm = new P2();
        String inputname = "B-small-attempt0.in";
        List<String> inputList = pm.readFile(inputname);
        Iterator<String> it = inputList.iterator();
        List resList = new ArrayList<String>();

        int T = Integer.parseInt(it.next());
        for (int t = 0; t < T; t++) {
            resList.add(solve(it));
        }

        pm.writeFile(resList, inputname + ".answer.out");
    }

    private static String solve(Iterator<String> it) {
        String[] HNM = it.next().split(" ");
        int H = Integer.parseInt(HNM[0]);
        int N = Integer.parseInt(HNM[1]);
        int M = Integer.parseInt(HNM[2]);

        int[][] ceilings = new int[N][M];
        int[][] floors = new int[N][M];
        Double[][] best = new Double[N][M];

        for (int i = 0; i < N; i++) {
            String line = it.next();
            String[] tokens = line.split(" ");
            for (int j = 0; j < M; j++) {
                ceilings[i][j] = Integer.parseInt(tokens[j]);
            }
        }
        for (int i = 0; i < N; i++) {
            String line = it.next();
            String[] tokens = line.split(" ");
            for (int j = 0; j < M; j++) {
                floors[i][j] = Integer.parseInt(tokens[j]);
            }
        }

        // Initial position
        best[0][0] = 0.0;

        // Before the tide goes down
        traverse(0, 0, H, N, M, ceilings, floors, best, true);
        if (best[N - 1][M - 1] != null) {
            return best[N - 1][M - 1].toString();
        }

        // While the tide goes down
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (best[i][j] != null) {
                    traverse(i, j, H, N, M, ceilings, floors, best, false);
                }
            }
        }

        if (best[N - 1][M - 1] == null) {
            throw new IllegalStateException("Did not find the exit!!");
        }
        String answer = best[N - 1][M - 1].toString();
        // System.out.println(answer);
        return answer;
    }

    private static void traverse(int i, int j, int H, int N, int M, int[][] ceilings, int[][] floors,
        Double[][] best, boolean constantWater) {

        int[] nextI = { i + 1, i, i - 1, i };
        int[] nextJ = { j, j - 1, j, j + 1 };

        for (int a = 0; a < 4; a++) {
            int ii = nextI[a];
            int jj = nextJ[a];
            if (ii < 0 || ii >= N || jj < 0 || jj >= M) {
                continue;
            }

            Double t = best[i][j];
            if (t == null) {
                throw new IllegalStateException("Then how did I arrive here?");
            }
            int hnow = (int) Math.round(H - (10 * t));

            int c = ceilings[i][j];
            int cc = ceilings[ii][jj];
            int f = floors[i][j];
            int ff = floors[ii][jj];
            int h = Math.max(f, hnow);
            int hh = Math.max(ff, hnow);

            if (c - f < 50) {
                throw new IllegalStateException("I should not even be here!!");
            }
            if (cc - ff < 50 || cc - f < 50 || c - ff < 50) {
                // no way
                continue;
            }

            if (constantWater) {
                if (cc - hh < 50) {
                    // No way (for now)
                    continue;
                }
                double timeNext = 0.0;
                if (best[ii][jj] == null || timeNext < best[ii][jj]) {
                    best[ii][jj] = timeNext;
                    // Yabadabadoo
                    traverse(ii, jj, H, N, M, ceilings, floors, best, true);
                }
            } else {
                Double twait = t;
                if (cc - hh < 50) {
                    twait = t + ((hh - cc + 50) / 10.0);
                }

                int hwait = (int) Math.round(h - 10 * (twait - t));

                int timeneeded = ((hwait) - f >= 20) ? 1 : 10;

                double timeNext = twait + timeneeded;
                if (best[ii][jj] == null || timeNext < best[ii][jj]) {
                    best[ii][jj] = timeNext;
                    // Yabadabadoo
                    traverse(ii, jj, H, N, M, ceilings, floors, best, false);
                }
            }
        }

    }
}
