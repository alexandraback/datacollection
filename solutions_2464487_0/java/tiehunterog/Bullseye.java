package round1;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Bullseye {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static BigInteger TWO = new BigInteger("2");
	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(new File("A-small-attempt0.in"));
		File file = new File("Bullseye.out");
		FileWriter writer = new FileWriter(file);
		int n = scan.nextInt();
		for(int i = 0;i<n;i++){
			BigInteger r = new BigInteger(scan.next());
			BigInteger paint = new BigInteger(scan.next());
			BigInteger ringsMin = BigInteger.ONE;
			BigInteger ringsMax = new BigInteger("10000000000000000000000000000000000000000000000000000000000");
			
			while(ringsMin.add(BigInteger.ONE).compareTo(ringsMax)<0){
				BigInteger rings = ringsMin.add(ringsMax).divide(TWO);
				BigInteger amountMax = TWO.multiply(r).multiply(rings).add(rings.multiply(rings.multiply(new BigInteger("2")))).subtract(rings);
				if(amountMax.compareTo(paint)>0){
					ringsMax = rings;
				}else{
					ringsMin = rings;
				}
			}
			BigInteger amountMax = TWO.multiply(r).multiply(ringsMax).add(ringsMax.multiply(ringsMax.multiply(new BigInteger("2")))).subtract(ringsMax);
			if(amountMax.compareTo(paint)>0){
				writer.write("Case #"+(i+1)+": "+ringsMin.toString()+"\r\n");
			}else{
				writer.write("Case #"+(i+1)+": "+ringsMax.toString()+"\r\n");
			}
		}
		writer.flush();
		writer.close();
	}

}
