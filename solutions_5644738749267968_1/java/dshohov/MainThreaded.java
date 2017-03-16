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
                        runCase(fi + 1, input.subList(1 + fi * 3, 1 + 3 + fi * 3));
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
        int numberOfBlocks = Integer.parseInt(caseData.get(0).get(0));
        assert caseData.get(1).size() == numberOfBlocks;
        assert caseData.get(1).size() == caseData.get(2).size();
        List<Double> naomiWeights = new ArrayList<>(numberOfBlocks);
        List<String> naomiStrings = caseData.get(1);
        for (int i = 0; i < numberOfBlocks; i++) {
            naomiWeights.add(Double.parseDouble(naomiStrings.get(i)));
        }
        Collections.sort(naomiWeights);
        List<Double> kenWeights = new ArrayList<>(numberOfBlocks);
        List<String> kenStrings = caseData.get(2);
        for (int i = 0; i < numberOfBlocks; i++) {
            kenWeights.add(Double.parseDouble(kenStrings.get(i)));
        }
        Collections.sort(kenWeights);

        int scoreWarOptimal = warOptimal(new ArrayList<>(naomiWeights), new ArrayList<>(kenWeights));
        int deceitfulWarOptimal = deceitfulWarOptimal(naomiWeights, kenWeights);

        outputLines.put(caseNumber, "Case #" + caseNumber + ": " + deceitfulWarOptimal + " " + scoreWarOptimal);
//        System.out.println("Farms bought in case #" + caseNumber + ": " + farmsBought);
    }

    public int warOptimal(List<Double> naomiWeights, List<Double> kenWeights) {
        //naomi takes biggest weight
        int naomiScore = 0;
        for (int i = 0, j = naomiWeights.size(); i < j; i++) {
            double heaviestNaomisBlock = naomiWeights.remove(naomiWeights.size() - 1);
            //ken looks for the block heavier than Naomi's
            int winningKensBlockIndex = -1;
            for (int k = kenWeights.size() - 1; k >= 0; k--) {
                if (kenWeights.get(k) > heaviestNaomisBlock) {
                    winningKensBlockIndex = k;
                } else {
                    break;
                }
            }
            if (winningKensBlockIndex >= 0) {
                double kenBlock = kenWeights.remove(winningKensBlockIndex);
                assert kenBlock > heaviestNaomisBlock;
            } else {
                //ken drop lightest block
                kenWeights.remove(0);
                ++naomiScore;
            }
        }
        return naomiScore;
    }

    public int deceitfulWarOptimal(List<Double> naomiWeights, List<Double> kenWeights) {
        int naomiScore = 0;
        for (int i = 0, j = naomiWeights.size(); i < j; i++) {
            //naomi finds lightest weight in kens set
            double lightestKensWeight = kenWeights.get(0);
            //she now finds weight just over ken's block
            int lightestOverBlockIndex = -1;
            for (int k = 0, l = naomiWeights.size(); k < l; k++) {
                if (naomiWeights.get(k) > lightestKensWeight) {
                    lightestOverBlockIndex = k;
                    break;
                }
            }
            if (lightestOverBlockIndex >= 0) {
                kenWeights.remove(0);
                double naomisBlockWeight = naomiWeights.remove(lightestOverBlockIndex);
                assert lightestKensWeight < naomisBlockWeight;
                ++naomiScore;
            } else {
                break;
            }
        }
        return naomiScore;
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

//        inputReader = new BufferedReader(new FileReader(args[1]));
//        while ((line = inputReader.readLine()) != null) {
//            System.out.println(line);
//        }
//        inputReader.close();
    }
}
