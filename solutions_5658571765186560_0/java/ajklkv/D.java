import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.Scanner;

public class D {
    public static void main(String[] args) throws Exception {
        PrintWriter writer = new PrintWriter(new FileOutputStream("D.out"));
        Scanner scanner = new Scanner(new FileInputStream("D.in"));
        //PrintWriter writer = new PrintWriter(System.out);
        //Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int t = 0; t < T; t++) {
            int x = scanner.nextInt();
            int r = scanner.nextInt();
            int c = scanner.nextInt();
            int max = Math.max(r, c);
            int min = Math.min(r, c);
            boolean win;
            if (x >= 7 ) {
                win = true;
            } else if (x > max) {
                win = true;
            } else if (x == 1) {
                win = false;
            } else if ((min * max) % x != 0) {
                win = true;
            } else if (x < 2*min - 1) {
                win = false;
            } else if (x >= 2*min) {
                win = true;
            } else if (x == 3) {
                win = false;
            } else if (x == 5) {
                win = false;
            } else {
                throw new RuntimeException("unknown x " + t );
            }
            writer.println(String.format("Case #%d: %s", t + 1, win ? "RICHARD" : "GABRIEL"));
        }
        scanner.close();
        writer.close();
    }
}

