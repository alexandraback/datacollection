package dancinggooglers;

import java.io.File;
import java.util.Scanner;

public class DanceScoreCalculator {


    public static void main(String[] args) {
        if(args.length <= 0 || args[0] == null) {
            System.out.println("You must enter a file to read");
            System.out.println("Usage: blah <filename>");
            System.exit(0);
        }

        File argFile = new File(args[0]);
        try {
            Scanner googleSpeakScanner = new Scanner(argFile);
            String firstLine = googleSpeakScanner.nextLine();
            Integer linesToScan = new Integer(firstLine);
            for(int i = 1; i <= linesToScan; i++) {
                String googleDancerLine = googleSpeakScanner.nextLine();
                DanceScoreCase danceCase = new DanceScoreCase(googleDancerLine);
                System.out.println(String.format("Case #%d: %d", i, danceCase.maxDancersThatCouldPass()));
            }
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }
}
