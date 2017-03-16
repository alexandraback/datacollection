package codejam;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.math.BigDecimal;

public class A {

	
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		try {
			System.setIn(new FileInputStream(args[0]));
			System.setOut(new PrintStream(new FileOutputStream(args[1])));
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
		DataInputStream in = new DataInputStream(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		PrintWriter out = new PrintWriter(System.out);

		int numCase = Integer.parseInt(br.readLine());

		for (int i = 1; i <= numCase; i++) {
			System.out.print("Case #"+i+": ");
			run(br, out);
		}
	}

	public static void run(BufferedReader br, PrintWriter out)
			throws NumberFormatException, IOException {

		String[] tmp=getTokens(br);
		BigDecimal startR=new BigDecimal(tmp[0]);
		BigDecimal paint=new BigDecimal(tmp[1]);
		
		BigDecimal increment=startR.add(BigDecimal.ONE).multiply(startR.add(BigDecimal.ONE))
				.subtract(startR.multiply(startR));
		int n=0;
		
		while(true){
			increment=startR.add(new BigDecimal(Integer.toString(2*n+1))).
					multiply(startR.add(new BigDecimal(Integer.toString(2*n+1)))).
					subtract(startR.add(new BigDecimal(Integer.toString(2*n))).
							multiply(startR.add(new BigDecimal(Integer.toString(2*n)))));
			paint=paint.subtract(increment);
			if(paint.compareTo(BigDecimal.ZERO)<0)
				break;
			n++;
			
		}
		
		System.out.println(n);
		
	}

	public static String[] getTokens(BufferedReader br) throws IOException {
		return br.readLine().split("\\s+");
	}
	/*
	 * public static float calculate(float[] Data){
	 * 
	 * }
	 */
	
}
