package round1C;

import base.CodeJamScanner;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class B {
    private static CodeJamScanner scanner;
    private static ArrayList<String> list;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner file = new Scanner(new File("C:\\Users\\Samuel\\Downloads\\input.txt"));
        scanner = new CodeJamScanner(file);
        Integer cases = scanner.getInteger();
        for (Integer i = 0; i < cases; i++) {
            scanner.outputTestCase((i + 1), runTestCase());
        }
    }

    private static String runTestCase() {
        ArrayList<Integer> nums = scanner.getIntegerList();
        // Number of keys
        Integer K = nums.get(0);
        // Length of target word
        Integer L = nums.get(1);
        // Number of keypresses allowed
        Integer S = nums.get(2);
        String keyboard = scanner.getString();
        String target = scanner.getString();

        Map<Integer, Integer> cases = new HashMap<Integer, Integer>();
        list = new ArrayList<String>();

        getPerms(keyboard.split(""), "", S);

        // How many bananas you bring
        Integer maxB = 0;

        // How many total bananas will you bring across all scenarios
        Integer total = 0;
        for (String sequence : list) {
            Integer current = 0;
            for (Integer i = 0; i <= sequence.length() - L; i++) {
                if (sequence.substring(i, i + L).equals(target)) {
                    current++;
                }
            }
            if (current > maxB) {
                maxB = current;
            }
            total += current;
        }
        //return total.toString();
        if (total == 0) {
            return "0";
        } else {
            double average = (double) total / (double) list.size();
            return Double.toString((double)maxB - average);
        }
    }

    private static void getPerms(String[] chars, String progress, Integer targetLength) {
        if (progress.length() != targetLength) {
            for (String chr : chars) {
                getPerms(chars, progress + chr, targetLength);
            }
        } else {
            list.add(progress);
        }
    }
}
