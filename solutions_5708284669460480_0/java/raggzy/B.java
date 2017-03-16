package codejam.y2015.round1c;

import codejam.template.Runner;
import codejam.template.Solver;

import java.io.PrintStream;
import java.util.Scanner;

/**
 * Created by raggzy on 10-May-15.
 */
public class B extends Solver {
    public B(Scanner in, PrintStream out, int TC) {
        super(in, out, TC);
    }

    private void bf(char[] source, String target, int[] count, StringBuilder current, int left) {
        if (left == 0) {
            int index = -1;
            int currCount = 0;
            while (true) {
                index = current.indexOf(target, index + 1);
                if (index < 0) {
                    break;
                }
                currCount++;
            }
            count[currCount]++;
            return;
        }
        for (char c : source) {
            current.append(c);
            bf(source, target, count, current, left - 1);
            current.deleteCharAt(current.length() - 1);
        }
    }

    @Override
    public void solve() {
        int K = in.nextInt();
        int L = in.nextInt();
        int S = in.nextInt();
        in.nextLine();
        String source = in.nextLine();
        String target = in.nextLine();
        // finding max substr
        int minJump = target.length();
        for (int jump = 1; jump < target.length(); jump++) {
            String suffix = target.substring(jump);
            String prefix = target.substring(0, suffix.length());
            if (suffix.equals(prefix)) {
                minJump = jump;
                break;
            }
        }
        // finding if symbols can be
        boolean containAllTarget = true;
        for (char c : target.toCharArray()) {
            if (!source.contains("" + c)) {
                containAllTarget = false;
                break;
            }
        }
        int maxBananas = containAllTarget ? 1 + (S - L) / minJump : 0;
        int[] count = new int[maxBananas + 1];
        bf(source.toCharArray(), target, count, new StringBuilder(), S);
        int sum = 0;
        for (int c : count) {
            sum += c;
        }
        double ev = 0;
        for (int i = 0; i <= maxBananas; i++) {
            ev += 1.0 * (maxBananas - i) * count[i] / sum;
        }
        println("Case #%d: %f", TC, ev);
    }

    public static void main(String[] args) throws Exception {
        Runner.main(B.class);
    }
}
