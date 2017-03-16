import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;


public class war {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException{
		BufferedReader buf=new BufferedReader(new FileReader("file.in"));
		PrintWriter printer=new PrintWriter("file.out");
		int T=Integer.parseInt(buf.readLine());
		//if one beats it, play it
		//otherwise, play smallest
		for(int i=1;i<=T;i++){
			printer.print("Case #"+i+": ");
			int N=Integer.parseInt(buf.readLine());
			String[] str=buf.readLine().split(" ");
			String[] str2=buf.readLine().split(" ");
			double[] n=new double[N];
			double[] k=new double[N];
			for(int j=0;j<N;j++){
				n[j]=Double.parseDouble(str[j]);
				k[j]=Double.parseDouble(str2[j]);
			}
			Arrays.sort(n);
			Arrays.sort(k);
			double[] n2=n.clone();
			double[] k2=k.clone();
			int x=dwaro(n,k);
			int y=waro(n2,k2);
			printer.println(x+" "+y);
		}
		printer.close();
	}
	public static int dwaro(double[] n,double[] k){
		int wins=0;
		int atk=0;
		for(int atn=0;atn<n.length&atk<n.length;){
			if(n[atn]>k[atk]){
				n[atn++]=0;
				k[atk++]=0;
				wins++;
			}else{
				atn++;
			}
		}
		return wins;
	}
	public static int waro(double[] n,double[] k){
		int atk=0;
		int beat=0;
		for(int atn=0;atn<n.length&&atk<n.length;){
			if(k[atk]>n[atn]){
				n[atn++]=0;
				k[atk++]=0;
				beat++;
			}else{
				atk++;
			}
		}
		return n.length-beat;
	}

}
