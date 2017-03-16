package ramanvesh.codejam._1_1B_2015;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.stream.IntStream;

/**
 * Created by ram.kasam on 11/04/15.
 */
public class Main {

    public static void main(String[] args) {
        File testCaseFile = new File("1_1B_2015/testcase.txt");
        try (Scanner scanner = new Scanner(testCaseFile)) {
            String line = getNextLine(scanner);
            int noOfTasks = Integer.parseInt(line.trim());

            IntStream.range(1, noOfTasks + 1)
                    .forEach(testCaseNumber -> {
                        long N = Long.parseLong(getNextLine(scanner));
                        long count = 0;
                        long num = 0;
                        if(N < 10){
                            count = N;
                        } else {
                            int range = getRange(N);
                            for (int i = 1; i < range; i++) {
                                long straight = (long) (Math.pow(10, Math.max(i / 2, 1)) - 1);
                                count += straight;
                                num += straight;
                                if (num > 9) {
                                    num = getReverse(num);
                                    count += Math.pow(10, i) - num + 1;
                                } else {
                                    count++;
                                }
                                num = (long) Math.pow(10, i);
                            }
                            if(num < N) {
                                long[] bestReversable = getBestReversable(N);
                                if (bestReversable[1] > bestReversable[0]) {
                                    count += bestReversable[0] - Math.pow(10, range - 1);
                                    count += N - bestReversable[1] + 1;
                                } else {
                                    count += N - Math.pow(10, range - 1);
                                }
                            }
                        }
                        System.out.println("Case #"+testCaseNumber+": " + count);
                    });
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private static long[] getBestReversable(long n) {
        if(n%10 == 0){
            n -= 1;
        }
        StringBuilder string = new StringBuilder(String.valueOf(n));
        for (int i = (string.length() + 1)/2 ;i<string.length()-1;i++){
            string.setCharAt(i,'0');
        }
        string.setCharAt(string.length() - 1, '1');
        long num = Long.parseLong(string.toString());
        return new long[]{getReverse(num),num};
    }

    private static int getRange(long num){
        for(int i = 0; ; i++){
            if(Math.pow(10,i) > num){
                return i;
            }
        }
    }

    private static long getReverse(long num){
        StringBuilder string = new StringBuilder(String.valueOf(num));
        string.reverse();
        return Long.parseLong(string.toString());
    }

    private static long printTime(String message, long time) {
//        long newTime = System.nanoTime();
//        System.out.println(message + (newTime -time));
//        return newTime;
        return 0;
    }

    private static String getNextLine(Scanner scanner) {
        String nextLine;
        do {
            nextLine = scanner.nextLine().trim();
        } while (nextLine.startsWith("//"));
        return nextLine;
    }
}
