import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;


public class R1_ProblemA {

	public static String name="ProblemA";
	public static long[] motes;
	public static long size;
	public static long best;
	public static void main(String[] args) throws IOException{
		BufferedReader buf=new BufferedReader(new FileReader(name+".txt"));
		PrintWriter printer=new PrintWriter(name+"_out.txt");
		int numTrial=Integer.parseInt(buf.readLine());
		for(int i=1;i<=numTrial;i++){
			printer.print("Case #"+i+": ");
			String[] s=buf.readLine().split(" ");
			size=Long.parseLong(s[0]);
			int p=Integer.parseInt(s[1]);
			s=buf.readLine().split(" ");
			motes=new long[p];
			for(int j=0;j<p;j++)
				motes[j]=Long.parseLong(s[j]);
			Arrays.sort(motes);
			best=motes.length;
			int k=-1;
			int op=0;
			while(k!=0){
				k=choose(op);
				if(k==1)
					op++;
			}
			for(k=0;k<motes.length;k++)
				if(motes[k]!=Long.MAX_VALUE)
					op++;
			printer.println(best);
		}
		printer.close();
	}
	public static int choose(int op){
		while(motes[0]<size){
			for(int i=0;i<motes.length;i++)
				if(motes[i]==Long.MAX_VALUE)
					break;
				else if(motes[i]<size){
					size+=motes[i];
					motes[i]=Long.MAX_VALUE;
				}
			Arrays.sort(motes);
		}
		//System.out.println(size);
		int k=0;
		while(k<motes.length&&motes[k]!=Long.MAX_VALUE)
			k++;
		best=Math.min(best,op+k);
		if(op>motes.length)
			return 0;
		if(motes[0]==Long.MAX_VALUE)
			return 0;
		size=size*2-1;
		return 1;
	}


}
