package round1C;

import base.CodeJamScanner;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class A {
    private static CodeJamScanner scanner;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner file = new Scanner(new File("C:\\Users\\Samuel\\Downloads\\input.txt"));
        scanner = new CodeJamScanner(file);
        Integer cases = scanner.getInteger();
        for (Integer i = 0; i < cases; i++) {
            scanner.outputTestCase((i + 1), runTestCase());
        }
    }

    private static String runTestCase() {
        ArrayList<Integer> nums = scanner.getIntegerList();
        Integer R = nums.get(0);
        Integer C = nums.get(1);
        Integer W = nums.get(2);

        Integer timesPerRow = C / W;
        Integer lockedInPlace = timesPerRow * R;
        if (C - (timesPerRow * W) != 0) {
            W = W + 1;
        }
        Integer shots = lockedInPlace + (W - 1);
        return shots.toString();
    }
}
