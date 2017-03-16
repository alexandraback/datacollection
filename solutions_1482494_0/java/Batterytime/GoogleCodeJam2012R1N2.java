/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam2012;

import java.io.*;
import java.util.HashSet;

/**
 *
 * @author Stephen
 */
public class GoogleCodeJam2012R1N2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try 
        {
            FileInputStream fs = new FileInputStream("input.txt");
            DataInputStream in = new DataInputStream(fs);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            FileWriter fws = new FileWriter("output.txt");
            BufferedWriter out = new BufferedWriter(fws);
            String numLine = br.readLine();
            System.out.println(numLine);
            int numCases = Integer.parseInt(numLine);
            String caseLine;
            for(int i = 1; i <= numCases; i++)
            {
                caseLine = br.readLine();
                System.out.println("Case #"+i);
                int N = Integer.parseInt(caseLine);
                int[] oneStarReq = new int[N];
                int[] twoStarReq = new int[N];
                int[] starsEarned = new int[N];
                for(int j = 0; j < N; j++) {
                    caseLine = br.readLine();
                    String[] splitted = caseLine.split(" ");
                    oneStarReq[j] = Integer.parseInt(splitted[0]);
                    twoStarReq[j] = Integer.parseInt(splitted[1]);
                    starsEarned[j] = 0;
                }
                int currStars = 0;
                int numLevels = -1;
                boolean gameOver = false;
                boolean failed = false;
                boolean didALevel = false;
                while(!gameOver) {
                    didALevel = false;
                    numLevels++;
                    for(int j = 0; j < N; j++) {
                        if(starsEarned[j] == 0 && twoStarReq[j] <= currStars) {
                            currStars += 2;
                            starsEarned[j] = 2;
                            didALevel = true;
                            break;
                        }
                    }
                    if(didALevel)
                        continue;
                    for(int j = 0; j < N; j++) {
                        if(starsEarned[j] == 1 && twoStarReq[j] <= currStars) {
                            currStars ++;
                            starsEarned[j] = 2;
                            didALevel = true;
                            break;
                        }
                    }
                    if(didALevel)
                        continue;
                    int bestLevel = 0;
                    int highestTwoStar = 0;
                    for(int j = 0; j < N; j++) {
                        if(starsEarned[j] == 0 && oneStarReq[j] <= currStars) {
                            if(twoStarReq[j] > highestTwoStar) {
                                bestLevel = j;
                                highestTwoStar = twoStarReq[j];
                            }
                            didALevel = true;
                        }
                    }
                    if(didALevel) {
                        currStars++;
                        starsEarned[bestLevel] = 1;
                    }
                    gameOver = !didALevel;
                }
                for(int j = 0; j < N; j++) {
                    if(starsEarned[j] != 2) {
                        failed = true;
                        break;
                    }
                }
                if(failed)
                    out.write("Case #"+i+": Too Bad\r\n");
                else
                    out.write("Case #"+i+": "+numLevels+"\r\n");
            }
            in.close();
            out.close();
            
            displayOutput();
        } 
        catch (Exception e) 
        {
            System.err.println("Oops! Error occured: " + e.getMessage());
        }
    }
    
    public static void displayOutput()
    {
        System.out.println("START OUTPUT\n-------------------");
        try
        {
            FileInputStream fs = new FileInputStream("output.txt");
            DataInputStream in = new DataInputStream(fs);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            String readLine;
            while ((readLine = br.readLine()) != null)   {
                System.out.println(readLine);
            }
        }
        catch (Exception e) 
        {
            System.err.println("Oops! Error occured: " + e.getMessage());
        }
        System.out.println("---------------------\nEND OUTPUT");
    }
}
