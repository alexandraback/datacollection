package gcj2015Q;

import java.io.*;
import java.util.*;

public class C {
	public static void main(String[] args) {
		new C().run(new Scanner(System.in));
	}

	void run(Scanner sc) {
		int n = sc.nextInt();
		for(int i = 1; n-- > 0; i++)
			solve(sc, i);
	}
	
	static class State {
		enum StateChar{ONE, I, J, K};
		StateChar c;
		boolean sig;
		StateChar get(char c) {
			if(c == 'i') return StateChar.I;
			if(c == 'j') return StateChar.J;
			if(c == 'k') return StateChar.K;
			return StateChar.ONE;
		}
		StateChar getState(StateChar a, StateChar b) {
			if(a == StateChar.ONE) return b;
			if(b == StateChar.ONE) return a;
			
			if(a == b) return StateChar.ONE;
			if(a == StateChar.I && b == StateChar.J) return StateChar.K;
			if(b == StateChar.I && a == StateChar.J) return StateChar.K;
			if(a == StateChar.I && b == StateChar.K) return StateChar.J;
			if(b == StateChar.I && a == StateChar.K) return StateChar.J;
			if(a == StateChar.K && b == StateChar.J) return StateChar.I;
			if(b == StateChar.K && a == StateChar.J) return StateChar.I;
			
			return StateChar.ONE;
		}
		boolean getSig(StateChar a, StateChar b) {
			if(a == StateChar.ONE) return false;
			if(b == StateChar.ONE) return false;

			if(a == b) return true;
			if(a == StateChar.I && b == StateChar.J) return false;
			if(b == StateChar.I && a == StateChar.J) return true;
			if(a == StateChar.I && b == StateChar.K) return true;
			if(b == StateChar.I && a == StateChar.K) return false;
			if(a == StateChar.K && b == StateChar.J) return true;
			if(b == StateChar.K && a == StateChar.J) return false;
			
			return false;
		}
		State(char c) {
			this.c = get(c);
		}
		void setNext(char a) {
			StateChar A = get(a);
			StateChar next = getState(c, A);
			boolean next_sig = sig ^ getSig(c, A);
			c = next;
			sig = next_sig;
		}
		void setFront(char a) {
			StateChar A = get(a);
			StateChar next = getState(A, c);
			boolean next_sig = sig ^ getSig(A, c);
			c = next;
			sig = next_sig;
		}
		public String toString(){
			return (sig ? "-" : "")
					+ (c == StateChar.ONE ? "1" : 
						c == StateChar.I ? "i" : 
							c == StateChar.J ? "j" : "k");
		}
		boolean isI() {
			return c == StateChar.I && !sig;
		}
		boolean isK() {
			return c == StateChar.K && !sig;
		}
		boolean isJ() {
			return c == StateChar.J && !sig;
		}
		boolean isMinus1(long X) {
			if((X & 1) == 1 && sig && c == StateChar.ONE) return true;
			if((X & 3) == 2 && c != StateChar.ONE) return true;
			return false;
		}
	}

	void solve(Scanner sc, int case_num) {
		int L = sc.nextInt();
		long X = sc.nextLong();
		String str = sc.next();
		// total
		State s = new State('1');
		if(true) {
			for(int i = 0; i < L; i++) {
				s.setNext(str.charAt(i));
			}
			boolean isMinus1 = s.isMinus1(X);
			
			// i check
			State s1 = new State('1');
			int i_index0 = 0, i_index1 = 0;
			boolean hasi = false;
			int counter0 = 0;
			a:for(int j = 0; j < 8; j++) {
				for(int i = 0; i < L; i++) {
					s1.setNext(str.charAt(i));
					counter0++;
					if(s1.isI()) {
						i_index0 = j;
						i_index1 = i;
						hasi = true;
						break a;
					}
				}
			}
			
			// k check
			State s2 = new State('1');
			int k_index0 = 0, k_index1 = 0;
			boolean hask = false;
			int counter1 = 0;
			a:for(int j = 0; j < 8; j++) {
				for(int i = L - 1; i >= 0; i--) {
					s2.setFront(str.charAt(i));
	//				System.out.println(s2);
					counter1++;
					if(s2.isK()) {
						k_index0 = j;
						k_index1 = i;
						hask = true;
						break a;
					}
				}
			}
	//		int count = (i_index0 + k_index0) * L + (i_index1 + k_index1);
			int count = counter1 + counter0;
			boolean res = isMinus1 && hasi && hask && count < X * L;
//			if(res) 
//			{
//				System.out.println(i_index0+" "+i_index1+" "+k_index0+" "+k_index1+" "+counter0+" "+counter1+" "+s);
//			}
			
			System.out.printf("Case #%d: %s\n", case_num, res ? "YES" : "NO");
		} else {
			int type = 0;
			for(long x = 0; x < X; x++) {
				for(int i = 0; i < L; i++) {
					s.setNext(str.charAt(i));
					if(type == 0) {
						if(s.isI()) {
							s = new State('1');
							type++;
						}
					}
					if(type == 1) {
						if(s.isJ()) {
							s = new State('1');
							type++;
						}
					}
				}
			}
			boolean res = false;
			if(type == 2 && s.isK()) res = true;

			System.out.printf("Case #%d: %s\n", case_num, res ? "YES" : "NO");
		}
	}
}
