package roundA;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class Bullseye {
    public static void main(String[] args) throws IOException {
        if (args.length != 2) {
            System.out.println("You should supply two file names (input and output files)");
            return;
        }
        
        new Bullseye().run(args);
    }
    
    private void run(String[] args) throws IOException {
        Scanner scan = new Scanner(new File(args[0]));
        StringBuffer writer = new StringBuffer();
        int T = scan.nextInt();
        
        for (int i=0; i<T; i++) {            
            long r = scan.nextLong();
            long t = scan.nextLong();                    
            writer.append(String.format("Case #%d: %s", i+1, solve(r, t)));
            writer.append("\n");
            scan.nextLine();
        }
        FileWriter fw = new FileWriter(args[1]);
        fw.write(writer.toString());        
        fw.close();
        
        System.out.println(writer.toString());
    }
    
    static BigInteger FOUR = new BigInteger("4");
    static BigInteger EIGHT = new BigInteger("8");

    private String solve(long r, long t) {
        // 2 * x^2 - (2*r - 1)x - t <= 0        
        long b = 2 * r - 1;
        BigInteger b_big = new BigInteger(Long.toString(b));
        BigInteger t_big = new BigInteger(Long.toString(t));
        BigInteger discriminant = sqrt(b_big.multiply(b_big).add(t_big.multiply(EIGHT)));
        //long dicriminant = b * b + 8 * t;
        //long x = (long)(((long)Math.sqrt(dicriminant) - b) / 4);
        BigInteger x = discriminant.subtract(b_big).divide(FOUR);
        return x.toString();
    }
    
    static BigInteger sqrt(BigInteger n) {
        BigInteger a = BigInteger.ONE;
        BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
        while(b.compareTo(a) >= 0) {
          BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
          if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
          else a = mid.add(BigInteger.ONE);
        }
        return a.subtract(BigInteger.ONE);
      }
}
