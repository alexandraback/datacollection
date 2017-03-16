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
			long left = 0;
			while (left>=0) {
				left = t- ((r+1)*(r+1)-r*r);
				if (left >= 0) {
					t = left;
					n++;			
				}
				r=r+2;
			}			
			out.write("Case #"+i+": "+ n);
			out.newLine();
		}
		
		in.close();
		out.close();
	}

}
