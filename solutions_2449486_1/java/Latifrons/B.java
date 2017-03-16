import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class B {

	static String pre = "1s";
	static String in = pre + ".in";
	static String out = pre + ".out";

	static Scanner s;
	static FileWriter fw;
	
	
	public static void main(String[] args) throws IOException {
		s = new Scanner(new FileInputStream(in));
		fw = new FileWriter(out);

		// init();

		int lines = s.nextInt();
		for (int i = 1; i <= lines; i++) {
			long start = System.currentTimeMillis();
			String result = handle();
			String output = String.format("Case #%d: %s\n", i, result);
			fw.write(output);
			System.out.printf("%3d %s",
					(System.currentTimeMillis() - start) / 1000, output);
		}

		fw.close();
		System.out.println("Done");
	}


	private static String handle() {
		int n = s.nextInt();
		int m = s.nextInt();
		int[][] b = new int[n][m];
		for (int i = 0 ; i < n;i++){
			for (int j = 0 ; j < m;j++){
				b[i][j] = s.nextInt();
			}
		}
		//row
		int[] rowmax = new int[n];
		
		for (int i = 0 ; i < n;i++){
			int max = Integer.MIN_VALUE;
			for (int j = 0 ; j < m;j++){
				if (b[i][j] > max){
					max = b[i][j];
				}
			}
			rowmax[i] = max;
		}
		//row
		int[] colmax = new int[m];
		
		for (int i = 0 ; i < m;i++){
			int max = Integer.MIN_VALUE;
			for (int j = 0 ; j < n;j++){
				if (b[j][i] > max){
					max = b[j][i];
				}
			}
			colmax[i] = max;
		}
		
		for (int i = 0 ; i < n;i++){
			for (int j = 0 ; j < m;j++){
				if (b[i][j] < rowmax[i] && b[i][j] < colmax[j]){
					return "NO";
				}
			}
		}
		return "YES";
	}
	
}
