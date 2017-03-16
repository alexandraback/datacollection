import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class C {

	static class Profile {
		int[] nums;
		int[] freq;
		public Profile(int[] n) {
			nums = new int[n.length];
			for (int i=0; i<n.length; i++)
				nums[i] = n[i];
			freq = new int[128];
			rec(0, 1);
		}
		void rec(int idx, int sofar) {
			if (idx == nums.length) {
				freq[sofar]++;
			} else {
				rec(idx+1, sofar);
				rec(idx+1, sofar*nums[idx]);
			}
		}
	}

	static ArrayList<Profile> p;

	public static void main(String[] args) {
		try {
			File fin = new File("C-small-1-attempt0.in");
			Scanner sc = new Scanner(fin);
			File fout = new File("C-small-out.txt");
			PrintWriter pw = new PrintWriter(fout);
			//PrintWriter pw = new PrintWriter(System.out);
			int T = sc.nextInt();
			int R = sc.nextInt();
			int N = sc.nextInt();
			int M = sc.nextInt();
			int K = sc.nextInt();
			int[] nums = new int[N];
			p = new ArrayList<Profile>();
			rec(nums, 0, 2, M);
			pw.write("Case #1:\n");
			for (int i=0; i<R; i++) {
				int[] products = new int[K];
				for (int j=0; j<K; j++) {
					products[j] = sc.nextInt();
				}
				pw.write(solve(N, M, products) + "\n");
			}
			pw.flush();
			pw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}


	static String solve(int N, int M, int[] products) {
		double lowestError = Double.MAX_VALUE;
		Profile bestProfile = null;
		for (Profile pf: p) {
			boolean ok = true;
			for (int product: products) {
				if (pf.freq[product] == 0) {
					ok = false;
					break;
				}
			}
			if (!ok) continue;
			double error = 0.0;
			for (int product: products) {
				int fq = 0;
				for (int p2: products) {
					if (p2 == product) fq++;
				}
				error += Math.abs((1.0*fq/products.length) - (1.0*pf.freq[product]/8.0));
			}
			if (error < lowestError) {
				lowestError = error;
				bestProfile = pf;
			}
		}
		if (bestProfile == null) {
			String ret = "";
			for (int i=0; i<N; i++) ret += "2";
			return ret;
		}
		String ret = "";
		for (int i=0; i<N; i++) {
			ret += bestProfile.nums[i];
		}
		return ret;
	}

	static void rec(int[] nums, int idx, int start, int stop) {
		if (idx==nums.length) {
			p.add(new Profile(nums));
			return;
		}
		for (int a=start; a<=stop; a++) {
			nums[idx] = a;
			rec(nums, idx+1, a, stop);
		}
	}
}
