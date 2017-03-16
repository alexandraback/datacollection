import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Writer;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class B {

    private String mInputFileName;
    private String mOutputFileName;
    
    private int N;
    private List<Level> mLevels;
    
    public B(String inputFileName, String outputFileName) {
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
                mLevels = new LinkedList<Level>();
                for (int j = 0; j < N; j++) {
                    int a = scanner.nextInt();
                    int b = scanner.nextInt();
                    mLevels.add(new Level(a, b));
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
        String res = "Too Bad";
        int step = 0;
        int earned = 0;
        while (!mLevels.isEmpty()) {
            int s = help(earned);
            step++;
            if (s == -1) {
                break;
            } else {
                earned += s;
            }
        }
        if (mLevels.isEmpty()) {
            res = "" + step;
        }
        System.out.println(res);
        return res;
    }
    
    private int help(int earned) {
        int res = -1;
        Collections.sort(mLevels, new Bcomp());
        Level l = mLevels.get(0);
        if (l.b <= earned) {
            if (l.aWon) {
                res = 1;
            } else {
                res = 2;
            }
            mLevels.remove(l);
            //System.out.println("remove: " + l.a + ", " + l.b);
        }
        if (res == -1) {
            Collections.sort(mLevels, new Acomp());
            l = mLevels.get(0);
            if (l.a <= earned) {
                //System.out.println("level 1: " + l.a + ", " + l.b);
                res = 1;
                l.aWon = true;
                l.a = Integer.MAX_VALUE;
            }
        }
        return res;
    }
    
    private static class Level {
        private int a;
        private int b;
        private boolean aWon = false;
        
        private Level(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }
    
    private static class Bcomp implements Comparator<Level> {

        public int compare(Level arg0, Level arg1) {
            if (arg0.b < arg1.b) return -1;
            if (arg1.b < arg0.b) return 1;
            if (!arg0.aWon) return -1;
            if (!arg1.aWon) return 1;
            return 0;
        }
        
    }
    
    private static class Acomp implements Comparator<Level> {

        public int compare(Level arg0, Level arg1) {
            if (arg0.a < arg1.a) return -1;
            if (arg1.a < arg0.a) return 1;
            if (arg1.b < arg0.b) return -1;
            if (arg0.b < arg1.b) return 1;
            return 0;
        }
        
    }
    
    public static void main(String[] args) {
        String fileName = "test";
        String extension = ".txt";
        String outputSuffix = "_output";
        new B(fileName + extension, 
                fileName + outputSuffix + extension).solve();
    }

}
