import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;

public class LessMoney {

	public static void main (String [] args) throws IOException {
		String root = "C-small-attempt0";
		String fileName = "C:\\Users\\Aaron\\Downloads\\" + root + ".in";
		BufferedReader reader = new BufferedReader (new FileReader(new File(fileName)));
		int nTestCases = Integer.parseInt(reader.readLine());
		ArrayList<String> out = new ArrayList<String>();
		for (int t = 0; t < nTestCases; t++) {
			String[] bn = reader.readLine().split(" ");
			
			int maxCoins = Integer.parseInt(bn[0]);			
			int maxValue = Integer.parseInt(bn[2]);
			
			String[] denoms = reader.readLine().split(" ");
			ArrayList<Integer> coins = new ArrayList<Integer>();
			for (int i = 0; i < denoms.length; i++) coins.add(Integer.parseInt(denoms[i]));
			
			
			int[][] v = computeTable(maxValue, maxCoins, coins);
			
			int ans = 0;
			int nextDenom = findMissing(v, 0);
			while (nextDenom != -1) {
				ans++;
				coins.add(nextDenom);
				v = computeTable(maxValue, maxCoins, coins);
				nextDenom = findMissing(v, nextDenom);
			}
			
			System.out.println("CASE " + (t + 1) + ": " + ans);
			out.add("Case #" + (t+1) + ": " + ans);
			System.out.println("-----------------");
		}
		
		PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("C:\\Users\\Aaron\\Downloads\\"+ root + "-SOL.out")));
		for (String s : out) {
			writer.write(s + "\n");
		}
		
		writer.close();
		reader.close();
	}
	
	public static int findMissing (int[][] v, int start) {
		for (int i = start; i < v.length; i++) {
			if (v[i][0] != 1) {
				return i;
			}
		}
		return -1;
	}
	
	public static int[][] computeTable (int maxValue, int maxCoins, ArrayList<Integer> coins) {
		int[][] v = new int[maxValue + 1][coins.size() + 1];
		for (int[] i : v) {
			Arrays.fill(i, Integer.MAX_VALUE);
		}
		
		Arrays.fill(v[0], 0);
		v[0][0] = 1;
		
		
		for (int i = 0; i < v.length; i++) {
			for (int j = 0; j < coins.size(); j++) {
				if (i + coins.get(j) < v.length && v[i][0] == 1) {
					//Check to see if it's optimal - minimize the maximum # of a particular denom
					int[] component = v[i].clone();
					component[j + 1] += 1;
					if (component[j + 1] > maxCoins) continue;
					
					int maxOriginal = maxAcross(component);
					int maxNew = maxAcross(v[i + coins.get(j)]);
					if (maxOriginal < maxNew) {
						v[i + coins.get(j)] = component;
					}
				}
			}
		}
		
		return v;
	}
	
	public static int maxAcross (int[] a) {
		int max = 0;
		for (int i : a) max = Math.max(i, max);
		return max;
	}
}
