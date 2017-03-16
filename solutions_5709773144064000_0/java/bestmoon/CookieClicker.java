package codejam2014;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.text.DecimalFormat;

import util.InputReader;

public class CookieClicker implements Runnable{
	private InputReader in;
	private PrintWriter out;
	private static String delimiter = " ";

	public static void main(String[] args) {
		new Thread(new CookieClicker()).start();
	}

	public CookieClicker(){
		try{
			BufferedReader buffer = new BufferedReader(new FileReader("d:\\B-small-attempt0.in"));
			in = new InputReader(buffer);
			System.setOut(new PrintStream(new FileOutputStream("d:\\output.txt")));
			out = new PrintWriter(System.out);
		} catch (FileNotFoundException e) {
			throw new RuntimeException();
		}
	}

	@Override
	public void run() {
		int numTests = in.readInt();

		for (int testNumber = 0; testNumber < numTests; testNumber++) {
			out.print("Case #" + (testNumber + 1) + ": ");
			String line = in.readString();

			String[] token = line.split(delimiter);
			double c = Double.parseDouble(token[0]);
			double f = Double.parseDouble(token[1]);
			double x = Double.parseDouble(token[2]);
			
			int factory = calcFactory(c, f, x);
			double result = 0;
			if(factory == 0) {
				result = x/2;
			}
			else {
				for(int i = 0; i<factory; i++){
					result = result + c/(2+ (i)*f);
				}
				result = result + x/(2+factory*f);
			}
			
			String s = new DecimalFormat("0.0000000").format(result);
			out.println(s.trim());
		}
		out.close();
	}

	private int calcFactory(double c, double f, double x) {
		int n = 0;
		boolean flag = true;
		while(flag) {
			double t1 = x/(2+n*f);
			double t2 = x/(2+(n+1)*f) + c/(2+n*f);
			if(t1 < t2){
				flag = false;
			}
			else {
				n++;
			}
		}
		return n;
	}
}
