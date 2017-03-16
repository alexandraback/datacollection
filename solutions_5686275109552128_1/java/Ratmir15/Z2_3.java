package c2015_c.c2015_r1;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.*;

public class Z2_3 {

    public static final int INT = 100;

    public static void main(String[] args) throws Exception {
        FileWriter fw = new FileWriter("C:\\output.txt");
        BufferedWriter out = new BufferedWriter(fw);
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\z2.txt";
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\B-small-attempt0.in";
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\B-generated.in";
        String pathname = "C:\\Users\\YC14rp1\\Downloads\\B-large.in";
        Scanner scanner = new Scanner(new File(pathname));
        int tn = scanner.nextInt();
        scanner.nextLine();
        for (int ti = 1; ti <= tn; ti++) {
            int d = scanner.nextInt();
            int[] a = new int[d];
            int sum = 0;
            int mx = 0;
            for (int i=0;i<d;i++) {
                a[i] = scanner.nextInt();
                sum += a[i];
                if (a[i]>mx) {
                    mx = a[i];
                }
            }
            int min = Integer.MAX_VALUE;
            for (int i=mx;i>=1;i--) {
                int moves = 0;
                for (int j=0;j<d;j++) {
                    if (a[j]>i) {
                        moves += (a[j]-1)/i;
                    }
                }
                moves += i;
                if (min>moves) {
                    min = moves;
                }
            }
            System.out.println(min);
            //Answer answer = getMinutes(d, a, sum);
            String s;
            System.out.println(Arrays.toString(a));
            //System.out.println(answer.steps);
            s = "Case #" + ti + ": " + min;
            System.out.println(s);
            out.write(s);
            out.write("\n");
        }
        out.close();
    }

    private static Answer getMinutes(int d, int[] a, Integer sum) {
        if (sum==0) {
            return new Answer(0,new ArrayList<Step>());
        }
        int[] ints = Arrays.copyOf(a, INT);
        int[] ints2 = Arrays.copyOf(a, INT);
        int mx = 0;
        int mxi = -1;
        int sum2 = sum;
        for (int i=0;i<d;i++) {
            if (ints2[i]>0) {
                ints2[i]--;
                sum2--;
            }
            if (ints[i]>mx) {
                mx = ints[i];
                mxi = i;
            }
        }
        Answer ans = getMinutes(d, ints2, sum2);
        ans.minutes += 1;
        int min = ans.minutes;
        ans.steps.add(new Wait());
        if (mxi>-1) {
            //int min = Integer.MAX_VALUE;
            int mxx = mx/2;
            if (mx % 2==1) {
                mxx += 1;
            }
            for (int i=2;i<=mxx;i++) {
                ints[d] = i;
                ints[mxi] = mx - i;
                Answer answer = getMinutes(d + 1, ints, sum);
                int m2 = answer.minutes + 1;
                if (m2<=min) {
                    min = m2;
                    ans.steps = answer.steps;
                    ans.steps.add(new Move(mxi, i));
                    ans.minutes = min;
                }
            }
        }
        //System.out.println(d+" "+sum+" "+Arrays.toString(a)+": "+min);
        return ans;
    }

    private static class Answer {
        private int minutes;
        private List<Step> steps;

        public Answer(int minutes, List<Step> steps) {
            this.minutes = minutes;
            this.steps = steps;
        }
    }

    private static class Step {

    }

    private static class Wait extends Step {
        @Override
        public String toString() {
            return "W";
        }
    }

    private static class Move extends Step {
        private int from;
        private int count;

        public Move(int from, int count) {
            this.from = from;
            this.count = count;
        }

        @Override
        public String toString() {
            return "M" +
                    from +
                    " " + count;
        }
    }

}
