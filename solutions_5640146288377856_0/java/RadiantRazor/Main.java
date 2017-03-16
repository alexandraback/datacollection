package ramanvesh.codejam.brattleship;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

/**
 * Created by ram.kasam on 11/04/15.
 */
public class Main {

    public static void main(String[] args) {
        File testCaseFile = new File("Brattleship/testcase.txt");
        try (Scanner scanner = new Scanner(testCaseFile)) {
            String line = getNextLine(scanner);
            int noOfTasks = Integer.parseInt(line.trim());

            IntStream.range(1, noOfTasks + 1)
                    .forEach(testCaseNumber -> {
                        List<Integer> RCW = Arrays.asList(getNextLine(scanner).split("\\s+")).stream()
                                .map(Integer::parseInt)
                                .collect(Collectors.toList());
                        int R = RCW.get(0);
                        int C = RCW.get(1);
                        int W = RCW.get(2);
                        int numPerColumn = (int) Math.floor(((double) C) / W);
                        int totalNum = (numPerColumn * R) + W;
                        if(C%W == 0){
                            totalNum--;
                        }
                        System.out.println("Case #"+testCaseNumber+": "+totalNum);
                    });
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
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
