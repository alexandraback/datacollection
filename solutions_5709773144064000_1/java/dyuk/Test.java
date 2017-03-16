import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test {
	public static void main(String[] args) {
		try {
			InputStream inputStream = new FileInputStream(
					"D:\\codeforse\\CF\\input.txt");
			OutputStream outputStream = new FileOutputStream(
					"D:\\codeforse\\CF\\output.txt");
			// InputStream inputStream = System.in;
			// OutputStream outputStream = System.out;
			InputReader in = new InputReader(inputStream);
			PrintWriter out = new PrintWriter(outputStream);
			C solver = new C();
			int t = in.nextInt();
			for (int i = 0; i < t; i++) {
				solver.solve(i + 1, in, out);
				if (i!=t-1){
					//out.println();
				}
			}
			out.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}

class C {

	public void solve(int testNumber, InputReader in, PrintWriter out) {
		double c = in.nextDouble();
		double f = in.nextDouble();
		double x = in.nextDouble();

		double prize = 2;
		
		//System.out.println("--- " +c+" "+f+" "+x+" "+prize);
		double time = 0;
		double t1;
		double t2;
		double t3;
		while (true){
			t1 = c/prize;
			t3 = x/prize;
			prize+=f;
			t2 = x/prize;
			if ((t1+t2)>t3){
				time+=t3;
				break;
			}else{
				time+=t1;
			}
			//System.out.println(t1+" "+t2+" "+t3+" "+time+" "+ prize);
		}
		
			 //System.out.println(time);
		
		out.println("Case #" + testNumber + ": "+time);


	}

	private static double round(double number) {
		double tmp = number * 10000000;
		return (double) (long) ((tmp - (long) tmp) >= 0.5f ? tmp + 1 : tmp) / 10000000;
	}

	private static double round1(double number) {
		double tmp = number * 100000;
		return (double) (long) ((tmp - (long) tmp) >= 0.5f ? tmp + 1 : tmp) / 100000;
	}
}

class pair {

}

class InputReader {

	public BufferedReader reader;
	public StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public Double nextDouble() {
		return Double.parseDouble(next());
	}

}
