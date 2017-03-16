/*
 ID:
 LANG: JAVA
 TASK:
 */

import java.util.*;
import java.lang.*;
import java.io.*;

public class manageEnergy {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("energy.in"));
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("energy.out")));
        
        int numCases = Integer.parseInt(reader.readLine());
        
        for (int i = 1; i <= numCases; i++) {
            String[] parts = reader.readLine().split("\\s+");
            long energy = Long.parseLong(parts[0]);
            long regain = Long.parseLong(parts[1]);
            int numAct = Integer.parseInt(parts[2]);
            long[] values = new long[numAct];
            parts = reader.readLine().split("\\s+");
            for (int k = 0; k < values.length; k++) {
                values[k] = Long.parseLong(parts[k]);
            }
            
            //System.out.println("Case #" + i + ": " + solve(energy, energy, regain, values, 0));
            writer.println("Case #" + i + ": " + solve(energy, energy, regain, values, 0));
                        
        }
        writer.close();
        reader.close();
    }
    
    
    public static long solve(long maxE, long energy, long regain, long[] values, int pos) {
        
        if (pos >= values.length)
            return 0;
        
        long gain = 0;
        for (int i = 0; i <= energy; i++) {
            long newEnergy = energy - i + regain;
            
            if (newEnergy > maxE) newEnergy = maxE;
            
            if (newEnergy < 0) {
                //System.out.println("LOWER THAN 0");
                continue;
            }
            gain = Math.max(solve(maxE, newEnergy, regain, values, pos+1) + i * values[pos], gain);
        }
        return gain;
        
    }
}