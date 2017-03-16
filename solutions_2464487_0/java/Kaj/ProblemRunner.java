import com.google.common.io.Files;

import java.io.File;
import java.io.PrintWriter;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

/**
 * Included Libraries
 * - com.google.guava:guava:14.0
 */
public
class ProblemRunner
{
    interface Problem
    {
        void parse(Scanner scanner);

        String solve();
    }

    public static
    void run(String[] args, Class<? extends Problem> clazz, final int soloCaseIndex) throws Exception
    {
        final String fileName = args[0];

        String outputFile = "out/" + fileName.replace(".in", "") ;
        outputFile += new SimpleDateFormat("-HHmm.ss").format(new Date());
        outputFile += ".out";

        Scanner scanner = new Scanner(new File(fileName));
        int caseCount = scanner.nextInt();
        Problem[] cases = new Problem[caseCount];
        for (int c = 0; c < caseCount; c++)
        {
            cases[c] = clazz.newInstance();
            cases[c].parse(scanner);
        }

        final File file = new File(outputFile);
        Files.createParentDirs(file);
        PrintWriter printWriter = new PrintWriter(file);

        if (soloCaseIndex > 0)
        {
            printWriter.println("Solo!:");
            doCase(soloCaseIndex-1, cases, printWriter);
        }
        else
        {
            for (int i = 0; i < cases.length; i++)
            {
                doCase(i, cases, printWriter);
            }
        }

        printWriter.close();

    }

    private static
    void doCase(final int index, Problem[] cases, final PrintWriter printWriter)
    {
        String caseStr = "Case #" + (index + 1) + ": ";
        System.out.println(caseStr);
        printWriter.print(caseStr);
        String solve = cases[index].solve();
        System.out.print(caseStr);
        System.out.println(solve);
        System.out.println("------");
        printWriter.println(solve);
        printWriter.flush();
    }
}
