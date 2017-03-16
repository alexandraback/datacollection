package dmitry.shohov;

import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class MainThreaded {
    private static List<List<String>> input = new ArrayList<>();
    private static PrintWriter writer;
    private SortedMap<Integer, String> outputLines = Collections.synchronizedSortedMap(new TreeMap<Integer, String>());

    private ThreadPoolExecutor executor = new ThreadPoolExecutor(1, 1, 5, TimeUnit.DAYS, new LinkedBlockingQueue<Runnable>(), new ThreadFactory() {
        @Override
        public Thread newThread(Runnable r) {
            Thread thread = new Thread(r);
            thread.setDaemon(true);
            return thread;
        }
    });

    public MainThreaded() {

    }

    public void run() throws Exception {
        assert input.size() > 0;
        int numberOfCases = Integer.parseInt(input.get(0).get(0));
        List<Future<?>> tasks = new ArrayList<>(numberOfCases);
        for (int i = 0; i < numberOfCases; i++) {
            final int fi = i;
            tasks.add(executor.submit(new Runnable() {
                @Override
                public void run() {
                    try {
                        runCase(fi + 1, input.subList(1 + fi, 1 + 1 + fi));
                    } catch (Throwable t) {
                        t.printStackTrace();
                    }
                }
            }));
        }
        for (Future<?> task : tasks) {
            task.get();
        }
        for (String outputLine : outputLines.values()) {
            writer.println(outputLine);
        }
    }

    public void runCase(int caseNumber, List<List<String>> caseData) {
        String s = caseData.get(0).get(0);
        int slashIndex = s.indexOf('/');
        assert slashIndex != -1;

        int a = Integer.parseInt(s.substring(0, slashIndex));
        int b = Integer.parseInt(s.substring(slashIndex + 1));

        int bb = b;
        while (bb > 1) {
            int rem = bb % 2;
            if (rem != 0) {
                if (a % bb == 0) {
                    a = a / bb;
                    b = b / bb;
                    break;
                } else {
                    outputLines.put(caseNumber, "Case #" + caseNumber + ": impossible");
                    return;
                }
            }
            bb = bb / 2;
        }

        int generations = 0;
        while (a < b) {
            b = b / 2;
            ++generations;
            if (generations > 40) {
                outputLines.put(caseNumber, "Case #" + caseNumber + ": impossible");
                return;
            }
        }

        outputLines.put(caseNumber, "Case #" + caseNumber + ": " + generations);
    }

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);
        TimeZone.setDefault(TimeZone.getTimeZone("GMT"));

        if (args.length < 2) {
            System.err.println("Requires two arguments - input and output files");
            return;
        }
        File inputFile = new File(args[0]);
        if (!inputFile.exists()) {
            System.err.println("Input file (first argument) does not exist");
            return;
        }

        BufferedReader inputReader = new BufferedReader(new FileReader(inputFile));
        String line;
        while ((line = inputReader.readLine()) != null) {
            List<String> lineInput = new ArrayList<>();
            StringTokenizer tokenizer = new StringTokenizer(line, " ");
            while (tokenizer.hasMoreTokens()) {
                lineInput.add(tokenizer.nextToken());
            }
            input.add(lineInput);
        }
        inputReader.close();

        writer = new PrintWriter(new BufferedWriter(new FileWriter(args[1])));

        MainThreaded main = new MainThreaded();
        main.run();

        writer.flush();
        writer.close();

        inputReader = new BufferedReader(new FileReader(args[1]));
        while ((line = inputReader.readLine()) != null) {
            System.out.println(line);
        }
        inputReader.close();
    }
}
