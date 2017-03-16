import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class C {

	public static void main(String[] args) throws IOException {
//		Scanner in = new Scanner(new File("in/C/test.in"));
		 Scanner in = new Scanner(new File("in/C/small.in"));
		// Scanner in = new Scanner(new File("in/C/big.in"));
//		BufferedWriter bw = new BufferedWriter(new FileWriter("out/C/test.out"));
		 BufferedWriter bw = new BufferedWriter(new FileWriter(
		 "out/C/small.out"));
		// BufferedWriter bw = new BufferedWriter(new FileWriter(
		// "out/C/big.out"));

		int cases = in.nextInt();
		for (int c = 1; c <= cases; c++) {
			int low = in.nextInt();
			int high = in.nextInt();
			int length = String.valueOf(low).length();
			int count = 0;
			if (length != 1) {
				int maxD = (int) Math.pow(10, length - 1);
				System.err.println("Case " + c + ": Maximum " + maxD);
				for (int k = 1; k < length; k++) {
					int playingWith = (int) Math.pow(10, k);
					int m = (int)Math.pow(10,length-k);
					System.err.println("Playing with " + playingWith);
					for (int j = low; j < high; j++) {
						int first = j / maxD;
						int toMoveFront = j%playingWith;
						int tmpFirst = toMoveFront / (playingWith/10);
						if(tmpFirst < first)
							continue;
						int recycled = toMoveFront * m + j /playingWith;
						if(recycled > high){
							int dif = playingWith-toMoveFront;
							j += dif;
						}else if(recycled > j){
							count++;
						}
					}
				}
			}
			bw.write("Case #" + (c) + ": " + count);
			System.err.println("Case #" + (c) + ": " + count);
			bw.newLine();
		}
		in.close();
		bw.flush();
		bw.close();
	}
}
