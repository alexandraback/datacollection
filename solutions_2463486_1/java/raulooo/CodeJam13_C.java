import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

import javax.jws.Oneway;


public class CodeJam13_C {


	void pr(Object... ob) {
		if(false)
		out.println(Arrays.deepToString(ob).replace("],", "],\n"));}

	Scanner in;
	PrintWriter out;
	int read(int idx){
		int r=0;
		while(idx>0){
			r+=T[idx-1];
			idx -= (idx & -idx);
		}
		return r;
	}
	void update(int idx, int val){
		while(idx<=N){
			T[idx-1]+=val;
			idx += (idx & -idx);
		}
	}
//	int N = 10000001;
	int N = 10000001;
	int T[] = new int[N];
	public void solve() throws Exception{
		in = new Scanner(new File("/Users/rc/test1/C-large-1.in"));
//		Scanner in = new Scanner(new File("/Users/rc/Eclipse-Workspaces/Algorithm-Competitions-EWS/HuaHCodingProject/src/input_temp_case"));
//		Scanner in = new Scanner(new File("src/C_example"));
		
		
		//Scanner in = new Scanner(new File("D:/in.txt"));
		String writtenFile = "/Users/rc/test1/C-large-1.in.out.txt";
//		out = new PrintWriter(System.out);
		out = new PrintWriter(new File(writtenFile));
		int casos = Integer.parseInt(in.nextLine());
		
		pr(isPalindrome(9));
		pr(isPalindrome(11),isPalindrome(121));
		pr(isPalindrome(1231));
		int [] aa = new int[N];
//		long x = 100000000000005L;
		long x = 100000000000005L;
		for (int j = 1; (long)j*(long)j <= x; j++) {
			if(isPalindrome(j) && isPalindrome(((long)j*((long)j)))){
				aa[j]=1;
				update(j,1);
			}
		}
//		pr(aa,T);
		for (int i = 0; i < casos; i++) {
			String ab[]= in.nextLine().split(" ");
			long a = Long.parseLong(ab[0]);
			long b = Long.parseLong(ab[1]);
			int r = read((int)Math.sqrt(b))-read((int)Math.sqrt(a-1));
			out.println("Case #"+(i+1)+": "+r);
//			return;
		}
		in.close();
		out.close();
	}
	boolean isPalindrome(long i){
		long rev = 0;
		long xi=i;
		while(i>0){
			rev=rev*10L+(i%10L);
			i/=10L;
		}
		return (rev==xi);
	}
	public static void main(String[] args) throws Exception {
		new CodeJam13_C().solve();
	}
}