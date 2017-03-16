import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("A.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("A.out"));
		
		int T = in.nextInt();
		for(int i = 1; i <=T; i++){
			long r = in.nextLong();
			long t = in.nextLong();
			long n = 0;

			double rr = Long.valueOf(r).doubleValue();
			double tt = Long.valueOf(t).doubleValue();
			double m = 4*rr*rr+1-4*rr+8*tt;
			if (m<0)
				n = 0;
			else {
				m = ((1-2*rr)+ Math.sqrt(m))/4;
				n = (long) m;
			}
						
			out.write("Case #"+i+": "+ n);
			out.newLine();
		}
		
		in.close();
		out.close();
	}

}
