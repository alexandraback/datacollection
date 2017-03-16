import java.util.*;
import java.io.*;
public class FairAndSquare3 {
	public static void main(String[] args) {
		String inputfile = args[0];
		BufferedReader input;
		try {
			input = new BufferedReader(new FileReader(inputfile));
		} catch (FileNotFoundException e) {
			System.err.println("File not found");
			return;
		}
		Scanner s = new Scanner(input);
		int T = s.nextInt();
		long[] FnS = {1,2,3,11,22,101,111,121,202,212,1001,1111,2002,10001,10101,10201,11011,11111,
		              11211,20002,20102,100001,101101,110011,111111,200002,1000001,1001001,1002001,
		              1010101,1011101,1012101,1100011,1101011,1102011,1110111,1111111,2000002,2001002};
		for (int x = 1; x <=T; x++) {
			long A = s.nextLong();
			A = (long) Math.ceil(Math.sqrt(A));
			long B = s.nextLong();
			B = (long) Math.floor(Math.sqrt(B));
			long count = 0;
			for (long num : FnS) {
				if (A <= num && num <= B) {
					count++;
				}
			}
			System.out.println("Case #" + x + ": " + count);
		}
	}
}
