import java.io.*;
import java.text.DecimalFormat;
import java.util.Map;
import java.util.TreeMap;

public class Task1 {
    public static DecimalFormat df = new DecimalFormat("#0.000000");

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(new File("t.txt")));
        BufferedWriter writer = new BufferedWriter(new FileWriter(new File("out.txt")));
        int num = Integer.parseInt(reader.readLine().trim());
        for (int i = 0; i < num; i++) {
            String orig = reader.readLine();
            writer.write("Case #" + (i + 1) + ": ");
            String[] strs = orig.split(" +");
            double total = 0;
            int col = Integer.parseInt(strs[0]);
            double[] gg = new double[col+1];
            for (int j = 1; j < strs.length; j++) {
                total += Integer.parseInt(strs[j]);
                gg[j] = Double.parseDouble(strs[j]);
            }
            double[] ans = new double[col+1];
            boolean[] zeros = new boolean[col+1];
            int count = 0;
            do {
                int ind = -1;
                for (int j = 1; j < zeros.length; j++) {
                    if(!zeros[j] && ans[j] < 0 && ((ind >= 0 && ans[j] < ans[ind]) || ind < 0)){
                        ind = j;
                    }
                }
                if(ind > -1){
                    zeros[ind] = true;
                }
                double newtotal = 0.0;
                for (int j = 0; j < zeros.length; j++) {
                    if(!zeros[j]){
                        newtotal += gg[j];
                    }

                }
                double lowest = (total + newtotal)/ (col - count);
                for (int j = 1; j < ans.length; j++) {
                    if (zeros[j]) {
                        ans[j] = 0.0;
                    } else {
                        ans[j] = 100 * (lowest - gg[j]) / total;
                    }
                }
                count++;
            } while (!istrue(ans));
            for (int j = 1; j < strs.length; j++) {
                writer.write(df.format(ans[j]));
                if (j < strs.length - 1) {
                    writer.write(" ");
                }
            }
            if (i < num - 1) {
                writer.write('\n');
            }
        }
        writer.close();
        reader.close();
    }

    private static boolean istrue(double[] ans) {
        for (int i = 1; i < ans.length; i++) {
            if (ans[i] < 0) {
                return false;
            }
        }
        return true;
    }
}
