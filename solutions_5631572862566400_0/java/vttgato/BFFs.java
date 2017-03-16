import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;
import java.util.TreeSet;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

//Author : vttgato
//Email  : votoanthuan@gmail.com
//JDK    : Java SE 8 (Oracle)

public class BFFs
{
    private final static ExecutorService executor = Executors.newWorkStealingPool();
    private final static char            NEWLINE  = '\n';

    private static ConcurrentHashMap<Integer, String> mapResult;
    private static CountDownLatch                     latch;
    //    private static String inputFile = "test.in";
//    private static String inputFile = "A-small-attempt0.in";
    private static String inputFile = "C-small-attempt0.in";

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
            try (BufferedWriter output = Files.newBufferedWriter(Paths.get(outputFile),
                                                                 StandardCharsets.UTF_8,
                                                                 StandardOpenOption.CREATE,
                                                                 StandardOpenOption.TRUNCATE_EXISTING))
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

    public static class DemoTask extends Task
    {
        int   N;
        int[] V;

        public DemoTask (int testcase, Scanner scanner)
        {
            super(testcase);
            N = scanner.nextInt();
            log(N);

            V = new int[N];
            for (int i = 0; i < N; i++)
            {
                V[i] = scanner.nextInt() - 1;
                //log(V[i]);
            }
        }

        @Override
        public void handle () throws Exception
        {
//            log("handle testcase", testcase, "dinners", dinners);

            StringBuilder sb = new StringBuilder();
            sb.append("testcase ").append(testcase).append(NEWLINE);

            int R = 0;
            ArrayList<TreeSet<ArrayList<Integer>>> as = new ArrayList<>();

            Comparator<ArrayList<Integer>> comparator = (a, b) -> {
                if (a.size() > b.size())
                    return 1;
                if (a.size() == b.size())
                    return 0;
                return -1;
            };

            for (int x = 0; x < N; ++x)
            {
                as.add(new TreeSet<>(comparator));
            }
            for (int x = 0; x < N; ++x)
            {
                int cur = x;
                int prev = -1;
                Boolean[] used = new Boolean[N];
                for (int j = 0; j < N; j++)
                {
                    used[j] = false;
                }
                used[cur] = true;
                int length = 1;
                ArrayList<Integer> c = new ArrayList<>();
                c.add(cur);
                while (!used[V[cur]])
                {
                    ++length;
                    prev = cur;
                    cur = V[cur];
                    c.add(cur);
                    used[cur] = true;
                }
                if (prev == V[cur])
                {
                    if (as.get(prev) == null)
                        as.get(prev).add(new ArrayList<>());
                    as.get(prev).add(c);
                }
                else
                {
                    length = 1;
                    for (int cc = V[cur]; cc != cur; cc = V[cc])
                    {
                        ++length;
                    }
                }
                R = Math.max(R, length);
            }
            int length = 0;
            Boolean[] used = new Boolean[N];
            for (int t = 0; t < N; t++)
            {
                used[t] = false;
            }

            for (int t = 0; t < N; ++t)
            {
                if (!used[t] && !as.get(t).isEmpty())
                {
                    length += as.get(t).last().size();
                    if (!as.get(V[t]).isEmpty())
                    {
                        used[V[t]] = true;
                        length += as.get(V[t]).last().size() - 2;
                    }
                }
            }
            R = Math.max(R, length);


            sb.append(" r ").append(R).append(NEWLINE);

            //log("finish testcase", testcase, "dinners", dinners);
            addResult(Integer.toString(R));
            log(sb);
        }
    }
}
