import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class FairSquareSmall {

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		FileWriter fw = new FileWriter("oa.txt");
		int testCaes = scan.nextInt();
		for (int t = 1; t <= testCaes; ++t) {
			long low = scan.nextLong();
			long high = scan.nextLong();
			int count = 0;
			for (long i = (long) (Math.sqrt(low)+0.999); i <= (long) Math.sqrt(high); ++i) {
				if (isFair(i) && isFair(i * i)) {
					++count;
					System.out.println("" + i + " " + i * i);
				}
			}
			fw.write("Case #" + t + ": " + count + "\n");

		}
		fw.flush();
		fw.close();
	}

	static boolean isFair(Long x) {
		String strx = x.toString();
		for (int i = 0; i < strx.length(); ++i) {
			if (strx.charAt(i) != strx.charAt(strx.length() - i - 1))
				return false;
		}
		return true;
	}
}
