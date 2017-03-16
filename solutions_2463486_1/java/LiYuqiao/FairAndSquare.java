import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;


public class FairAndSquare {
	public BigInteger [] FS;
	public int cnt;
	public FairAndSquare(){
		cnt=0;
		FS=new BigInteger[100000];
		FS[cnt++]=new BigInteger("1");
		FS[cnt++]=new BigInteger("4");
		FS[cnt++]=new BigInteger("9");
	}
	public void record(char[] num){
		BigInteger bi = new BigInteger(String.valueOf(num));
		BigInteger ans=bi.multiply(bi);
		FS[cnt++]=ans;
	}
	public void DFS(char[] num,int n,int k,int sum){
		if(k>n/2){
			if(n%2==1){
				for(int i=0;i<=2;i++){
					if(sum+i*i<10){
						num[k-1]=(char)('0'+i);
						record(num);
					}
				}
				return;
			}
			record(num);
			return;
		}
		for(int i=0;i<=2;i++){
			if(i==0 && k==1)continue;
			if(sum+2*i*i<10){
				num[k-1]=(char)(i+'0');
				num[n-k]=(char)(i+'0');
				DFS(num,n,k+1,sum+2*i*i);
			}
		}
	}
	public void getFS(){
		for(int i=2;i<=52;i++){
			char[] num=new char[i];
			DFS(num,i,1,0);
		}
	}
	
	
	public static void main(String[] args)throws Exception {
		FairAndSquare fas=new FairAndSquare();
		fas.getFS();
		BufferedReader reader=new BufferedReader(new FileReader("C-large-1.in"));
		BufferedWriter writer=new BufferedWriter(new FileWriter("out.txt"));
		int T=Integer.parseInt(reader.readLine());
		int k=1;
		while(k<=T){
			String[] interval=reader.readLine().split(" ");
			BigInteger A=new BigInteger(interval[0]);
			BigInteger B=new BigInteger(interval[1]);
			int begin=0,end=0;
			int i=0;
			while(fas.FS[i].compareTo(A)<0)
				i++;
			begin=i;
			while(fas.FS[i].compareTo(B)<=0)
				i++;
			end=i;
			int res=end-begin;
			writer.write("Case #"+k+": "+res);
			writer.newLine();
			k++;
			writer.flush();
		}
		reader.close();
		writer.close();
	}
}
