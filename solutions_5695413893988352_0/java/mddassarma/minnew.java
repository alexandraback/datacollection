import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class minnew {

	public static void main(String[] args) throws IOException{
		BufferedReader buf=new BufferedReader(new FileReader("mindist.in"));
		PrintWriter printer=new PrintWriter("mindist.out");
		int N=Integer.parseInt(buf.readLine());
		for(int i=1;i<=N;i++){
			printer.println("Case #"+i+": "+solveit(buf.readLine()));
		}
		printer.close();
		
	}
	public static long[] solve(byte[] cc,byte[] jj){
		byte[] c=cc.clone();
		byte[] j=jj.clone();
		for(int i=0;i<c.length;i++)
			if(c[i]=='?'){
				long[] best=null;
				long diff=Long.MAX_VALUE;
				for(int k=0;k<10;k++){
					c[i]=(byte)(k+'0');
					long[] temp = solve(c,j);
					if(Math.abs(temp[0]-temp[1])<diff){
						diff=Math.abs(temp[0]-temp[1]);
						best=temp;
					}
				}
				return best;
			}
		for(int i=0;i<j.length;i++)
			if(j[i]=='?'){
				long[] best=null;
				long diff=Long.MAX_VALUE;
				for(int k=0;k<10;k++){
					j[i]=(byte)(k+'0');
					long[] temp = solve(c,j);
					if(Math.abs(temp[0]-temp[1])<diff){
						diff=Math.abs(temp[0]-temp[1]);
						best=temp;
					}
				}
				return best;
			}
		return new long[]{Long.parseLong(new String(c)),Long.parseLong(new String(j))};
	}
	public static String solveit(String str){
		String[] s=str.split(" ");
		System.out.println(s[0]+"///"+s[1]);
		byte[] cn= new byte[s[0].length()];
		byte[] jn= new byte[cn.length];
		for(int i=0;i<cn.length;i++){
			cn[i]=(byte) s[0].charAt(i);
			jn[i]=(byte) s[1].charAt(i);
		}
		long[] ll=solve(cn,jn);
		String a=ll[0]+"";
		String b=ll[1]+"";
		for(int i=s[0].length()-a.length();i>0;i--)
			a="0"+a;
		for(int i=s[0].length()-b.length();i>0;i--)
			b="0"+b;
		return a+" "+b;
	}
}
