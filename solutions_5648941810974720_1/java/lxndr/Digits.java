import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Random;
import java.util.Scanner;

public class Digits {

    static String[] nums = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE",
            "SIX", "SEVEN", "EIGHT", "NINE" };

    public static void main(String[] args)
            throws FileNotFoundException, UnsupportedEncodingException {
        Scanner in = new Scanner(new File("A-large.in"));
        PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
        String countStr = in.nextLine();
        int count = Integer.parseInt(countStr);
        for (int c = 0; c < count; c++) {
            String s = in.nextLine();
            writer.println("Case #" + (c + 1) + ": " + findAll(s));
        }
        writer.close();
        in.close();
    }

    public static String findAll(String s) {
        String ret = "";
        String origin = s;
        ArrayList<Integer> nums = new ArrayList<Integer>();
        int[] order = randomOrder();
        for (int c = 0; c < 10; c++) {
            String[] hold = parseNum(s, order[c]);
            s = hold[1];
            if (!hold[0].equals("")) {
                nums.add(Integer.parseInt(hold[0]));
                c--;
            }
        }
        nums.sort(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1 - o2;
            }
        });
        for (int q : nums) {
            ret = ret + q;
        }
        if (!s.equals("")) {
            ret = findAll(origin);
        }
        return ret;
    }

    public static int[] randomOrder() {
        int[] ret = new int[10];
        ArrayList<Integer> n = new ArrayList<Integer>();
        for (int c = 0; c < 10; c++) {
            n.add(c);
        }
        long seed = System.nanoTime();
        Collections.shuffle(n, new Random(seed));
        int y = 0;
        for (int x : n) {
            ret[y] = x;
            y++;
        }
        return ret;
    }

    public static String[] parseNum(String s, int n) {
        String word = nums[n];
        String ret = s;
        boolean found = true;
        for (int c = 0; c < word.length(); c++) {
            if (!s.contains(String.valueOf(word.charAt(c)))) {
                found = false;
            } else {
                int r = s.indexOf(word.charAt(c));
                s = s.substring(0, r) + s.substring(r + 1);
            }
        }
        if (!found) {
            String[] r = { "", ret };
            return r;
        } else {
            String[] r = { n + "", s };
            return r;
        }
    }
}
