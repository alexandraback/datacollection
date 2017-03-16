import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class Fractiles2 {
	
	public static int[] findTilePos(int K, int C, int S){
		int[] pos = new int[S];
		for(int i=1; i<=S; ++i){
			pos[i-1] = i;
		}
		return pos;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			// A-small-attempt0.in
			Scanner scanner = new Scanner(
					new File(
							"/Users/xiangyixie/Documents/eclipse_workspace/2016Codejam/input/D-small-attempt1.in"));
			FileWriter writer = new FileWriter(
					new File(
							"/Users/xiangyixie/Documents/eclipse_workspace/2016Codejam/output/a.txt"),
					false);
			int T = scanner.nextInt();
			for (int i = 0; i < T; ++i) {
				int K = scanner.nextInt();
				int C = scanner.nextInt();
				int S = scanner.nextInt();
				int[] pos = findTilePos(K, C, S);
				writer.write("Case #" + (i + 1) + ": ");
				//System.out.println("Case #" + (i + 1) + ": " + S + " " + o);
				if (S > 0 && pos[0] != 0) {
					for (int m = 0; m < pos.length; ++m) {
						writer.write(pos[m] + " ");
					}
				} else {
					writer.write("IMPOSSIBLE");
				}
				writer.write("\n");
			}

			scanner.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			return;
		}

		System.out.println("done");

	}

}
