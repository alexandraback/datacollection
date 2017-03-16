import java.math.BigInteger;
import java.util.*;

/**
 * Created by Tor on 09.04.2016.
 */
public class Fractiles {

    public static void main(String[] args) {
        new Fractiles().go();
    }

    private void go() {
        Scanner s = new Scanner(System.in);

        int numCases = s.nextInt();
        for(int i=1;i<=numCases;i++) {
            int originalLength = s.nextInt();
            int complexity = s.nextInt();
            int numStudents = s.nextInt();

            List<BigInteger> tiles = solve(originalLength, complexity, numStudents);
            printCase(i, tiles);
        }
    }

    private void printCase(int caseNum, List<BigInteger> tiles) {
        StringBuilder sb = new StringBuilder();
        sb.append("Case #").append(caseNum).append(":");
        if(tiles != null) {
            for (BigInteger tile : tiles) {
                sb.append(" ").append(tile.add(BigInteger.ONE));
            }
        } else {
            sb.append(" IMPOSSIBLE");
        }
        System.out.println(sb);
    }

    public static List<BigInteger> solve(int originalLength, int complexity, int numStudents) {
        if(numStudents*complexity < originalLength) {
            return null;
        }

        List<BigInteger> tiles = new ArrayList<BigInteger>();
        LinkedList<Integer> remaining = getRemaining(originalLength);

        BigInteger baseNumber = BigInteger.valueOf(originalLength);
        while(!remaining.isEmpty()) {
            BigInteger index = BigInteger.ZERO;

            for(int i=0;i<complexity;i++) {
                BigInteger temp;
                if(!remaining.isEmpty()) {
                    temp = BigInteger.valueOf(remaining.pollLast());
                } else {
                    temp = BigInteger.ZERO;
                }

                index = index.add(baseNumber.pow(i).multiply(temp));
            }
            tiles.add(index);
        }

        return tiles;
    }

    private static LinkedList<Integer> getRemaining(int originalLength) {
        LinkedList<Integer> remaining = new LinkedList<Integer>();
        for(int i=0;i<originalLength;i++)
            remaining.add(i);
        return remaining;
    }
}
