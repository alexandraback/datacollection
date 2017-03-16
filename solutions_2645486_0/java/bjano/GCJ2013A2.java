import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;


public class GCJ2013A2 {

	static long carry[];
	static long use[];
	static long value[];
	static long newE[];
	
//	public static long solveFor(long ) {
		
//	}
	
	/*
	public static long solveFor(long[] maxE, long[] addE, long[] gains) {
		long mval = -1;
		int mpos = -1;
		for (int i=0;i<gains.length;i++)
		{
			if (gains[i]>mval)
			{
				mval = gains[i];
				mpos = i;
			}
		}
		int ix = mpos;
		long gainNow = 0;
		long usedE = 0;
		while ((ix>0) && (maxE[mpos] > 0))
		{
			
		}
		
		
	}*/
	
	public static void setCarryToMax(int fromTaskIx,long maxNewCarry,long E,long R,int N) {
		if (maxNewCarry <= 0)
			return;
		
		long possibleMaxCarry = E - R;
		
		if (maxNewCarry + carry[fromTaskIx] > possibleMaxCarry)
			maxNewCarry = possibleMaxCarry - carry[fromTaskIx];
		
		long prevCarry = 0;
		if (fromTaskIx > 0)
		{
			prevCarry = carry[fromTaskIx-1];
		
			long needFromPrev = maxNewCarry - (newE[fromTaskIx] + prevCarry - use[fromTaskIx]);
		
			if (needFromPrev > 0)
				setCarryToMax(fromTaskIx-1, needFromPrev, E,R,N);
			prevCarry = carry[fromTaskIx-1];
		}
		
		long av = newE[fromTaskIx] + prevCarry  - use[fromTaskIx];
		if (av > maxNewCarry)
			av = maxNewCarry;
		
		carry[fromTaskIx] += av;
	}

	
	public static void main(String[] args) throws Exception{
//		String fname = "B_example";
		String fname = "B_small";
//		String fname = "B_large";
		
		File file = new File(fname+"_in.txt");
		Scanner scanner = new Scanner(file);

		FileWriter outFile = new FileWriter(fname+"_out.txt");
		PrintWriter outp = new PrintWriter(outFile);
		
		int T = scanner.nextInt();
		
		long maxRes = 1;
		for (int i=0;i<18;i++)
			maxRes = maxRes * 10;
		
		carry = new long[10000];
		use = new long[10000];
		value = new long[10000];
		newE = new long[10000];
		
		for (int i=1;i<=T;i++)
		{
			long E = scanner.nextLong();
			long R = scanner.nextLong();
			int N = scanner.nextInt();
			
			for (int j=0;j<N;j++)
			{
				carry[j] = 0;
				use[j] = 0;
				value[j] = scanner.nextLong();
				newE[j] = R;
			}
			newE[0] = E;
			
			Integer[] idx = new Integer[(int)N];
			for (int j=0;j<idx.length;j++)
				idx[j] = j;

			Arrays.sort(idx, new Comparator<Integer>() {
			    @Override public int compare(final Integer o1, final Integer o2) {
			        return (int)(value[o2.intValue()] - value[o1.intValue()]);
			    }
			});
			
			for (int j=0;j<idx.length;j++)
			{
				int ix = idx[j];
				long prevCarry = 0;
				if ( ix > 0)
				{
					setCarryToMax(ix-1,999999999,E,R,N);
					prevCarry = carry[ix-1];
				}
				use[ix] = prevCarry + newE[ix] - carry[ix];
				
//				System.out.printf("%d ",idx[j]);
			}
			long g = 0;
			for (int j=0;j<N;j++)
				g += value[j] * use[j];
			
			System.out.printf("\n");
			
			outp.printf("Case #%d: %d\n",i,g);
			
//			for (int j=0;j<100;j++) System.out.printf("%d:%b ",j,isEnough(r,t,j));
//			System.out.printf("\n\n");
		}
		
		outp.close();

	}

}
