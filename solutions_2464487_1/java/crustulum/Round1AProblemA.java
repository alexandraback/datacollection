import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;


public class Round1AProblemA {

	  public static BigInteger sqrt(BigInteger n) {
		    BigInteger a = BigInteger.ONE;
		    BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
		    while(b.compareTo(a) >= 0) {
		      BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
		      if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
		      else a = mid.add(BigInteger.ONE);
		    }
		    return a.subtract(BigInteger.ONE);
		  }
	  
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);
		int T =  Integer.parseInt(sc.nextLine());
		int Case = 1;
		PrintStream out;
		out = new PrintStream(new FileOutputStream("1AoutputA.txt"));
		while(Case <= T){
			String s = sc.nextLine();
			String [] rt = s.split(" ");
			BigInteger r = new BigInteger(rt[0]);
			BigInteger t = new BigInteger(rt[1]);
			BigInteger two = new BigInteger("2");
			BigInteger eight = new BigInteger("8");
			BigInteger b = two.multiply(r).subtract(BigInteger.ONE);
			BigInteger p = (sqrt((b.multiply(b)).add(eight.multiply(t))));
			BigInteger a = (((BigInteger.ONE.subtract(two.multiply(r))).add(p)).divide(new BigInteger("4")));
			out.println("Case #" + Case + ": " + a);
			Case++;
		}
		System.setOut(out);
	}

}
