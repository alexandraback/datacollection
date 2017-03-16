package Reound1C;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Stack;

public class D {
	public static void main(String[] args) {
		try {
			FileWriter w = new FileWriter(new File("E:\\output.out"));
			BufferedReader r = new BufferedReader(new FileReader(new File("E:\\A-small-attempt0.in")));
			int numbeOfCases = Integer.parseInt(r.readLine());
			for(int t = 0; t < numbeOfCases; t++) {
				int classes = Integer.parseInt(r.readLine());
				int[][] inh = new int[classes][classes];
				for(int i = 0; i < classes; i++) {
					String[] s = r.readLine().split(" ");
					for(int j = 1; j < s.length; j++)
						inh[i][Integer.parseInt(s[j]) - 1] = 1;
				}
				String ans = "No";
				A: for(int i = 0; i < classes; i++)
					for(int j = 0; j < classes; j++)
						if(m(inh, i, j)) {
							ans = "Yes";
							break A;
						}
				w.write("Case #" + (t + 1) + ": " + ans);
				//System.out.print("Case #" + (t + 1) + ": " + ans);
				//System.out.print(x[i] * 100 + " ");
				if(t < numbeOfCases - 1)
					//System.out.print("\n");
					w.write("\n");
				System.out.println(t);
			}
			w.close();
			r.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	private static boolean m(int[][] inh, int f, int t) {
		boolean isVisited = false;
		Stack<Integer> s = new Stack<Integer>();
		s.add(f);
		while(!s.isEmpty()) {
			for(int i = 0; i < inh[f].length; i++) {
				if(inh[f][i] == 1) {
					if(i == t) {
						if(isVisited)
							return true;
						else
							isVisited = true;
					}
					s.add(i);
				}
			}
			f = s.pop();
		}
		return false;
	}
}