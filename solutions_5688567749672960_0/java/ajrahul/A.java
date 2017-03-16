import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

class A {
	
	static int[] arr=new int[1000001];
	
	static BufferedReader br;
	static PrintWriter pw;
	static StringTokenizer st;
	
	public static void main(String[] args)throws IOException {
		br=new BufferedReader(new FileReader("A-small-attempt0.in"));
		pw=new PrintWriter(new FileOutputStream("output_A.in"));
		solve();
		pw.flush();
	}
	
	static void solve()throws IOException {
		int t=Integer.parseInt(br.readLine());
		for(int i=2;i<1000001;i++)
			arr[i]=1000001;
		counter();
		for(int i=1;i<=t;i++) {
			int n=Integer.parseInt(br.readLine());
			pw.println("Case #"+i+": "+arr[n]);
		}
	}
	
	static void counter() {
		arr[1]=1;
		for(int i=2;i<1000001;i++) {
			arr[i]=Math.min(arr[i-1]+1, arr[i]);
			int num=i;
			long rev=0;
			while(num>0) {
				rev=num%10+rev*10;
				num/=10;
			}
			//pw.println(rev);
			if(rev<1000000 && rev>i)
				arr[(int)rev]=Math.min(arr[i]+1, arr[(int)rev]);
		}
	}
}







