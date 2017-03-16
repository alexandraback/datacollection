import java.util.*;
import java.io.*;

public class Dijkstra {
	
	enum Quaternion {
		one, i, j, k, neg_one, neg_i, neg_j, neg_k;
		
		static Quaternion fromChar(char c) {
			switch (c) {
			case 'i': return Quaternion.i;
			case 'j': return Quaternion.j;
			case 'k': return Quaternion.k;
			default: throw new IllegalArgumentException("You know");
			}
		}
		
		static Quaternion multiply(Quaternion a, Quaternion b) {
			boolean neg = false;
			if ( isNeg(a) ) {
				neg = !neg;
				a = neg(a);
			}
			if ( isNeg(b) ) {
				neg = !neg;
				b = neg(b);
			}
			Quaternion[][] table = 
				{ { Quaternion.one, Quaternion.i, Quaternion.j, Quaternion.k},
				  {	Quaternion.i, Quaternion.neg_one, Quaternion.k, Quaternion.neg_j },
				  { Quaternion.j, Quaternion.neg_k, Quaternion.neg_one, Quaternion.i },
				  { Quaternion.k, Quaternion.j, Quaternion.neg_i, Quaternion.neg_one }
				};
			int row = a.ordinal(); int col = b.ordinal();
			if ( neg ) {
				return neg(table[row][col]);
			} else {
				return table[row][col];
			}
		}
		
		static boolean isNeg(Quaternion a) {
			switch (a) {
			case neg_one: return true;
			case neg_i: return true;
			case neg_j: return true;
			case neg_k: return true;
			default: return false;
			}
		}
		
		static Quaternion neg(Quaternion a) {
			switch (a) {
			case one: return neg_one;
			case i: return neg_i;
			case j: return neg_j;
			case k: return neg_k;
			case neg_one: return one;
			case neg_i: return i;
			case neg_j: return j;
			case neg_k: return k;
			default: throw new RuntimeException("What the heck is a?");
			}
		}
		
		static void print() {
			for ( Quaternion elem1 : values() ) {
				for ( Quaternion elem2 : values() ) {
					System.out.println(elem1 + " x " + elem2 + " = " + multiply(elem1, elem2));
				}
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("dijkstra.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("dijkstra.out")));
		
		int T = Integer.parseInt(f.readLine());
		cases: for ( int i=1; i<=T; i++ ) {
			StringTokenizer st = new StringTokenizer(f.readLine());
			int L = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			while ( M > 12 ) {
				M -= 4;
			}
			String string = f.readLine();
			Quaternion value = Quaternion.one;
			int ptr = 0;
			boolean reachedI = false;
			boolean reachedJ = false;
			while ( ptr < L * M ) {
				int offset = ptr % L;
				value = Quaternion.multiply(value, Quaternion.fromChar(string.charAt(offset)));
				if ( !reachedI ) {
					if ( value == Quaternion.i ) {
						reachedI = true;
						value = Quaternion.one;
					}
				} else {
					if ( !reachedJ ) {
						if ( value == Quaternion.j ) {
							reachedJ = true;
							value = Quaternion.one;
						}
					}
				}
				if ( ptr == L*M - 1 && reachedI && reachedJ ) {
					if ( value == Quaternion.k ) {
						out.println(String.format("Case #%d: YES",i));
						continue cases;
					}
				}
				ptr++;
			}
			
			out.println(String.format("Case #%d: NO",i));
		}
		
		f.close();
		out.close();
	}
}
