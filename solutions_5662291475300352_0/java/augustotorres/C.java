/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package codejam;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author astorres
 */
public class C {

    public static final String rutaDatos = "C:\\Users\\astorres\\Desktop\\CodeJam\\";
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        String problem = "C";
        //String input=problem+"-sample.in";
        String input=problem+"-small-1-attempt0.in";
        //String input=problem+"-large.in";
        Scanner in = new Scanner(new File(rutaDatos+input));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(rutaDatos+"out\\"+input+".out.txt")));

        int D[] = new int[2];
        int S[] = new int[2];
        double M[] = new double[2];
        int nh;
        
        int T = in.nextInt();
        for(int i=0;i<T;i++) {
            
            /*********************************/
            int res=0;
            int N = in.nextInt();
            nh=0;
            for(int j=0;j<N;j++) {
                int a = in.nextInt();
                int b = in.nextInt();
                int c = in.nextInt();
                for(int k=0;k<b;k++)
                {
                    D[nh+k]=a;
                    S[nh+k]=c+k;
                }
                nh+=b;
            }
            
            if(nh<=1) res=0;
            else {
                M[0] = (double)S[0]*(360-(double)D[0])/360f;
                M[1] = (double)S[1]*(360-(double)D[1])/360f;
                if(D[0]>=D[1]) {
                    //System.out.println(M[1]+" - "+M[0]);
                     if(M[1]<M[0]) {
                        if(M[0]+S[0]<M[1]) res=0;
                        else res=1;
                    } else {
                        if(M[0]+S[0]>M[1]) res=0;
                        else res=1;
                    }
                } else {
                    if(M[0]<M[1]) {
                        if(M[1]+S[1]<M[0]) res=0;
                        else res=1;
                    } else {
                        if(M[1]+S[1]>M[0]) res=0;
                        else res=1;
                    }
                }
            }
            
            /*********************************/
            
            System.out.println("Case #"+(i+1)+": "+res);
            out.println("Case #"+(i+1)+": "+res);
        }
        out.close();
    }
    
}
