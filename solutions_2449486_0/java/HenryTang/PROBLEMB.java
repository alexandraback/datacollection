import java.io.*;
import java.awt.*;
import java.awt.event.InputEvent;
import java.awt.image.BufferedImage;
import java.util.*;


public class PROBLEMB
{

	public static void main(String[] args) throws IOException, Exception{
		File srcFile = new File ("B-small-attempt0.in");
		BufferedReader in = new BufferedReader (new FileReader (srcFile));
		File dstFile = new File ("output.txt");
		PrintWriter out = new PrintWriter (new BufferedWriter (new FileWriter (dstFile)));
		int cases = Integer.parseInt(in.readLine());
		int casecounter = 1;
		for (int i=0;i<cases;i++){
			StringTokenizer tokenizer = new StringTokenizer(in.readLine(), " ");
			int N = Integer.parseInt(tokenizer.nextToken());
			int M = Integer.parseInt(tokenizer.nextToken());
			int[][] field = new int[N][M];
			for (int j=0;j<N;j++){
				StringTokenizer tk = new StringTokenizer(in.readLine(), " ");
				for (int k=0;k<M;k++){
					field[j][k]=Integer.parseInt(tk.nextToken());
				}
			}
			out.println(solve(field, N, M, casecounter));
			casecounter++;
			
		}
		
		
		in.close();
		out.close();
			
	}

	private static String solve(int[][] field, int n, int m, int casecounter) {
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				boolean hz = false;
				boolean vt = false;
				for (int k=0;k<n;k++){
					if (field[k][j]>field[i][j]){
						vt = true;
						continue;
					}
				}
				for (int k=0;k<m;k++){
					if (field[i][k]>field[i][j]){
						hz = true;
						continue;
					}
				}
				if (hz && vt){
					return ("Case #" + casecounter + ": NO");
				}
			}
		}
		return ("Case #" + casecounter + ": YES");
	}
	

	
}