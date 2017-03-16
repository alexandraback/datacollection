import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;
import static java.lang.System.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;

public class Lawnmower{
	static int[][] target;
	static int n, m;
	static int[] row, col;
	public static void main(String[] args)throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(out));
		int t = Integer.valueOf(br.readLine());
		for(int tt=0; tt<t; tt++){
			String[] ss = br.readLine().trim().split("\\s+");
			n = Integer.valueOf(ss[0]);
			m = Integer.valueOf(ss[1]);
			target = new int[n][m];
			row = new int[n];
			col = new int[m];
			for(int i=0; i<n; i++){
				ss = br.readLine().trim().split("\\s+");
				int k = -1;	//store maximum in row
				for(int j=0; j<m; j++){
					target[i][j] = Integer.valueOf(ss[j]);
					k = max(k, target[i][j]);
				}
				row[i] = k;
			}
			for(int i=0; i<m; i++){
				int k = -1;	//store maximum in col
				for(int j=0; j<n; j++){
					k = max(k, target[j][i]);
				}
				col[i] = k;
			}
			boolean possible = true;
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					if(row[i]!=target[i][j] && col[j]!=target[i][j]){
						possible = false;
					}
				}
			}
			if(possible){
				out.printf("Case #%d: YES\n", tt+1);
			}else{
				out.printf("Case #%d: NO\n", tt+1);
			}
		}
		bw.flush();
	}
}
