import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;



public class Bullseye {
	public static void main(String[] args) throws IOException {
		BufferedWriter bw;
		FileOutputStream fos = new FileOutputStream("C:\\Users\\Administrator\\Downloads\\codejam.out");
		bw = new BufferedWriter(new OutputStreamWriter(fos));
		Scanner reader = new Scanner (System.in);
		int nCases = reader.nextInt();
		reader.nextLine();
		for(int i=1; i<=nCases; i++) {
			long r = reader.nextLong();
			long t = reader.nextLong();
			long n = 1;
			long lastN = n;
			while(true) {
				if(compute(n, r) > t) {
					break;
				}
				lastN = n;
				n *= 2;
			}
			long result = 1;
			long mid = 0;
			while(true) {
				if(n - lastN <= 1) {
					result = lastN;
					break;
				}
				mid = (n + lastN) / 2;
				long res = compute(mid, r);
				if(res > t) {
					n = mid;
				} else if (res < t) {
					lastN = mid;
				} else {
					result = mid;
					break;
				}
			}
			
			String line ="Case #" + i + ": " + result;
			//System.out.println(line);
			bw.write(line);
			bw.newLine();
		}
		bw.close();
	}

	private static long compute(long n, long r) {
		return 2 * n * n - n + 2 * n * r;	
	}
}
