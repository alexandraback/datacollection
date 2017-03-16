/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam2012_sum_brute;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
/**
 *
 * @author Manos
 */
public class CodeJam2012_Sum_brute {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            int T;
            int N;
            
            int numbers[];
            
            BufferedReader rdr = new BufferedReader(new InputStreamReader(System.in));
            T=Integer.parseInt(rdr.readLine());
            for (int i=1; i <= T; i++){
                String line = rdr.readLine();
                String [] linePcs = line.split(" ");
                N = Integer.parseInt(linePcs[0]);
                
                numbers = new int[N];
                for (int j = 0; j<N; j++){
                    numbers[j] = Integer.parseInt(linePcs[j+1]);
                }
                
                int sums[] = new int [(int)Math.pow(2, N)];
                
                int Npow2 = sums.length;
                for (int j = 0; j < Npow2 ; j++){
                    sums[j]=0;
                    int ptr = j;
                    for (int k = 0; k<N; k++){
                        if (ptr%2==1){
                            sums[j]+=numbers[k];
                        }
                        ptr/=2;
                    }
                }
                
                boolean found = false;
                int sum = 0;
                int original []= new int[Npow2];
                System.arraycopy(sums, 0, original, 0, Npow2);
                Arrays.sort(sums);
                for (int j = 1; j < Npow2-1 ; j++){
                    if (sums[j]== sums[j+1]){
                        found = true;   
                        sum = sums[j];
                        break;
                    }
                }
                System.out.println("Case #" + i + ":");
                if (!found){
                     System.out.println("Impossible");
                }
                
                else {
                    
                    int j ;
                    for (j = 0; j < Npow2-1 ; j++){
                        if (original[j]==sum){
                            int ptr = j;
                            for (int k = 0; k<N; k++){
                                if (ptr%2==1){
                                    System.out.print(numbers[k]+" ");
                                }
                                ptr/=2;
                            }
                            break;
                        }
                    }
                    System.out.println();
                    for (j++; j < Npow2-1 ; j++){
                        if (original[j]==sum){
                            int ptr = j;
                            for (int k = 0; k<N; k++){
                                if (ptr%2==1){
                                    System.out.print(numbers[k]+" ");
                                }
                                ptr/=2;
                            }
                            break;
                        }
                    }
                    System.out.println();
                }
                
                
                
            }         
        }
        catch (IOException | NumberFormatException e){
            
        }
    }
}
