package shutovich;

import java.io.File;
import java.io.IOException;
import java.math.BigInteger;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by U on 4/9/2016.
 */
public class Tiles {

    static String getResult(int tileCount, int depth, int tryCount) {
        if (tryCount * depth < tileCount) {
            return "IMPOSSIBLE";
        } else {
            int p = 0;
            List<String> positions = new ArrayList<>();
            BigInteger t = BigInteger.valueOf(tileCount);
            while (p < tileCount) {
                // Print (p) (p + 1) .. (p + depth - 1) in base 'tileCount'
                BigInteger bi = BigInteger.valueOf(p);
                for (int i = 0; i < depth - 1; i++) {
                    bi = bi.multiply(t);
                    bi = bi.add(BigInteger.valueOf(Math.min(p + i + 1, tileCount - 1)));
                }
                bi = bi.add(BigInteger.ONE);
                positions.add(bi.toString());
                p += depth;
            }
            return String.join(" ", positions);
        }
    }

    public static void main(String[] args) throws IOException {
        List<String> lines = Files.readAllLines(new File("input4").toPath());
        int count = Integer.parseInt(lines.get(0));
        List<String> resultLines = new ArrayList<>();
        for (int i = 0; i < count; i++) {
            String[] parts = lines.get(i + 1).split("\\s+");
            int tileCount = Integer.parseInt(parts[0]);
            int depth = Integer.parseInt(parts[1]);
            int tryCount = Integer.parseInt(parts[2]);
            resultLines.add("Case #" + (i + 1) + ": " + getResult(tileCount, depth, tryCount));
        }
        Files.write(new File("output4").toPath(), resultLines);

    }

}
