import java.math.BigInteger;
import java.util.Scanner;

public class Jamcoin {
    
    public static char[] makeJam(char[] jamSeed) {
        for (int k = jamSeed.length-2; k >= 0; k--) {
            if (jamSeed[k] == '0') {
                jamSeed[k] = '1';
                return jamSeed;
            } else {
                jamSeed[k] = '0';
            }
        }
        return jamSeed;    
    }
    
    public static BigInteger divisor(BigInteger n) {
        BigInteger i = BigInteger.valueOf(2);
        while (i.multiply(i).compareTo(n) < 0) {
            if ( n.mod(i).equals(BigInteger.ZERO) )
                return i;
            i = i.add(BigInteger.ONE);
            
            if (i.compareTo(BigInteger.valueOf(1000)) > 0 )
                break;
        }
        return BigInteger.ZERO;
    }
    
    public static BigInteger interpret(String jam, int b) {
        BigInteger n = BigInteger.ZERO;
        BigInteger base = BigInteger.valueOf(b);
        for (int i=0; i < jam.length(); i++) {
            int pos = jam.length() - 1 - i;
            BigInteger coeff;
            if (jam.charAt(pos) == '1')
                coeff = BigInteger.ONE;
            else
                coeff = BigInteger.ZERO;
            BigInteger term = base.pow(i).multiply(coeff);
            n = n.add(term);
        }
        return n;
    }
    
    public static BigInteger[] prove(String jam) {
        BigInteger[] proof = new BigInteger[9];
        for (int base=2; base<11; base++) {
            BigInteger divisor = divisor(interpret(jam, base));
            if (divisor.equals(BigInteger.ZERO))
                return null;
            else
                proof[base - 2] = divisor;
        }
        return proof;
    }
    
    public static void main(String[] args) {
        
        Scanner inFile = new Scanner(System.in);
        int problems = Integer.parseInt(inFile.nextLine());
        int len = inFile.nextInt();
        int required = inFile.nextInt();
        System.out.printf("Case #1:\n");
        
        char[] jamSeed = new char[len];
        jamSeed[0] = '1';
        for (int i=1; i<len-1; i++)
            jamSeed[i] = '0';
        jamSeed[len-1] = '1';
            
        while ( required > 0 ) {
            
            BigInteger[] proof = prove(String.valueOf(jamSeed));
            if (proof != null) {
                System.out.printf("%s %s %s %s %s %s %s %s %s %s\n", 
                          String.valueOf(jamSeed), proof[0].toString(), 
                          proof[1].toString(), proof[2].toString(), 
                          proof[3].toString(), proof[4].toString(),
                          proof[5].toString(), proof[6].toString(), 
                          proof[7].toString(), proof[8].toString());                              
                required--;
            }
               
            jamSeed = makeJam(jamSeed);
        }
        inFile.close();
    }
}