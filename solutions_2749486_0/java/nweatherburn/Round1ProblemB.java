import java.util.Scanner;
import java.io.PrintWriter;
import java.io.File;
import java.awt.Point;

/**
 * Google CodeJam
 * n.weatherburn@gmail.com
 * 
 * @author Nicholas Weatherburn
 */

public class Round1ProblemB {
    
    public static void main(String[] args) throws Exception{
        Scanner scan = new Scanner(new File("B-small-attempt1.in"));
        PrintWriter pw = new PrintWriter("Resuts-Small-B.txt");
        int repeats = scan.nextInt();
        scan.nextLine();
        for (int i = 0; i < repeats; i++) {
            StringBuilder result = new StringBuilder();
            int finalX = scan.nextInt();
            int finalY = scan.nextInt();
            int x = 0;
            int y = 0;
            
            boolean xFound = false;
            boolean yFound = false;
            int count = 1;
            while (x != finalX && result.length() < 500) {
                if ((x + count) == finalX) {
                    result.append('E');
                    x += count;
                    count++;
                } else if ((x - count) == finalX) {
                    result.append('W');
                    x -= count;
                    count++;
                } else if (x < finalX) {
                    while (x != finalX && result.length() < 500) {
                        result.append("WE");
                        x -= count;
                        count++;
                        x += count;
                        count++;
                    }
                } else if (x > finalX) {
                    while (x != finalX && result.length() < 500) {
                        result.append("EW");
                        x += count;
                        count++;
                        x -= count;
                        count++;
                    }
                }
            }
            while (y != finalY && result.length() < 500) {
                if (y + count == finalY) {
                    result.append('N');
                    y += count;
                    count++;
                } else if (y - count == finalY) {
                    result.append('S');
                    y -= count;
                    count++;
                } else if (y < finalY) {
                    while (y != finalY && result.length() < 500) {
                        result.append("SN");
                        y -= count;
                        count++;
                        y += count;
                        count++;
                    }
                } else if (y > finalY && result.length() < 500) {
                    while (y != finalY) {
                        result.append("NS");
                        y += count;
                        count++;
                        y -= count;
                        count++;
                    }
                }
            }
            if (x != finalX || y != finalY) {
                System.out.println(i + "\t" + "(" + x + "," + y + ")" + "(" + finalX + "," + finalY + ")");
            }
            pw.println("Case #" + (i + 1) + ": " + result);

        }
        scan.close();
        pw.close();
        System.out.println("Finished");
    }
    
}