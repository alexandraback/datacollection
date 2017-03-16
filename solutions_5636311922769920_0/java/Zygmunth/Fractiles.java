package me;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.text.MessageFormat;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

@SuppressWarnings("Duplicates")
public class Fractiles {


    public static void main(String[] args) throws IOException {
        File file = new File("/Users/prv/IdeaProjects/CodeJam/in.txt");
        FileWriter out = new FileWriter("/Users/prv/IdeaProjects/CodeJam/out.txt");
        Scanner scanner = new Scanner(file);
        int caseCount = scanner.nextInt();
        for (int i = 0; i < caseCount; i++) {
            int size = scanner.nextInt();
            int comp = scanner.nextInt();
            int budg = scanner.nextInt();
            BigInteger bComp = BigInteger.valueOf(comp);
            BigInteger bSize = BigInteger.valueOf(size);
            if (budg*comp < size) {
                out.write("Case #" + (i+1) +": IMPOSSIBLE\n");
            } else {
                int last = 0;
                out.write("Case #" + (i+1) +":");

                while (last < size) {
                    BigInteger num = BigInteger.ZERO;
                    for (int j = comp - 1; j >= 0 && last<size; j--) {
                        num = num.add(bSize.pow(j).multiply(BigInteger.valueOf(last++)));
                    }
                    out.write(" " + num.add(BigInteger.ONE));
                }
                out.write("\n");
            }
        }
        out.close();
    }

}
