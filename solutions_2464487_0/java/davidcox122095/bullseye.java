/*
 ID:
 LANG: JAVA
 TASK:
 */

import java.util.*;
import java.lang.*;
import java.io.*;

public class bullseye {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("bullseye.in"));
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("bullseye.out")));
        
        int numCases = Integer.parseInt(reader.readLine());
        for (int i = 1; i <= numCases; i++) {
            String[] parts = reader.readLine().split("\\s+");
            long startRadius = Integer.parseInt(parts[0]);
            long paintAmt = Integer.parseInt(parts[1]);
            
            //System.out.println("Case #" + i + ": " + solve(startRadius, paintAmt));
            writer.println("Case #" + i + ": " + solve(startRadius, paintAmt));
        }
        reader.close();
        writer.close();
    }
    
    public static int solve(long startRadius, long paintAmt) {
        
        int ringCount = 0;
        
        long prevArea = startRadius*startRadius;
        long curArea;
        long paintNeeded;
        while(true) {
            
            startRadius++;
            curArea = (startRadius)*(startRadius);
            paintNeeded = curArea - prevArea;
            if (paintAmt - paintNeeded < 0) break;
        
            ringCount++;
            paintAmt -= paintNeeded;
            startRadius++;
            prevArea = (startRadius*startRadius);
        }
        return ringCount;
        
    }
}