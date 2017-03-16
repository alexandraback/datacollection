import java.io.*;
import java.util.*;
public class Lawnmower {
	public static Scanner scan = null;
	public static PrintWriter out = null;
	public static boolean bug = false;
	static{
		try {
			scan = new Scanner(new FileReader("input2.txt"));
			out = new PrintWriter(new File("output2.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	public static void main(String[] args){
		int n1 = Integer.parseInt(scan.next());
		int count = 0;
		while (true){
			int n = Integer.parseInt(scan.next());
			int m = Integer.parseInt(scan.next());
			int[][] m1 = new int[n][m];
			int[] yl = new int[n];
			int[] xl = new int[m];
			for (int i=0;i<n;i++){
				int k1 = Integer.MIN_VALUE;
				for (int j=0;j<m;j++){
					int temp = Integer.parseInt(scan.next());
					m1[i][j]= temp;
					if (temp>k1){
						k1 = temp;
					}
					if (temp>xl[j]){
						xl[j]=temp;
					}
				}
				yl[i]=k1;
			}
			
			boolean fin = true;
			for (int i=0;i<n;i++){
				for (int j=0;j<m;j++){
					if (m1[i][j]>=yl[i]
							||m1[i][j]>=xl[j]){
						
					}
					else {
						fin=false;
					}
				}
			}
			
			if (bug){
				for (int[] e: m1){
					System.out.println(Arrays.toString(e));
				}
			}
			if (bug) System.out.println("xl "+Arrays.toString(xl));
			if (bug) System.out.println("yl "+Arrays.toString(yl));
			if (bug) System.out.println();
			if (fin){
				out.println("Case #"+(count+1)+": YES");
			}
			else {
				out.println("Case #"+(count+1)+": NO");
			}
			out.flush();
			count++;
			if (n1-count<=0){
				break;
			}
		}
		
		
	}
}
