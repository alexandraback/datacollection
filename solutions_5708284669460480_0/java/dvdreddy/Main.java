import java.util.Map;
import java.util.Scanner;
import java.io.IOException;
import java.util.HashMap;
import java.util.Set;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author dvdreddy
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		B123 solver = new B123();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class B123 {


    private int[] getKmp(String targ) {
        int cnt = targ.length();
        int[] ret = new int[cnt + 1];
        ret[0] = -1; ret[1] = 0;
        int cnd = 0, pos = 2;
        while (pos <= cnt) {
            if (targ.charAt(pos - 1) == targ.charAt(cnd)) {
                cnd++; ret[pos] = cnd; pos++;
            } else if (cnd > 0) {
                cnd = ret[cnd];
            } else {
                ret[pos] = 0; pos++;
            }
        }
        return ret;
    }

    private Map<Character, Double> getProbMap(String alph) {
        int tot = alph.length();
        Map<Character, Double> ps = new HashMap<Character, Double>();
        for (int i = 0; i < tot; i++) {
            Double val = ps.get(alph.charAt(i));
            if (val == null) {
                ps.put(alph.charAt(i), 1.0 / tot);
            } else {
                ps.put(alph.charAt(i), val + (1.0/tot));
            }
        }
        return ps;
    }


    private int nextSt(int[] kmpTab, char curChar,
            String targ, int probStat) {
        int curStat = probStat;
        while (true) {
            if (curChar == targ.charAt(curStat)) {
                return curStat + 1;
            } else if (curStat == 0) {
                return 0;
            } else {
                curStat = kmpTab[curStat];
            }
        }
    }


    private int getMaxCount(int[] kmpTab, int sz, int l) {
        return 1 + (int) ((l - sz) / (sz - kmpTab[sz]));
    }



    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int k = in.nextInt();
        int s = in.nextInt();
        int l = in.nextInt();
        String alph = in.next();
        String targ = in.next();
        int[] kmpTab = getKmp(targ);
        int sz = targ.length();
        Map<Character, Double> probMap = getProbMap(alph);

        double[][] prob = new double[2][sz];

        for (int i = 0; i < sz; i++){
            prob[1][i] = 0.0; prob[0][i] = 0.0;
        }

        prob[0][0] = 1.0; int curp = 0;
        double exp = 0.0;

        double target = (double) getMaxCount(kmpTab, sz, l);


        if (!probMap.keySet().containsAll(getProbMap(targ).keySet())) {
            target = 0.0;
        }


        for(int i = 0; i < l; i++) {
            int next = curp ^ 1;
            for (int j = 0; j < sz; j++) {
                prob[next][j] = 0.0;
            }

            for (Map.Entry<Character, Double> keys : probMap.entrySet()) {
                for (int j = 0; j < sz; j++) {
                    int nextSt = nextSt(kmpTab, keys.getKey(), targ, j);
                    if (nextSt == sz) {
                        exp += (keys.getValue() * prob[curp][j]);
                        prob[next][kmpTab[sz]] += (keys.getValue() * prob[curp][j]);
                    } else {
                        prob[next][nextSt] += (keys.getValue() * prob[curp][j]);
                    }
                }
            }
            curp = next;
        }


        System.out.println("Max Count is " + getMaxCount(kmpTab, sz, l));


        out.println("Case #" + testNumber + ": " +
                (target - exp));
    }
}

