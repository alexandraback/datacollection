import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Writer;
import java.util.Scanner;

public class DancingWithTheGooglers {

    private String mInputFileName;
    private String mOutputFileName;
    
    private int N;
    private int S;
    private int P;
    private int[] mScores;
    
    public DancingWithTheGooglers(String inputFileName, String outputFileName) {
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
                N = scanner.nextInt();
                S = scanner.nextInt();
                P = scanner.nextInt();
                mScores = new int[N];
                for (int j = 0; j < N; j++) {
                    mScores[j] = scanner.nextInt();
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
        int res = 0;
        for (int j = 0; j < N; j++) {
            int score = mScores[j];
            int q = score / 3;
            int r = score % 3;
            int noSup = q;
            int sup = q;
            if (score > 0) {
                switch (r) {
                case 0:
                    sup++;
                    break;
                case 1:
                    noSup++;
                    sup++;
                    break;
                case 2:
                    noSup++;
                    sup += 2;
                    break;
                }
            }
            
            if (noSup >= P) {
                res++;
            } else if (S > 0 && sup >= P) {
                res++;
                S--;
            }
        }
        //System.out.println(res);
        return "" + res;
    }

    public static void main(String[] args) {
        String fileName = "test";
        String extension = ".txt";
        String outputSuffix = "_output";
        new DancingWithTheGooglers(fileName + extension, 
                fileName + outputSuffix + extension).solve();
    }

}
