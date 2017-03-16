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

	//	FileInputStream fin=new FileInputStream("C:/Users/4dm1n/Desktop/D-small-attempt0.in");
	//	File myfile=new File("C:/Users/4dm1n/Desktop/A.out");
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	//	RandomAccessFile rand=new RandomAccessFile(myfile,"rw");
		
		int t,c,k,s,tt,i;
		long idx,dis;
		String st[];
		StringBuilder sb;
		t=Integer.parseInt(br.readLine());
		for(tt=1;tt<=t;tt++){
			st=br.readLine().split(" ");
			k=Integer.parseInt(st[0]);c=Integer.parseInt(st[1]);s=Integer.parseInt(st[2]);
			sb=new StringBuilder("Case #"+tt+": ");
			dis=pow(k,c-1);idx=1;
			for(i=0;i<k;i++){
				sb.append(idx+" ");idx+=dis;
			}
			sb.append("\n");
		//	rand.writeBytes(sb.toString());
			System.out.print(sb);
		}
	}
}