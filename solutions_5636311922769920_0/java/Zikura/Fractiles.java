import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

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

            List<BigInteger> tiles = solve(originalLength, complexity);
            printCase(i, tiles);
        }
    }

    private void printCase(int caseNum, List<BigInteger> tiles) {
        StringBuilder sb = new StringBuilder();
        sb.append("Case #").append(caseNum).append(":");
        for(BigInteger tile : tiles) {
            sb.append(" ").append(tile.add(BigInteger.ONE));
        }
        System.out.println(sb);
    }

    public static List<BigInteger> solve(int originalLength, int complexity) {
//        System.out.println("Solving ("+originalLength+", "+complexity+")");
        List<BigInteger> tiles = new ArrayList<BigInteger>();

        BigInteger length = BigInteger.valueOf(originalLength);
        // Forskyv alle plasser nedover i hierarkiet:
        for(int i=0;i<originalLength;i++) {
            BigInteger bigI = BigInteger.valueOf(i);
            BigInteger currentIndex = BigInteger.valueOf(i);
            BigInteger offset = BigInteger.ZERO;
            for(int level=1;level<complexity;level++) {
                offset = length.pow(level).multiply(bigI);
                currentIndex = (offset).add(currentIndex);
//                System.out.println("level="+level+", offset="+offset+", index="+currentIndex);
            }
//            System.out.println("Adding "+(currentIndex+1));
            tiles.add(currentIndex);
        }

        return tiles;
    }
}
