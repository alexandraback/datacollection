import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.HashSet;
import java.util.Scanner;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

//Author : vttgato
//Email  : votoanthuan@gmail.com
//JDK    : Java SE 8 (Oracle)

public class TheLastWord
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
            numTestCase = scanner.nextInt();scanner.nextLine();
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
    private static String inputFile = "A-small-attempt0.in";


    public static class DemoTask extends Task
    {
        private String s;
        private char[] ac;
        private int len;

        public DemoTask (int testcase, Scanner scanner)
        {
            super(testcase);
            s = scanner.nextLine();
            ac = s.toCharArray();
            len = ac.length;
        }

        @Override
        public void handle () throws Exception
        {
//            log("handle testcase", testcase, "dinners", dinners);

            StringBuilder sb = new StringBuilder();
            sb.append("testcase ").append(testcase).append(NEWLINE);
            sb.append(" s ").append(s).append(NEWLINE);

            String r = "" + ac[0];

            for (int i = 1; i < len; i++)
            {
                if(ac[i] >= r.charAt(0))
                    r = ac[i] + r;
                else
                    r += ac[i];
            }


            sb.append(" r ").append(r).append(NEWLINE);

            //log("finish testcase", testcase, "dinners", dinners);
            addResult(r);
            log(sb);
        }
    }
}
