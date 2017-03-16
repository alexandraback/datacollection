import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Writer;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class RecycledNumbers {

    private String mInputFileName;
    private String mOutputFileName;
    
    private long A;
    private long B;
    private Set<String> mPairSet = new HashSet<String>();
    
    public RecycledNumbers(String inputFileName, String outputFileName) {
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
                mPairSet.clear();
                A = scanner.nextLong();
                B = scanner.nextLong();
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
        for (long i = A; i <= B; i++) {
            res += getNumPairs(i);
        }
        //System.out.println(res);
        return "" + res;
    }
    
    private int getNumPairs(long num) {
        int res = 0;
        String numStr = "" + num;
        int len = numStr.length();
        if (len > 1) {
            for (int i = 1; i < len; i++) {
                String newStr = numStr.substring(i) + numStr.substring(0, i);
                long newNum = Long.parseLong(newStr);
                if (newNum > num && newNum <= B) {
                    String pair = num + " " + newNum;
                    if (!mPairSet.contains(pair)) {
                        mPairSet.add(pair);
                        res++;
                    }
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        String fileName = "test";
        String extension = ".txt";
        String outputSuffix = "_output";
        new RecycledNumbers(fileName + extension, 
                fileName + outputSuffix + extension).solve();
    }

}
