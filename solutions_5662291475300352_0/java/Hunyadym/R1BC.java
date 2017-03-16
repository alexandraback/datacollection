import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class R1BC {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new BufferedReader(new FileReader(new File("R1BC.in"))));
        PrintWriter pw = new PrintWriter(new FileWriter(new File("R1BC.out")));
        int testNum = sc.nextInt();
        for (int t = 0; t < testNum; ++t) {
            ArrayList<Hiker> hikers = new ArrayList<>();
            int groupnum = sc.nextInt();
            for (int i = 0; i < groupnum; ++i) {
                int deg = sc.nextInt();
                int groupsize = sc.nextInt();
                int speed = sc.nextInt();
                for (int j = 0; j < groupsize; ++j) {
                    hikers.add(new Hiker(deg, ((double)360)/speed));
                    speed++;
                }
            }

            int result;
            if (hikers.size() == 0) {
                result = 0;
            } else if (hikers.size() == 1) {
                result = 0;
            } else if (hikers.size() == 2) {
                Hiker firstHiker ;
                Hiker secondHiker ;
                if (hikers.get(0).deg > hikers.get(1).deg) {
                    firstHiker =  hikers.get(0);
                    secondHiker =  hikers.get(1);
                } else {
                    firstHiker = hikers.get(1);
                    secondHiker = hikers.get(0);
                }
                if (firstHiker.speed == secondHiker.speed) {
                    result = 0;
                }
                else if (firstHiker.speed > secondHiker.speed) {
                    double timeToReach = (secondHiker.deg + 360 - firstHiker.deg) / (firstHiker.speed - secondHiker.speed);
                    if (timeToReach <= (360 - secondHiker.deg) / secondHiker.speed) {
                        result = 1 ;
                    } else {
                        result = 0;
                    }
                }
                else if (firstHiker.speed < secondHiker.speed) {
                    double timeToReach = (firstHiker.deg + 360 - secondHiker.deg) / (secondHiker.speed - firstHiker.speed);
                    if (timeToReach <= (360 - firstHiker.deg) / firstHiker.speed) {
                        result = 1 ;
                    } else {
                        result = 0;
                    }
                } else {
                    result = -1;
                }
            } else {
                result = -1;
            }

            pw.println("Case #" + (t + 1) + ": " + result);
        }
        pw.close();
        sc.close();
    }

    private static class Hiker {
        double speed ;
        int deg ;

        public Hiker(int deg, double speed) {
            this.deg = deg;
            this.speed = speed;
        }
    }
}
