import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class fsquare {

	/**
	 * @param args
	 */
	static long[] l=new long[]{
			1,
			2,
			3,
			11,
			22,
			101,
			111,
			121,
			202,
			212,
			1001,
			1111,
			2002,
			10001,
			10101,
			10201,
			11011,
			11111,
			11211,
			20002,
			20102,
			100001,
			101101,
			110011,
			111111,
			200002,
			1000001,
			1001001,
			1002001,
			1010101,
			1011101,
			1012101,
			1100011,
			1101011,
			1102011,
			1110111,
			1111111,
			2000002,
			2001002,
			10000001,
			10011001,
			10100101,
			10111101,
			11000011,
			11011011,
			11100111,
			11111111,
			20000002
	};
	public static void main(String[] args) throws IOException{
		BufferedReader buf=new BufferedReader(new FileReader("problem3_i.txt"));
		PrintWriter printer=new PrintWriter("problem3.txt");
		
		int T=Integer.parseInt(buf.readLine());
		
		for(int i=1;i<T+1;i++){
			
			String[] s=buf.readLine().split(" ");
			long a=Long.parseLong(s[0]);
			long b=Long.parseLong(s[1]);
			int c=0;
			int at=0;
			while(l[at]*l[at]<a)
				at++;
			while(l[at]*l[at]<=b){
				c++;
				at++;
			}
			printer.println("Case #"+i+": "+c);
		}
		printer.close();
	}
	public static boolean isPal(double j){
		int a=(int)j;
		String p=a+"";
		for(int i=0;i<=p.length()/2;i++)
			if(p.charAt(i)!=p.charAt(p.length()-i-1))
				return false;
		return true;
	}

}
