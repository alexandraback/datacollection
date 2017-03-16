import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;


public class Bullseye {
	
	public static void main(String[] args) throws IOException {
		File inputFile = new File("E:\\Code-Jam\\Bullseye\\A-large.in");
		File outputFile = new File("E:\\Code-Jam\\Bullseye\\A-large.out");
		BufferedReader reader = new BufferedReader(new FileReader(inputFile));
		BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile));
		int noOfTestCases = Integer.parseInt(reader.readLine());
		for (int i = 1; i <= noOfTestCases; i++) {
			String[] inputs = reader.readLine().split(" ");
			String line = "Case #" + i + ": " + getNoOfRingsDrawn(inputs[0], inputs[1]) + "\n";
			writer.write(line);
		}
		reader.close();
		writer.close();
	}

	
	private static String getNoOfRingsDrawn(String input1, String input2) {
		BigInteger initialRadius = new BigInteger(input1);
		BigInteger paintQty = new BigInteger(input2);
		BigInteger two = new BigInteger("2");
		BigInteger four = new BigInteger("4");
		BigInteger eight = new BigInteger("8");
		
		//Quad Equation
		BigInteger partA = (BigInteger.ONE).subtract(two.multiply(initialRadius));
		BigInteger fourR = four.multiply(initialRadius);
		BigInteger fourR2 = fourR.multiply(initialRadius);
		BigInteger partB = fourR2.subtract(fourR).add(BigInteger.ONE).add(eight.multiply(paintQty));
		BigInteger sqrtNum = sqrt(partB);
		BigInteger result = partA.add(sqrtNum).divide(four);
		
		return result.toString();
	}
	
	private static BigInteger sqrt(BigInteger number) {
		  BigInteger a = BigInteger.ONE;
		  BigInteger b = new BigInteger(number.shiftRight(5).add(new BigInteger("8")).toString());
		  while(b.compareTo(a) >= 0) {
		    BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
		    if(mid.multiply(mid).compareTo(number) > 0) b = mid.subtract(BigInteger.ONE);
		    else a = mid.add(BigInteger.ONE);
		  }
		  return a.subtract(BigInteger.ONE);
		}

}
