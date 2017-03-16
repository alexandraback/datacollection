import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Brattleship {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(new File("input.in"));
                BufferedWriter bw = new BufferedWriter(new FileWriter(new File("output.out")))) {
            int n = sc.nextInt();
            for (int i = 0; i < n; i++) {
                String answer = "Case #" + (i + 1) + ": " + solve(sc.nextInt(), sc.nextInt(), sc.nextInt());
                System.out.println(answer);
                bw.write(answer);
                bw.newLine();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static int solve(int r, int c, int w) {
        System.out.println(r + " " + c + " " + w);
        List<int[][]> martixs = getMartixs(r, c, w);
        int miss = 0;
        while (martixs.size() > 1) {

            miss++;
            martixs = removeByChoice(martixs);
        }
        return w + miss;
    }

    private static List<int[][]> removeByChoice(List<int[][]> martixs) {
        int count = martixs.size();
        int r = -1;
        int c = -1;
        int value = 0;
        int[][] determineMartix = new int[martixs.get(0).length][martixs.get(0)[0].length];
        for (int[][] martix : martixs) {
            for (int i = 0; i < martix.length; i++) {
                for (int j = 0; j < martix[0].length; j++) {
                    determineMartix[i][j] += martix[i][j];
                }
            }
        }
        int absMin = Integer.MAX_VALUE;
        for (int i = 0; i < determineMartix.length; i++) {
            for (int j = 0; j < determineMartix[0].length; j++) {
                int absMinus = Math.abs(determineMartix[i][j] - count);
                if (Math.min(absMinus, absMin) == absMinus) {
                    r = i;
                    c = j;
                    absMin = absMinus;
                    value = determineMartix[i][j] - count > 0 ? 1 : -1;
                }
            }
        }
        List<int[][]> newList = new ArrayList<>();
        final int i = r;
        final int j = c;
        final int maintain = value;
        martixs.stream().filter(martix -> martix[i][j] == maintain).forEach(newList::add);
        return newList;
    }

    private static List<int[][]> getMartixs(int r, int c, int w) {
        List<int[][]> martixs = new ArrayList<>();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c - w + 1; j++) {
                int[][] martix = new int[r][c];
                for (int k = 0; k < r; k++) {
                    for (int l = 0; l < c; l++) {
                        martix[k][l] = -1;
                    }
                }
                for (int k = 0; k < w; k++) {
                    martix[i][j + k] = 1;
                }
                martixs.add(martix);
            }
        }
        return martixs;

    }
}
