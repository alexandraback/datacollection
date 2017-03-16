import java.io.*;
import java.util.*;

public class Lawnmower{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("in.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		int t = Integer.parseInt(br.readLine());

		for(int i = 1; i <= t; i++){
			boolean success = true;

			String[] tmp = br.readLine().split(" ");
			int n = Integer.parseInt(tmp[0]);
			int m = Integer.parseInt(tmp[1]);


			int[][] vals = new int[n][m];

			int[] xval = new int[n];
			int[] yval = new int[m];
			Arrays.fill(xval,0);
			Arrays.fill(yval,0);

			for(int x = 0; x < n; x++){
				tmp = br.readLine().split(" ");

				for(int y = 0; y < m; y++){
					vals[x][y] = Integer.parseInt(tmp[y]);
					xval[x] = Math.max(xval[x], vals[x][y]);
					yval[y] = Math.max(yval[y], vals[x][y]);

				}
			}

			Loop: for(int x = 0; x < n; x++){
				for(int y = 0; y < m; y++){
					if(vals[x][y] < Math.min(xval[x], yval[y])) {
						success = false;
						break Loop;
					}

				}
			}


			if(success)
				pw.println("Case #" + i + ": YES");
			else
				pw.println("Case #" + i + ": NO");
		}


		pw.flush();
		pw.close();
	}
}