/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package rq2;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author Yilian Zhang
 */
public class Rq2 {

    public static int E=0;
    public static int R=0;
    public static int N=0;
    public static int[] v = new int[10];
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        // TODO code application logic here

        Scanner inFile = new Scanner(new File("B-small-attempt0.in"));
        //Scanner inFile = new Scanner(new File("file.in"));
        PrintWriter outFile = new PrintWriter(new File("outsmall.file"));
        int caseN = (int) inFile.nextInt();
        System.out.println(caseN);
        int maxG = 0;
        E = 0;
        R = 0;
        N = 0;

        // TODO code application logic here
        for (int i = 1; i < caseN + 1; i++) {
            //read file
            maxG = 0;
            E = inFile.nextInt();
            R = inFile.nextInt();
            N = inFile.nextInt();
            for (int j = 0; j < N; j++) {
                v[j] = inFile.nextInt();
            }
            if (R >= E) {
                for (int j = 0; j < N; j++) {
                    maxG += v[j]*E;
                }
            }
            else{
                    maxG = getMax(1,E,0);                  
                }
            
            
            System.out.println("Case #" + i + ": " + maxG);
            outFile.println("Case #" + i + ": " + maxG);


        }



        //close the file
        inFile.close();
        outFile.close();


    }
    
    public static int getMax(int steps, int init, int cM ) {
        int maxG=0;
        if(steps==N){
            if(init>E){
                System.out.println("over the Maximum");
                maxG = cM + E*v[N-1];
                return maxG;
            }
            else {
                maxG = cM + init*v[N-1];
                return maxG;
            }            
        }
        else if(steps<N){
            for(int es=0;es<=init; es++){
                
                int re = init-es+R;
                if (re>=E) re=E;
                int maxb = cM + es*v[steps-1];
               // System.out.println("es is "+ es+"re is "+ re);
                int temp = getMax(steps+1,re,maxb);
                if (temp > maxG) maxG = temp;
            }
            return maxG;
        }
        
        return 0 ;
    }
    
    
    
}

