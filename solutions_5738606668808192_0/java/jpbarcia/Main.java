

import java.math.BigInteger;
import java.util.*;


public class Main {

    public static boolean debug = true;
    public static List<String> ls; 
    public static StringBuilder  number;
    public static int N = 16;
    public static int J = 50;
    public static void Rec(int pos) {
        if(pos >= (N-1)) {
            ls.add(number.toString());
            //if(debug)
                //System.out.println(ls.size());
            return;
        }
        if(ls.size() > 3000000)
            return;
        Rec(pos+1);
        number.setCharAt(pos, '1');
        Rec(pos+1);
        number.setCharAt(pos, '0');
        
        
    }
    
    public static BigInteger toBase(BigInteger a, int b) {
        BigInteger base = new BigInteger(String.valueOf(b));
        BigInteger ans = new BigInteger("0");
        BigInteger cont = new BigInteger("1");
        while(true) {
        
            if(a == BigInteger.ZERO)
                return ans;
            BigInteger temp = a.mod(new BigInteger("10"));
            ans = ans.add( (temp).multiply(cont) );
            
            a = a.divide(new BigInteger("10"));
            
            cont = cont.multiply(base);
        }
        
    }
    
    public static BigInteger FirstDiv(BigInteger a) {
        for(BigInteger i = new BigInteger("2"); i.compareTo(a) == -1; i = i.add(BigInteger.ONE)) {
            if((a.mod(i)).compareTo(BigInteger.ZERO) == 0)
                return i;
        }
        return a;
    }
    
    public static void main(String[] args) {
        
        String tempstr = new String("1");
        for(int i = 0; i < N-2; i++)
            tempstr = tempstr.concat("0");
        tempstr = tempstr.concat("1");
        number = new StringBuilder(tempstr);
        ls = new ArrayList<>();
        List<BigInteger> ans = new ArrayList<>();
        Rec(1);
        int cont = 0;
        boolean noEs = false;
        System.out.println("asd");
        int index = 0;
        while(cont < J) {
            noEs = false;
            //if((new BigInteger(ls.get(index))).isProbablePrime(cont*123)) 
                //noEs = true;
            for(int i = 2; i < 11; i++) {
                if(debug)
                    System.out.println("i: " + i + ", cont: " + cont);
                Random f = new Random(i*cont+i);
                int cert = f.nextInt(10000000);
                BigInteger temp = toBase( new BigInteger(ls.get(index)), i);
                if(debug)
                    System.out.println(temp);
                if(temp.isProbablePrime(cert) || noEs) {
                    noEs = true;
                    break;
                }
                
            }
            index++;
            if(noEs) {
                if(debug)
                    System.out.println("No es: " + ls.get(index-1));
                continue;
            }
            ans.add(new BigInteger(ls.get(index-1)));
            if(debug) 
                System.out.println("nuevo :" +ls.get(index-1));
            cont++;
        }
        System.out.println("*********RESPUESTAS********");
        for(int i = 0; i < cont; i++) {
            BigInteger tempn = ans.get(i);
            System.out.print(ans.get(i).toString());
            for(int k = 2; k <= 10; k++)
                System.out.print(" " + FirstDiv(toBase(tempn, k)));
            System.out.print("\n");
        }
        
        
        
    }
    
    
    
}
