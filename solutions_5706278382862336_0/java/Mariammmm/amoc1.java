import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;


public class amoc1 {
	private static long [] pow = new long [42];
	private static HashSet<Long> allPow = new HashSet<>();
	public static void main(String args[])throws IOException{
		pow[0] = 1;
		allPow.add(pow[0]);
		for(int i = 1; i< pow.length; i++){
			pow[i] = pow[i -1]*2;
			allPow.add(pow[i]);
		}
		
		BufferedReader in=new BufferedReader(new FileReader("elf.in"));
		PrintWriter out = new PrintWriter(new FileWriter("elf.out"));
		
		int t = Integer.parseInt(in.readLine());
		for(int i = 0; i< t; i++){
			StringTokenizer tok = new StringTokenizer(in.readLine(),"/");
			int res = oneTest(Long.parseLong(tok.nextToken()), Long.parseLong(tok.nextToken()));
			out.print("Case #");
			out.print(i+1);
			out.print(": ");
			if(res == -1){
				out.print("impossible");
			}	else {
				out.print(res);
			}
			
			out.println();
		}
		out.flush();
		out.close();
	}
	
	private static int oneTest(long mricx, long mnish){
		long g=GCD(mricx, mnish);
		mricx/=g;
		mnish/=g;
		if(!allPow.contains(mnish)) return -1;
		long part = 1;

		for(int i = 1; i <=40; i++){
			part*=2;
			g = GCD(mnish, part);
			long saerto = mnish/g*(part);
			long mricx1 = mricx*(saerto/mnish);
			long mricx2 = saerto / part;
			if(mricx1 - mricx2 >= 0) return i;
		}
		
		return -1;
	}
	static long GCD(long a, long b){
		if(a==0) return b;
		if(b==0) return a;
		while(true){
			a=a%b;
			long c=a;
			a=b;
			b=c;
			if(b==0) return a;
		}
	}
}
