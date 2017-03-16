/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam2012_safety;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
/**
 *
 * @author Manos
 */
public class CodeJam2012_Safety {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
         try {
            int T;
            int N;
            ArrayList<Double> judgeScores;
            double tempList[];
            
            BufferedReader rdr = new BufferedReader(new InputStreamReader(System.in));
            T=Integer.parseInt(rdr.readLine());
            for (int i=1; i <= T; i++){
                String line = rdr.readLine();
                String [] linePcs = line.split(" ");
                N = Integer.parseInt(linePcs[0]);
                
                tempList = new double[N];
                for (int j = 0; j<N; j++){
                    tempList[j]=Double.parseDouble(linePcs[j+1]);
                }
                
                double sum = 0.0;
                for (int j = 0; j<N; j++ ){
                    sum+= tempList[j];
                }
                for (int j = 0; j<N; j++ ){
                    tempList[j]/=sum;
                }
                
                double originalList[]= new double[N];
                System.arraycopy(tempList, 0, originalList, 0, N);            
                Arrays.sort(tempList);
              
                double safeScore= tempList[0], usedSum = 0;
                
                for (int j=1; j<N; j++){
                    if ( j*(tempList[j]-tempList[j-1]) < 1-usedSum ){
                        usedSum+=j*(tempList[j]-tempList[j-1]);
                        safeScore = tempList[j];
                    }
                    else {
                        safeScore+= (1-usedSum)/j;
                        usedSum =1;
                        break;
                    }
                        
                }
                
                if (usedSum<1){
                    safeScore += (1-usedSum)/N;
                }
                
                System.out.print("Case #" + i + ": ");
                
                for (int j=0; j<N; j++){
                    System.out.print((Math.max((safeScore- originalList[j])*100.0,0))+" ");
                }
                System.out.println();
                
            }
            
        } catch (IOException ex) {
            System.out.println ("CodeJam is bugged!!!");
        }
    
    }
}
