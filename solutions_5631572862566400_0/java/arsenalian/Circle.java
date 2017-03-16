import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Circle {
	public static void main (String[] args) throws IOException {
		FileReader fin = new FileReader("CircleInput.txt");
		BufferedReader bin = new BufferedReader (fin);
		int t = Integer.parseInt(bin.readLine());
		FileWriter fout = new FileWriter("CircleOutput.txt");
		BufferedWriter bout = new BufferedWriter(fout);
		PrintWriter pout = new PrintWriter(bout);
		for (int i = 0; i < t; i++) {
			int n = Integer.parseInt(bin.readLine());
			int answer = 0;
			int []f = new int[n];
			ArrayList<ArrayList<Integer>> fi = new ArrayList<ArrayList<Integer>>();
			String s = bin.readLine();
			StringTokenizer st = new StringTokenizer(s);
			for (int j = 0; j < n; j++) {
				fi.add(new ArrayList<Integer>());
			}
			for (int j = 0; j < n; j++) {
				f[j] = Integer.parseInt(st.nextToken())-1;
				fi.get(f[j]).add(j);
			}
			ArrayList<ArrayList<Integer>> paths = new ArrayList<ArrayList<Integer>>();
			for (int j = 0; j < n; j++) {
				HashSet<Integer> visited = new HashSet<Integer>();
				ArrayList<Integer> path = new ArrayList<Integer>();
				path.add(j);
				int current = j;
				while (true) {
					visited.add(current);
					int friend = f[current];
					if (visited.contains(friend)) {
						int ind = path.indexOf(friend);
						int size = path.size() - ind;
						if (size == 2) {
							paths.add(path);
						}
						if (size > answer) answer = size;
						break;
					}
					else {
						current = friend;
						path.add(friend);
					}
				}
			}
			for (int j = 0; j < paths.size(); j++) {
				ArrayList<Integer> p = paths.get(j);
				for (int k = 0; k < n; k++) {
					if (p.contains(k)) continue;
					HashSet<Integer> visited = new HashSet<Integer>();
					ArrayList<Integer> path = new ArrayList<Integer>();
					path.add(k);
					int current = k;
					visited.addAll(p);
					while (true) {
						visited.add(current);
						int friend = f[current];
						if (friend == p.get(0) || friend == p.get(p.size()-1)) {
							int ans = p.size() + path.size();
							if (ans > answer) answer = ans;
							break;
						}
						else if (visited.contains(friend)) {
							break;
						}
						else {
							current = friend;
							path.add(friend);
						}
					}
				}
			}
			
			pout.println("Case #"+(i+1)+": "+answer);
		}
		pout.close();
	}
}
