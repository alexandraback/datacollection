
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author bachu
 */
public class Rpancakes {
    public static void main(String args[]) throws FileNotFoundException {
        Scanner scan = new Scanner(new File("pancakes.in"));
        PrintWriter writer = new PrintWriter(new File("pancakes.out"));
        int cases = scan.nextInt();
        for (int i = 0; i < cases; i++) {
            String line = scan.next();
            boolean arr[] = new boolean[line.length()];
            for (int j = 0; j < line.length(); j++) {
                arr[j] = line.charAt(j) == '+';
            }
            int ans = solve(arr, arr.length - 1);
            System.out.println(line);
            writer.write(String.format("Case #%d: %d%n", i+1, ans));
        }
        writer.close();
    }
    
    static int solve(boolean arr[], int endIndex) {
        if (endIndex < 0) {
            return 0;
        }
        if (arr[endIndex] == true) {
            return solve(arr, endIndex - 1);
        }
        if (arr[0] == false) {
            boolean arr2[] = new boolean[endIndex+1];
            for (int i = 0; i <= endIndex; i++) {
                arr2[i] = !arr[i];
            }
            for (int i = 0; i <= endIndex; i++) {
                arr[i] = arr2[endIndex-i];
            }
            return 1 + solve(arr, endIndex-1);
        }
        int minTrue = 0;
        for (int i = 0; i < endIndex; i++) {
            if (arr[i] == true) {
                arr[i] = false;
            }
            else {
                return 1 + solve(arr, endIndex);
            }
            minTrue = i;
        }
        return 1 + solve(arr, endIndex);
    }
}
