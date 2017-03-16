import java.io.*;
import java.util.Collection;
import java.util.Set;
import java.util.TreeSet;

/**
 * Date: 13/04/13
 * Time: 03:59
 */
public class FairAndSquare {

    private static final Long MAX_VALUE = 10000000l; // Max sqrt

    private static Collection<Long> generateFairAndSquare() {
        long start = 0;
        Set<Long> result = new TreeSet<Long>();
        while (start <= MAX_VALUE) {
            if(isAPalindrom(start)) {
                long square = start * start;
                if(isAPalindrom(square)) {
                    result.add(square);
                }
            }

            start = start + 1;
        }

        return result;
    }

    private static boolean isAPalindrom(long input) {
        String s = input + "";
        char[] c = s.toCharArray();
        if(c.length == 1) return true;
        for (int i = 0; i < c.length / 2; i++) {
            if( c[i] != c[c.length - i - 1]) return false;
        }

        return true;
    }


    private static int countFaireAndSquare(long start, long end, Collection<Long> values) {
        int count = 0;
        for (Long value : values) {
            if(value < start) continue;
            if(value > end) break;

            count++;
        }

        return count;
    }

    /**
     * run tests from input and print them in output
     * @param inputFile
     * @param outputFile
     */
    public static void runTest(String inputFile, String outputFile) {
        try{
            Collection<Long> generatedSquares = generateFairAndSquare();

            FileInputStream fstream = new FileInputStream(inputFile);
            DataInputStream in = new DataInputStream(fstream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            int nbTestCases = Integer.parseInt(br.readLine());

            StringBuilder res = new StringBuilder();
            for(int i = 1; i <= nbTestCases; ++i) {
                String[] limits = br.readLine().split(" ");

                res.append("Case #").append(i).append(": ").append(countFaireAndSquare(Long.parseLong(limits[0]), Long.parseLong(limits[1]), generatedSquares));
                res.append("\n");

            }
            in.close();

            BufferedWriter writer = new BufferedWriter( new FileWriter( outputFile));
            writer.write( res.toString());

            writer.close();

        }catch (Exception e){
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        runTest("C:\\workarea\\inout\\C-large-1.in", "C:\\workarea\\inout\\output.txt");

    }

}
