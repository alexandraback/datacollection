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
                        runCase(fi + 1, input.subList(1 + fi * 2, 1 + 2 + fi * 2));
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
        int stringsNumber = Integer.parseInt(caseData.get(0).get(0));
        String[] stringSets = caseData.get(1).toArray(new String[caseData.get(1).size()]);
        assert stringSets.length == stringsNumber;
        LinkedList<char[]> sets = new LinkedList<>();
        for (int i = 0; i < stringsNumber; i++) {
            sets.add(stringSets[i].toCharArray());
        }
        char[][] currentSets = new char[sets.size()][];
        int combinations = setSet(sets, currentSets, 0, sets.size());
        outputLines.put(caseNumber, "Case #" + caseNumber + ": " + combinations);
    }

    private int setSet(LinkedList<char[]> sets, char[][] currentSets, int indexToSet, int setsSize) {
        int validCombinations = 0;
        for (int i = 0; i < sets.size(); i++) {
            char[] set = sets.get(i);
            currentSets[indexToSet] = set;
            if (!check(currentSets, indexToSet)) {
                break;
            }
            if (indexToSet + 1 < setsSize) {
                LinkedList<char[]> subSet = new LinkedList<>(sets);
                subSet.remove(i);
                validCombinations += setSet(subSet, currentSets, indexToSet + 1, setsSize);
            } else {
                ++validCombinations;
            }
        }
        return validCombinations;
    }

    private boolean check(char[][] currentSets, int upToIndex) {
        BitSet characters = new BitSet(26);
        char previousChar = 0;
        for (int i = 0; i <= upToIndex; i++) {
            for (int j = 0; j < currentSets[i].length; j++) {
                char currentChar = currentSets[i][j];
                if (previousChar != currentChar) {
                    //new char
                    if (characters.get(currentChar - 97)) {
                        return false;
                    } else {
                        previousChar = currentChar;
                        characters.set(currentChar - 97);
                    }
                }
            }
        }
        return true;
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
