import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;


public class PartElf {
	
	public static void main(String[] args) throws IOException {
		System.out.println(args[0]);
		System.out.println(args[1]);
		
		Set<BigInteger> powersOfTwo = new HashSet<BigInteger>();
		long i =1;
		powersOfTwo.add(new BigInteger(Long.toString(i)));
		for(int j=0; j<39; j++) {
			i*=2;
			powersOfTwo.add(new BigInteger(Long.toString(i)));
		}
		
		Scanner s = new Scanner(new File(args[0]));
		File out = new File(args[1]);
		if(!out.exists()) {
			out.createNewFile();
		} else {
			out.delete();
			out.createNewFile();
		}
		FileWriter fw = new FileWriter(out);
		
		int numCases = s.nextInt();
		for(int j=1; j<=numCases; j++) {
			String fraction = s.next();
			String[] fractionParts = fraction.split("/");
			BigInteger num = new BigInteger(fractionParts[0]);
			BigInteger den = new BigInteger(fractionParts[1]);
			
			BigInteger gcd = num.gcd(den);

			while(gcd.compareTo(BigInteger.ONE) != 0) {
				num = num.divide(gcd);
				den = den.divide(gcd);
				gcd = num.gcd(den);
			}
			
			if(!powersOfTwo.contains(den)) {
				fw.write("Case #"+j+": impossible\n");
				continue;
			}
			
			BigInteger two = new BigInteger("2");
			
			int count = 0;
			while(num.compareTo(den) < 0) {
				num = num.multiply(two);
				count++;
			}
			
			fw.write("Case #"+j+": " + count +"\n");
			
		}
		fw.close();
	}

}
