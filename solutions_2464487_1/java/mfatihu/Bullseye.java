import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

public class Bullseye {

    PrintWriter result;
    int T;
    String rS;
    String tS;
    //int r;
    //int t;
    BigInteger r;
    BigInteger t;

    Bullseye() throws IOException {

        result = new PrintWriter(new FileWriter("result"));
    }

    BigInteger sqrtbi(BigInteger n) {
        BigInteger a = BigInteger.ONE;
        BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
        while(b.compareTo(a) >= 0) {
            BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
            if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
            else a = mid.add(BigInteger.ONE);
        }
        return a.subtract(BigInteger.ONE);
    }

    void solveDeep(BigInteger r, BigInteger t, int k) {



        BigInteger cozum = new BigInteger("0");

        BigInteger delta = r.pow(2).multiply(new BigInteger("4")).
                add(new BigInteger("1")).
                subtract(r.multiply(new BigInteger("4"))).
                add(t.multiply(new BigInteger("8")));

        BigInteger kokdelta = sqrtbi(delta);

        BigInteger eksibe = new BigInteger("1").
                subtract(r.multiply(new BigInteger("2")));

        if(eksibe.add(kokdelta).compareTo(new BigInteger("0")) == -1) {

            cozum = eksibe.subtract(kokdelta).divide(new BigInteger("4"));
        }
        else {

            cozum = eksibe.add(kokdelta).divide(new BigInteger("4"));
        }

        result.println("Case #" + k + ": " + cozum);
    }

    void solve() throws FileNotFoundException {

        File input = new File("input");
        Scanner scanner = new Scanner(input);

        T = scanner.nextInt();

        for(int c=1; c<= T; c++) {

            rS = scanner.next();
            tS = scanner.next();
            r = new BigInteger(rS);
            t = new BigInteger(tS);

            solveDeep(r,t,c);
        }
    }

    public static void main(String[] args) throws IOException {

        Bullseye bull = new Bullseye();

        bull.solve();

        bull.result.close();
    }

}
