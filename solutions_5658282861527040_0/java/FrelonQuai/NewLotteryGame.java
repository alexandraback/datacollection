/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package googlecodejamproject;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author Jeje
 */
public class NewLotteryGame {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException{
        FileInputStream handle = new FileInputStream("A-small-practice.in");
        FileOutputStream handle2 = new FileOutputStream("A-small-practice.out");
	BufferedReader reader = new BufferedReader(new InputStreamReader(handle));
		
        int nombreDeTests=Integer.parseInt(reader.readLine());

         for(int j=0;j<nombreDeTests;j++){
            String data=reader.readLine();
            
            String []explodedData=data.split(" ");
            
            int A=Integer.parseInt(explodedData[0]);
            int B=Integer.parseInt(explodedData[1]);
            int K=Integer.parseInt(explodedData[2]);
            
            int nvalue=result(A,B,K);
            
            int nouveauJ=j+1;
            handle2.write(("Case #"+nouveauJ+": "+nvalue+"\n").getBytes());  
         }
    }
    
     public static int result(int A,int B,int K){
         int compteur=0;
         for(int i=0;i<A;i++){
             for(int j=0;j<B;j++){
                 if((i&j)<K){
                     compteur++;
                 }
             }
         }
         return compteur;
    }
    
}