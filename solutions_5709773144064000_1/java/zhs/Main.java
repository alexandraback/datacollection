
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author zhs
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            System.setIn(new FileInputStream("/home/zhs/file/code/codejam/in"));
            System.setOut(new PrintStream("/home/zhs/file/code/codejam/out"));
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int cnt = 1; cnt <= t; cnt++) {
            System.out.print("Case #" + cnt + ": ");
            double c = scanner.nextDouble();
            double f = scanner.nextDouble();
            double y = scanner.nextDouble();
            double a = 2;
            double x = 0;
            double min = y / a;
            while (x <= min) {
                x += c / a;
                a += f;
                min = Math.min(min, x + y / a);
            }
            System.out.println(min);
        }
    }
}
