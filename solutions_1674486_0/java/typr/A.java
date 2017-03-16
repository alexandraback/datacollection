package a3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class A {
	static class Path{
		boolean expanded = false;
		boolean[] r = new boolean[1000];
		List<Integer> points = new ArrayList<Integer>();
		Path(int... p){
			for (int a : p){
				points.add(a);
			}
		}
		/*boolean merge(Path p){
			for (int i = 0; i < 1000; i++){
				if (r[i] & p.r[i]) return true; else r[i] = r[i] || p.r[i];
			}
			return false;
		}*/
		
		boolean expand(int[][]p){
			while (points.size() > 0){
				int i = points.remove(points.size() - 1);
				if (r[i]) return true; else  r[i] = true;
				for (int a : p[i]) points.add(a);
			}
			return false;
		}
	}
	public static void main(String[] args) throws Exception{
		String in_file = "a3/as.in";
		String out_file = in_file.replace(".in", ".out");
		BufferedReader in = new BufferedReader(new FileReader(in_file));
		BufferedWriter out = new BufferedWriter(new FileWriter(out_file));
		int t = Integer.parseInt(in.readLine());
		for (int i = 1; i <= t; i++){
			String s = in.readLine();
			int n = Integer.parseInt(s);
			int[][] p = new int[n][];
			Path[] paths = new Path[n];
			for (int j = 0; j < n; j++){
				s = in.readLine();
				String [] tmp = s.split(" ");
				int k = Integer.parseInt(tmp[0]);
				p[j] = new int[k];
				for (int jj = 1; jj <= k; jj++){
					int kk = Integer.parseInt(tmp[jj]);
					p[j][jj-1] = kk-1;
				}
				paths[j] = new Path(p[j]);
			}
			
			out.write("Case #" + i + ": ");
			boolean found = false;
			for (int j = 0; j < n; j++){
				found = paths[j].expand(p);
				if (found) break;
			}
			out.write(found ? "Yes\n" : "No\n");
		}
		
		
		in.close();
		out.close();
		
	}
}
