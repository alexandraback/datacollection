import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class CodeJam13_B {


	void pr(Object... ob) {
		if(false)
		out.println(Arrays.deepToString(ob).replace("],", "],\n"));}
	void out(String res){
		
	}

	Scanner in;
	PrintWriter out;
	public void solve() throws Exception{
		in = new Scanner(new File("/Users/rc/test1/B-large.in"));
//		Scanner in = new Scanner(new File("/Users/rc/Eclipse-Workspaces/Algorithm-Competitions-EWS/HuaHCodingProject/src/input_temp_case"));
//		Scanner in = new Scanner(new File("src/B_example"));
		
		
		//Scanner in = new Scanner(new File("D:/in.txt"));
		String writtenFile = "/Users/rc/test1/B-large.in.out.txt";
//		out = new PrintWriter(System.out);
		out = new PrintWriter(new File(writtenFile));
		int casos = Integer.parseInt(in.nextLine());
		for (int i = 0; i < casos; i++) {
			String ab[]=in.nextLine().split(" ");
			int n=Integer.parseInt(ab[0]);
			int m=Integer.parseInt(ab[1]);
			int grid [][] = new int[n][m];
			for (int j = 0; j < n; j++) {
				String a []=in.nextLine().split(" ");
				for (int k = 0; k < a.length; k++) {
					grid[j][k]=Integer.parseInt(a[k]);
				}
			}
			pr(grid);
			boolean could1=true;
			boolean[][] coulds= new boolean[n][m];
			for (int j = 0; j < n; j++) {
				for (int j2 = 0; j2 < m; j2++) {
					int me = grid[j][j2];
					//right
					boolean could=true;
					for (int k = j2+1; k < m; k++) {
						if(grid[j][k]>me){
							could=false;
							break;
						}
					}
					//left
					boolean could2=true;
					for (int k = j2-1; k >= 0; k--) {
						if(grid[j][k]>me){
							could2=false;
							break;
						}
					}
					//up
					boolean could3=true;
					for (int k = j-1; k >= 0; k--) {
						if(grid[k][j2]>me){
							could3=false;
							break;
						}
					}
					//down
					boolean could4=true;
					for (int k = j+1; k<n; k++) {
						if(grid[k][j2]>me){
							could4=false;
							break;
						}
					}
					if((could && could2) || (could3 && could4)){
						coulds[j][j2]=true;
					}else{
//						pr(j,j2);
						j=n;
						could1=false;
						break;
					}
				}
			}
//			for (int j = 0; j < n; j++) {
//				for (int j2 = 0; j2 < m; j2++) {
//					if(!coulds[j][j2]){
//						could1=false;
//					}
//				}
//			}
			if(could1)
				out.println("Case #"+(i+1)+": YES");
			else
				out.println("Case #"+(i+1)+": NO");
//			return;
		}
		in.close();
		out.close();
	}
	public static void main(String[] args) throws Exception {
		new CodeJam13_B().solve();
	}
}