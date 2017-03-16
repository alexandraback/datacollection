package recycled;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Arrays;

public class Recycled 
{
	static int[] arr = new int[10];
	
	static int rot(int x, int N, int mult) {
		return x/10 + (x%10)*mult;
	}
	
	static int count(int j, int B, int N, int mult) {
		int cnt = 0;
		int tmp = rot(j,N,mult);
		while (tmp != j) {
			if (tmp > j && tmp <= B) {
				arr[cnt] = tmp;
				++cnt;
			}
			tmp = rot(tmp,N,mult);
		}
		Arrays.sort(arr,0,cnt);
		int ret = 0;
		for (int i = 0; i < cnt; ++i)
		{
			if (i == 0 || arr[i] != arr[i-1]) {
				//System.out.println(j+","+arr[i]);
				++ret;
			}
		}
		return ret;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
		String line = in.readLine();
		int X = Integer.parseInt(line);
		for (int i = 0; i < X; ++i) {
			long ret = 0;
			line = in.readLine();
			String[] toks = line.split(" ");
			int A = Integer.parseInt(toks[0]), B = Integer.parseInt(toks[1]);
			int N = (A+"").length();
			int mult = (int)Math.round(Math.pow(10, N-1));
			//System.out.println("Doing "+A+","+B+" with mult = "+mult);
			for (int j = A; j < B; ++j) {
				ret += count(j,B,N,mult);
			}
			System.out.println("Case #"+(i+1)+": "+ret);
		}
	}
}
