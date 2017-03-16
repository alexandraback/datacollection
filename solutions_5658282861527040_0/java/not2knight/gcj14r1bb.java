import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class gcj14r1bb {
    public static void main(String[] args) {
        try {
            new gcj14r1bb().solve();
        } catch (Exception e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    void solve() throws Exception {
        Locale.setDefault(Locale.US);

//        String fn = "E:\\isinev\\develop\\contests\\training\\spoj\\work\\b.in";
        String fn = "E:\\isinev\\download\\B-small-attempt0.in";

        File fin = new File(fn + ".res");
        PrintWriter pw = new PrintWriter(fin);
        Scanner sc = new Scanner(new File(fn));

        int tc = sc.nextInt();

        for (int tci = 1; tci <= tc; tci++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int k = sc.nextInt();
            pw.format("Case #%d: %s%n", tci, count(true, a, true, b, k));
            pw.flush();
        }
        pw.close();
    }

    private int count(boolean fa, int a, boolean fb, int b, int k) {
        int res = 0;
        for (int ia = 0; ia < a; ia++) {
            for (int ib = 0; ib < b; ib++) {
                if ((ia & ib) < k) {
                    res++;
                }
            }
        }
        return res;
    }


}