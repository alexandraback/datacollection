import java.util.*;
import java.math.*;
public class B {
	static long MOD = 1000000007;
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		long [] fact = new long [101];
		fact[0] =1;
		for (int i = 1; i<fact.length; ++i) {
			fact[i] = ((fact[i-1]) * ((long)i)) % MOD;
		}
		
		
		for (int iii = 1; iii<=T; ++iii) {
			int N = Integer.parseInt(sc.nextLine());
			String s = sc.nextLine();
			String [] b = s.split(" ");
			char [][] tmp = new char [b.length][];
			for (int i = 0; i<b.length; ++i) tmp[i] = b[i].toCharArray();
			int [] numu = new int [256];
			char [] tmpL = new char [tmp.length];
			char [] tmpF = new char [tmp.length];
			boolean [] usedindex = new boolean [tmp.length];
			
			boolean works = true;
			for (int i = 0; i<b.length; ++i) {
				if (tmp[i][0] == tmp[i][tmp[i].length-1]) numu[tmp[i][0]]++;
				tmpL[i] = tmp[i][tmp[i].length-1];
				tmpF[i] = tmp[i][0];
				//if (tmpL[i] == tmpF[i]) usedindex[i] = true;
				if (!valid(b[i])) works = false;
			}
			
			long ans = 1;
			int groupcnt = 0;
			boolean [] usedchar = new boolean [256];
			StringBuilder bb = new StringBuilder(s.length());
			
			A : while (true) {
				char c = findStart(tmp, usedindex, usedchar);
				if (c == 0) break;
				groupcnt++;
				usedchar[c] = true;
				for (int ii = 0; ii<tmp.length; ++ii) if (tmpL[ii] == c && tmpF[ii] == c) bb = bb.append(b[ii]);	

				//System.err.println("Found Group @ " + c + " w/ fact " +fact[numu[c]]);
				
			
				long groupc = fact[numu[c]];
				for (int i = 0; i<tmp.length; ++i) {
					if (usedindex[i]) continue;
					if (tmpF[i] == c && tmpL[i] != c) {
						//System.err.println("Found Connection From " + c + "  - > " + ((char)tmpL[i]));
					
						if (usedchar[tmpL[i]]) { works = false; break A; }
						c = tmpL[i];
						usedchar[c] = true;
						usedindex[i] = true;
						groupc = (groupc * fact[numu[c]]) % MOD;
						bb = bb.append(b[i]);
						for (int ii = 0; ii<tmp.length; ++ii) if (tmpL[ii] == c && tmpF[ii] == c) bb = bb.append(b[ii]);	
						i = -1;
					}
				}
				ans = (ans * groupc) % MOD;
			}
			for (int i = 0; i<tmp.length; ++i) if (tmpL[i] != tmpF[i] && !usedindex[i]) works = false;
			ans = (ans * fact[groupcnt]) % MOD;
			
			if (works && !valid(bb.toString())) works = false;
			if (!works) ans = 0;
			
			
			
			System.out.printf("Case #%d: %d\n",iii,((int)ans));
		}
	}
	public static char findStart(char [][] tmp, boolean [] usedi, boolean [] usedc) {
		D : for(char c = 'a'; c <= 'z'; ++c) {
			if (usedc[c]) continue;
			for (int i =0; i<tmp.length; ++i) {
				if (tmp[i][tmp[i].length-1] == c && tmp[i][0] != c) continue D;
			}
			
			for (int i = 0; i<tmp.length; ++i) {
				if (usedi[i] || tmp[i][0] != c) continue;
				if (tmp[i][tmp[i].length-1] == c) continue;
				
				// Found one
				return c;
				
			}
			for (int i = 0; i<tmp.length; ++i) {
				if (usedi[i] || tmp[i][0] != c) continue;
				if (tmp[i][tmp[i].length-1] == c) return c;
				// Found a unitary group
			}
			
		}
		return (char)0;
	}
	
	
	public static boolean valid (String s) {
		boolean [] used = new boolean [256];
		char [] tmp = s.toCharArray();
		used[tmp[0]] = true;
		for (int i = 1; i<s.length(); ++i) {
			if (tmp[i] == tmp[i-1]) continue;
			if (used[tmp[i]]) return false;
			used[tmp[i]] = true;
		
		}
		return true;
	}
	
	

	
}