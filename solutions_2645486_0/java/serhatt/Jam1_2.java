import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;


public class Jam1_2 {

	
	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(System.in);
		FileWriter fstream = new FileWriter("jam2.txt");
		BufferedWriter out = new BufferedWriter(fstream);
		int T = scan.nextInt();
		
		for (int k = 0; k < T; k++) {
			long r = scan.nextLong();
			long t = scan.nextLong();
			long start = 0;
			long end = 4294967296L;
			long mid = 0;
			long mul;
			long res;
			long count = 0;
			while(true) {
				mid = (start+end)/2;
				mul = (2*r)+1+mid;
				if(end - start <= 1) {
					break; 
				}
				res = mid * mul;
				if(res > t) {
					end = mid;
				}
				else {
					start = mid;
				}
			}
			out.write("Case #" + (k+1) + ": " + mid);
			out.write("\n");
			System.out.println(k);
		}

		out.close();

	}

}
