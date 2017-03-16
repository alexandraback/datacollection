package shutovich;

import com.sun.deploy.util.StringUtils;

import java.io.File;
import java.io.IOException;
import java.math.BigInteger;
import java.nio.file.Files;
import java.util.AbstractMap.SimpleEntry;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

/**
 * Created by U on 4/9/2016.
 */
public class JamCoins {

    static List<String> getResultLines(int size, int numberCount) {
        List<String> divisors = IntStream.range(2, 11).mapToObj(k -> new BigInteger("11", k).longValue())
                .map(x -> x.toString())
                .collect(Collectors.toList());
        return IntStream.range(0, numberCount)
                .mapToObj(j -> new BigInteger(BigInteger.valueOf(j).toString(2), 4).toString(2))
                .map(s -> "1" + String.join("", Collections.nCopies(size - s.length() - 4, "0")) + s + "01")
                .map(s -> new BigInteger(s, 2).multiply(BigInteger.valueOf(3)).toString(2))
                .map(s -> s + " " + String.join(" ", divisors))
                .collect(Collectors.toList());
    }

// size = 7, l = 3 (101 or 100): 1 <value> 01 for size - 1

    public static void main(String[] args) throws IOException {
        List<String> lines = Files.readAllLines(new File("input3").toPath());
        int count = Integer.parseInt(lines.get(0));
        List<String> resultLines = new ArrayList<>();
        for (int i = 0; i < count; i++) {
            String[] parts = lines.get(i + 1).split("\\s+");
            int size = Integer.parseInt(parts[0]);
            int numberCount = Integer.parseInt(parts[1]);
            resultLines.add("Case #" + (i + 1) + ":");
            List<String> resultLines1 = getResultLines(size, numberCount);
            resultLines1.stream().map(s -> s.split("\\s+"))
                    .forEach(parts1 -> IntStream.range(2, 11).forEach(j -> {
                        if (parts1.length != 10 || parts1[0].length() != size) {
                            throw new RuntimeException("Incorrect number count");
                        }
                        BigInteger number = new BigInteger(parts1[0], j);
                        int divisor = Integer.parseInt(parts1[j - 1]);
                        if (number.mod(BigInteger.valueOf(divisor)).longValue() != 0l) {
                            throw new RuntimeException("Incorrect result: " + parts1[0] + " at " + j
                                    + "(" + parts1[j - 1] + ")");
                        }
                    }));
            resultLines.addAll(resultLines1);

        }
        Files.write(new File("output3").toPath(), resultLines);
    }

}
