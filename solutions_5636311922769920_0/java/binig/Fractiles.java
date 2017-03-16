import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * Created by benoi_000 on 4/9/2016.
 */
public class Fractiles {
    public static class Solver {

        public int[] solve(int k,int c, int s) {
            if (c==1 && s<k || s<k-1) return null;
            int[] res =  new int[c==1?k: Math.max(1,k-1)];
            for (int i=0;i<res.length;i++) {
                res[i] = k-i;
            }
            return res;
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(Thread.currentThread().getContextClassLoader().getResourceAsStream("fractiles/D-small-attempt1.in"));
        PrintStream printStream =  new PrintStream("C:\\Users\\benoi_000\\workspace\\codeJam2016\\process\\fractiles\\D-small-attempt1.text" );
        //scanner = new Scanner(Thread.currentThread().getContextClassLoader().getResourceAsStream("fractiles/test.txt"));
        //printStream =  System.out;
        int nb = scanner.nextInt();
        scanner.nextLine();
        for (int i=0;i<nb;i++) {
            int k = scanner.nextInt();
            int c = scanner.nextInt();
            int s = scanner.nextInt();
            printStream.print("Case #"+(i+1)+":");
            int res[] = new Solver().solve(k,c,s);
            if (res != null) {
                for(int r:res) {
                    printStream.print(' ');
                    printStream.print(r);

                }
            } else {
                printStream.print(" IMPOSSIBLE");
            }
            printStream.println();

        }
    }

}
