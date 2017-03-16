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
		FileWriter fw = new FileWriter("out.out");
		int testCaes = scan.nextInt();
		for (int t = 1; t <= testCaes; ++t) {
			int low = scan.nextInt();
			int high = scan.nextInt();
			int count = 0;
			for (int i = (int) (Math.sqrt(low)+0.999); i <= (int) Math.sqrt(high); ++i) {
				if (isFair(i) && isFair(i * i)) {
					++count;
//					System.out.println("" + i + " " + i * i);
				}
			}
			fw.write("Case #" + t + ": " + count + "\n");

		}
		fw.flush();
		fw.close();
	}

	static boolean isFair(Integer x) {
		String strx = x.toString();
		for (int i = 0; i < strx.length(); ++i) {
			if (strx.charAt(i) != strx.charAt(strx.length() - i - 1))
				return false;
		}
		return true;
	}
}
