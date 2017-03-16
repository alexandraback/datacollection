import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
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
		
		double p2 = calcPart2(r,t);
		double p1 = calcPart1(r);	
		
//		System.out.println("p2= "+ p2 + ", p1= "+ p1);
		return getNumber(p2 -p1);
	}

	private static long getNumber(double d) {
		if (d<= 0) {
			System.out.println("Error with answer= "+ d);
		}
		
		long ret = (long) d;
		return ret;
	}

	private static double calcPart1(long r) {
		
		return (2*r -1)/4.0;
	}

	private static double calcPart2(long r, long t) {
		
		return Math.sqrt(((2*r-1)*(2*r-1) + 8*t)/16.0);
	}

}
