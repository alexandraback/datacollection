import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;
import java.util.DoubleSummaryStatistics;

/**
 * Date: 12/04/2014
 * Time: 12:38
 */

public class DeceitfulWar {
    public static void main(String[] args) throws IOException {
        new DeceitfulWar().doSomething();
    }

    void doSomething() throws IOException {
        try {
            File test = new File("").getAbsoluteFile();
            File[] inList = test.listFiles(new FilenameFilter() {
                @Override
                public boolean accept(File dir, String name) {
                    return name.toLowerCase().contains(".in");
                }
            });
            File fIn = inList[0];
            for (int i = 1; i < inList.length; i++) {
                if (new Date(fIn.lastModified()).compareTo(new Date(inList[i].lastModified())) < 0) {
                    fIn = inList[i];
                }
            }
            File fOut = new File("DeceitfulWar.out");
            BufferedReader in = new BufferedReader(new FileReader(fIn));
            BufferedWriter out = new BufferedWriter(new FileWriter(fOut));
            int n = Integer.valueOf(in.readLine());
            for (int i = 1; i <= n; i++) {
                out.write("Case #" + i + ": " + solve(in));
                out.newLine();
            }
            in.close();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    ArrayList<Double> read(BufferedReader in) throws IOException {
        String[] read = in.readLine().split(" ");
        ArrayList<Double> a = new ArrayList<>();
        for (String s : read) {
            a.add(Double.parseDouble(s));
        }
        Collections.sort(a);
        return a;
    }

    String solve(BufferedReader in) throws IOException {
        int n = Integer.valueOf(in.readLine());

        ArrayList<Double> naomi = read(in);
        ArrayList<Double> ken = read(in);
        ArrayList<Double> ken2 = new ArrayList<>(ken);

        int c1 = n;
        for (int i = 0, j = 0; j < n && i < n; j++) {
            if (naomi.get(i) < ken.get(j)) {
                c1--;
                i++;
            }

        }

        int c2 = 0;
        for (int i = 0, j = 0; j < n && i < n; i++) {
            if (naomi.get(i) > ken2.get(j)) {
                c2++;
                j++;
            }
        }

        return c2 + " " + c1;
    }
}
