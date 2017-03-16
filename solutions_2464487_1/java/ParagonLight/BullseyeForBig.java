package Round1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;

public class BullseyeForBig {

	/**
	 * @param args
	 */
	
	public static BigDecimal sqrt_newtonBigInteger(BigDecimal number) {
		BigDecimal xn = new BigDecimal("1");
		BigDecimal x = new BigDecimal("1");
		BigDecimal numberDecimal = number;
		// double xn = 1;
		// double x = 1;
		int maxCount = 10;
		int count = 0;
		BigDecimal xnSquare = xn.multiply(xn);
		BigDecimal threshold = new BigDecimal("0.1");
		xnSquare = xnSquare.add(numberDecimal.negate());
		BigDecimal two = new BigDecimal("2");
		// System.out.println(xnSquare + " " +
		// xn.multiply(xn).add(numberDecimal.negate()).abs());
		while (xn.multiply(xn).add(numberDecimal.negate()).abs()
				.compareTo(threshold) == 1) {
//			System.out.println(xn.multiply(xn).add(numberDecimal.negate()));
//			 System.out.println(xn + " " + x + " " + number);
			x = xn.multiply(xn).add(numberDecimal.negate())
					.divide(xn.multiply(two), 100, RoundingMode.HALF_UP);
			// x = (xn*xn-number)/(2*xn);
			xn = xn.add(x.negate());
			// xn = (xn - x);
			count++;
		}
		// System.out.println(xn + " "+ " " + number);
		return xn;
	}

	
	
	public static BigDecimal maxCicle(BigDecimal r, BigDecimal t, BigDecimal one, BigDecimal two, BigDecimal four){
		BigDecimal theta = two.multiply(t.add(r.negate())).add(two.multiply(r).add(one).pow(2).divide(four)); 
//		System.out.println(theta);
		BigDecimal root = sqrt_newtonBigInteger(theta);
//		System.out.println(root);
		BigDecimal minus = two.multiply(r).add(one).divide(two);
//		System.out.println(minus);
		return root.add(minus.negate());
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader br;
		try {
			int N;
			br = new BufferedReader(new FileReader("A-large.in"));
			PrintWriter pw = new PrintWriter(new File("output"));
			String line = br.readLine();
			N = Integer.parseInt(line);
			int count = 1;
			while (count <= N) {
				line = br.readLine();
				String[] strs = line.split(" ");
//				int r = Integer.parseInt(strs[0]);
//				double t = Integer.parseInt(strs[1]);
				BigDecimal circle;
				boolean enoughPaint = true;
//				double nextUse = ((r + 1) * (r + 1) - r * r);
				BigDecimal two = new BigDecimal("2");
				BigDecimal one = new BigDecimal("1");
				BigDecimal four = new BigDecimal("4");
				BigDecimal r = new BigDecimal(strs[0]);
				BigDecimal t = new BigDecimal(strs[1]);
				
				circle = maxCicle(r,t,one,two,four);
				System.out.println(circle + " " + circle.add(one).divide(two));
				BigInteger circleInt = circle.add(one).divide(two).toBigInteger();
//				
//				
//				
//				
//				while(enoughPaint){
////					System.out.println(r + " ");					
//					whole = whole.add(new BigInteger("2").multiply(r.add(circle)).add(new BigInteger("1").negate()));
//					System.out.println(whole + " " + t);
//					if(t.compareTo(whole) == -1){
//						enoughPaint = false;	
//						break;
//					}	
//					else{
//						circle = circle.add(two);	
//					}
//				}
////				
////				
				System.out.println("Case #" + count + ": " + circleInt);
				pw.write("Case #" + count + ": " + circleInt + "\n");
				pw.flush();
				count++;
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}


	}

}
