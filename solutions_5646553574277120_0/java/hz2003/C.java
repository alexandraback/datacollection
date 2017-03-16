package Round1C;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	static int[] ds;
	public static void zuhe(int V, int index, int sum, int[] ds, boolean cover[]) {
		if (sum > V)
			return;
		cover[sum] = true;
		if (index >= ds.length)
			return;
		zuhe(V, index + 1, sum + ds[index], ds, cover);
		zuhe(V, index + 1, sum, ds, cover);
	}
	
	public static int coverToV(int V, int[] ds) {
		boolean [] cover = new boolean[V + 1];
		zuhe(V, 0, 0, ds, cover);
		for (int i = 1; i <= V; i++)
			if (cover[i] == false)
				return i;
		return V + 1;
	}
	public static int minNum(int V, int[] ds) {
		int temp = coverToV(V, ds);
		int result = 0;
		while (temp <= V) {
			result++;
			int[] t = new int[ds.length + 1];
			for (int i = 0; i < ds.length; i++)
				t[i] = ds[i];
			t[t.length - 1] = temp;
			ds = t;
			temp = coverToV(V, ds);
			System.out.println(Arrays.toString(ds));
		}
		return result;
	}
	public static void main(String[] args) {
		File fin = new File("src/Round1C/C-small-attempt0.in");
		Scanner scan;
		try {
			scan = new Scanner(fin);
		
			PrintWriter output = new PrintWriter("src/Round1C/C_test.out.txt");
			int T = scan.nextInt();
			for(int i = 0; i < T; i++)
			{
				int C = scan.nextInt();
				int D = scan.nextInt();
				int V = scan.nextInt();
				int[] ds = new int[D];
				for(int j = 0; j < D; j++)
					ds[j] = scan.nextInt();
				int result = minNum(V, ds);
				output.println("Case #" + (i + 1) + ": " + result );
				System.out.println("Case #" + (i + 1) + ": " + result);
			}
			scan.close();
			output.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
