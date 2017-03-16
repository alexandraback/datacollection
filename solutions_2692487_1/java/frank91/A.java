/**
 * User: francesco
 * Date: 25/04/13
 * Time: 16:16
 */

import java.util.Scanner;
import java.io.PrintWriter;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.util.Arrays;
public class A {
	public static void main(String[] args) {
		String base = "/Users/francesco/Dropbox/Work/codejam/io/";
		String input = base + "input.in";
		String output = base + "ouput.out";

		try {
			Scanner in = new Scanner(new FileReader(input));
			PrintWriter out = new PrintWriter(output);

			int n = in.nextInt();

			for (int c = 0; c < n; c++) {
				System.out.println("Test case: " + (c + 1));
				out.print("Case #" + (c + 1) + ": ");
				TaskA task = new TaskA();
				task.solve(in, out);
				out.println();
			}
			out.close();
			in.close();
		} catch (FileNotFoundException ex) {
			ex.printStackTrace();
		}

	}
}

class TaskA {
	int A,N;
	int[] mote;
	public void solve(Scanner in, PrintWriter out) {
		A = in.nextInt();
		N = in.nextInt();
		mote = new int[N];
		for (int i = 0; i< N; i++){
			mote[i] = in.nextInt();
		}
		Arrays.sort(mote);

		if(A==1){
			out.print(N);
		} else {
			out.print(moves(A,0,0));
		}
	}

	public int moves(int a, int i, int moves){
		if(N==moves){
			return Integer.MAX_VALUE;
		} else {
			for(;i<mote.length;i++){
				if(a>mote[i]){
					a+=mote[i];
				} else {
					int tmp = moves(a+a-1,i,moves+1);
					int tmp2 = moves + N-i;
					if(tmp < tmp2){
						return tmp;
					} else {
						return tmp2;
					}
				}
			}
			return moves;
		}
	}
}