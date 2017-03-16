package codejam.y2013.round1B;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class A {
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new FileReader("inputs/1B/A.in"));
		PrintWriter output = new PrintWriter("inputs/1A/A.out");

		String out;
		int N = input.nextInt();
		for(int c = 1; c <= N; c++) {
			int A = input.nextInt();
			int N2 = input.nextInt();
			ArrayList<Integer> motes = new ArrayList<Integer>(N2);
			for(int i = 0; i < N2; i++) {
				motes.add(input.nextInt());
			}
			Collections.sort(motes);
			int s = motes.size();
			for(int i = 0; i < s; i++) {
				if(motes.get(0) < A) {
					A += motes.get(0);
					motes.remove(0);
				} else {
					break;
				}
			}
			
			
			out = "Case #" + c + ": " + solve(A, motes, null);
			output.println(out);
			System.out.println(out);
		}
		input.close();
		output.close();
	}
	
	private static long solve(int A, ArrayList<Integer> m, ArrayList<Integer> motes) {
		int s = m.size();
		long temp, count;
		long min = s;
		if(s > 0) {
			for(int i = 1; i < s; i++) {
				motes = (ArrayList<Integer>) m.clone();
				temp = A;
				count = i;
				for(int j = 0; j < i; j++) {
					temp += temp-1;
					while(motes.size() != 0 && temp > motes.get(0)) {
						temp += motes.get(0);
						motes.remove(0);
					}
				}
				for(int j = motes.size()-1; j >= 0; j--) {
					if(temp <= motes.get(j))
						count++;
					else
						break;
				}
				min = Math.min(min, count);
			}
			return min;
		} else {
			return 0;
		}
	}
	
}

