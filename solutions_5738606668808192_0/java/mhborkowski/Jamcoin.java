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
    
    public static long divisor(long n) {
        long i = 2;
        while (i * i < n) {
            if ( n % i == 0 )
                return i;
            i++;
        }
        return -1;
    }
    
    public static long interpret(String jam, int b) {
        long n = 0;
        for (int i=0; i < jam.length(); i++) {
            int pos = jam.length() - 1 - i;
            int d = Character.digit(jam.charAt(pos), 10);
            n = n + d * ((long) Math.pow(b, i));
        }
        return n;
    }
    
    public static long[] prove(String jam) {
        long[] proof = new long[9];
        for (int base=2; base<11; base++) {
            long divisor = divisor(interpret(jam, base));
            if (divisor == -1)
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
            
            long[] proof = prove(String.valueOf(jamSeed));
            if (proof != null) {
                System.out.printf("%s %d %d %d %d %d %d %d %d %d\n", 
                          String.valueOf(jamSeed),
                          proof[0], proof[1], proof[2], proof[3], proof[4],
                          proof[5], proof[6], proof[7], proof[8]);                              
                required--;
            }
               
            jamSeed = makeJam(jamSeed);
        }
        inFile.close();
    }
}