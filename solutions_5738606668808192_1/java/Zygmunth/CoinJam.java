package me;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.text.MessageFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

@SuppressWarnings("Duplicates")
public class CoinJam {
    public static BigInteger divisor(BigInteger integer, BigInteger limit) {
        for (BigInteger i = BigInteger.valueOf(3); i.compareTo(limit) < 0; i = i.add(BigInteger.ONE)) {
            BigInteger mod = integer.mod(i);
            if (mod.equals(BigInteger.ZERO)) {
                return i;
            }
        }
        return null;
    }

    public static void main(String[] args) throws IOException {
        File file = new File("/Users/prv/IdeaProjects/CodeJam/in.txt");
        FileWriter out = new FileWriter("/Users/prv/IdeaProjects/CodeJam/out.txt");
        Scanner scanner = new Scanner(file);
        int caseCount = scanner.nextInt();
        for (int i = 0; i < caseCount; i++) {
            out.write("Case #1:\n");
            int length = scanner.nextInt();
            int count = scanner.nextInt();
            long smallestBin = (((long)1) << (length-1)) + 1;
            long largestBin = (((long)1) << (length)) - 1;
            int found = 0;
            long current = smallestBin;
            while (found < count && current<=largestBin) {
                List<Integer> res =  calc(current);
                if (res != null) {
                    found++;
                    out.write(Long.toBinaryString(current) + " ");
                    for (int j = 0; j < res.size(); j++) {
                        Integer div = res.get(j);
                        out.write(div + " ");
                    }
                    out.write("\n");
                }
                current +=2;
            }
        }
        out.close();
    }

    private static List<Integer> calc(long current) {
        String str = Long.toBinaryString(current);
        int[] bases = {2,3,4,5,6,7,8,9,10};
        ArrayList<Integer> res = new ArrayList<>();
        for (int base : bases) {
            BigInteger number = new BigInteger(str,base);
            BigInteger divisor = divisor(number, BigInteger.valueOf(100));
            if (divisor == null) {
                return null;
            }
            res.add(divisor.intValue());
        }
        return res;
    }

}
