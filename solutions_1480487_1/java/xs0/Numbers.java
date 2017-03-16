package codejam.round1B;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.LineNumberReader;
import java.util.ArrayList;

public class Numbers {
	static boolean couldLose(double[] others, double have, int index, double remain) {
		int n = others.length;
		for (int a = 0; a < n; a++) {
			if (a == index)
				continue;
			
			if (others[a] < have) {
				if (others[a] + remain <= have)
					return false;
				remain -= have - others[a];
			}
		}
		
		return true;
	}
	
	static double[] compute(double[] input) {
		int n = input.length;
		double[] res = new double[n];
		
		for (int a = 0; a < n; a++) {
			double add = 0;
			double step = 1;
			while (step > 0.0000000000000001) {
				step *= 0.5;
				if (couldLose(input, input[a] + add + step, a, 1.0 - add - step))
					add += step;
			}
			
			res[a] = add;
		}
		
		return res;
	}
	
	public static void main(String[] args) throws IOException {
		File f = new File("/home/mitja/cj/A");
		for (File input : f.listFiles()) {
			if (input.isFile() && input.getName().endsWith(".in")) {
				File output = new File(f, input.getName() + ".out");
				
				FileWriter out = new FileWriter(output);
				
				int[][] lines = readInts(input);
				
				int nCases = lines[0][0];
				for (int c = 1; c <= nCases; c++) {
					int[] l = lines[c];
					int sum = 0;
					for (int i = 1; i <= l[0]; i++)
						sum += l[i];
					
					double[] data = new double[l[0]];
					for (int i = 1; i <= l[0]; i++)
						data[i - 1] = (double)l[i] / sum;
					
					double[] res = compute(data);
					StringBuilder sb = new StringBuilder();
					sb.append("Case #").append(c).append(":");
					for (double d : res)
						sb.append(' ').append(d * 100);
					
					System.out.println(sb);
					out.append(sb.append("\n"));
				}
				
				out.close();
			}
		}
	}

	private static int[][] readInts(File input) throws IOException {
		ArrayList<int[]> out = new ArrayList<int[]>();
		
		LineNumberReader lnr = new LineNumberReader(new FileReader(input));
		
		String l;
		while ((l = lnr.readLine()) != null) {
			String[] parts = l.trim().split(" ");
			
			int[] i = new int[parts.length];
			for (int a = 0; a < parts.length; a++)
				i[a] = Integer.parseInt(parts[a]);
			
			out.add(i);
		}
		
		return out.toArray(new int[out.size()][]);
	}
}
