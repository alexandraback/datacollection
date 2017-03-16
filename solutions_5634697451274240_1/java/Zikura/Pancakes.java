import java.util.Scanner;

/**
 * Created by Tor on 09.04.2016.
 */
public class Pancakes {

    public static void main(String[] args) {
        new Pancakes().go();
    }

    private void go() {
        Scanner s = new Scanner(System.in);

        int numCases = s.nextInt();
        for(int i=1;i<=numCases;i++) {
            String stack = s.next();

            int numMoves = calculateMoves(stack);

            System.out.format("Case #%d: %d\n", i, numMoves);
        }
    }

    protected static int calculateMoves(String stack) {
        int numMoves = 0;
        char current = stack.charAt(0);
        for(int i=0;i<stack.length();i++) {
            if(stack.charAt(i)!=current) {
                current = stack.charAt(i);
                numMoves++;
            }
        }
        if(current=='-')
            numMoves++;

        return numMoves;
    }
}
