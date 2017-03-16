/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam.Round1B;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

/**
 *
 * @author Rondrer
 */
public class Osmos {
    
    public static void main(String[] args) throws IOException {
        String filename = "input/A-large.in";
        BufferedReader reader = new BufferedReader(new FileReader(filename));
        BufferedWriter writer = new BufferedWriter(new FileWriter(filename.substring(0, filename.length()-3)+ ".out"));
        
        int T = Integer.parseInt(reader.readLine());
        for (int i = 0; i < T; i++) {
            String[] line = reader.readLine().split(" ");
            int A = Integer.parseInt(line[0]);
            int N = Integer.parseInt(line[1]);
            
            ArrayList<Integer> list = new ArrayList<>(N);
            
            line = reader.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                list.add(Integer.parseInt(line[j]));           
            }
            Collections.sort(list);
                        
            writer.write("Case #" + (i+1) + ": " + howManySteps(list, A, N)+ "\n");
        }
        writer.flush();
    }

    private static int howManySteps(ArrayList<Integer> list, int A, int N) {
        int steps = 0;
        int size = A;
        ArrayList<Integer> deleteList = new ArrayList<>(N);
        
        for (int i = 0; i < N; i++) {
            int mote = list.get(i);
            if (mote < size) {
                size += mote;
                continue;
            }
            deleteList.add(N - i + steps);
            int tempsize = size;
            int j = 0;
            while (mote >= tempsize)
            {
                tempsize += tempsize -1;
                j++;
                if (j > N - i) {
                    break;
                }
            }

            size = tempsize;
            size += mote;
            steps += j;
            
            
       
            
            
        }
        if (deleteList.isEmpty()) return steps;
        int minDelete = Collections.min(deleteList);
        return Math.min(minDelete, steps);
    }
    
}
