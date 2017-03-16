import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.HashSet;
import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.*;

//Author : vttgato
//Email  : votoanthuan@gmail.com
//JDK    : Java SE 8 (Oracle)

public class CoinJam
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
            numTestCase = 50;//scanner.nextInt();
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
                output.write("Case #1:");
                output.newLine();
                for (int t = 1; t <= numTestCase; t++)
                {
                    String r = mapResult.get(t);
                    if (r == null)
                        continue;
                    log(r);
                    output.write(r);
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

    public static int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};






//    private static String inputFile = "test.in";
    private static String inputFile = "C-small-attempt0.in";
//    private static String inputFile = "A-large.in";


    public static class DemoTask extends Task
    {
        private final int LEN = 16;
        private static ConcurrentHashMap<String,Boolean> mapR = new ConcurrentHashMap<>();


        public DemoTask (int testcase, Scanner scanner)
        {
            super(testcase);

        }

        @Override
        public void handle () throws Exception
        {
//            log("handle testcase", testcase, "dinners", dinners);

            StringBuilder sb = new StringBuilder();
            sb.append("testcase ").append(testcase).append(NEWLINE);

            ThreadLocalRandom random = ThreadLocalRandom.current();
            StringBuilder sbi = new StringBuilder(LEN);
            String r = "";
            long n;
            int countSuccess;

            for (int t = 0; t < 1000; t++)
            {
                sbi.setLength(0);

                sbi.append('1');
                for (int i = LEN - 2; i > 0; i--)
                    sbi.append(random.nextBoolean() ? '1' : '0');
                sbi.append('1');

                r = sbi.toString();
                if (mapR.putIfAbsent(r, Boolean.TRUE) != null)
                    continue;

                countSuccess = 0;
                for (int radix = 2; radix <= 10; radix++)
                {
                    n = Long.parseLong(r, radix);
                    for (int p : primes)
                    {
                        if (n <= p)
                            break;
                        if ((n % p) == 0)
                        {
                            sbi.append(' ').append(p);

                            sb.append(" radix ").append(radix).append(" n ").append(n).append(" p ").append(p).append(NEWLINE);
                            countSuccess++;
                            break;
                        }
                    }
                }
                sb.append("countSuccess ").append(countSuccess).append(NEWLINE);
                if (countSuccess != (10 - 2 + 1))
                    r = "";
                else
                {
                    r = sbi.toString();
                    break;
                }
            }

            sb.append(" r ").append(r).append(NEWLINE);

            //log("finish testcase", testcase, "dinners", dinners);
            addResult(r);
            log(sb);
        }
    }
}
