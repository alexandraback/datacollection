import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by linxy on 4/29/16.
 */
public class A {

    private static void update(Map<Character, Integer> freq, String word, int count) {
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            int newCount = freq.get(c) - count;
            if (newCount == 0) {
                freq.remove(c);
            } else {
                freq.put(c, newCount);
            }
        }
    }

    private static void add(List<Integer> nums, int num, int count) {
        for (int i = 0; i < count; i++) {
            nums.add(num);
        }
    }

    private static void process(char unique, int num, String word, Map<Character, Integer> freq, List<Integer> nums) {
        if (freq.containsKey(unique)) {
            int c = freq.get(unique);
            add(nums, num, c);
            update(freq, word, c);
        }
    }

    private static String solve(String s) {
        Map<Character, Integer> freq = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (freq.containsKey(c)) {
                freq.put(c, freq.get(c) + 1);
            } else {
                freq.put(c, 1);
            }
        }
        List<Integer> nums = new ArrayList<>();
        process('Z', 0, "ZERO", freq, nums);
        process('W', 2, "TWO", freq, nums);
        process('X', 6, "SIX", freq, nums);
        process('G', 8, "EIGHT", freq, nums);
        process('H', 3, "THREE", freq, nums);
        process('R', 4, "FOUR", freq, nums);
        process('S', 7, "SEVEN", freq, nums);
        process('F', 5, "FIVE", freq, nums);
        process('O', 1, "ONE", freq, nums);
        process('I', 9, "NINE", freq, nums);

        Collections.sort(nums);
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < nums.size(); i++) {
            builder.append(nums.get(i));
        }
        return builder.toString();
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new FileInputStream("A-large.in"));
        PrintWriter out = new PrintWriter(new FileOutputStream("A-large.out"));
        int numCase = in.nextInt();
        in.nextLine();
        for (int caseNum = 1; caseNum <= numCase; caseNum++) {
            out.print("Case #" + caseNum + ": ");
            String line = in.nextLine();
            System.out.println(line);
            String result = solve(line);
            out.println(result);
        }
        System.out.println("last");
        in.close();
        out.close();
    }
}
