import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;


public class Main {
	
	static BigInteger paint;
	
	public static void main (String[] args) {
		
		BufferedReader br;
		try {
			File outputFile = new File("src/output.txt");
			// if file doesnt exists, then create it
			if (!outputFile.exists()) {
				outputFile.createNewFile();
			}
			FileWriter fw = new FileWriter(outputFile.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);
			br = new BufferedReader(new FileReader("src/A-large.in"));

			String line = br.readLine();
			
			int numberOfTestCase = Integer.parseInt(line);
			for (int i = 0; i < numberOfTestCase; i++) {
				System.out.println(i);
				String boundsString = br.readLine();
				String[] boundsInt = boundsString.split(" ");
				
				BigInteger radius = new BigInteger(boundsInt[0]);
				paint = new BigInteger(boundsInt[1]);

				BigInteger numberOfRings = calculateResult(radius, paint);
				
				int caseNumber = i + 1;
				bw.write("Case #" + caseNumber + ": " + numberOfRings);
				bw.newLine();
			}
			bw.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static BigInteger calculateResult (BigInteger radius, BigInteger paint) {
		BigInteger areaOfCurrLv = new BigInteger("0");
		BigInteger sum = new BigInteger("0");
		BigInteger level = new BigInteger("1");
		
		BigInteger a1 = radius.multiply(new BigInteger("2")).add( new BigInteger("1") );
		
		return findN (a1, new BigInteger("1"), paint);
	}
	
	public static BigInteger findN (BigInteger a1, BigInteger min, BigInteger max) {// 1 to max
		BigInteger toReturn = null;
		BigInteger n1 = min;
		if ( min.add(new BigInteger("100")).compareTo(max) > 0 ) {
			BigInteger n2 = min.add(new BigInteger("1"));
			
			while(true) {
				BigInteger rhs1 = a1.add(n1.multiply(new BigInteger("2"))).add(new BigInteger("-2")).multiply(n1);
				BigInteger rhs2 = a1.add(n2.multiply(new BigInteger("2"))).add(new BigInteger("-2")).multiply(n2);
				if ( paint.compareTo(rhs1) >= 0 && paint.compareTo(rhs2) < 0) {
					toReturn = n1;
					break;
				}
				
				n1 = n1.add(new BigInteger("1"));
				n2 = n2.add(new BigInteger("1"));
			}
		} else {
			BigInteger mid = min.add(max).divide(new BigInteger("2"));
			BigInteger rhs = a1.add(mid.multiply(new BigInteger("2"))).add(new BigInteger("-2")).multiply(mid);
			
			if (paint.compareTo(rhs) > 0) {
				toReturn = findN (a1, mid, max);
			} else if (paint.compareTo(rhs) == 0) {
				toReturn = mid;
			}	else {
				toReturn = findN (a1, min, mid);
			} 
		}
		return toReturn;
	}
}
