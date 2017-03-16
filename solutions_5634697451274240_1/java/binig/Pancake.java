import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * Created by benoi_000 on 4/9/2016.
 */
public class Pancake {

    public static class Solver {
        public Solver() {

        }

        public int solve(boolean[] cakes) {
            int count = 0;
            boolean reverse = false;
            boolean prev=false;
            for (int i=0;i<cakes.length;i++) {
                boolean val = cakes[cakes.length-i-1];
                if (i>0&&val ==prev) {
                    continue;
                }
                if (reverse?val:!val) {
                    reverse =!reverse;
                    count++;
                }
                prev = val;
            }
            return count;
        }
    }

    public static void main(String args[]) throws FileNotFoundException {
        Scanner scanner = new Scanner(Thread.currentThread().getContextClassLoader().getResourceAsStream("pancake/B-large.in"));
        PrintStream printStream = new PrintStream("C:\\Users\\benoi_000\\workspace\\codeJam2016\\process\\pancake\\B-large.out" );
        int nb = scanner.nextInt();
        scanner.nextLine();
        for (int i=0;i<nb;i++) {
            String pb = scanner.nextLine();
            boolean[] cakes= new boolean[pb.length()];
            for(int j=0;j<cakes.length;j++) {
                cakes[j] = pb.charAt(j)=='+';
            }
            int sol = new Solver().solve(cakes);
            printStream.println("Case #"+(i+1)+": "+sol);
        }
    }

}
