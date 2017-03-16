package codejam.y2013.r1b;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

/**
 * @author Cronos
 */
public class Task1 {

    static class Mote implements Comparable<Mote> {
        long value;
        boolean initial;

        Mote(long value, boolean initial) {
            this.value = value;
            this.initial = initial;
        }

        public int compareTo(Mote o) {
            if (value < o.value) return -1;
            else if (value == o.value) return 0;
            return 1;
        }
    }

    static Scanner input;
    static BufferedWriter output;

    public static void main(String[] args) throws Exception {
        input = new Scanner(new File("D:/Programming/Projects/CodeJam/input.txt"));
        output = new BufferedWriter(new FileWriter("D:/Programming/Projects/CodeJam/output.txt"));
        int T = input.nextInt();
        for (int i = 1; i <= T; i++) {
            String result = getResult();
            System.out.println("Case #" + i + ": " + result);
            output.write("Case #" + i + ": " + result);
            output.newLine();
        }
        output.close();
    }

    public static String getResult() {
        long A = input.nextLong();
        int N = input.nextInt();
        List<Mote> motes = new LinkedList<Mote>();
        for (int i = 0; i < N; i++) {
            motes.add(new Mote(input.nextLong(), true));
        }
        Collections.sort(motes);
        if (A == 1) return "" + N;
        long res = A;
        int i = 0;
        while (true) {
            if (i >= motes.size()) break;
            Mote current = motes.get(i);
            if (current.value < res) {
                res += current.value;
                i++;
                continue;
            } else {
                motes.add(i, new Mote(res - 1, false));
            }
        }
        int totalInitial = 0;
        int totalNonInitial = 0;
        int removedCount = 0;
        for (i = motes.size() - 1; i >= 0; i--) {
            if (motes.get(i).initial) totalInitial++;
            else totalNonInitial++;
            if (totalNonInitial > totalInitial) {
                motes = motes.subList(0, i);
                removedCount += totalInitial;
                totalInitial = 0;
                totalNonInitial = 0;
            }
        }
        int count = removedCount;
        for (i = 0; i < motes.size(); i++) {
            if (!motes.get(i).initial) count++;
        }
        return "" + count;
    }

}
