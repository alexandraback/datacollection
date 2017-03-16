import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.TreeSet;

public class Solution {

    private static class Activity implements Comparable<Activity>{
        public int index;
        public long value;
        Activity(int i, long v) {
            this.index = i;
            this.value = v;
        }

        public int compareTo(Activity other) {
            long diff = other.value - value;
            if (diff < 0) return -1;
            if (diff > 0) return 1;
            return 0;
        }
    }

    private static long solve(long e, long r, int n, long[] v) {
        long result = 0;
        PriorityQueue<Activity> activities = new PriorityQueue<Activity>(n);
        TreeSet<Integer> processed = new TreeSet<Integer>();
        int i;

        for (i = 0; i < n; i++) {
            activities.add(new Activity(i, v[i]));
        }


        Integer li, ri;
        boolean farther_li, farther_ri;
        Activity a;
        Long toAdd = 0L;
        for (i = 0; i < n; i++) {
            a = activities.poll();
            toAdd = 0L;
            li = processed.floor(a.index - 1);
            ri = processed.ceiling(a.index + 1);

            farther_li = (li == null) || ((a.index - li) * r >= e);
            farther_ri = (ri == null) || ((ri - a.index) * r >= e);

            if (farther_li && farther_ri) {
                toAdd = e * a.value;
            } else if (!farther_li && farther_ri) {
                toAdd = Math.min((a.index - li) * r, e) * a.value;
            } else if (farther_li && !farther_ri) {
                toAdd = Math.min((ri - a.index) * r, e) * a.value;
            } else {
                long capacity = (ri - li) * r - e;
                if (capacity > 0) {
                    toAdd = capacity * a.value;
                }
            }
            result += toAdd;
            processed.add(a.index);
        }

        return result;
    }


    public static void main(String[] args) {
        //try { System.setIn(new java.io.FileInputStream("B-large.in")); } catch (java.io.FileNotFoundException e) { }
        //try { System.setOut(new java.io.PrintStream("B-large.out")); } catch (java.io.FileNotFoundException e) { }
        //try { System.setIn(new java.io.FileInputStream("input.in")); } catch (java.io.FileNotFoundException e) { }
        //try { System.setOut(new java.io.PrintStream("output.out")); } catch (java.io.FileNotFoundException e) { }
        int cases, c, i;
        Scanner scanner = new Scanner(System.in);
        long e, r;
        int n;
        long[] v;

        cases = scanner.nextInt();
        for (c = 1; c <= cases; c++) {
            e = scanner.nextLong();
            r = scanner.nextLong();
            n = scanner.nextInt();
            v = new long[n];
            for (i = 0; i < n; i++) {
                v[i] = scanner.nextInt();
            }
            System.out.println("Case #" + String.valueOf(c) + ": " + String.valueOf(solve(e, r, n, v)));
        };
    }
}
