package codejam.y2016.round1b;

import codejam.template.Runner;
import codejam.template.Solver;

import java.io.PrintStream;
import java.util.*;
import java.util.stream.IntStream;

/**
 * Created by raggzy on 4/30/2016.
 */
public class B extends Solver {
    public B(Scanner in, PrintStream out, int TC) {
        super(in, out, TC);
    }

    int minDiff = Integer.MAX_VALUE;
    String minOne;
    String minTwo;

    void diff(char[] one, char[] two, int oneIdx, int twoIdx) {
        if (oneIdx == one.length) {
            if (twoIdx == two.length) {
                String currOne = new String(one);
                String currTwo = new String(two);
                int diff = Math.abs(Integer.valueOf(currOne) - Integer.valueOf(currTwo));
                if (diff < minDiff) {
                    minDiff = diff;
                    minOne = currOne;
                    minTwo = currTwo;
                }
            } else if (two[twoIdx] == '?') {
                for (char cc = '0'; cc <= '9'; cc++) {
                    char tmp = two[twoIdx];
                    two[twoIdx] = cc;
                    diff(one, two, oneIdx, twoIdx + 1);
                    two[twoIdx] = tmp;
                }
            } else {
                diff(one, two, oneIdx, twoIdx + 1);
            }
        } else if (one[oneIdx] == '?') {
            for (char cc = '0'; cc <= '9'; cc++) {
                char tmp = one[oneIdx];
                one[oneIdx] = cc;
                diff(one, two, oneIdx + 1, twoIdx);
                one[oneIdx] = tmp;
            }
        } else {
            diff(one, two, oneIdx + 1, twoIdx);
        }
    }

    @Override
    public void solve() {
        String C = in.next();
        String J = in.next();
        diff(C.toCharArray(), J.toCharArray(), 0, 0);
        println("Case #%d: %s %s", TC, minOne, minTwo);
    }

    public static void main(String[] args) throws Exception {
        Runner.main(B.class);
    }
}
