import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class Round1A2013Q1 {

	public static void main(String[] args) throws Exception {
		Scanner reader = new Scanner(new File("A-large.in.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("Alarge.txt"));
		int cases = Integer.parseInt(reader.nextLine());
		int count = 1;
		long start = System.currentTimeMillis();
		while (cases >= count) {
			String[] line = reader.nextLine().split(" ");
			BigInteger startradius = new BigInteger(line[0]);
			BigInteger paint = new BigInteger(line[1]);
			BigInteger rhsfirst = paint.divide(new BigInteger("2"));
			BigInteger rhssecond = startradius.multiply(new BigInteger("2")).subtract(BigInteger.ONE);
			rhssecond = rhssecond.pow(2);
			rhssecond = rhssecond.divide(new BigInteger("16"));
			BigInteger rhs = rhsfirst.add(rhssecond);
			BigInteger lhs = findsqrt(rhs);
			BigInteger lhssecond = startradius.multiply(new BigInteger("2")).subtract(BigInteger.ONE);
			lhssecond = lhssecond.divide(new BigInteger("4"));
			BigInteger result = lhs.subtract(lhssecond);
			while(true) {
				BigInteger paintcost = result.pow(2).multiply(new BigInteger("2"));
				paintcost = paintcost.subtract(result);
				BigInteger paintcostsecond = result.multiply(new BigInteger("2")).multiply(startradius);
				paintcost = paintcost.add(paintcostsecond);
				if(paintcost.compareTo(paint) > 0) {
					result = result.subtract(BigInteger.ONE);
					break;
				}
				else
					result = result.add(BigInteger.ONE);
			}
			pw.println("Case #" + count + ": " + result);
			System.out.println("Case #" + count + ": " + result);
			count++;
		}
		long end = System.currentTimeMillis();
		System.out.println((end - start) / 1000);
		pw.close();	
	}
	
	public static BigInteger findsqrt(BigInteger number) {
		BigInteger result = newtonnext(BigInteger.ONE, number);
		while(true) {
			BigInteger next = newtonnext(result, number);
			if(!(next.compareTo(result) < 0))
				break;
			result = next;
		}
		result = result.subtract(BigInteger.ONE);
		return result;
	}
	
	public static BigInteger newtonnext(BigInteger number, BigInteger sqrt) {
		return sqrt.divide(number).add(number).divide(new BigInteger("2"));
	}

}
