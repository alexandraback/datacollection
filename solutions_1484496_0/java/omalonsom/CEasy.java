package gcj1012;

import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class CEasy {

	int T;

	char[] code;

	public static void main(String[] args) throws Exception {
		new CEasy().run();
	}

	void run() throws Exception {
		String name = "C-small-attempt0";
		Scanner in = new Scanner(System.in);
		in = new Scanner(new FileInputStream(name + ".in"));
		PrintStream out = System.out;
		out = new PrintStream(name + ".out");
		T = in.nextInt();
		for (int C = 1; C <= T; C++) {
			int N = in.nextInt();

			int S[] = new int [N];
			for (int i = 0; i < S.length; i++)
				S[i] = in.nextInt();

			int [] partition = new int [20];
			if(rec(S,partition,19)){
				out.printf("Case #%d:\n", C);
				for (int i = 0; i < S.length; i++)
					if(partition[i]==1)
						out.print(S[i]+ " ");
				out.println("");
				for (int i = 0; i < S.length; i++)
					if(partition[i]==2)
						out.print(S[i]+ " ");
				out.println("");
			} else
				out.printf("Case #%d: Impossible\n", C);
		}
	}

	boolean rec(int[] S, int P[] , int k){
		if(k==-1) return check(S, P);
		P[k] = 0; if(rec(S,P,k-1))return true;
		P[k] = 1; if(rec(S,P,k-1))return true;
		P[k] = 2; if(rec(S,P,k-1))return true;
		return false;
	}
	boolean check(int[] S, int P[] ){
		boolean valid = false;
		for (int i : P)
			if(i!=0) valid = true;
		if(!valid) return false;
		int sum[] = new int [3];
		for (int i = 0; i < S.length; i++)
			sum[P[i]]+=S[i];
		return sum[1] == sum[2];
	}

}
