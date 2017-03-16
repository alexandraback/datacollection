package qualification2013;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Treasure {
    static String[] result;
    
    public static void main(String[] args) throws IOException {
        read();
        write();
    }

    static void read() throws IOException {
        File input = new File("input.txt");
        Scanner scanner = new Scanner(input);
        int T = scanner.nextInt();
        result = new String[T];
        for (int t=0; t<T; t++) {
            System.out.println("CASE " + (t+1));
            Problem problem = new Problem();
            int K = scanner.nextInt();
            int N = scanner.nextInt();
            for (int k=0; k<K; k++) {
                int key = scanner.nextInt();
                problem.keys[key]++;
            }
            problem.chests = new ArrayList<Chest>(N);
            for (int n=0; n<N; n++) {
                Chest chest = new Chest();
                chest.number = n+1;
                chest.key = scanner.nextInt();
                int no = scanner.nextInt();
                for (int i=0; i<no; i++) {
                    int key = scanner.nextInt();
                    chest.keys[key]++;
                }
                problem.chests.add(chest);
            }
            result[t] = solve(problem);
        }
    }

    static boolean maybeDoable(Problem problem) {
        int keys[] = new int[201];
        System.arraycopy(problem.keys, 0, keys, 0, 201);
        boolean[] used = new boolean[21];
        for (int i=0; i<20; i++) {
            for (Chest chest : problem.chests) {
                if (!used[chest.number] && keys[chest.key] > 0) {
                    used[chest.number] = true;
                    for (int j=1; j<201; j++) {
                        keys[j] += chest.keys[j];
                    }
                }
            }
        }
        for (Chest chest : problem.chests) {
            if (keys[chest.key] == 0) {
                return false;
            } else {
                keys[chest.key]--;
            }
        }
        return true;
    }

    static String solve(Problem problem) {
        if (!maybeDoable(problem)) {
            return null;
        }
        if (problem.chests.isEmpty()) {
            return "";
        }
        for (Chest chest : problem.chests) {
            if (problem.keys[chest.key] > 0) {
                Problem next = new Problem();
                System.arraycopy(problem.keys, 0, next.keys, 0, 201);
                next.keys[chest.key]--;
                for (int i=0; i<201; i++) {
                    next.keys[i] += chest.keys[i];
                }
                next.chests = new ArrayList<Chest>(problem.chests.size()-1);
                for (Chest c : problem.chests) {
                    if (c != chest) {
                        next.chests.add(c);
                    }
                }
                String solution = solve(next);
                if (solution != null) {
                    return chest.number + " " + solution;
                }
            }
        }
        return null;
    }

    static void write() throws IOException {
        File output = new File("output.txt");
        PrintWriter pw = new PrintWriter(output);

        for (int t=0; t<result.length; t++) {
            if (result[t] == null) {
                result[t] = "IMPOSSIBLE";
            }
            pw.println("Case #"+(t+1)+": "+result[t].trim());
        }

        pw.close();
    }

    static class Problem {
        int[] keys = new int[201];
        List<Chest> chests;
    }

    static class Chest {
        int number;
        int key;
        int[] keys = new int[201];
    }
    
}
