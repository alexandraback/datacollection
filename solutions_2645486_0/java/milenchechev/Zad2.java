/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package zad2;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Formatter;
import java.util.Scanner;

/**
 *
 * @author Milen
 */
public class Zad2 {

    static long energy;
    static long maxEnergy;
    static long recovery;
    static long n;
    static long[] arr;
    static long max;
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("input.txt"));
        Formatter out = new Formatter(new File("output.txt"));
        
        int tests = in.nextInt();
        for(int test = 0 ; test < tests ; test++){
            energy = in.nextInt();
            maxEnergy = energy;
            recovery = in.nextInt();
            n = in.nextInt();
            arr = new long[(int)n];
            max = 0;
            for(int i = 0 ; i < n;i++){
                arr[i] = in.nextInt();
            }
            dfs(0,0);
            out.format("Case #%d: %d\n",test+1,max);
            
        }
        out.close();
    }
    
    public static void dfs(long sum, long level){
        if(level==n){
            if(max < sum){
                max = sum;
            }
            return;
        }     
        for(int i = 0 ; i <= energy; i++){
            long tmp = energy;
            energy-=(i-recovery);
            if(energy > maxEnergy){
                energy = maxEnergy;
            }
            dfs(sum+i*arr[(int)level],level+1);
            energy=tmp;       
        }
    }
}
