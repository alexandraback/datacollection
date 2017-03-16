package org.virutor;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;

public class Fractiles {

    public static void main(String[] args) {

        try (Stream<String> ln = Files.lines(Paths.get(args[0]))) {

            String[] lines = ln.toArray(String[]::new);

            int cases = Integer.parseInt(lines[0].trim());
            for (int i = 1; i < cases + 1; i++) {
                String[] params = lines[i].split(" ");
                long K = Long.parseLong(params[0]);
                long C = Long.parseLong(params[1]);
                long S = Long.parseLong(params[2]);
                solveAndPrint(K, C, S, i);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static void solveAndPrint(long K, long C, long S, long cs) {

        if (C * S < K) {
            System.out.println("Case #" + cs + ": IMPOSSIBLE");
            return;
        }

        List<Long> solution = new ArrayList<>();

        long kIndex = 1;
        do {
            long treeIndex = kIndex;
            for (int i = 1; i < C; i++) {
                if (kIndex < K) {
                    kIndex++;
                }
                treeIndex = (treeIndex - 1) * K + kIndex;
            }
            solution.add(treeIndex);
            kIndex++;
        } while (kIndex < K + 1);

        System.out.print("Case #" + cs + ":");
        for(long i : solution) {
            System.out.print(" " + i);
        }
        System.out.println();


    }

}
