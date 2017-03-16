package com.vahid.codejam.codejam2016.round1b;

import java.io.*;
import java.util.Scanner;


public class ProblemC {
    public static void main(String[] args) throws IOException {
        Scanner scanner = null;
        BufferedWriter output = null;
        try {
            scanner = new Scanner(new BufferedReader(
                    new FileReader("input.txt")));
            output = new BufferedWriter(new FileWriter("output.txt"));

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

        int n = scanner.nextInt();
        scanner.nextLine();

        for (int i=0; i < n; i++){
            int count = scanner.nextInt();
            scanner.nextLine();
            String[] x = new String[count];
            String[] y = new String[count];
            for (int j = 0 ; j<count; j++) {
                String str = scanner.nextLine();
                String[] split = str.split(" ");
                x[j] = split[0];
                y[j] = split[1];
            }
            output.write( "Case #"+(i+1)+": " + solve(count, x, y));
            output.newLine();
        }

        output.close();
    }

    private static int solve(int count, String[] x, String[] y) {
        int limit = 1 << count ;
        int response = 0;
        for (int i =1; i< limit; i++ ) {
            int counter= 0;
            boolean test = true;
            for (int j =0 ; j<count; j++ ) {
                if ((i &  (1 << j)) >0) {
                    if (check(count, x, y, j, i)) counter++;
                    else {
                        test = false;
                        break;
                    }
                } else {

                }
            }
            if (test) {
                response = Math.max(response, counter);
            }

        }
        return response;
    }

    private static boolean check(int count, String[] x, String[] y, int j, int map) {
        boolean response1 = false;
        for (int i = 0; i<count && !response1; i++) {
            if ((i!=j) && (map & (1 << i))==0) {
                if (x[i].equals(x[j])) response1 = true;
            }
        }


        boolean response2 = false;
        for (int i = 0; i<count && !response2; i++) {
            if ((i!=j) && (map & (1 << i))==0) {
                if (y[i].equals(y[j])) response2 = true;
            }
        }



        return response1 && response2;
    }

}
