package Problem2;
import java.io.*;
import java.util.*;
import java.lang.*;

public class Solution {
	public static void main(String args[]){
		try{
			File file=new File("C:\\Users\\tanuj\\Downloads\\output.txt");
			BufferedWriter bw=new BufferedWriter(new FileWriter(file));
			BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\tanuj\\Downloads\\input.txt"));
			int T=Integer.parseInt(br.readLine());
			for(int t=0;t<T;t++){
			String s="";
				
			StringTokenizer st=new StringTokenizer(br.readLine());
			int N=Integer.parseInt(st.nextToken());
			int M=Integer.parseInt(st.nextToken());
			long a[]=new long[N];
			long b[]=new long[M];
			int A[]=new int[N];
			int B[]=new int[M];
			st=new StringTokenizer(br.readLine());
			for(int i=0;i<N;i++){
				a[i]=Long.parseLong(st.nextToken());
				A[i]=Integer.parseInt(st.nextToken());
			
			}
			st=new StringTokenizer(br.readLine());
			for(int i=0;i<N;i++){
				b[i]=Long.parseLong(st.nextToken());
				B[i]=Integer.parseInt(st.nextToken());
			}
			long val=calhigh(a,b,A,B,0,0);
			System.out.println(val);
				s=val+"";
				s="Case #"+(t+1)+": "+s;
				bw.write(s);
				bw.newLine();
			}
			bw.close();
		}catch(Exception e){
			System.out.println(e);
		}
	}
	
	public static long calhigh(long a[],long b[],int A[],int B[],int i,int j){
		if(i>=A.length)	return 0;
		else if(j>=B.length) return 0;
		long val=0;
		if(A[i]==B[j]){
			val+=Math.min(a[i],b[j]);
			if(b[j]==a[i])
			val+=calhigh(a,b,A,B,i+1,j+1);
			else if(b[j]>a[i]){
				long ar[]=new long[a.length];
				long br[]=new long[b.length];
				for(int k=0;k<a.length;k++){
					ar[k]=a[i];
				}
				for(int k=0;k<b.length;k++){
					br[k]=br[j];
				}
				br[j]=br[j]-ar[i];
				ar[i]=0;
				val+=calhigh(ar,br,A,B,i+1,j);
			}
			else{
				long ar[]=new long[a.length];
				long br[]=new long[b.length];
				for(int k=0;k<a.length;k++){
					ar[k]=a[i];
				}
				for(int k=0;k<b.length;k++){
					br[k]=br[j];
				}
				ar[i]=ar[i]-br[j];
				br[j]=0;
				val+=calhigh(a,b,A,B,i,j+1);
			}
			
		}
		else{
			val+=Math.max(calhigh(a,b,A,B,i+1,j),calhigh(a,b,A,B,i,j+1));
		}
		System.out.println(i+" "+j+" "+val);
		return val;
	}
}
