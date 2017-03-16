import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;


public class B {
	static int plates[];
	static int cur_best;
	
	public static void getMin(int maxNum, int moves, int index) {
		System.out.println(" index = "  + index + " " + " moves = " + moves + " maxnum = " + maxNum);
		if (moves + maxNum >= cur_best) return;
		if (index >= plates.length) {
			cur_best = Math.min(maxNum + moves, cur_best);
			System.out.println("Updating " + (maxNum + moves));
			return;
		}
		int cur = plates[index];
		for (int div = 1; div <= cur; div++) {
			int largestChunk = (int) Math.ceil(((double) cur) / div);
			getMin(Math.max(maxNum, largestChunk), moves + div - 1, index + 1);
		}
	}
	
	public static void main(String[] args) throws IOException {
//		BufferedReader in = new BufferedReader(new FileReader("b_test.in"));
		BufferedReader in = new BufferedReader(new FileReader("B-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(System.out);
		
		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			int d = Integer.parseInt(in.readLine());
			String[] pls = in.readLine().split(" ");
			plates = new int[d];
			for (int i = 0; i < d; i++) plates[i] = Integer.parseInt(pls[i]);
			Arrays.sort(plates);
			for (int i = 0; i < plates.length/2; i++) {
				int temp = plates[i];
				plates[i] = plates[plates.length - i - 1];
				plates[plates.length - i - 1] = temp;
			}
			cur_best = plates[0];
			getMin(0, 0, 0);
			System.out.println(Arrays.toString(plates));
			pw.format("Case #%d: %d\n", t, cur_best);
		}
		
		
		
		
		pw.close();
		in.close();
	}
}
