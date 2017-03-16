import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;


public class CookieClicker {

	
public static void main(String[] args) throws IOException{
		
		String fileIn = "C:/Users/Valentin/workspace/GoogleCodeJamQualif/src/B-large.in";
		String fileOut = "C:/Users/Valentin/workspace/GoogleCodeJamQualif/src/test.out";
		System.setIn(new FileInputStream(fileIn));
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		System.setOut(new PrintStream(fileOut));
		
		String line;
		int testCase = 1;
		
		double C = 0.0;
		double F = 0.0;
		double X = 0.0;
		
		boolean firstLine = true;
		while ((line = stdin.readLine()) != null && line.length() != 0) {
			String[] input = line.split(" ");
			if (firstLine) {
				firstLine = false;
				continue; 
			}
			C = Double.parseDouble(input[0]);
			F = Double.parseDouble(input[1]);
			X = Double.parseDouble(input[2]);
			calculate(C, F, X, testCase);
			testCase++;
		}
		
		
	}

	private static void calculate(double c, double f, double x, int testCase) {
		double cookies = 0.0;
		double prod = 2.0;
		double timeForWin = (x - cookies) / prod;
		double timeForNextBuy = (c - cookies) / prod;
		double time = 0.0;
		boolean win = false;
		while (! win) {
			timeForWin = (x - cookies) / prod;
			timeForNextBuy = (c - cookies) / prod;
			if (!rentable(x, c, f, prod)) {
				time += timeForWin;
				win = true;
				break;
			}
			else {
				time += timeForNextBuy;
				cookies = 0.0;
				prod += f;
			}
		}
		System.out.println("Case #" + testCase + ": " + time);
	}

	private static boolean rentable(double x, double c, double f, double prod) {
		double newTime = x / (prod + f);
		double timeToWin = (x - c) / prod;
		return newTime <= timeToWin;
	}
	
}
