/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package zad2;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Formatter;
import java.util.HashSet;
import java.util.Scanner;

/**
 *
 * @author Milen
 */
public class Zad2 {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("input.txt"));
        Formatter out = new Formatter(new File("output.txt"));
        int tests = in.nextInt();
        for (int k = 0; k < tests; k++) {
            HashSet<Integer> visitedLevel2 = new HashSet<Integer>();
            HashSet<Integer> visitedLevel1 = new HashSet<Integer>();
            int levels = in.nextInt();
            int currentPoints = 0;
            int steps = 0;
            int[] starsSecond = new int[levels];
            int[] starsFirst = new int[levels];
            for (int i = 0; i < levels; i++) {
                starsFirst[i] = in.nextInt();
                starsSecond[i] = in.nextInt();
            }
            boolean isChanged = true;
            while (visitedLevel2.size() < levels && isChanged) {
                isChanged = false;
                for (int i = 0; i < starsSecond.length; i++) {
                    if (starsSecond[i] <= currentPoints) {
                        if (!visitedLevel2.contains(i)) {
                            visitedLevel2.add(i);
                            if (visitedLevel1.contains(i)) {
                                currentPoints++;
                            } else {
                                currentPoints += 2;
                            }
                            visitedLevel1.add(i);
                            steps++;
                            isChanged = true;
                            break;
                        }
                    }
                }
                if (isChanged) {
                    continue;
                }
                for (int i = 0; i < starsFirst.length; i++) {
                    if (starsFirst[i] <= currentPoints) {
                        if (!visitedLevel2.contains(i) && !visitedLevel1.contains(i)) {
                            visitedLevel1.add(i);
                            currentPoints++;
                            steps++;
                            isChanged = true;
                            break;
                        }
                    }
                }
            }
            if(visitedLevel2.size()<levels){
                out.format("Case #%d: Too Bad\n", k+1);
            }else{
                out.format("Case #%d: %d\n", k+1,steps);
            }
        }
        out.close();
    }
}
