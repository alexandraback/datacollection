package google2013a;

import java.io.*;
import java.math.BigInteger;
import java.util.Locale;
import java.util.Scanner;
import java.util.StringTokenizer;

//------------------------------------------------------------------------------
class Calcular{
    BigInteger cuatro = new BigInteger("4");
    BigInteger cinco = new BigInteger("5");
    BigInteger dos = new BigInteger("2");
    BigInteger diez = new BigInteger("10");
    
    BigInteger calcular(BigInteger radio ,BigInteger pintura ){
        BigInteger base = new BigInteger("0");
        BigInteger tope = new BigInteger("200000000000000000000");
        BigInteger centro = null;
        
        while(base.compareTo(tope) != 1){
            centro = base.add(tope.subtract(base).divide(dos));
            BigInteger areacentro = area(centro,radio);
            //System.err.println("----------------- centro " + centro +" area " + areacentro);
            
            if (areacentro.compareTo(pintura)==0){
                return centro;
            }
            else{
                if (pintura.compareTo(areacentro)==-1){
                    tope = centro.subtract(BigInteger.ONE);
                }
                else{
                    base = centro.add(BigInteger.ONE);
                }
                
            }
            //System.err.println(base+ " " + tope + " centro " + centro +" area " + areacentro);
        }
        //System.err.println("-----------------------");
        //System.err.println(areabase + "  " + areatope);
        BigInteger areacentro = area(centro,radio);
        if (areacentro.compareTo(pintura)==1){
            centro = centro.subtract(BigInteger.ONE);
        }
        
        return centro;
    }
    BigInteger area(BigInteger n, BigInteger radio){
        BigInteger nmenos1 = n.subtract(BigInteger.ONE);
        BigInteger potencia = cuatro.multiply(nmenos1);
        BigInteger auxi = n.multiply(potencia.divide(dos));
        BigInteger total = n.multiply(dos).multiply(radio).add(n).add(auxi);
        
        return total;
    }
}
//------------------------------------------------------------------------------
public class Google2013A {
    public static void main(String[] args) throws FileNotFoundException {
        Lector lector = new Lector("A.txt");
        
        int entero = lector.sc.nextInt();
        lector.sc.nextLine();
        Calcular c = new Calcular();
                        
        for (int caso=1;caso<=entero;caso++){
            String linea = lector.sc.nextLine();
            StringTokenizer tk = new StringTokenizer(linea);
            BigInteger radio = new BigInteger(tk.nextToken().trim());
            BigInteger pintura = new BigInteger(tk.nextToken().trim());
         
            BigInteger res = c.calcular(radio,pintura);
            System.out.println("Case #" + caso+": "+res);
            System.err.println("Case #" + caso+": "+res);
        }
    }
}
//------------------------------------------------------------------------------
class Lector{
    Scanner sc;
    
    Lector(String filename) throws FileNotFoundException{
        Locale usLocale = new Locale("en", "US");
        String dir = "c:\\CodeJam2014\\";
        File f = new File(dir, filename);
        InputStream in = new FileInputStream(f);
        sc = new Scanner(in);
        sc.useLocale(usLocale);
    }
}
//------------------------------------------------------------------------------
