import java.util.Scanner;
public class A {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		for(int i = 1; i<=N; i++) {
			
			String s = sc.next();
			int[] nbs = new int['Z'+1];
			for(int j = 0; j<s.length(); j++) {
				nbs[s.charAt(j)]++;
			}
			int hm[] = new int[10];
			hm[0] = nbs['Z'];
			nbs['Z'] -= hm[0];
			nbs['E'] -= hm[0];
			nbs['R'] -= hm[0];
			nbs['O'] -= hm[0];
			hm[2] = nbs['W'];
			nbs['T'] -= hm[2];
			nbs['W'] -= hm[2];
			nbs['O'] -= hm[2];
			hm[4] = nbs['U'];
			nbs['F'] -= hm[4];
			nbs['O'] -= hm[4];
			nbs['U'] -= hm[4];
			nbs['R'] -= hm[4];
			hm[3] = nbs['R'];
			nbs['T'] -= hm[3];
			nbs['H'] -= hm[3];
			nbs['R'] -= hm[3];
			nbs['E'] -= hm[3];
			nbs['E'] -= hm[3];
			hm[5] = nbs['F'];
			nbs['F'] -= hm[5];
			nbs['I'] -= hm[5];
			nbs['V'] -= hm[5];
			nbs['E'] -= hm[5];
			hm[6] = nbs['X'];
			nbs['S'] -= hm[6];
			nbs['I'] -= hm[6];
			nbs['X'] -= hm[6];
			hm[7] = nbs['S'];
			nbs['S'] -= hm[7];
			nbs['E'] -= hm[7];
			nbs['V'] -= hm[7];
			nbs['E'] -= hm[7];
			nbs['N'] -= hm[7];
			hm[8] = nbs['H'];
			nbs['E'] -= hm[8];
			nbs['I'] -= hm[8];
			nbs['G'] -= hm[8];
			nbs['H'] -= hm[8];
			nbs['T'] -= hm[8];
			hm[1] = nbs['O'];
			nbs['O'] -= hm[1];
			nbs['N'] -= hm[1];
			nbs['E'] -= hm[1];
			hm[9] = nbs['I'];
			String out = "";
			for(int j = 0; j<10; j++) {
				for(int k = 0; k<hm[j]; k++) {
					out = out + j;
				}
			}
			
			
			
			
			
			
			
			
			System.out.println("Case #" + i + ": " + out);
		}
	}
	
}