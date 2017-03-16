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
        String[] keyboardChars = keyboard.split("");
        String target = scanner.getString();

        Map<Integer, Integer> cases = new HashMap<Integer, Integer>();
        Integer ways = 1;


        for (String letter : target.split("")) {
            if (Arrays.asList(keyboardChars).indexOf(letter) < 0) {
                return "0.0";
            } else {
                Integer c = 0;
                for (String chr : keyboardChars) {
                    if (chr.equals(letter)) {
                        c++;
                    }
                }
                ways = ways * c;
            }
        }

        Integer max = 0;
        for (Integer i = 0; i < L; i++) {
            String gen = target;
            while (gen.length() < S) {
                gen = gen.substring(0, gen.length() - i);
                gen += target;
            }
            gen = gen.substring(0, S);
            Integer count = countAppearances(gen, target);
            if (count > max) {
                max = count;
            }
        }

        list = new ArrayList<String>();
        //getPerms(keyboard.split(""), "", L);

        // How many bananas you bring
        Integer maxB = max;
//
//        // How many total bananas will you bring across all scenarios
//        Integer total = 0;
//        for (String sequence : list) {
//            Integer current = 0;
//            for (Integer i = 0; i <= sequence.length() - L; i++) {
//                if (sequence.substring(i, i + L).equals(target)) {
//                    current++;
//                }
//            }
//            total += current;
//        }
        //return total.toString();
        if (ways == 0) {
            return "0";
        } else {
            // double average = ((double) total / (double) list.size()) * (S - L + 1);
            double average = ((double) ways / Math.pow((double) keyboardChars.length, (double) L)) * (S - L + 1);
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



    private static Integer countAppearances(String gen, String target) {
        Integer current = 0;
        for (Integer i = 0; i <= gen.length() - target.length(); i++) {
            if (gen.substring(i, i + target.length()).equals(target)) {
                current++;
            }
        }
        return current;
    }
}
