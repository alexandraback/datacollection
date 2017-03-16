import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;


public class A {

	static String path = "D:\\Personal\\Dropbox\\Programming\\Google CodeJam 2012\\Round1A\\test\\";
	static String inputfilename = "A-large.in";
	static BufferedReader reader;
	static BufferedWriter writer;
	
	static int nextInt() throws Exception {
		return Integer.parseInt(reader.readLine());
	}
	
	static void nextDoubleArr(double[] arr) throws Exception {
		String line[] = reader.readLine().split(" ");
		for (int i = 0; i < line.length; i++) {
			arr[i] = Double.parseDouble(line[i]);
		}
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
		int i;
		for (i=0;i<t;i++) {
			int[] arr = new int[2];
			nextIntArr(arr);
			int a = arr[0];
			int b = arr[1];
			double[] p = new double[a];
			nextDoubleArr(p);
			double min = 2 + b;
			double d = 1;
			for (int j = 0; j<a; j++) {
				d *= p[j];
				min = Math.min(min, d*(2*(a-j-1)+b-a+1) + (1-d)*(2*(a-j-1)+2*b-a+2));
			}
			println("Case #"+(i+1)+": "+min);
		}
	}

}
