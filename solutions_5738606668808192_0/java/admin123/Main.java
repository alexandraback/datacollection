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
	static long nm[]=new long[11];
	static long getpf(long n){
		long i;
		if(n%2==0) return 2;
		for(i=3;i*i<=n;i+=2){
			if(n%i==0) return i;
		}
		return -1;
	}
	static void getnum(long n){
		long p2=1,p3=1,p4=1,p5=1,p6=1,p7=1,p8=1,p9=1,p10=1;nm[2]=nm[3]=nm[4]=nm[5]=nm[6]=nm[7]=nm[8]=nm[9]=nm[10]=0;
		for(int i=0;i<16;i++){
			if((n&(1<<i))>0){
				nm[2]+=p2;nm[3]+=p3;nm[4]+=p4;nm[5]+=p5;nm[6]+=p6;nm[7]+=p7;nm[8]+=p8;nm[9]+=p9;nm[10]+=p10;
			}
			p2*=2;p3*=3;p4*=4;p5*=5;p6*=6;p7*=7;p8*=8;p9*=9;p10*=10;
		}
	}
	
	
	public static void main(String[] args) throws Exception {
		PrintWriter pr = new PrintWriter(System.out, true);

	//	FileInputStream fin=new FileInputStream("C:/Users/4dm1n/Desktop/D-large.in");
	//	File myfile=new File("C:/Users/4dm1n/Desktop/A.out");
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	//	RandomAccessFile rand=new RandomAccessFile(myfile,"rw");
		
		int t,n,j,i,c,r,tt;
		long num,prime[]=new long[11];
		String st[];
		StringBuilder sb;
		t=Integer.parseInt(br.readLine());
		for(tt=1;tt<=t;tt++){
			st=br.readLine().split(" ");
			n=Integer.parseInt(st[0]);j=Integer.parseInt(st[1]);
			sb=new StringBuilder("Case #"+tt+": \n");
			num=(1<<15)|1;
			while(num<(1<<16)){
				getnum(num);
				for(i=2;i<11;i++){
					prime[i]=getpf(nm[i]);if(prime[i]==-1) break;
				}
				if(i==11){
					sb.append(nm[10]+" ");j--;
					for(i=2;i<11;i++) sb.append(prime[i]+" ");
					sb.append("\n");
				}
				num+=2;if(j==0) break;
			}
		//	sb.append("\n");
		//	rand.writeBytes(sb.toString());
			System.out.print(sb);
		}
	}
}