import javax.swing.*;
import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Locale;
import java.util.StringTokenizer;

public class C implements Runnable {

    private static final String DIR = "/home/igoradmin/work/develop/competitions/codejam/2015/src/";

    String problemName = C.class.getName();

    static final int inf = (int) 1e9;

    //    String fileName = String.format(DIR + "%s-statement", problemName);
//    String fileName = String.format(DIR + "%s-small-attempt0", problemName);
	String fileName = String.format(DIR + "%s-large", problemName);

    int[] p;

    public void run() {
        try {
//            int nt = nextInt();
//            for (int it = 1; it <= nt; it++) {
//                int res = solve();
//                out.format("Case #%d: %s%n", it, res);
//            }

            {
                boolean[] pu = new boolean[8];
                ArrayList<Integer> pl = new ArrayList<Integer>();
                for (int i = 2; i < pu.length; i++) {
                    if (pu[i]) {
                        continue;
                    }
                    pl.add(i);
                    for (int j = 2 * i; j < pu.length; j += i) {
                        pu[j] = true;
                    }
                }
                p = new int[pl.size()];
                for (int i = 0; i < pl.size(); i++) {
                    p[i] = pl.get(i);
                }
            }

            out.format("Case #1:%n");
            solve();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            out.close();
        }
    }

    private void solve() {
        StringBuilder sb = new StringBuilder();

        int SLEN = 32;
        int JC = 500;

        sb.append(1);
        for (int i = 2; i <= SLEN; i++) {
            sb.append(0);
        }

        int c = 0;

        int[] dr = new int[]{-1, -1, 3, 2, 3, 2, 7, 2, 3, 2, 3};
        int[] rr = new int[11];
        for (int ri = 2; ri <= 10; ri++) {
            BigInteger rm = new BigInteger(sb.toString(), ri);
            rr[ri] = rm.mod(BigInteger.valueOf(ri)).intValue();
        }
//        HashMap<String, Integer> cd = new HashMap<String, Integer>();
//        int md = 0;
        int N = 1 << 18;

        nloop:
        for (int I = 0; I < N && c <= JC; I++) {

            sb.setLength(0);
            String v = Integer.toString(I, 2);
            sb.append(v);
            sb.append(1);
            String si = sb.toString();


            for (int r = 2; r <= 10; r++) {
                long rn = Long.valueOf(si, r);
                if ((rn % dr[r] + rr[r]) % dr[r] != 0) {
                    continue nloop;
                }
            }

//            String sd = sb.toString();
//            if (cd.containsKey(sd)) {
//                int cdm = cd.get(sd) + 1;
//                if (md < cdm) {
//                    md = cdm;
//                    System.out.format("%d %s%n", cdm, sd);
//                }
//                cd.put(sd, cdm);
//            } else {
//                cd.put(sd, 1);
//            }
//            if (sd.equals(" 3 2 3 2 7 2 3 2 3")) {
//                out.format("%s%s%n", si, sd);
//            }
            String sd = " 3 2 3 2 7 2 3 2 3";
            sb.setLength(0);
            sb.append(1);
            while (sb.length() + si.length() < SLEN) {
                sb.append('0');
            }
            sb.append(si);

//            for (int r = 2; r <= 10; r++) {
//                long rn = Long.valueOf(si, r);
//                sb.append(' ').append(rn % dr[r]);
//            }

            out.format("%s%s%n", sb.toString(), sd);
            c++;
        }
    }

    static {
        Locale.setDefault(Locale.US);
    }

    BufferedReader in;
    PrintWriter out;
    StringTokenizer st;

    public C() throws FileNotFoundException {
        in = new BufferedReader(new FileReader(new File(fileName + ".in")));
        out = new PrintWriter(fileName + ".out");
        st = new StringTokenizer("");
    }

    public static void main(String[] args) throws FileNotFoundException {
        new Thread(new C()).start();
    }

    String next() throws IOException {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws NumberFormatException, IOException {
        return Integer.parseInt(next());
    }

    double nextDouble() throws NumberFormatException, IOException {
        return Double.parseDouble(next());
    }

    long nextLong() throws NumberFormatException, IOException {
        return Long.parseLong(next());
    }
}