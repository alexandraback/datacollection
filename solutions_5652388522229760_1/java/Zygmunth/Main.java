package me;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.text.MessageFormat;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) throws IOException {
        File file = new File("/Users/prv/IdeaProjects/CodeJam/in.txt");
        FileWriter out = new FileWriter("/Users/prv/IdeaProjects/CodeJam/out.txt");
        Scanner scanner = new Scanner(file);
        int caseCount = scanner.nextInt();
        for (int i = 0; i < caseCount; i++) {
            BigInteger m = scanner.nextBigInteger();
            BigInteger res = findAnswer(m);
            if (res != null) {
                out.write(MessageFormat.format("Case #{0,number,#}: {1,number,#}\n", i+1,res.longValueExact()));
            } else {
                out.write(MessageFormat.format("Case #{0,number,#}: INSOMNIA\n", i+1));
            }
        }
        out.close();
    }

    private static BigInteger findAnswer(BigInteger m) {
        BigInteger res = null;
        if (!m.equals(BigInteger.ZERO)) {
            Set<Integer> digits = new HashSet<>();
            BigInteger n = BigInteger.ZERO;
            do {
                n = n.add(m);
                n.toString().chars().forEach(digits::add);
            } while (digits.size() != 10);
            res = n;
        }
        return res;
    }
}
