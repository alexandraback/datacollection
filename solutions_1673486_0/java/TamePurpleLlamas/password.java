import java.io.*;
import java.util.*;
public class password
{	
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(new File("password.in"))));
		PrintStream out = new PrintStream(new File("password.out"));
		int tests = Integer.parseInt(in.readLine());
		StringTokenizer s1;
		for(int a = 1; a <= tests; a++){
			s1 = new StringTokenizer(in.readLine(), " ");
			int A = Integer.parseInt(s1.nextToken());
			int B = Integer.parseInt(s1.nextToken());
			double[] probs = new double[A];
			s1 = new StringTokenizer(in.readLine(), " ");
			for(int x = 0; x < A; x++)
				probs[x] = Double.parseDouble(s1.nextToken());
			double[] chanceAtPos = new double[A+1];
			for(int x = 1; x < A+1; x++){
				double temp = 1;
				for(int y = 0; y < x-1; y++)
					temp *= probs[y];
				temp *= (1-probs[x-1]);
				chanceAtPos[x] = temp;
			}
			chanceAtPos[0] = 1;
			for(int x = 0; x < A; x++)
				chanceAtPos[0] *= probs[x];
			//option 1
			int keystrokes = B - A +1 ; //including enter
			double opt1;
			opt1 = keystrokes * chanceAtPos[0] + (1-chanceAtPos[0]) * (keystrokes + B + 1);
			//option 2
			double opt2 = Double.MAX_VALUE;
			for(int backspace = 1; backspace <= A; backspace++){
				double valueIfDel = 0;
				double valueIfNot = 0;
				int IfDel = backspace*2 + (B-A) + 1; //including enter
				int IfNot = backspace*2 + (B-A) + 1 + B + 1;
				for(int x = 0; x < A - backspace; x++)
					valueIfNot += IfNot * chanceAtPos[x+1];
				for(int x = A-backspace; x < A; x++)
					valueIfDel += IfDel * chanceAtPos[x+1];
				valueIfDel += IfDel * chanceAtPos[0];
				if(valueIfDel+valueIfNot < opt2){
					System.out.println(backspace);
					opt2 = valueIfDel+valueIfNot;
				}	
			}
			//option 3
			double opt3 = 1 + B + 1;
			double ult;
			if(opt1 < opt2 && opt1 < opt3)
				ult = opt1;
			else if(opt2 < opt1 && opt2 < opt3)
				ult = opt2;
			else
				ult = opt3;
			String tempa = "" + ult;
			int qw = tempa.indexOf('.');
			int add = 6 - (tempa.length() - qw - 1);
			if(add > 0)
				for(int x = 0; x < add; x++)
					tempa += '0';
			else{
				ult = ult * Math.pow(10, 6);
				int temp = (int)(ult);
				ult = temp / Math.pow(10, 6);
				tempa = "" + ult;
			}
			out.println("Case #" + a + ": " + tempa);
		}
	}
}