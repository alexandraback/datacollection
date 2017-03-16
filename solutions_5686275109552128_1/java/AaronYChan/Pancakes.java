import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;

public class Pancakes {

	public static void main (String [] args) throws IOException {
		String fileRoot = "B-large";
		String fileName = "C:\\Users\\Aaron\\Downloads\\" + fileRoot + ".in";
		BufferedReader reader = new BufferedReader (new FileReader(new File(fileName)));
		int nTestCases = Integer.parseInt(reader.readLine());
		ArrayList<String> out = new ArrayList<String>();
		for (int t = 0; t < nTestCases; t++) {
			reader.readLine();
			String[] parts = reader.readLine().split(" ");
			int[] diners = new int[parts.length];
			int max = 0;
			for (int i = 0; i < parts.length; i++) {
				int in = Integer.parseInt(parts[i]);
				max = Math.max(in, max);
				diners[i] = in;
			}
			
			int[] div = new int[diners.length];
			Arrays.fill(div, 1);
			
			int[] res = diners.clone();
			
			int absMin = max;
			
			while (sumOf(div) - div.length < max) {
				int curMax = 0;
				int ix = 0;
				for (int i = 0; i < res.length; i++) {
					if (res[i] > curMax) {
						curMax = res[i];
						ix = i;
					}
				}
				
				res[ix] = (int)Math.ceil(diners[ix] / (double) (div[ix] + 1));
				div[ix] += 1;
				
				int curCost = getCost(res, div);
				absMin = Math.min(absMin, curCost);
				//System.out.println("Diners: " + Arrays.toString(diners));
				//System.out.println("Div: " + Arrays.toString(div));
				//System.out.println("Res: " + Arrays.toString(res));
				//System.out.println("cost: " + curCost);
				//System.out.println("-----------");
			}
			
			//System.out.println("ABS MIN:  " + absMin);
			
			out.add("Case #" + (t+1) + ": " + absMin);
		}
		
		PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("C:\\Users\\Aaron\\Downloads\\" + fileRoot + "-sol.out")));
		for (String s : out) {
			writer.write(s + "\n");
		}
		
		
		writer.close();
		reader.close();
	}
	
	public static int sumOf (int[] a) {
		int sum = 0;
		for (int i = 0; i < a.length; i++) {
			sum += a[i];
		}
		return sum;
	}
	
	public static int getCost (int[] res, int[] div) {
		int max = 0;
		for (int i : res) max = Math.max(i, max);
		int splitMins = sumOf(div) - div.length;
		return max + splitMins;
	}
	
	
}
