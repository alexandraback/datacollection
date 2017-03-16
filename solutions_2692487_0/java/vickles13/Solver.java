import java.util.*;
import java.io.*;
import java.math.*;



public class Solver
{
	public String solve1(BufferedReader reader) throws IOException {
		long[] dims = convertLong(reader.readLine().split(" "));
		long[] motes = convertLong(reader.readLine().split(" "));
		Arrays.sort(motes);
		return solve1help(dims[0], 0, motes) + "";
	}
	
	public int solve1help(long curSize, int index, long[] motes) {
		if (index >= motes.length) {return 0;}
		if (curSize > motes[index]) {
			return solve1help(curSize + motes[index], index + 1, motes);
		} else {
			// either go to next one or delete them all
			if (curSize == 1) {
				return motes.length - index;
			}
			int numMoves = 0;
			while (curSize <= motes[index]) {
				curSize += curSize - 1;
				numMoves++;
			}
			return Math.min(motes.length - index, numMoves + solve1help(curSize + motes[index], index+1, motes));
		}
	}
	
	public static void main(String[] args)
	{	
		try
		{			
			FileReader flrdr = new FileReader(new File("test.in"));
			BufferedReader br = new BufferedReader(flrdr);
			FileWriter writer = new FileWriter("output.txt");
			int n = Integer.parseInt(br.readLine());
			Solver s = new Solver();
			for(int i = 1; i < n+1; i++)
			{
				System.out.println(i);
				//System.out.println("Case #" + i + ": " + s.solve4(br) + "\n");
				writer.write("Case #" + i + ": " + s.solve1(br) + "\n");
			}
			writer.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	
	public static void checkFiles(String f1, String f2) {
		try {
			FileReader flrd1 = new FileReader(new File(f1));
			FileReader flrd2 = new FileReader(new File(f2));
			BufferedReader br1 = new BufferedReader(flrd1);
			BufferedReader br2 = new BufferedReader(flrd2);
			int count = 1;
			while(br1.readLine().equals(br2.readLine())) {
				count++;
			}
			System.out.println(count);
		}
		catch(Exception e) {e.printStackTrace();}
	}
	
	/* HELPER FUNCTIONS */
		
	// Calculate the ceiling of the square root of a bigint with a binary search.
	public String getSqrt(String num) {
		if(num == "1") {return "1";}
		BigInteger two = new BigInteger("2");
		BigInteger big = new BigInteger(num);
		BigInteger b = big;
		BigInteger a = BigInteger.ONE;
		BigInteger mid;
		BigInteger midsq;
		while (a.compareTo(b) < 0) {
			mid = a.add(b).divide(two).add(BigInteger.ONE);
			midsq = mid.multiply(mid);
			if (midsq.compareTo(big) < 0) {
				a = mid;
			} else if (midsq.compareTo(big) > 0) {
				b = mid.subtract(BigInteger.ONE);
			} else return mid.toString();
		}
		return a.toString();
	}
	
	public int[] convert(String[] s) {
		int[] res = new int[s.length];
		for(int i = 0;i < s.length; i++) {
			res[i] = Integer.parseInt(s[i]);
		}
		return res;
	}
	
	public long[] convertLong(String[] s) {
		long[] res = new long[s.length];
		for(int i = 0;i < s.length; i++) {
			res[i] = Long.parseLong(s[i]);
		}
		return res;
	}
	
	public void printArr(int[][] s) {
		for(int[] row : s) {
			for(int el : row) {System.out.print(el);}
			System.out.println("");
		}
	}
}