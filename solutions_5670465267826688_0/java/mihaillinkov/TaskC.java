import java.io.*;
import java.util.*;

public class TaskC {
    private static TaskReader reader = new TaskReader(System.in);
    private static PrintWriter printer;
    private static Map<String, String> map = new HashMap();

    private void solve(int testNumber, String line) {
        boolean [] rightSuffix = new boolean[line.length()];
        String suffix = line.substring(line.length() - 1);
        rightSuffix[line.length() - 1] = suffix.equals("k");
        for (int i = line.length() - 2; i > -1; i--) {
            suffix = multiple(Character.toString(line.charAt(i)), suffix);
            rightSuffix[i] = suffix.equals("k");
        }

        String first = "1";
        for (int i = 0; i < line.length() - 2; i++) {
            first = multiple(first, Character.toString(line.charAt(i)));
            if ("i".equals(first)) {
                String second = "1";
                for (int j = i + 1; j < line.length() - 1; j++) {
                    second = multiple(second, Character.toString(line.charAt(j)));
                    if ("j".equals(second) && rightSuffix[j + 1]) {
                        printer.println("Case #" + testNumber + ": YES");
                        return;
                    }
                }
            }
        }

        printer.println("Case #" + testNumber + ": NO");
    }

    private String multiple(String first, String second) {
        String result;
        if (first.startsWith("-") || second.startsWith("-")) {
            first = first.replace("-", "");
            second = second.replace("-", "");
            result = map.get(first + second);
            if (result.startsWith("-")) {
                result = result.substring(1);
            } else {
                result = "-" + result;
            }
        } else {
            result = map.get(first + second);
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        map.put("11", "1");
        map.put("1i", "i");
        map.put("1j", "j");
        map.put("1k", "k");
        map.put("i1", "i");
        map.put("ii", "-1");
        map.put("ij", "k");
        map.put("ik", "-j");
        map.put("j1", "j");
        map.put("ji", "-k");
        map.put("jj", "-1");
        map.put("jk", "i");
        map.put("k1", "k");
        map.put("ki", "j");
        map.put("kj", "-i");
        map.put("kk", "-1");
        printer = new PrintWriter("output");
        int testAmount = reader.nextInt();
        for (int test = 1; test <= testAmount; test++) {
            reader.nextInt();
            int repeated = reader.nextInt();
            String line = reader.next();
            StringBuilder completeLine = new StringBuilder();
            for (int i = 0; i < repeated; i++) {
                completeLine.append(line);
            }
            new TaskC().solve(test, completeLine.toString());
            System.err.println(test);
        }
        printer.close();
    }
}