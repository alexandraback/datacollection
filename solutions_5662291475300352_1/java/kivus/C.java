import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

/**
 *
 *
 */
public class C {
    public static void main(String[] args) {
         try {
             Scanner scanner = (new Scanner(new File("c:/users/rafal/ideaprojects/src/Cin.txt")));


             FileOutputStream out = new FileOutputStream("c:/users/rafal/ideaprojects/src/Cout.txt");

             int numberOfCases;
             numberOfCases = scanner.nextInt();
             scanner.nextLine();

             PrintWriter wr = new PrintWriter(out);
             for (int i = 0; i < numberOfCases; i++) {
                 doCase(i + 1, scanner, wr);
                 if (i < numberOfCases - 1)
                    scanner.nextLine();
             }
             wr.close();
             out.close();

         } catch (IOException e) {
             System.out.println("Error: " + e);
         }
     }

    private static class Hiker {
        int d;
        int m;

        private Hiker(int d, int m) {
            this.d = d;
            this.m = m;
        }
    }
    private static void doCase(int caseNumber, Scanner scanner, PrintWriter wr) {
        int n = scanner.nextInt();

        int []d = new int[n];
        int []h = new int[n];
        int []m = new int[n];


        List<Hiker> list = new ArrayList<Hiker>();
        for (int i = 0; i < n; i++) {
            d[i] = scanner.nextInt();
            h[i] = scanner.nextInt();
            m[i] = scanner.nextInt();

            for (int j = 0; j < h[i]; j++) {
                list.add(new Hiker(d[i], m[i] + j));
            }
        }


        int minEncounters = list.size() - 1;

        for (int i = 0; i < list.size(); i++) {
            Hiker follow = list.get(i);

            long encounters = 0;
            for (int j = 0; j < list.size(); j++) {
                if (i == j) continue;

                Hiker hh = list.get(j);
//                double time = (double)follow.m * (360 - follow.d ) / 360;
                long time2 = (long)follow.m * (360 - follow.d );
                // how many times do we meet hiker hh
                if (hh.m == follow.m) {
                    if (follow.d > hh.d) {
                        encounters++;
                    } else {
                        // no encounters...
                    }
                } else if (hh.m > follow.m) {
                    // slower hiker
                    if (follow.d > hh.d) {
                        encounters++;
                    } else {
                        // check if hiker hh can finish before us
                        long time22 = (long)hh.m * (360 - hh.d);
                        if (time22 > time2) {
                            encounters++;
                        }
                    }
                } else {
                    // faster hiker
                    // this much time to get to point "0"
                    double t0 = (double)hh.m * (360 - hh.d) / 360;
                    double tt2 = (long)hh.m * (360 - hh.d);
//                    double timeLeft = time - t0;
                    double timeLeft2 = time2 - tt2;
//                    if (timeLeft > 0 && timeLeft2 <= 0 || timeLeft <= 0 && timeLeft2 > 0) {
//                        System.out.println("!!!!!!!!!!!!!!!!!!");
//                    }
                    if (timeLeft2 > 0) {
//                        double fullCircles = (double)timeLeft / (hh.m);
                        long fullCircles2 = (long)timeLeft2 / ((long)hh.m * 360);
//                        int fullC = (int)Math.floor(fullCircles2);
//                        if (Math.floor(fullCircles) != Math.floor(fullCircles + 1e-10)) {
//                            System.out.println(fullCircles);
//                        }
                        if (fullCircles2 > 0) {
                            encounters += fullCircles2;
                        }
                    }
                }
            }
            if (encounters < minEncounters) {
                minEncounters = (int)encounters;
            }
        }


        String result = ""+minEncounters;
        wr.println("Case #" + caseNumber + ": " + result);
        System.out.println("Case #" + caseNumber + ": " + result);
        // ...

    }

}