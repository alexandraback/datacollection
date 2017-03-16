package com.myung;

import java.io.*;
import java.util.ArrayList;

/**
 * R1-1 - Counter Culture
 */
public class Main {
    public static void main(String[] args) throws FileNotFoundException, IOException{
        FileOutputStream fos = new FileOutputStream("A-small-attempt2.out");
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(fos));

        FileInputStream fis = new FileInputStream("A-small-attempt2.in");
        InputStreamReader isr = new InputStreamReader(fis);
        BufferedReader reader = new BufferedReader(isr);

        String line = reader.readLine(); // read first line

        int MaxCase = Integer.parseInt(line);

        for(int caseIndex = 1; caseIndex <= MaxCase ; caseIndex++ ) {
            line = reader.readLine();

            long maxNum = Long.parseLong(line);

            optiSteps = Long.MAX_VALUE;
            goStep(maxNum, maxNum, 1);

            if(optiSteps > maxNum) {
                String out = String.format("Error Case #%d: %d %d\n", caseIndex,maxNum, optiSteps);
            }

            String out = String.format("Case #%d: %d\n", caseIndex, optiSteps);

            System.out.printf(out);
            writer.write(out);
        }

        reader.close();
        writer.close();
    }

    public static long optiSteps = Long.MAX_VALUE;

    public static void goStep(long input, long maxNum, long curSteps) {
        if(input == 1L) {
            if(curSteps < optiSteps)
                optiSteps = curSteps;

            return;
        }

        long reverseNum = reverse(input);
        if (reverseNum < input){
            goStep(reverseNum, maxNum, curSteps+1);
        } else {
            goStep(input - 1, maxNum, curSteps + 1);
        }
    }

    public static long reverse(long input) {
        if(input < 10 || ((input % 10) == 0) || ((input % 10) > 1))
            return input;

        return Long.parseLong(new StringBuilder((new Long(input)).toString()).reverse().toString());
    }
}
