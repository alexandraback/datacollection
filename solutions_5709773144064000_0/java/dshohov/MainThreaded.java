package dmitry.shohov;

import java.io.*;
import java.text.DecimalFormat;
import java.util.*;
import java.util.concurrent.*;

public class MainThreaded {
    private static List<List<String>> input = new ArrayList<>();
    private static PrintWriter writer;
    private SortedMap<Integer, String> outputLines = Collections.synchronizedSortedMap(new TreeMap<Integer, String>());

    private ThreadPoolExecutor executor = new ThreadPoolExecutor(8, 8, 5, TimeUnit.DAYS, new LinkedBlockingQueue<Runnable>(), new ThreadFactory() {
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
                        runCase(fi + 1, input.get(1 + fi));
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

    public void runCase(int caseNumber, List<String> caseData) {
        double farmPrice = Double.parseDouble(caseData.get(0));
        double farmRate = Double.parseDouble(caseData.get(1));
        double goal = Double.parseDouble(caseData.get(2));

        double timeSpent = 0;
        double currentRate = 2;
//        int farmsBought = 0;

        double time;
        double timeWithFarm;
        double bestTime = 0;
        do {
            //calculate time to reach goal with current number of farms
            time = timeSpent + goal / currentRate;
            //time with one additional farm
            timeWithFarm = timeSpent + (farmPrice / currentRate) + goal / (currentRate + farmRate);
            if (time > timeWithFarm) {
                timeSpent += (farmPrice / currentRate);
                currentRate += farmRate;
//                ++farmsBought;
            } else {
                bestTime = timeSpent + goal / currentRate;
            }
        } while (time > timeWithFarm);
        DecimalFormat format = new DecimalFormat("0.0000000");
        outputLines.put(caseNumber, "Case #" + caseNumber + ": " + format.format(bestTime));
//        System.out.println("Farms bought in case #" + caseNumber + ": " + farmsBought);
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
