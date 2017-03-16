
package com.vahid.contest.codejam.codejam2015.qualification;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class StandingOvation {
    public static int calculateMinimumeInvitations(int shynessLevel, int sMax, String peopleShyness, int numberOfPeople) {
        if (shynessLevel > sMax)
            return 0;
        int currentShynessPeople = Integer.parseInt(peopleShyness.substring(shynessLevel, shynessLevel+1));
        int neededpeople = (numberOfPeople >= shynessLevel) ? 0 : shynessLevel - numberOfPeople;
        return neededpeople + calculateMinimumeInvitations(shynessLevel + 1, sMax, peopleShyness, numberOfPeople + neededpeople + currentShynessPeople);
    }

    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new File("input.txt"));
        BufferedWriter output = new BufferedWriter(new FileWriter("output.txt"));
        int n = input.nextInt();
        for (int counter = 1; counter <= n; counter++){
            int sMax = input.nextInt();
            String peopleShyness = input.nextLine().trim();
            output.write("Case #" + counter + ": " + calculateMinimumeInvitations(0, sMax, peopleShyness, 0));
            output.newLine();
        }
        input.close();
        output.close();
    }
}
