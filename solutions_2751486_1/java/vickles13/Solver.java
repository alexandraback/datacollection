import java.util.*;
import java.io.*;
import java.math.*;



public class Solver
{
	
	public String solve1(BufferedReader reader) throws IOException {
		String[] dims = reader.readLine().split(" ");
		String name = dims[0];
		int len = name.length();
		int n = Integer.parseInt(dims[1]);
		long val = 0;
		int[] starts = new int[len];
		int ix = 0;
		int[] ends = new int[len];
		int soFar = 0;
		for (int i = 0; i < len; i++) {
			char c = name.charAt(i);
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				if (soFar >= n) {
					ends[ix] = i-1;
					starts[ix] = i - soFar;
					ix++;
				}
				soFar = 0;
			} else {
				soFar++;
			}
		}
		if (soFar >= n) {
			ends[ix] = len-1;
			starts[ix] = len - soFar;
			ix++;
		}
		if (ix == 0) {
			return "0";
		}
		int s = 0;
		for (int i = 0; i < len; ++i) {
			if (i <= starts[s]) {
				val += len - (starts[s] + n - 1);
			} else if (i + n - 1 <= ends[s]){
				val += len - (i + n-1);
			} else {
				s++; i--;
				if (s >= ix) {break;}
			}
		}
		return "" + val;
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