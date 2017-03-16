
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author psergiol
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    
    public static String reverse(String s){
	String t = "";
        int i;
        for(i = s.length()-1; i >= 0; i--)
            t += s.charAt(i);
	return t;
    }
    
    public static boolean is_palin(String s){
        int i, j;
        for(i = s.length()-1, j = 0; j < i; i--, j++)
            if(s.charAt(i) != s.charAt(j))
                return false;
	return true;
    }
        
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        int i, j, k, l, n, cont, ans = 0;
        String a, b;
        String[] val = new String[10];
        Scanner cin = new Scanner(System.in);
        BigInteger[] v = new BigInteger[1000];
        BigInteger c, d;
        v[0] = BigInteger.ONE;
        v[1] = new BigInteger("4");
        v[2] = new BigInteger("9");
        cont = 3;
        for(i = 0; i < 10; i++)
            val[i] = String.valueOf(i);
        for(i = 1; i < 10000000; i++){
            a = String.valueOf(i);
            b = reverse(a);
            d = new BigInteger(a+b);
            d = d.multiply(d);
            if(d.toString().length()>16)
                break;
            if(is_palin(d.toString())){
                v[cont] = d;
//                System.out.println(v[cont]+" "+d);
                cont++;
            }
            for(k = 0; k < 10; k++){                
                d = new BigInteger(a+val[k]+b);
                d = d.multiply(d);
                if(is_palin(d.toString())){
                    v[cont] = d;
//                    System.out.println(v[cont-1]+" "+d);
                    cont++;
                }
            }
        }
//        System.out.println("Acabo "+ cont);
        n = cin.nextInt();
        for(k = 1; k <= n; k++){
            a = cin.next();
            b = cin.next();
            c = new BigInteger(a);
            d = new BigInteger(b);
            ans = 0;
            for(l = 0; l < cont; l++){
                if(c.compareTo(v[l]) <= 0 && v[l].compareTo(d) <= 0){
                    ans++;
                }
            }
            System.out.println("Case #"+k+": "+ans);
        }
    }
}
