/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejamsamples;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author Grevam
 */
public class bullseye {
    public static void main(String[] params){
        
        File fIn = new File("c:\\in.in");
        File fOut = new File("c:\\out.in");
        
        
        try{                        
            FileWriter fstreamo = new FileWriter( fOut );
            BufferedWriter out = new  BufferedWriter(fstreamo);
            Scanner scIn = new Scanner( fIn );
            
            int a = scIn.nextInt();
            
            for( int i=0; i<a; i++ ){                                                  
                BigDecimal r = new BigDecimal( "" + scIn.nextInt() );
                BigDecimal t = new BigDecimal( "" + scIn.nextInt() );


                BigDecimal PI = new BigDecimal("1");

                BigDecimal _dos = new BigDecimal("2");
                BigDecimal _uno = new BigDecimal("1");



                BigDecimal maxArea = new BigDecimal("0");
                BigDecimal N = new BigDecimal("1");

                for( ; ;  ){
                    BigDecimal currArea = N.multiply(N).multiply(_dos).add( N.multiply(_dos.multiply(r)) ).add(N.multiply(new BigDecimal("-1")));            

                    if( currArea.compareTo(t)>0 ){
                        break;
                    }else{
                        N = N.add(_uno);
                    }
                }

                N = N.add( new BigDecimal("-1") );

                if( N.equals(BigDecimal.ZERO) ){
                    N=_uno;
                }
                
                 out.write( "Case #"  +  (i+1) + ": " +  N.toString()  );
                 
                 if( i<a-1 ){
                    out.write( "\r\n" );
                }
                 System.out.println("N=" + N.toString());
            }

            out.close();
            
        }catch(Exception ex){
            int g=1;
        }
            
        
        /**/
        
        
          /*BigDecimal A = new BigDecimal("2");
        BigDecimal B = r.multiply(_dos ).add( new BigDecimal("-1") );
        BigDecimal C = t.multiply( new BigDecimal("-1") );
        
        BigDecimal D = Math.sqrt( B.multiply(B).add( A.multiply(C).multiply( new BigDecimal("4") ).multiply( new BigDecimal("-1") ) ) );
        
        BigInteger R1 = */
            
    }
    
    public static BigInteger sqrt(BigInteger n) {
        BigInteger a = BigInteger.ONE;
        BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
        while(b.compareTo(a) >= 0) {
            BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
            if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
            else a = mid.add(BigInteger.ONE);
        }
        BigInteger res = a.subtract(BigInteger.ONE);
        
       
        
        return res;
   }
    
}
