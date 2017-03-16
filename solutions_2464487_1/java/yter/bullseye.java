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
import java.math.MathContext;
import java.math.RoundingMode;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Grevam
 */
public class bullseye {
    public static void main(String[] params){
        
        File fIn = new File("c:\\inl.in");
        File fOut = new File("c:\\out.in");
        
        
        try{                        
            FileWriter fstreamo = new FileWriter( fOut );
            BufferedWriter out = new  BufferedWriter(fstreamo);
            Scanner scIn = new Scanner( fIn );
            
            int a = Integer.parseInt( scIn.nextLine() );
            
            for( int i=0; i<a; i++ ){ 
                String rl = scIn.nextLine();
                String[] aux = rl.split(" ");
                BigDecimal r = new BigDecimal( "" + aux[0] );
                BigDecimal t = new BigDecimal( "" + aux[1] );


                BigDecimal PI = new BigDecimal("1");

                BigDecimal _dos = new BigDecimal("2");
                BigDecimal _uno = new BigDecimal("1");



                BigDecimal maxArea = new BigDecimal("0");
                BigDecimal N = new BigDecimal( sqrt( t.multiply(new BigDecimal(0.5)).toBigInteger() ) );
                
                
                /*BigDecimal A = new BigDecimal("2");
                BigDecimal B = r.multiply(_dos ).add( new BigDecimal("-1") );
                BigDecimal C = t.multiply( new BigDecimal("-1") );

                
                BigDecimal D = bigSqrt(  B.multiply(B).add( A.multiply(C).multiply( new BigDecimal("4") ).multiply( new BigDecimal("-1") ) ) , MathContext.DECIMAL32 );
  
                BigDecimal R1 = B.multiply(new BigDecimal("-1")).add( D ).divide( A.multiply(_dos) );
                BigDecimal R2 = B.multiply(new BigDecimal("-1")).add( D.multiply(new BigDecimal("-1")) ).divide(A.multiply((_dos)));
                
                if( R1.compareTo( BigDecimal.ZERO )<0 ){
                    N = new BigDecimal( R2.toBigInteger() );
                }else{
                    N= new BigDecimal( R1.toBigInteger() );
                }*/
                
                for( ; ;  ){
                    BigDecimal currArea = N.multiply(N).multiply(_dos).add( N.multiply(_dos.multiply(r)) ).add(N.multiply(new BigDecimal("-1")));            
                    
                    BigDecimal J = new BigDecimal( N.multiply( new BigDecimal(0.5) ).toBigInteger() );
                    
                    BigDecimal currArea2 =  J.multiply(J).multiply(_dos).add( J.multiply(_dos.multiply(r)) ).add(J.multiply(new BigDecimal("-1")));            
                    
                    if( currArea2.compareTo(t)>0 ){
                        N = J;
                    }else if( currArea.compareTo(t)<=0 ){
                        break;
                    }else{                        
                        N = N.add( new BigDecimal("-1") );
                    }
                }

                //N = N.add( new BigDecimal("-1") );

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
    
     public static BigDecimal bigSqrt(BigDecimal squarD, MathContext rootMC)
  {
    // Static constants - perhaps initialize in class Vladimir!
    BigDecimal TWO = new BigDecimal(2);
    double SQRT_10 = 3.162277660168379332;


    // General number and precision checking
    int sign = squarD.signum();
    if(sign == -1)
      throw new ArithmeticException("\nSquare root of a negative number: " + squarD);
    else if(sign == 0)
      return squarD.round(rootMC);

    int prec = rootMC.getPrecision();           // the requested precision
    if(prec == 0)
      throw new IllegalArgumentException("\nMost roots won't have infinite precision = 0");

    // Initial precision is that of double numbers 2^63/2 ~ 4E18
    int BITS = 62;                              // 63-1 an even number of number bits
    int nInit = 16;                             // precision seems 16 to 18 digits
    MathContext nMC = new MathContext(18, RoundingMode.HALF_DOWN);


    // Iteration variables, for the square root x and the reciprocal v
    BigDecimal x = null, e = null;              // initial x:  x0 ~ sqrt()
    BigDecimal v = null, g = null;              // initial v:  v0 = 1/(2*x)

    // Estimate the square root with the foremost 62 bits of squarD
    BigInteger bi = squarD.unscaledValue();     // bi and scale are a tandem
    int biLen = bi.bitLength();
    int shift = Math.max(0, biLen - BITS + (biLen%2 == 0 ? 0 : 1));   // even shift..
    bi = bi.shiftRight(shift);                  // ..floors to 62 or 63 bit BigInteger

    double root = Math.sqrt(bi.doubleValue());
    BigDecimal halfBack = new BigDecimal(BigInteger.ONE.shiftLeft(shift/2));

    int scale = squarD.scale();
    if(scale % 2 == 1)                          // add half scales of the root to odds..
      root *= SQRT_10;                          // 5 -> 2, -5 -> -3 need half a scale more..
    scale = (int)Math.floor(scale/2.);          // ..where 100 -> 10 shifts the scale

    // Initial x - use double root - multiply by halfBack to unshift - set new scale
    x = new BigDecimal(root, nMC);
    x = x.multiply(halfBack, nMC);                          // x0 ~ sqrt()
    if(scale != 0)
      x = x.movePointLeft(scale);

    if(prec < nInit)                 // for prec 15 root x0 must surely be OK
      return x.round(rootMC);        // return small prec roots without iterations

    // Initial v - the reciprocal
    v = BigDecimal.ONE.divide(TWO.multiply(x), nMC);        // v0 = 1/(2*x)


    // Collect iteration precisions beforehand
    ArrayList<Integer> nPrecs = new ArrayList<Integer>();

    assert nInit > 3 : "Never ending loop!";                // assume nInit = 16 <= prec

    // Let m be the exact digits precision in an earlier! loop
    for(int m = prec+1; m > nInit; m = m/2 + (m > 100 ? 1 : 2))
      nPrecs.add(m);


    // The loop of "Square Root by Coupled Newton Iteration" for simpletons
    for(int i = nPrecs.size()-1; i > -1; i--)
    {
      // Increase precision - next iteration supplies n exact digits
      nMC = new MathContext(nPrecs.get(i), (i%2 == 1) ? RoundingMode.HALF_UP :
                                                        RoundingMode.HALF_DOWN);

      // Next x                                                 // e = d - x^2
      e = squarD.subtract(x.multiply(x, nMC), nMC);
      if(i != 0)
        x = x.add(e.multiply(v, nMC));                          // x += e*v     ~ sqrt()
      else
      {
        x = x.add(e.multiply(v, rootMC), rootMC);               // root x is ready!
        break;
      }

      // Next v                                                 // g = 1 - 2*x*v
      g = BigDecimal.ONE.subtract(TWO.multiply(x).multiply(v, nMC));

      v = v.add(g.multiply(v, nMC));                            // v += g*v     ~ 1/2/sqrt()
    }

    return x;                        // return sqrt(squarD) with precision of rootMC
  }
    
}
