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
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Jeje
 */
public class PartElf {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException{
        FileInputStream handle = new FileInputStream("A-small-practice.in");
        FileOutputStream handle2 = new FileOutputStream("A-small-practice.out");
	BufferedReader reader = new BufferedReader(new InputStreamReader(handle));
		
        int nombreDeTests=Integer.parseInt(reader.readLine());

         for(int j=0;j<nombreDeTests;j++){
            String chaineEnCours=reader.readLine();
            String[]numEtDenom=chaineEnCours.split("/");
            long numerateur=Long.parseLong(numEtDenom[0]);
            long denominateur=Long.parseLong(numEtDenom[1]);
            
            int nvalueInt=result(numerateur,denominateur);
            
            String nvalue="";
            
            if(nvalueInt==-1){
                nvalue="impossible";
            }
            else{
                nvalue=""+nvalueInt;
            }
            
            int nouveauJ=j+1;
            handle2.write(("Case #"+nouveauJ+": "+nvalue+"\n").getBytes());  
         }
    }
    
    public static long gcm(long a, long b) {
        return b == 0 ? a : gcm(b, a % b); // Not bad for one line of code :)
    }
    
     public static int result(long numerateur,long denominateur){
         long PGCD=gcm(numerateur,denominateur);
         long vraiNumerateur=numerateur;
         long vraiDenominateur=denominateur;
         if(PGCD>1){
             vraiNumerateur=vraiNumerateur/PGCD;
             vraiDenominateur=vraiDenominateur/PGCD;
         }
         if(powerOfTwo(vraiDenominateur)==-1){
             return -1;
         }
         else{
             if(vraiNumerateur==1){
                 return powerOfTwo(vraiDenominateur);
             }
             double quotient=vraiNumerateur*1.0/vraiDenominateur;
             return getPuissanceCorrespondante(quotient);
         }
     }
     
     private static int getPuissanceCorrespondante(double unQuotient){
         if(unQuotient>0.5){
             return 1;
         }
         int puissance=0;
         while(puissance<41 && unQuotient<1.0/Math.pow(2,puissance)){
             puissance++;
         }
         return puissance;
     }
     
     private static int powerOfTwo(long number){
        long square = 1;
        int puissance=0;
        while(number >= square){
            if(number == square){
                return puissance;
            }
            square = square*2;
            puissance++;
        }
        return -1;
    }
    
}