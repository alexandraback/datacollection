package ee.prof;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class B {

    static String bestAnswer;
    static int[] bestScores = new int[3];

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("B-small-attempt1.in"));
//        Scanner sc = new Scanner(new File("B-large.in"));
//        Scanner sc = new Scanner(System.in);
//        PrintStream out = System.out;
        PrintStream out = new PrintStream(new FileOutputStream("B-small.out"));
//        PrintStream out = new PrintStream(new FileOutputStream("B-large.out"));
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            String s0 = sc.next();
            String s1 = sc.next();
            List<Integer> result0 = new ArrayList<>();
            List<Integer> result1 = new ArrayList<>();
            char[] chars0 = s0.toCharArray();
            char[] chars1 = s1.toCharArray();


            step(0, result0, result1, chars0, chars1);


            out.println("Case #" + (i + 1) + ": " + bestAnswer);
            bestAnswer = null;
            bestScores = new int[3];
        }

    }

    private static void step(int j, List<Integer> result0, List<Integer> result1, char[] chars0, char[] chars1) {
        if (j == chars0.length) {
            processAns(result0, result1);
            return;
        }

        char c0 = chars0[j];
        char c1 = chars1[j];
        List<Integer> new0Result0 = new ArrayList<>(result0);
        List<Integer> new0Result1 = new ArrayList<>(result1);

        int c0int = c0 - '0';
        int c1int = c1 - '0';
        if (c0 != '?' && c1 != '?') {
            new0Result0.add(c0int);
            new0Result1.add(c1int);
            step(j + 1, new0Result0, new0Result1, chars0, chars1);

        } else if (c0 == '?' && c1 == '?') {
            List<Integer> new1Result0 = new ArrayList<>(result0);
            List<Integer> new1Result1 = new ArrayList<>(result1);
            List<Integer> new2Result0 = new ArrayList<>(result0);
            List<Integer> new2Result1 = new ArrayList<>(result1);
            List<Integer> new3Result0 = new ArrayList<>(result0);
            List<Integer> new3Result1 = new ArrayList<>(result1);
            List<Integer> new4Result0 = new ArrayList<>(result0);
            List<Integer> new4Result1 = new ArrayList<>(result1);

            new0Result0.add(0);
            new0Result1.add(0);
            step(j + 1, new0Result0, new0Result1, chars0, chars1);

            new1Result0.add(0);
            new1Result1.add(1);
            step(j + 1, new1Result0, new1Result1, chars0, chars1);

            new2Result0.add(1);
            new2Result1.add(0);
            step(j + 1, new2Result0, new2Result1, chars0, chars1);

            new3Result0.add(0);
            new3Result1.add(9);
            step(j + 1, new3Result0, new3Result1, chars0, chars1);

            new4Result0.add(9);
            new4Result1.add(0);
            step(j + 1, new4Result0, new4Result1, chars0, chars1);

        } else if (c0 == '?') {
            List<Integer> new1Result0 = new ArrayList<>(result0);
            List<Integer> new1Result1 = new ArrayList<>(result1);
            List<Integer> new2Result0 = new ArrayList<>(result0);
            List<Integer> new2Result1 = new ArrayList<>(result1);
            List<Integer> new3Result0 = new ArrayList<>(result0);
            List<Integer> new3Result1 = new ArrayList<>(result1);
            List<Integer> new4Result0 = new ArrayList<>(result0);
            List<Integer> new4Result1 = new ArrayList<>(result1);

            new0Result0.add(c1int);
            new0Result1.add(c1int);
            step(j + 1, new0Result0, new0Result1, chars0, chars1);

            new1Result0.add((c1int + 1) % 10);
            new1Result1.add(c1int);
            step(j + 1, new1Result0, new1Result1, chars0, chars1);

            int e = (c1int - 1) % 10;
            if(e==-1){
                e=9;
            }
            new2Result0.add(e);
            new2Result1.add(c1int);
            step(j + 1, new2Result0, new2Result1, chars0, chars1);

            new3Result0.add(0);
            new3Result1.add(c1int);
            step(j + 1, new3Result0, new3Result1, chars0, chars1);

            new4Result0.add(9);
            new4Result1.add(c1int);
            step(j + 1, new4Result0, new4Result1, chars0, chars1);


        } else {//c1 == '?'

            List<Integer> new1Result0 = new ArrayList<>(result0);
            List<Integer> new1Result1 = new ArrayList<>(result1);
            List<Integer> new2Result0 = new ArrayList<>(result0);
            List<Integer> new2Result1 = new ArrayList<>(result1);
            List<Integer> new3Result0 = new ArrayList<>(result0);
            List<Integer> new3Result1 = new ArrayList<>(result1);
            List<Integer> new4Result0 = new ArrayList<>(result0);
            List<Integer> new4Result1 = new ArrayList<>(result1);


            new0Result0.add(c0int);
            new0Result1.add(c0int);
            step(j + 1, new0Result0, new0Result1, chars0, chars1);

            new1Result0.add(c0int);
            new1Result1.add((c0int + 1) % 10);
            step(j + 1, new1Result0, new1Result1, chars0, chars1);

            new2Result0.add(c0int);
            int e = (c0int - 1) % 10;
            if(e==-1){
                e=9;
            }
            new2Result1.add(e);
            step(j + 1, new2Result0, new2Result1, chars0, chars1);

            new3Result0.add(c0int);
            new3Result1.add(0);
            step(j + 1, new3Result0, new3Result1, chars0, chars1);

            new4Result0.add(c0int);
            new4Result1.add(9);
            step(j + 1, new4Result0, new4Result1, chars0, chars1);
        }

    }

    private static void processAns(List<Integer> result0, List<Integer> result1) {
        StringBuilder sb1 = new StringBuilder();
        StringBuilder sb2 = new StringBuilder();

        for (Integer integer : result0) {
            sb1.append(integer);
        }
        for (Integer integer : result1) {
            sb2.append(integer);
        }

        String st1 = sb1.toString();
        int int1 = Integer.parseInt(st1);
        String st2 = sb2.toString();
        int int2 = Integer.parseInt(st2);

        int diff = Math.abs(int1 - int2);
        if (bestAnswer == null || (diff < bestScores[0]) ||
                (diff == bestScores[0] && int1 < bestScores[1] ||
                        (diff == bestScores[0] && int1 == bestScores[1] && int2 < bestScores[2]))) {

            bestAnswer = st1 + " " + st2;
            bestScores[0] = diff;
            bestScores[1] = int1;
            bestScores[2] = int2;
        }
    }
}
