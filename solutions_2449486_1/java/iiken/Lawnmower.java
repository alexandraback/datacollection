import java.util.Scanner;
import java.io.FileWriter;
import java.io.File;
import java.util.Collections;
import java.util.*;
public class Lawnmower{
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("a.in"));
		FileWriter fw = new FileWriter("a.out");
		int t = sc.nextInt();
		
		for ( int x = 0 ; x < t ; x++){
			int n = sc.nextInt();
			int m = sc.nextInt();
			int [][] a =new int[n][];
			ArrayList<Integer> h = new ArrayList<Integer>();
			int[] count  = new int[101];
			for ( int i = 0; i < n; i++){
				a[i] = new int[m];
				for ( int j = 0; j < m ; j++){
					a[i][j] = sc.nextInt();
					count[a[i][j]] ++;
					if ( !h.contains(a[i][j])) h.add(a[i][j]);
				}
			}
			Collections.sort(h);
			boolean res = true;
			for ( int i = 0; i < h.size()-1; i++){
				int height = h.get(i);
				int nextH = h.get(i+1);
				ArrayList<Integer> row = new ArrayList<Integer>();
				ArrayList<Integer> col = new ArrayList<Integer>();
				for ( int j = 0 ; j < n ; j++ ) {
					boolean flag = true;
					for ( int k = 0; k < m ; k ++ )
						if ( a[j][k] != height ) flag = false;
					if ( flag ) row.add(j);
				}
				for ( int j = 0; j < m ; j++){
					boolean flag = true;
					for ( int k = 0; k < n; k++)
						if ( a[k][j] != height ) flag = false;
					if ( flag ) col.add(j);
				}
				
				for ( int r : row )
					for ( int j = 0; j < m; j++)
						a[r][j] = nextH;
				for ( int c : col)
					for ( int j = 0; j < n; j++)
						a[j][c] = nextH;
				int countH = row.size() * m + col.size()*n - (row.size() * col.size());
				count[height] -= countH;
				count[nextH] += countH;
				if ( count[height] != 0) {
					res = false;
					break;
				}
				
			}
			//....Do sth here
			fw.write("Case #" + (x+1) + ": ");
			if ( res ) fw.write("YES");
			else fw.write("NO");
			fw.write("\n");
			
		}
		fw.close();
	}
}	
