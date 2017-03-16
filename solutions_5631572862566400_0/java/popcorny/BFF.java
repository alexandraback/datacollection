package idv.popcorny.jam2016;

import java.io.File;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

/**
 * Created by popcorny on 4/16/16.
 */
public class BFF {

    private int[] bffs;
    private int n;

    public BFF(int[] bffs) {
        this.bffs = bffs;
        this.n = bffs.length;
    }

    public int getBestArrange(int[] list, int top, boolean[] used) {



        int bff = bffs[list[top-1]];
        int max = 0;


        if (!used[bff]) {
            // next is bff
            list[top] = bff;
            used[bff] = true;
            int curr = getBestArrange(list, top + 1, used);
            if (curr > max) {
                max = curr;
            }
            used[bff] = false;
        }

        for (int i=0; i<n; i++) {

            if (used[i]) {
                continue;
            }

            if (bffs[i] == list[top-1]) {
                list[top] = i;
                used[i] = true;
                int curr = getBestArrange(list, top + 1, used);
                if (curr > max) {
                    max = curr;
                }
                used[i] = false;
            }
        }


        // cycle close
        if (bff == list[0]) {
//            printList("cycle " + top + " ", list, top);
            int curr = top;
            if (curr > max) {
                max = curr;
            }
        }

//        for (int i=0; i<top; i++) {
//            System.out.printf("%d ", list[i]);
//        }
//        System.out.printf(" -> max: %d\n", max);

        return max;
    }

    private void printList(String msg, int[] list, int top) {        ;
        System.out.print(msg);
        for (int i=0; i<top; i++) {
            System.out.printf("%d ", list[i]+1);
        }
        System.out.println();
    }

    public int getBestArrange() {
        int[] list = new int[n];
        boolean[] used = new boolean[n];

        int max = 0;

        for (int i=0; i<n; i++) {
            list[0] = i;
            list[1] = bffs[i];

            used[i] = true;
            used[bffs[i]] = true;

            int curr = getBestArrange(list, 2, used);
            if (curr > max) {
                max = curr;
            }

            used[i] = false;
            used[bffs[i]] = false;
        }

        return max;
    }

    public static void main(String[] args) throws Exception {
        Scanner scanner;
        PrintWriter writer;
        String quizname = "bff";
        String testname = "small";
        String input   = String.format("quiz/%s/%s.in", quizname, testname);
        String output  = String.format("quiz/%s/%s.out", quizname, testname);

        if (new File(input).exists()) {
            scanner = new Scanner(new File(input));
            if (testname.equals("sample")) {
                writer = new PrintWriter(System.out);
            } else {
                writer = new PrintWriter(output);
            }
        } else {
            scanner = new Scanner(System.in);
            writer = new PrintWriter(System.out);
        }


        int t = scanner.nextInt();

        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();

            int[] bffs = new int[n];
            for (int j=0; j<n; j++) {
                bffs[j] = scanner.nextInt()-1;
            }
            writer.printf("Case #%d: %s\n", i + 1, new BFF(bffs).getBestArrange());
        }
        writer.flush();
    }
}
