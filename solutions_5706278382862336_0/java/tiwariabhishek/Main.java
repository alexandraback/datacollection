import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;

public class Main{

	public static void main(String args[]){
		long[] pow2=new long[41];
		pow2[0]=1;
		for(int i=1;i<41;i++) pow2[i]=pow2[i-1]*2;
		try{
			FileReader fr=new FileReader("input.txt");
			BufferedReader br=new BufferedReader(fr);
			PrintWriter pr=new PrintWriter("out.txt");
			String str=br.readLine();
			int T=Integer.parseInt(str);
			for(int t=1;t<=T;t++){
				str=br.readLine();
				int bl=str.indexOf('/');
				long a=Long.parseLong(str.substring(0,bl));
				long b=Long.parseLong(str.substring(bl+1));
				long md=gcd(a,b);
				a/=md;b/=md;
				int aInd=0,bInd=Arrays.binarySearch(pow2,b);
				for(int i=0;i<41;i++) if(pow2[i]>=a){aInd=i;break;}
				// System.out.println(bInd);
				int ans=-1;
				if(bInd>=0){ 
					ans=aInd==0?bInd:bInd-aInd+1;
				}
				
				str="Case #"+t+": "+(ans==-1?"impossible":ans);
				pr.println(str);
				System.out.println(str);
			}
			pr.flush();
		}catch(IOException ioe){
			ioe.printStackTrace();
		}
	}
	static long gcd(long a,long b){
		if(b==0) return a;
		return gcd(b,a%b);
	}
}