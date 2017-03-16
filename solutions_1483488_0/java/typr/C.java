package qual;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class C {

	public static int[] prepare(int m, int base, int k){
		int[] res = new int[m];
		for (int i = 0; i < m; i++){
			int rest = k % 10;
			k /= 10;
			k += rest * base;
			res[i] = k;
		}
		return res;
	}
	public static void main(String[] args) throws Exception{
		String in_file = "q/c/s_in.txt";
		String out_file = in_file.replace("_in.txt", "_out.txt");
		BufferedReader in = new BufferedReader(new FileReader(in_file));
		BufferedWriter out = new BufferedWriter(new FileWriter(out_file));
		
		int n = Integer.parseInt(in.readLine());
		for (int i = 1; i <= n; i++){
			String[] s = in.readLine().split(" ");
			int a = Integer.parseInt(s[0]);
			int b = Integer.parseInt(s[1]);

			int count = 0;
			int base = 1;
			int m = 0; 
			while (base * 10 <= a) {
				base *= 10;
				m++;
			}
			for (int k = a; k < b; k++){
				int[] prob = prepare(m, base, k);
				for (int p : prob){
					if (p > k && p <= b) count++;
				}
			}
			out.write("Case #" + i + ": " + count + "\n");
		}
		
		in.close();
		out.close();
	}

}
