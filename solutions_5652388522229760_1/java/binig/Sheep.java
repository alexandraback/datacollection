import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * Created by benoi_000 on 4/9/2016.
 */
public class Sheep {

    public static class Solver {
        public Solver() {

        }

        public String solve(int start) {
            if (start ==0) {
                return "INSOMNIA";
            }
            long max = start;
            long found =0;
            long allFound = (1<<10)-1;
            found = check(max, found);
            while (found!=allFound) {
                max += start;
                found = check(max, found);
            }
            return Long.toString(max);
        }

        private long check(long max, long found) {

            while (max >0) {
                long n = max%10;
                max = max/10;
                found = found | (1<<n);
            }
            return found;
        }
    }

    public static void main(String args[]) throws FileNotFoundException {
        Scanner scanner = new Scanner(Thread.currentThread().getContextClassLoader().getResourceAsStream("sheep/A-large.in"));
        PrintStream printStream =  new PrintStream("C:\\Users\\benoi_000\\workspace\\codeJam2016\\process\\sheep\\A-large.out" );
        // scanner = new Scanner(Thread.currentThread().getContextClassLoader().getResourceAsStream("sheep/test.txt"));
      //   printStream =  System.out;
        int nb = scanner.nextInt();
        scanner.nextLine();
        for (int i=0;i<nb;i++) {
            int pb = scanner.nextInt();

            String sol = new Solver().solve(pb);
            printStream.println("Case #"+(i+1)+": "+sol);
        }
    }

}
