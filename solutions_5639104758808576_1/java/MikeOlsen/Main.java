package jam;

import java.io.*;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    static String inputfile = "qual_a_small.in";
    static String outputfile = "qual_a_small.out";
    static String answer;
    static BufferedWriter writer;
    static Scanner scanner;

    public static void writeAnswer(int caseNum) throws Exception {
        System.out.println("Case #" + caseNum + ": " + answer);
        writer.write("Case #" + caseNum + ": " + answer);
        writer.newLine();
    }

    public static void main(String[] args) throws Exception {
        scanner = new Scanner(new File(inputfile));
        writer = new BufferedWriter(new FileWriter(outputfile));

        //Case loop:
        int numCases = scanner.nextInt();
        for(int caseNum = 1; caseNum <= numCases; caseNum++) {
            answer = "";
            solve();
            writeAnswer(caseNum);
        }

        //Cleanup:
        scanner.close();
        writer.close();
    }

    public static void solve() {
        // get input from scanner
        // write answer to answer
        int numAudience = scanner.nextInt();
        String audienceString = scanner.next();
        int numFriends = 0;
        int peopleSoFar = 0;

        for(int shyLevel = 0; shyLevel < numAudience; shyLevel++) {
            int curPeopleCount = Short.parseShort(String.valueOf(audienceString.charAt(shyLevel)));

            // <shyLevel> people required in peopleSoFar
            if(peopleSoFar < shyLevel) {
                numFriends += shyLevel - peopleSoFar;
                curPeopleCount += shyLevel - peopleSoFar;
            }
            else if(curPeopleCount == 0 && peopleSoFar == shyLevel) {
                numFriends++;
                curPeopleCount++;
            }

            // the question is, how many friends needed to make curPeopleCount stand?

            peopleSoFar += curPeopleCount;
        }

        answer = String.valueOf(numFriends);
    }
}