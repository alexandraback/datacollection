import java.io.*;
import java.util.*;

public class B{
	public static void main(String[] args) throws Exception{
		BufferedReader fin = new BufferedReader(new FileReader("B.txt"));
		PrintWriter fout = new PrintWriter(new FileWriter("Bout.txt"));

		String s = fin.readLine();
		int t = Integer.parseInt(s);
		s = fin.readLine();
		for(int i = 0; i < t; i++){
			String[] sp = s.split(" ");

			int n = Integer.parseInt(sp[0]);
			int S = Integer.parseInt(sp[1]);
			int p = Integer.parseInt(sp[2]);

			int[] scores = new int[n];
			for(int j = 3; j < sp.length; j++){
				scores[j-3] = Integer.parseInt(sp[j]);
			}
	
			int[][] mat = new int[31][2];
			mat[0][0] = 0;
			mat[1][0] = 1;
			mat[2][0] = 1;
			mat[3][0] = 1;
			mat[4][0] = 2;
			mat[5][0] = 2;
			mat[6][0] = 2;
			mat[7][0] = 3;
			mat[8][0] = 3;
			mat[9][0] = 3;
			mat[10][0] = 4;
			mat[11][0] = 4;
			mat[12][0] = 4;
			mat[13][0] = 5;
			mat[14][0] = 5;
			mat[15][0] = 5;
			mat[16][0] = 6;
			mat[17][0] = 6;
			mat[18][0] = 6;
			mat[19][0] = 7;
			mat[20][0] = 7;
			mat[21][0] = 7;
			mat[22][0] = 8;
			mat[23][0] = 8;
			mat[24][0] = 8;
			mat[25][0] = 9;
			mat[26][0] = 9;
			mat[27][0] = 9;
			mat[28][0] = 10;
			mat[29][0] = 10;
			mat[30][0] = 10;

			mat[0][1] = 0;
			mat[1][1] = 0;
			mat[2][1] = 1;
			mat[3][1] = 1;
			mat[4][1] = 0;
			mat[5][1] = 1;
			mat[6][1] = 1;
			mat[7][1] = 0;
			mat[8][1] = 1;
			mat[9][1] = 1;
			mat[10][1] = 0;
			mat[11][1] = 1;
			mat[12][1] = 1;
			mat[13][1] = 0;
			mat[14][1] = 1;
			mat[15][1] = 1;
			mat[16][1] = 0;
			mat[17][1] = 1;
			mat[18][1] = 1;
			mat[19][1] = 0;
			mat[20][1] = 1;
			mat[21][1] = 1;
			mat[22][1] = 0;
			mat[23][1] = 1;
			mat[24][1] = 1;
			mat[25][1] = 0;
			mat[26][1] = 1;
			mat[27][1] = 1;
			mat[28][1] = 0;
			mat[29][1] = 0;
			mat[30][1] = 0;

			int numreach = 0;
			int numcould = 0;
			for(int j = 0; j < scores.length; j++){
				if(mat[scores[j]][0] >= p){
					numreach++;
				} else if(mat[scores[j]][0] + 1 >= p && mat[scores[j]][1] == 1){
					numcould++;
				}
			}
			numreach += Math.min(numcould, S);

			fout.println("Case #" + (i + 1) + ": " + numreach);
			fout.flush();
			s = fin.readLine();
		}
	}
}
					
