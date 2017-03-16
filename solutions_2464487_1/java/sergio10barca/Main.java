
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
    
    public static BigInteger r = BigInteger.ONE;
    public static BigInteger dos = new BigInteger("2");
    public static int tam = 0;
    
    public static BigInteger required(BigInteger valor){
        BigInteger tot = r.multiply(dos);
        tot = tot.add((valor.subtract(BigInteger.ONE)).multiply(dos));
        tot = tot.add(BigInteger.ONE);
	return valor.multiply(tot);
    }

    public static BigInteger solve(BigInteger t){
        int valor;
	BigInteger inf = BigInteger.ZERO;
        BigInteger sup = t;
        BigInteger resp, mitad;
	while(inf.compareTo(sup)<= 0){
		mitad = inf.add((sup.subtract(inf)).divide(dos));
		resp = required(mitad);
                if((valor = resp.compareTo(t)) == 0)
                    return mitad;
                else if(valor < 0)
                        inf = mitad.add(BigInteger.ONE);
                else
                        sup = mitad.subtract(BigInteger.ONE);
	}
	return sup;
}
        
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        int k, casos;
        BigInteger t;
        Scanner cin = new Scanner(System.in);        
        casos = cin.nextInt();
        for(k = 1; k <= casos; k++){
            r = cin.nextBigInteger();
            t = cin.nextBigInteger();
            System.out.println("Case #"+k+": "+solve(t));
        }
    }
}
