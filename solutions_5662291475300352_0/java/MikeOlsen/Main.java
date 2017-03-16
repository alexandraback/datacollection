package jam;

import java.io.*;
import java.util.Scanner;

public class Main {
    static String inputfile = "1b_c.in";
    static String outputfile = "1b_c.out";
    static String answer;
    static BufferedWriter writer;
    static Scanner scanner;

    public static void writeAnswer(int caseNum) throws Exception {
        System.out.println("Case #" + caseNum + ": " + answer);
        writer.write("Case #" + caseNum + ": " + answer);
        writer.newLine();
    }

    public static void main(String[] args) throws Exception {
        scanner = new Scanner(new File(inputfile));
        writer = new BufferedWriter(new FileWriter(outputfile));

        //Case loop:
        int numCases = scanner.nextInt();
        for(int caseNum = 1; caseNum <= numCases; caseNum++) {
            //System.out.println("starting case num: " + caseNum);
            answer = "";
            solve();
            writeAnswer(caseNum);
        }

        //Cleanup:
        scanner.close();
        writer.close();
    }

    public static void solve() {
        // get input from scanner
        // write answer to answer
        // follow just behind slowest one
        // until the next hiker comes
        // at that point, you're given a choice: keep fjb, or move onto the next hiker to fjb
        // do both at once via programming
        // how to calculate next hiker arrival?
        // go through all hikers and if their D is greater than your fjb, then subtract 360


        Hiker h1 = new Hiker();
        Hiker h2 = new Hiker();
        int numGroups = scanner.nextInt();
        h1.d = scanner.nextInt();
        int numInGroup = scanner.nextInt();
        h1.m = scanner.nextInt();
        if(numGroups == 2) {
            h2.d = scanner.nextInt();
            scanner.nextInt();
            h2.m = scanner.nextInt();
        }
        else {
            h2.d = h1.d;
            h2.m = h1.m + 1;
        }

        // the question: will you cross?
        // the answer: yes, if fast outlaps slow at or before 360: outlaps, not just passes. as in
        // d > 360

        Hiker slow = h1.m < h2.m ? h2 : h1;
        Hiker fast = slow == h1 ? h2 : h1;

        long slowFinish = (360 - (long) slow.d) * (long) slow.m; // distance * time/distance
        long fastFinish = (720 - (long) fast.d) * (long) fast.m;

        System.out.println("slowFinish: " + slowFinish);
        System.out.println("fastFinish: " + fastFinish);
        if(slowFinish < fastFinish) answer = "0";
        else answer = "1";

    }

    static Instance getNextMeeting(Hiker h1, Hiker h2) {
        Instance result = new Instance();

        if(h1.m == h2.m) {
            result.valid = false;
            return result;
        }

        // xpos = time
        // ypos = d

        // m = minutes per 360
        // so, slope = 360/m

        // y = 360x/m1 + d1
        // y = 360x/m2 + d2



        return result;
    }

    static class Instance {
        double time;
        double d;
        boolean valid;
    }

    static class Hiker {
        int d;
        int m;
        public Hiker(){}
        public Hiker(int d, int m) {
            this.d = d;
            this.m = m;
        }
    }
}

