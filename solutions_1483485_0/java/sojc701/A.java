

import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Writer;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class A {

    private String mInputFileName;
    private String mOutputFileName;
    
    private static final String S0 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
    private static final String S1 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
    private static final String S2 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
    
    private static final String O0 = "our language is impossible to understand";
    private static final String O1 = "there are twenty six factorial possibilities";
    private static final String O2 = "so it is okay if you want to just give up";
    
    private static final int CHAR_SIZE = 26;
    private Set<Integer> mCharSet = new HashSet<Integer>(CHAR_SIZE);
    private int[] mChars = new int[CHAR_SIZE];
    //private int[] mMissing = {16, 25};
    private int[] mMissing = {25, 16};
    
    private String mSource;

    public A(String inputFileName, String outputFileName) {
        mInputFileName = inputFileName;
        mOutputFileName = outputFileName;
    }

    public void solve() {
        long startTimestamp = System.currentTimeMillis();
        preprocess();
        Scanner scanner = null;
        Writer output = null;
        try {
            scanner = new Scanner(new FileReader(mInputFileName));
            output = new BufferedWriter(new FileWriter(mOutputFileName));
            int cases = scanner.nextInt();
            scanner.nextLine();
            for (int i = 1; i <= cases; i++) {
                mSource = scanner.nextLine();
                System.out.println("CASE: " + i  + " / " + cases);
                if (i > 1) output.write('\n');
                output.write("Case #" + i + ": ");
                output.write(getAnswer());
            }
            output.close();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (scanner != null) {
                scanner.close();
            }
        }
        long endTimestamp = System.currentTimeMillis();
        System.out.println("TIME: " + (endTimestamp - startTimestamp));
    }
    

    private String getAnswer() {
        //System.out.println(mSource);
        StringBuilder sb = new StringBuilder();
        int len = mSource.length();
        for (int i = 0; i < len; i++) {
            char c = mSource.charAt(i);
            if (c != ' ') {
                c = (char)('a' + mChars[c - 'a']);
            }
            sb.append(c);
        }
        //System.out.println(sb.toString());
        return sb.toString();
    }
    
    private void preprocess() {
        Arrays.fill(mChars, -1);
        for (int i = 0; i < CHAR_SIZE; i++) {
            mCharSet.add(i);
        }
        process(S0, O0);
        process(S1, O1);
        process(S2, O2);
        
        int index = 0;
        for (int i = 0; i < CHAR_SIZE; i++) {
            if (mChars[i] == -1) {
                mChars[i] = mMissing[index++];
            }
        }
    }
    
    private void process(String source, String out) {
        int len = source.length();
        for (int i = 0; i < len; i++) {
            char c = source.charAt(i);
            if (c != ' ') {
                int v = out.charAt(i) - 'a';
                mChars[c - 'a'] = v;
                mCharSet.remove(v);
            }
        }
        
    }

    public static void main(String[] args) {
        String fileName = "in";
        String extension = ".txt";
        new A(fileName + extension,
                fileName + ".out" + extension).solve();
    }

}
