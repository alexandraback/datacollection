import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class terzo {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("/home/sharkk/Desktop/jam/C-small-attempt1.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("/home/sharkk/Desktop/jam/out")));
		String l;
		l=in.readLine();
		int idx=0;
		while((l=in.readLine())!=null)
		{
			idx++;
			String[] ll = l.split(" ");
			int N = Integer.parseInt(ll[0]);
			int M = Integer.parseInt(ll[1]);
			//int[][] dyn = new int[N+1][M+1];
			long[] A = new long[2*N];
			l=in.readLine();
			int i=0;
			for(String s : l.split(" ")) A[i++] = Long.parseLong(s);
			long[] B = new long[2*M];
			l=in.readLine();
			i=0;
			for(String s : l.split(" ")) B[i++] = Long.parseLong(s);
			
			out.println("Case #"+idx+": "+bt(0,0,A,B));
		}
		out.close();
	}
	static long bt(int i, int j, long[] A, long[] B)
	{
		if((i*2+1)>=A.length) return 0;
		if((j*2+1)>=B.length) return 0;
		
		
		long foo = 0;
		long b = 0;
		if(A[i*2+1]==B[j*2+1])
		{
			if(A[i*2] < B[j*2])
			{
				foo = A[i*2];
				B[j*2] -=  A[i*2];
				b=1;
			}
			else
			{
				foo = B[j*2];
				A[i*2] -= B[j*2];
				b=-1;
			}
		}
		
		long a = 0;
		if(b!=-1) a = Math.max(bt(i+1, j, A, B),a);
		if(b!=1) a = Math.max(bt(i, j+1, A, B),a);
		a = Math.max(bt(i+1, j+1, A, B),a);
		if(b==1) B[j*2] +=  A[i*2];
		else if(b==-1) A[i*2] += B[j*2];
		return a+foo;
	}
}
