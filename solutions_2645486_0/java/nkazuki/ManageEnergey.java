import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.*;

/**
 * @author Kazuki Nishiura
 */
public class ManageEnergey {
    // debug flags
    private static final boolean debug = false;
    private static final boolean inputFromStdIn = false;

    public static void main(String[] args) throws Exception {
        OutputWriter writer = new OutputWriter("rotate3.txt");
        Scanner scanner = createScanner("B-small-attempt.in");

        int numOfTestCase = Integer.parseInt(scanner.nextLine());
        for (int i = 1; i <= numOfTestCase; i++) {
            int totalEnergy = scanner.nextInt(), regain = scanner.nextInt(), numOfActivity = scanner.nextInt();
            int[] values = new int[numOfActivity];
            int[] usage = new int[numOfActivity];
            Arrays.fill(usage, regain);
            usage[0] = totalEnergy;
            int[] energyAfter = new int[numOfActivity];
            Arrays.fill(energyAfter, 0);
            int totalV = 0;
            if (regain == totalEnergy) {
                for (int j = 0; j < numOfActivity; j++) {
                    totalV += regain * scanner.nextInt();
                }
            } else {
                NavigableMap<Integer, List<Integer>> valuable = new TreeMap<Integer, List<Integer>>();
                for (int j = 0; j < numOfActivity; j++) {
                    values[j] = scanner.nextInt();
                    if (valuable.containsKey(values[j])) {
                        valuable.get(values[j]).add(j);
                    } else {
                        List<Integer> list = new ArrayList<Integer>();
                        list.add(j);
                        valuable.put(values[j], list);
                    }
                }
//                System.out.println("Activity: " + Arrays.toString(values));
                for (int value: valuable.descendingKeySet()) {
                    for (int index: valuable.get(value)) {
//                        System.out.println("Use " + value + " at " + index);
                        useMostOf(totalEnergy, regain, values, usage, value, index);
                    }
                }
//                System.out.println(Arrays.toString(usage));
                for (int j = 0; j < numOfActivity; j++) {
                    totalV += values[j] * usage[j];
                }
            }

            writer.println("Case #" + i + ": " + (int) Math.floor(totalV));
        }
        writer.close();
    }

    static private void useMostOf(int maxEnergy, int regain, int[] values, int[] usage, int value, int index) {
        int myUsage = usage[index];
        if (myUsage == maxEnergy) {
            return;
        }

        for (int i = index - 1; i >= 0; i--) {
            if (values[index] <= values[i]) {
                break;
            } else {
                int delta = maxEnergy - myUsage;
                if (usage[i] < delta) {
                    usage[i] = 0;
                    myUsage += usage[i];
                } else {
                    usage[i] -= delta;
                    myUsage += delta;
                    break;
                }
            }
        }
        usage[index] = myUsage;
    }

    // IO Utils
    static private Scanner createScanner(String fileName) throws Exception {
        if (inputFromStdIn) {
            return new Scanner(System.in);
        } else {
            File inFile = new File(fileName);
            return new Scanner(inFile);
        }
    }

    private static class OutputWriter {
        private PrintWriter writer;

        public OutputWriter(String fileNameSuffix) {
            if (!debug) {
                try {
                    writer = new PrintWriter(new BufferedWriter(
                            (new FileWriter(new File("output_" + fileNameSuffix)))));
                } catch (Exception e) {
                    System.err.println("File writer creation error.");
                }
            }
        }

        public void print(Object o) {
            if (debug) {
                System.out.print(o);
            } else {
                writer.print(o);
            }
        }

        public void println() {
            if (debug) {
                System.out.println();
            } else {
                writer.println();
            }
        }

        public void println(Object o) {
            if (debug) {
                System.out.println(o);
            } else {
                writer.println(o);
            }
        }

        public void close() {
            if (writer != null) {
                writer.close();
            }
        }
    }
}
