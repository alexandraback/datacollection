import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.RandomAccessFile;
import java.util.InputMismatchException;

public class Main {
	
	static long pow(long a,int p){
		long ans=1;
		while(p>0){
			if((p&1)>0) ans=ans*a;
			a=a*a;p>>=1;
		}
		return ans;
	}
	
	public static void main(String[] args) throws Exception {
		PrintWriter pr = new PrintWriter(System.out, true);

	//	FileInputStream fin=new FileInputStream("C:/Users/4dm1n/Desktop/D-large.in");
	//	File myfile=new File("C:/Users/4dm1n/Desktop/A.out");
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	//	RandomAccessFile rand=new RandomAccessFile(myfile,"rw");
		
		int t,c,k,s,tt,i,j,r,cc;
		long idx,dis,loc,diff;
		String st[];
		StringBuilder sb;
		t=Integer.parseInt(br.readLine());
		for(tt=1;tt<=t;tt++){
			st=br.readLine().split(" ");
			k=Integer.parseInt(st[0]);c=Integer.parseInt(st[1]);s=Integer.parseInt(st[2]);
			sb=new StringBuilder("Case #"+tt+": ");
			if((k/c)+(k%c>0?1:0)>s){
				sb.append("IMPOSSIBLE");
			}
			else{
				r=k/c;dis=pow(k,c-1);
				for(i=1;i<=r;i++){
					loc=0;diff=dis;
					for(j=1;j<=c;j++){
						loc+=((i-1)*c+j-1)*diff;
						diff/=k;
					}
					loc+=1;
					sb.append(loc+" ");
				}
				if(k%c>0){
					cc=k%c;dis=pow(k,cc-1);
					loc=0;diff=dis;
					for(j=1;j<=cc;j++){
						loc+=(r*c+j-1)*diff;
						diff/=k;
					}
					loc*=pow(k,c-cc);
					loc+=1;
					sb.append(loc+" ");
				}
			}
			sb.append("\n");
	//		rand.writeBytes(sb.toString());
			System.out.print(sb);
		}
	}
}