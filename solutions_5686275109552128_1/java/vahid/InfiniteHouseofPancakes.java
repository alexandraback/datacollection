package com.vahid.contest.codejam.codejam2015.qualification;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class InfiniteHouseofPancakes {

    public static int minTime(int[] numberOfPancakes){
        int max = numberOfPancakes[0];
        for (int i=1; i<numberOfPancakes.length; i++)
            max = Math.max(max , numberOfPancakes[i]);

        int min = Integer.MAX_VALUE;

        for (int i= 1; i <= max; i++){
            int cost = i;
            for (int element : numberOfPancakes){
                cost += reduce(element,i);
            }

            min = Math.min(min, cost);
        }
        return min;
    }

    private static int reduce(int element, int i) {
        int result = element / i;
        if (result*i != element)
            result++;
        return result-1;
    }

    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new File("input.txt"));
        BufferedWriter output = new BufferedWriter(new FileWriter("output.txt"));
        int n = input.nextInt();
        for (int counter = 1; counter <= n; counter++){

            int d = input.nextInt();
            int[] numberOfPancakes = new int[d];
            for (int i=0; i<d; i++)
                numberOfPancakes[i] = input.nextInt();
            output.write("Case #" + counter + ": " + minTime(numberOfPancakes));
            output.newLine();

        }
        input.close();
        output.close();
    }

}
