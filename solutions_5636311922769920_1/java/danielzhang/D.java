package qr16;

import java.io.*;
import java.math.BigInteger;
public class D {
//    private static final String MODE = "sample";
//    private static final String MODE = "small-attempt1";
    private static final String MODE = "large";

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("in/" + D.class.getPackage().getName() + "/" + D.class.getSimpleName() + "-" + MODE + ".in"));

        File outFile = new File("out/" + D.class.getPackage().getName() + "/" + D.class.getSimpleName() + "-" + MODE + ".out");
        outFile.createNewFile();
        BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));

        D solution = new D();

        int T = Integer.parseInt(br.readLine());

        for (int t = 1; t <= T; t ++){
            String[] line = br.readLine().split(" ");
            int tiles = Integer.parseInt(line[0]);
            int complexity = Integer.parseInt(line[1]);
            int students = Integer.parseInt(line[2]);
            String output = solution.solve(tiles, complexity, students);
            System.out.printf("Case #" + t + ":" + output + "\n");
            bw.write("Case #" + t + ":" + output + "\n");
        }
        br.close();
        bw.close();
    }

    private String solve(int tiles, int complexity, int students) {
        if(tiles > students * complexity){
            return " IMPOSSIBLE";
        }
        if(tiles == 1){
            return " 1";
        }
        BigInteger tile;
        StringBuilder sb = new StringBuilder();
        for(int i = 0; (i + 1) * complexity <= tiles; i ++){
            tile = getTile(tiles, complexity, i);
            sb.append(" ").append(tile);
        }

        if(tiles % complexity != 0) {
            BigInteger last = BigInteger.valueOf(tiles).pow(complexity).add(BigInteger.ONE).add(getTile(tiles, complexity, 0).negate());
            sb.append(" ").append(last);
        }
        return sb.toString();
    }

    private BigInteger getTile(int k, int c , int i) {
        BigInteger tile = BigInteger.ONE;
        for(int pow = 0; pow < c; pow ++){
            tile = tile.add(BigInteger.valueOf(k).pow(pow).multiply(BigInteger.valueOf(i * c + c - 1 - pow)));
        }
        return tile;
    }
}