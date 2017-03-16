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
	
	public String solve2(BufferedReader reader) throws IOException{
		int[] dims = convert(reader.readLine().split(" "));
		String ans = "";
		if (dims[0] < 0) {
			for (int i = 0; i > dims[0]; --i) {
				ans += "EW";
			}
		} else {
			for (int j = 0; j < dims[0]; ++j) {
				ans += "WE";
			}
		} 
		if (dims[1] < 0) {
			for (int i = 0; i > dims[1]; --i) {
				ans += "NS";
			}
		} else {
			for (int j = 0; j < dims[1]; ++j) {
				ans += "SN";
			}
		}
		return ans;/*
		
		int n = Math.abs(dims[1]) + Math.abs(dims[0]);
		int[][] grid = new int[2*n][2*n];
		grid[n+1][n] = 1;
		grid[n][n+1] = 1;
		grid[n-1][n] = 1;
		grid[n][n-1] = 1;
		String[][] gridS = new String[2*n][2*n];
		for (int i = 0; i < gridS.length; ++i) {
			for (int j = 0; j < gridS.length; ++j) {
				gridS[i][j] = "";
			}
		}
		for (int i = 0; i <= n; ++i) {
			for (int j = n-i; j <= n+i; j++) {
				for (int k = n-i; k <= n+i; k++) {
					int min = 1000000000;
					if(k - i >= 0 && grid[j][k-i] > 0) {
						min = Math.min(min, grid[j][k-i]);
					} else if (k+ i < 2*n && grid[j][k+i] > 0) {
						min = Math.min(min, grid[j][k+i]);
					} else if ( j + i < 2*n && grid[j+i][k] > 0) {
						min = Math.min(min, grid[j+i][k]);
					} else if (j - i>=0 && grid[j-i][k] > 0) {
						min = Math.min(min, grid[j-i][k]);
					}
					
					if(k - i >= 0 && grid[j][k-i] > 0 && min == grid[j][k-i]) {
						gridS[j][k] = gridS[j][k-i] + "N";
						grid[j][k] = grid[j][k-i] + 1;
					} else if (k+ i < 2*n && grid[j][k+i] > 0 && min == grid[j][k+i]) {
						gridS[j][k] = gridS[j][k+i] + "S";
						grid[j][k] = grid[j][k+i] + 1;
					} else if ( j + i < 2*n && grid[j+i][k] > 0 && min == grid[j+i][k]) {
						gridS[j][k] = gridS[j+i][k] + "W";
						grid[j][k] = grid[j][k+i] + 1;
					} else if (j - i>=0 && grid[j-i][k] > 0 && min == grid[j-i][k]) {
						gridS[j][k] = gridS[j-i][k] + "E";
						grid[j][k] = grid[j-i][k] + 1;
					}
					if (j == dims[0] + n && k == dims[1] + n) {
						return gridS[j][k];
					}
				}
			}
		}
		return "HELP";*/
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
				writer.write("Case #" + i + ": " + s.solve2(br) + "\n");
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