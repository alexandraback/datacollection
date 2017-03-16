import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: Neptun
 * Date: 4/13/13
 * Time: 5:05 PM
 * To change this template use File | Settings | File Templates.
 */
public class FairSquare {

    FileWriter output;
    FileWriter logger;
    int caseNumber;

    FairSquare() throws IOException {

        output = new FileWriter("output");
        logger = new FileWriter("log");
    }
    void closeFiles() throws IOException {

        output.close();
        logger.close();
    }

    void process() throws IOException {

        File input = new File("input");
        Scanner scanner = new Scanner(input);

        caseNumber = scanner.nextInt();

        int[] baseList = {1,2,3,11,22,101,111,121,202,212,1001,1111,2002,10001,10101,10201,11011,11111,11211,20002,20102,
                100001,101101,110011,111111,200002,1000001,1001001,1002001,1010101,1011101,1012101,1100011,1101011,1102011,
                1110111,1111111,2000002,2001002};

        //int[] plist = {1,4,9,121,484};

        long[] plist = new long[baseList.length];

        for(int i=0; i<baseList.length; i++) {

            plist[i] = (long) Math.pow(baseList[i],2);
            logger.write(plist[i] + "\n");
        }

        for(int i=1; i<=caseNumber; i++) {

            long A = scanner.nextLong();
            long B = scanner.nextLong();

            int totalResult = 0;

            for(int j=0; j<plist.length; j++) {

                logger.write(i+" "+j+" "+A+" "+B+" "+plist[j]+"\n");

                if(A <= plist[j] && B >= plist[j])
                    totalResult++;
            }

            output.write("Case #" + i + ": " + totalResult + "\n");
        }

        scanner.close();
    }

    public static void main(String[] args) throws IOException {

        FairSquare f = new FairSquare();
        f.process();

        f.closeFiles();
    }
}
