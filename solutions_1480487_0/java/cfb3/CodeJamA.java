
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Charles
 */
public class CodeJamA
{
    //input/output file name

    static final String FILE_NAME = "A";

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException
    {
        ArrayList<String> values = readFile(FILE_NAME + ".in");
        int count = 1;

        PrintWriter outFile = new PrintWriter(new File(FILE_NAME + ".out"));
        for (String line : values)
        {
            String output = processAlgorithm(line, count++);
            System.out.println(output);
            outFile.println(output);
        }
        outFile.close();
    }

    /**
     * Reads the CodeJam files and returns the input as a List of String. Should
     * be adjusted for each individual file inputs.
     *
     * @param fileName The name of the file to be read
     * @return the list containing the contents of the file.
     */
    public static ArrayList<String> readFile(String fileName)
    {
        ArrayList<String> results = new ArrayList<String>();
        try
        {
            Scanner inFile = new Scanner(new File(fileName));
            int numberOfLines = Integer.parseInt(inFile.nextLine());
            while (inFile.hasNextLine())
            {
                results.add(inFile.nextLine());
            }

            if (numberOfLines != results.size())
            {
                System.err.println("File size does not match...");
                System.exit(0);
            }

        }
        catch (FileNotFoundException ex)
        {
            System.err.println("File not found...");
            System.exit(0);
        }
        return results;
    }

    /**
     * Work the magic here.
     * @param line
     * @param count
     * @return 
     */
    private static String processAlgorithm(String line, int count)
    {
        StringBuilder result = new StringBuilder("Case #" + count + ": ");
        Scanner lineScan = new Scanner(line);

        int n = lineScan.nextInt();
        double[] scores = new double[n];
        double[] results = new double[n];
        double judgesTotal = 0;
        int index = 0;
        while (lineScan.hasNextInt())
        {
            scores[index] = lineScan.nextInt();
            judgesTotal += scores[index++];
        }
        double twiceJudgesTotal = judgesTotal * 2;
        boolean keepRemoving = true;

        int alteredN = n;
        double lowScore;
        while (keepRemoving)
        {
            keepRemoving = false;
            lowScore = twiceJudgesTotal / alteredN;
            for (index = 0; index < n; index++)
            {
                if (lowScore < scores[index])
                {
                    alteredN--;
                    twiceJudgesTotal -= scores[index];
                    scores[index] = -1;
                    keepRemoving = true;
                }
            }

        }

        lowScore = twiceJudgesTotal / alteredN;
        DecimalFormat fmt = new DecimalFormat("0.000000");
        double sum = 0;
        for (index = 0; index < n; index++)
        {
            if (scores[index] == -1)
            {
                result.append(0.0);
            }
            else
            {
                result.append(((lowScore - scores[index]) / judgesTotal) * 100);
            }
            result.append(" ");

        }

        return result.toString();
    }
}
