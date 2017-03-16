import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.StringTokenizer;


public class Lawnmower {

	
	public static void main(String[] args) throws IOException {

		String name = "B-small-attempt0";
		String path = "C:\\Users\\dbu\\Downloads\\";
		
		String text = TextReader.read(path + name + ".in");
		
		PrintStream out = new PrintStream(new File(path + name + ".out"));
		
		StringTokenizer tokenizer = new StringTokenizer(text);
		
		int T = Integer.parseInt(tokenizer.nextToken());
		System.out.println(T);
		System.out.println("======");
		for (int t = 0; t < T; t += 1) {
		
			int Y = Integer.parseInt(tokenizer.nextToken());
			int X = Integer.parseInt(tokenizer.nextToken());
			System.out.println(Y + " " + X);
			System.out.println("------------");
			
			int[][] H = new int[Y][];
			for (int y = 0; y < Y; y += 1) {
				H[y] = new int[X];
				for (int x = 0; x < X; x+=1) {
					H[y][x] = Integer.parseInt(tokenizer.nextToken());
				}
			}
			
			int[] HY = new int[Y];
			for (int y = 0; y < Y; y += 1) {
				int max = 0;
				for (int x = 0; x < X; x+=1) {
					if (max < H[y][x]) {
						max = H[y][x];
					}
				}
				HY[y] = max;
			}
			
			int[] HX = new int[X];
			for (int x = 0; x < X; x+=1) {
				int max = 0;
				for (int y = 0; y < Y; y += 1) {
					if (max < H[y][x]) {
						max = H[y][x];
					}
				}
				HX[x] = max;
			}
			
			for (int y = 0; y < Y; y += 1) {
				for (int x = 0; x < X; x+=1) {
					System.out.print(H[y][x] + " ");
				}
				System.out.println(" : " + HY[y]);
			}
			for (int x = 0; x < X; x+=1) {
				System.out.print(": ");
			}
			System.out.println();
			for (int x = 0; x < X; x+=1) {
				System.out.print(HX[x] + " ");
			}
			System.out.println();
			System.out.println("------------");
			
			boolean ok = true;
			for (int y = 0; y < Y; y += 1) {
				for (int x = 0; x < X; x+=1) {
					int min = HY[y];
					if (HX[x] < min) min = HX[x];
					System.out.print(min + " ");
					ok = ok && (min == H[y][x]); 
				}
				System.out.println();
			}
			System.out.println("------");
			String result = "Case #"+(t+1)+": " + (ok?"YES":"NO");
			System.out.println(result);
			out.println(result);
			System.out.println("======");
			
		}
		
		out.close();
	}
}
