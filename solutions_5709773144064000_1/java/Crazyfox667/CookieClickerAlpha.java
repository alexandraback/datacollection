import java.io.*;
import java.util.Date;
import java.util.DoubleSummaryStatistics;

/**
 * Date: 12/04/2014
 * Time: 12:35
 */

public class CookieClickerAlpha {
    public static void main(String[] args) throws IOException {
        new CookieClickerAlpha().doSomething();
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
            File fOut = new File("CookieClickerAlpha.out");
            BufferedReader in = new BufferedReader(new FileReader(fIn));
            BufferedWriter out = new BufferedWriter(new FileWriter(fOut));
            int n = Integer.valueOf(in.readLine());
            for (int i = 1; i <= n; i++) {
                out.write("Case #" + i + ": " + solve(in));
                out.newLine();
                out.flush();
            }
            in.close();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    void read(BufferedReader in) throws IOException {

    }

    String solve(BufferedReader in) throws IOException {
        String[] read = in.readLine().split(" ");
        double c = Double.parseDouble(read[0]);
        double f = Double.parseDouble(read[1]);
        double x = Double.parseDouble(read[2]);

        double p = 2.0;
        double b = 0.0;

        double time = Double.MAX_VALUE;
        double newTime = x / p;

        while (newTime < time) {
            time = newTime;
            b = b + c / p;
            p = p + f;
            newTime = b + x / p;
        }

        return Double.toString(time);
    }
}
