import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Arrays;


public class qt22 {
	static int e ;
	static int r ;
	static int n ;
	static int ans;
	static int v[];
	
	private static void dfs(int n1,int e1,int ans1) {
		if (n1 == n) {
			if (ans < ans1) {
				ans = ans1;
			}
		}
		else {
			for (int i=0;i<=e1;i++) {
				dfs(n1+1,Math.min(e1-i+r,e),ans1+v[n1]*i);
			}
		}
	}
	
	public static void test9(BufferedReader in) throws NumberFormatException, IOException {
		File out = new File("out.txt");
		FileWriter fw = new FileWriter(out);
		BufferedWriter bw = new BufferedWriter(fw);
		
		int cases = Integer.parseInt(in.readLine());
		for (int j=1;j<=cases;j++) {
			bw.write("Case #"+j+": ");
			String[] tmp = in.readLine().split(" ");
			e = Integer.parseInt(tmp[0]);
			r = Integer.parseInt(tmp[1]);
			n = Integer.parseInt(tmp[2]);
			v = new int[n];
			tmp = in.readLine().split(" ");
			for (int i=0;i<n;i++) {
				v[i] = Integer.parseInt(tmp[i]);
			}
			ans = Integer.MIN_VALUE;
			dfs(0,e,0);
			bw.write(ans+"\n");
		}		
		in.close();
		bw.close();
	}	
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		File conf = new File("A.in");
		FileReader fr=new FileReader(conf);
		BufferedReader in=new BufferedReader(fr);
		test9(in);
	}
}
