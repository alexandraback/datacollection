import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;


public class B {
	static String path = "D:\\Personal\\Dropbox\\Programming\\Google CodeJam 2012\\Round1A\\test\\";
	static String inputfilename = "B-large.in";
	static BufferedReader reader;
	static BufferedWriter writer;
	
	static int nextInt() throws Exception {
		return Integer.parseInt(reader.readLine());
	}
	
	static void nextIntArr(int[] arr) throws Exception {
		String line[] = reader.readLine().split(" ");
		for (int i = 0; i < line.length; i++) {
			arr[i] = Integer.parseInt(line[i]);
		}
	}
	
	static void print(String line) throws Exception {
		writer.write(line);
	}
	
	static void println(String line) throws Exception {
		print(line);
		writer.newLine();
	}
	
	public static void main(String args[]) throws Exception {
		reader = new BufferedReader(new FileReader(path + inputfilename));
		writer = new BufferedWriter(new FileWriter(path + inputfilename + ".out"));
		solve();
		reader.close();
		writer.close();
	}
	
	static void solve() throws Exception {
		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			int n = nextInt();
			int all[][] = new int[n][2];
			for (int j = 0; j < n; j++) {
				nextIntArr(all[j]);
			}
			int star = 0;
			int step = 0;
			boolean first[] = new boolean[n];
			boolean second[] = new boolean[n];
			boolean finished;
			while (true) {
				int j = 0;
				while (j<n && (second[j] || all[j][1]>star)) j++;
				if (j==n) {
					j = -1;
					int max = -1;
					for (int k=0;k<n;k++) {
						if (!first[k] && all[k][0]<=star && (j==-1 || all[k][1]>max)) {
							max = all[k][1];
							j = k;
						}
					}
					if (j==-1)
						break;
					step++;
					first[j] = true;
					star += 1;
				} else {
					if (first[j]) {
						star += 1;
					} else {
						star += 2;
						first[j] = true;
					}
					second[j] = true;
					step++;						
				}
			}
			boolean found = false;
			for (int j = 0; j<n;j++)
				if (!second[j]) {
					found = true;
					break;
				}
			if (found)
				println("Case #"+i+": Too Bad");
			else
				println("Case #"+i+": "+step);
		}
	}
}
