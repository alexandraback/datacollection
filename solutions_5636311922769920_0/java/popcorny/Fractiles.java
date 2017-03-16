package idv.popcorny.jam2016;

import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by popcorny on 4/9/16.
 */
public class Fractiles {


    private static boolean isPossible(int k, int c, int s) {
        return k / Math.pow(2, c - 1) <= s;
    }

    int k;
    int c;

    BigInteger[] tiles;

    public Fractiles(int k, int c) {
        System.out.printf(">> k=%d, c=%d\n", k, c);

        tiles = new BigInteger[k];
        int d = 0;
        int top=0;

        int s=0;
        do {
            BigInteger tile = BigInteger.valueOf(0);
            for (int i = 0; i < c; i++) {

                int offset = d < k ? d++ : 0;

                tile = tile
                        .multiply(BigInteger.valueOf(k))
                        .add(BigInteger.valueOf(offset));

                System.out.printf("d=%d c=%d s=%d, tile=%s\n", offset, i, s, tile);

            }
            tiles[top++] = tile.add(BigInteger.ONE);
            System.out.printf("tile=%s\n", tile);
            s++;
        } while(d < k);
        System.out.println();

    }

    @Override
    public String toString() {
        StringBuffer sb = new StringBuffer();
        for (int i=0; i<tiles.length && tiles[i] != null; i++) {
            sb.append(tiles[i] + " ");
        }
        return sb.toString();
    }

    public static void main(String[] args) throws Exception {
        Scanner scanner;
        PrintWriter writer;
        String quizname = "fractiles";
        String testname = "small";
        String input   = String.format("quiz/%s/%s.in", quizname, testname);
        String output  = String.format("quiz/%s/%s.out", quizname, testname);

        if (new File(input).exists()) {
            scanner = new Scanner(new File(input));
            if (testname.equals("sample")) {
                writer = new PrintWriter(System.out);
            } else {
                writer = new PrintWriter(output);
            }
        } else {
            scanner = new Scanner(System.in);
            writer = new PrintWriter(System.out);
        }


        int t = scanner.nextInt();

        for (int i = 0; i < t; i++) {
            int k = scanner.nextInt();
            int c = scanner.nextInt();
            int s = scanner.nextInt();

            if (!isPossible(k, c, s)) {
                writer.printf("Case #%d: impossibe\n", i + 1, k, c, s);
            } else {
                writer.printf("Case #%d: %s\n", i+1, new Fractiles(k, c));
            }
        }
        writer.flush();
    }
}
