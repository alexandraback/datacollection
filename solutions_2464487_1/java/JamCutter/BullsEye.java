import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.StringTokenizer;


public class BullsEye {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		PrintWriter pw = null;
		try {

			FileWriter fw = new FileWriter("MyFileWriter.txt");

			BufferedWriter bw = new BufferedWriter(fw);
			pw = new PrintWriter(bw);

			System.out.println("args[0]: " + args[0]);
			BufferedReader br = new BufferedReader(new FileReader(args[0]));

			long nTests = Long.valueOf(br.readLine());
			System.out.println("nTests = " + nTests);

			for (int i = 1; i <= nTests; i++) {

				String rtLine = br.readLine();
				StringTokenizer st = new StringTokenizer(rtLine);

				long r = Long.valueOf(st.nextToken());
				long t = Long.valueOf(st.nextToken());

				System.out.println("Case #" + i + ", r= " + r + ", t=" + t );				
				
				outputBullsEye(pw, i,r,t);
			}
			System.out.println("End");

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			pw.close();
		}


	}

	private static void outputBullsEye(PrintWriter pw, int i, long r, long t) {
		String output = "Case #" + i + ":";

		long  circles = solveEquation (r ,t);
		pw.println(output + " "+ circles);
		
	}

	private static long solveEquation(long r, long t) {
		
		BigDecimal p2 = calcPart2(r,t);
		BigDecimal p1 = calcPart1(r);	
		
		System.out.println("p2= "+ p2.doubleValue() + ", p1= "+ p1.doubleValue());
		return getNumber(p2.subtract(p1));
	}

	private static long getNumber(BigDecimal d) {
		if (d.longValue()<= 0) {
			System.out.println("Error with answer= "+ d);
		}
		
		
		return d.longValue();
	}
	
	private static BigDecimal calc2Rminus1(BigDecimal r){
		return (r.multiply(new BigDecimal(2))).subtract(new BigDecimal(1));
	}

	private static BigDecimal calcPart1(long r) {
		
		return calc2Rminus1(new BigDecimal(r)).divide(new BigDecimal(4));
	}

	private static BigDecimal calcPart2(long r, long t) {
		
		return sqrt((calc2Rminus1(new BigDecimal(r)).multiply(calc2Rminus1(new BigDecimal(r))).add(new BigDecimal(t).multiply(new BigDecimal(8))) ).divide(new BigDecimal(16)));
	}
	
	private static BigDecimal sqrt(BigDecimal in){
		
		int scale = in.scale();
	    BigDecimal sqrt = new BigDecimal(1);
	    sqrt.setScale(scale + 3, RoundingMode.FLOOR);
	    BigDecimal store = new BigDecimal(in.toString());
	    boolean first = true;
	    do{
	        if (!first){
	            store = new BigDecimal(sqrt.toString());
	        }
	        else first = false;
	        store.setScale(scale + 3, RoundingMode.FLOOR);
	        sqrt = in.divide(store, scale + 3, RoundingMode.FLOOR).add(store).divide(
	                BigDecimal.valueOf(2), scale + 3, RoundingMode.FLOOR);
	    }while (!store.equals(sqrt));
	    return sqrt.setScale(scale, RoundingMode.FLOOR);
	}

}
