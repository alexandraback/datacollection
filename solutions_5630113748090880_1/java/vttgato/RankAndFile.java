import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

//Author : vttgato
//Email  : votoanthuan@gmail.com
//JDK    : Java SE 8 (Oracle)

public class RankAndFile
{
    private final static ExecutorService executor = Executors.newWorkStealingPool();
    private final static char NEWLINE   = '\n';

    private static ConcurrentHashMap<Integer, String> mapResult;
    private static CountDownLatch latch;

    public static abstract class Task implements Runnable
    {
        protected int testcase;

        private Task (int testcase)
        {
            this.testcase = testcase;
        }

        protected void addResult (String result)
        {
//            log("addResult ", testcase, result);
            mapResult.put(testcase, result);
        }

        public abstract void handle () throws Exception;

        @Override
        public void run ()
        {
            try
            {
                handle();
            }
            catch (Exception e)
            {
                log("Exception in testcase", testcase, e.getMessage());
                e.printStackTrace();
            }
            finally
            {
                latch.countDown();
            }
        }
    }

    public static void main (String[] args)
    {
        inputFile = "./" + inputFile;
        final String outputFile = inputFile.replace(".in", ".out");
        long startTime = System.currentTimeMillis();
        int numTestCase = 0;

        try (BufferedReader input = Files.newBufferedReader(Paths.get(inputFile)))
        {
            Scanner scanner = new Scanner(input);
            numTestCase = scanner.nextInt();//scanner.nextLine();
            log("numTestCase", numTestCase);

            latch = new CountDownLatch(numTestCase);
            mapResult = new ConcurrentHashMap<>(numTestCase);
            for (int t = 1; t <= numTestCase; t++)
                executor.submit(new DemoTask(t, scanner));
            latch.await();
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }

        log();
        log("Total time:", (System.currentTimeMillis() - startTime) / 1000);
        log();

        if (mapResult != null)
        {
            try (BufferedWriter output = Files.newBufferedWriter(Paths.get(outputFile), StandardCharsets.UTF_8, StandardOpenOption.CREATE, StandardOpenOption.TRUNCATE_EXISTING))
            {
                for (int t = 1; t <= numTestCase; t++)
                {
                    String r = mapResult.get(t);
                    if (r == null)
                        continue;
                    String c = joinToString("Case #", t, ": ", r);
                    log(c);
                    output.write(c);
                    output.newLine();
                }
            }
            catch (Exception e)
            {
                e.printStackTrace();
            }
        }
    }

    public static void log ()
    {
        System.out.println();
    }

    public static String joinToString (Object... ao)
    {
        StringBuilder sb = new StringBuilder(ao.length << 3);
        for (Object o : ao)
            sb.append(o);
        return sb.toString();
    }

    public static String joinWithDelimiter (char delimiter, Object... ao)
    {
        StringBuilder sb = new StringBuilder(ao.length << 3);
        for (Object o : ao)
            sb.append(o).append(delimiter);
        return sb.toString();
    }

    public static void log (Object... ao)
    {
        System.out.println(joinWithDelimiter(' ', ao));
    }

//    private static String inputFile = "test.in";
//    private static String inputFile = "A-small-attempt0.in";
    private static String inputFile = "B-large.in";


    public static class DemoTask extends Task
    {
        private int N, total;
        private ArrayList<ArrayList<Integer>> table;
        private String R = "";

        public DemoTask (int testcase, Scanner scanner)
        {
            super(testcase);
            N = scanner.nextInt();
            log("N", N);

            table = new ArrayList<>();
            for (int i = 2 * N - 1; i > 0; i--)
            {
                ArrayList<Integer> row = new ArrayList<>();
                for (int j = N; j > 0; j--)
                    row.add(scanner.nextInt());
                table.add(row);
            }
        }

        @Override
        public void handle () throws Exception
        {
//            log("handle testcase", testcase, "dinners", dinners);

            StringBuilder sb = new StringBuilder();
            sb.append("testcase ").append(testcase).append(NEWLINE);


            final int MAX_HEIGHT = 2500 * 2;
            int[] counts = new int[MAX_HEIGHT];
            for (ArrayList<Integer> row : table)
                for (int height : row)
                    counts[height]++;
            for (int i = 0; i < MAX_HEIGHT; i++)
                if ((counts[i] & 1) != 0)
                    R += i + " ";

            sb.append(" r ").append(R).append(NEWLINE);

            //log("finish testcase", testcase, "dinners", dinners);
            addResult(R);
            log(sb);
        }
    }
}
