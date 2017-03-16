import java.io.*;
import java.util.*;

class kingdom
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader r=new BufferedReader(new InputStreamReader(System.in));
		String inp;
		int i,j;
				
		int T=Integer.valueOf(r.readLine());
		for(int a=0;a<T;a++)
		{
			int N=Integer.valueOf(r.readLine());
			int[] A = new int[N];
			int[] B = new int[N];
			for (i=0;i<N;i++) {
				String[] tmp =r.readLine().split("\\s");
				A[i] = Integer.valueOf(tmp[0]); //stars reqd to get 1 star
				B[i] = Integer.valueOf(tmp[1]); //stars reqd to get 2 star
			}
			int out=0;
			int stars=0;
			boolean fail=false;
			int comp=0;
			while(!fail && comp<N) {
				int dtr=0;
				for(i=0;i<N;i++) {
					if(B[i]<=stars && B[i]>=0) {
						stars+=1;
						if(A[i]>=0) stars+=1;
						B[i]=-1; //done
						dtr++;
						comp++;
					}
				}
				if(dtr==0) {
					for(i=0;i<N;i++) {
						if(A[i]<=stars && A[i]>=0) {
							if(B[i]>=0) stars+=1;
							A[i]=-1; //done
							dtr++;
							break;
						}
					}
				}
				if(dtr==0) fail=true;
				out+=dtr;
			}
		
			if(!fail) System.out.println("Case #"+(a+1)+": "+out);
			else  System.out.println("Case #"+(a+1)+": Too Bad");
		}
	}
}
