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
		
		BigDecimal k=(getSqrt((startR.multiply(new BigDecimal("2"))).add(new BigDecimal("3")).
				multiply(startR.multiply(new BigDecimal("2"))).add(new BigDecimal("3")).add(paint.multiply(new BigDecimal("8"))).subtract(new BigDecimal("8").add(startR.multiply(new BigDecimal("8")))))
				.subtract(new BigDecimal("3")).subtract(startR.multiply(new BigDecimal("2")))).
				divide(new BigDecimal("4"),0,BigDecimal.ROUND_FLOOR);
		
		
		while(k.multiply(k).multiply(new BigDecimal("2")).
				add(k.multiply(new BigDecimal("3"))).
				add(k.multiply(startR.multiply(new BigDecimal("2")))).add(BigDecimal.ONE.add(startR.multiply(new BigDecimal("2")))).subtract(paint).compareTo(BigDecimal.ZERO)<=0)
			k=k.add(BigDecimal.ONE);
		
		
		if(k.multiply(k).multiply(new BigDecimal("2")).
				add(k.multiply(new BigDecimal("3"))).
				add(k.multiply(startR.multiply(new BigDecimal("2")))).add(BigDecimal.ONE.add(startR.multiply(new BigDecimal("2")))).subtract(paint).compareTo(BigDecimal.ZERO)>0)
			k=k.subtract(BigDecimal.ONE);
		
		/*
		while(true){
			increment=startR.add(new BigDecimal(Integer.toString(2*n+1))).
					multiply(startR.add(new BigDecimal(Integer.toString(2*n+1)))).
					subtract(startR.add(new BigDecimal(Integer.toString(2*n))).
							multiply(startR.add(new BigDecimal(Integer.toString(2*n)))));
			paint=paint.subtract(increment);
			if(paint.compareTo(BigDecimal.ZERO)<0)
				break;
			n++;
			
		}*/
		
		System.out.println(k.add(BigDecimal.ONE));
		
	}

	static BigDecimal getSqrt(BigDecimal number){
		BigDecimal Epsilon=new BigDecimal("0.05");
		BigDecimal diff=BigDecimal.ONE;
		BigDecimal two=new BigDecimal("2");
		BigDecimal x_n=new BigDecimal("50");
		BigDecimal x_n_1;
		while(diff.compareTo(Epsilon)>0){
			x_n_1=x_n.add(number.divide(x_n,5,BigDecimal.ROUND_HALF_EVEN));
			x_n_1=x_n_1.divide(two,5,BigDecimal.ROUND_FLOOR);
			
			x_n=x_n_1.add(number.divide(x_n_1,5,BigDecimal.ROUND_HALF_EVEN));
			x_n=x_n.divide(two,5,BigDecimal.ROUND_FLOOR);
			
			diff=x_n_1.subtract(x_n).abs();	
			
		}
		return x_n;
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
