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

        int[] plist = {1,4,9,121,484};

        for(int i=1; i<=caseNumber; i++) {

            int A = scanner.nextInt();
            int B = scanner.nextInt();

            int totalResult = 0;

            for(int j=0; j<5; j++) {

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
