import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Writer;
import java.text.DecimalFormat;
import java.util.Scanner;

public class A {

    private String mInputFileName;
    private String mOutputFileName;
    
    private int A;
    private int B;
    private double[] mP;
    private double mCp;
    
    private static final DecimalFormat format = new DecimalFormat("#0.000000#");
    
    public A(String inputFileName, String outputFileName) {
        mInputFileName = inputFileName;
        mOutputFileName = outputFileName;
    }

    public void solve() {
        long start = System.currentTimeMillis();
        Scanner scanner = null;
        try {
            scanner = new Scanner(new FileReader(mInputFileName));
            Writer output = new BufferedWriter(new FileWriter(mOutputFileName));
            int cases = scanner.nextInt();
            for (int i = 1; i <= cases; i++) {
                A = scanner.nextInt();
                B = scanner.nextInt();
                mP = new double[A];
                mCp = 1;
                for (int j = 0; j < A; j++) {
                    mP[j] = scanner.nextDouble();
                    mCp *= mP[j];
                }
                System.out.println("CASE: " + i + " / " + cases);
                if (i > 1) output.write("\n");
                output.write("Case #" + i + ": ");
                output.write(getAnswer());
            }
            output.close();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (scanner != null) scanner.close();
        }
        System.out.println("TIME: " + (System.currentTimeMillis() - start));
    }

    private String getAnswer() {
        //System.out.println(Arrays.toString(mP));
        //System.out.println(mCp);
        //double res = 0;
        int totalStrokes = B + 1;
        int keep = totalStrokes - A;
        int rest = keep + totalStrokes;
        double wp = 1 - mCp;
        double res = mCp * keep + wp * (rest);
        for (int i = A - 1 ; i > 0; i--) {
            double last = mP[i];
            double currentP = mCp / last;
            keep += 2;
            rest += 2;
            double p = currentP * keep + (1 - currentP) * rest;
            res = Math.min(res, p);
            //System.out.println(p);
        }
        double allback = A + totalStrokes;
        //System.out.println(allback);
        res = Math.min(res, Math.min(res, allback));
        double drop = totalStrokes + 1;
        res = Math.min(res, Math.min(res, drop));
        //System.out.println(res);
        return format.format(res);
    }

    public static void main(String[] args) {
        String fileName = "test";
        String extension = ".txt";
        String outputSuffix = "_output";
        new A(fileName + extension, 
                fileName + outputSuffix + extension).solve();
    }

}
