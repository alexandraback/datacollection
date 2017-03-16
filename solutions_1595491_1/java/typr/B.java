package qual;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class B {
	public static void main(String[] args) throws Exception{
		String in_file = "q/b/l_in.txt";
		String out_file = in_file.replace("_in.txt", "_out.txt");
		BufferedReader in = new BufferedReader(new FileReader(in_file));
		BufferedWriter out = new BufferedWriter(new FileWriter(out_file));
		
		int t = Integer.parseInt(in.readLine());
		for (int i = 1; i <= t; i++){
			String[] tmp = in.readLine().split(" ");
			int n = Integer.parseInt(tmp[0]);
			int s = Integer.parseInt(tmp[1]);
			int p = Integer.parseInt(tmp[2]);
			int[] res = new int[n];
			for (int j = 0; j < n; j++){
				res[j] = Integer.parseInt(tmp[j + 3]);
			}

			int min = p > 0 ? p + (p-1) * 2 : p;
			int sup_min = p > 1 ? p + (p-2) * 2 : p;
			int count = 0;
			for (int j = 0; j < n; j++){
				int cres = res[j];
				if (cres >= min) {
					count++;
				} else if (s > 0 && cres >= sup_min) {
					count++;
					s--;
				}
			}
			out.write("Case #" + i + ": " + count + "\n");
		}
		
		in.close();
		out.close();
	}
}
