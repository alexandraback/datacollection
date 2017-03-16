import java.io.File;
import java.io.FileOutputStream;
import java.util.Scanner;

public class Solve2016R1A_C {
	private static String filePath = "C-small-attempt1.in";

	public static void main(String[] args) {
		StringBuffer answer = new StringBuffer();

		try (Scanner sc = new Scanner(new File(filePath))) {
			int T = sc.nextInt();
			for (int i = 1; i <= T; i++) {
				answer.append("Case #" + i + ": ");
				int N = sc.nextInt();
				
				int[] BFFs = new int[N+1];
				for (int j = 1; j <= N; j++) {
					BFFs[j] = sc.nextInt();
				}
				
				int y = 0;
				for (int j = 1; j <= N; j++) {
					boolean[] in = new boolean[N+1];
					for (int k = 1; k <= N; k++) in[k] = false;
					
					int[] circle = new int[N];
					int idx = 0;
					int curr = j;
					circle[idx] = curr;
					in[curr] = true;
					
					curr = BFFs[curr];
					circle[++idx] = curr;
					in[curr] = true;
					int currY = 2;
					
					while (true) {
						curr = BFFs[curr];
						if (curr == circle[idx-1]) {
							currY = digui(N, BFFs, circle, idx, in, currY);
							if (currY > y) {
								y = currY;
							}
							break;
						} else if (curr == circle[0]) {
							if (currY > y) {
								y = currY;
							}
							break;
						} else if (in[curr]) {
							break; // NG
						} else {
							circle[++idx] = curr;
							in[curr] = true;
							currY++;
						}
					}
				}
				answer.append(y).append("\n");
			}
			output(answer);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private static int digui(int N, int[] BFFs, int[] circle0, int idx0, boolean[] in0, int currY0) {
		int y = currY0;
		for (int j = 1; j <= N; j++) {
			if (in0[j]) continue;
			
			int[] circle = new int[N];
			for (int k = 0; k < N; k++) circle[k] = circle0[k];
			boolean[] in = new boolean[N+1];
			for (int k = 1; k <= N; k++) in[k] = in0[k];
			
			int curr = j;
			int idx = idx0 + 1;
			circle[idx] = curr;
			in[curr] = true;
			int currY = currY0 + 1;
			
			while (true) {
				curr = BFFs[curr];
				if (curr == circle[idx-1]) {
					currY = digui(N, BFFs, circle, idx, in, currY);
					if (currY > y) {
						y = currY;
					}
					break;
				} else if (curr == circle[0]) {
					if (currY > y) {
						y = currY;
					}
					break;
				} else if (in[curr]) {
					break; // NG
				} else {
					circle[++idx] = curr;
					in[curr] = true;
					currY++;
				}
			}
		}
		return y;
	}

	private static void output(StringBuffer answer) throws Exception {
		String outPath = "answer.out";
		if (filePath != null && !filePath.equals("")) {
			outPath = filePath.substring(0, filePath.length() - 2) + "out";
		}
		try (FileOutputStream fos = new FileOutputStream(outPath, false)) {
			fos.write(answer.toString().getBytes());
		}
		System.out.println(answer);
	}
}
