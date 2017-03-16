import java.util.Scanner;

/*  unique letters:
 *  ZERO:  Z
 *  ONE:   /
 *  TWO:   W
 *  THREE: / (0,4 gone: R)
 *  FOUR:  U
 *  FIVE:  / (4 gone: F)
 *  SIX:   X
 *  SEVEN: / (5 gone: V)
 *  EIGHT: G
 *  NINE:  / (6,8 gone: I)
*/

public class Round1B_A {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int a=1;a<=T;a++){
			String S = sc.next();
			char[] freq = new char[26];
			for(int i=0;i<S.length();i++){
				freq[S.charAt(i)-'A']++;
			}
			int[] f = new int[10];
			//0,2,4,6,8: Z,W,U,X,G
			f[0] = freq['Z'-'A'];
			freq['E'-'A'] -= f[0];
			freq['R'-'A'] -= f[0];
			freq['O'-'A'] -= f[0];
			f[2] = freq['W'-'A'];
			freq['T'-'A'] -= f[2];
			freq['O'-'A'] -= f[2];
			f[4] = freq['U'-'A'];
			freq['F'-'A'] -= f[4];
			freq['O'-'A'] -= f[4];
			freq['R'-'A'] -= f[4];
			f[6] = freq['X'-'A'];
			freq['S'-'A'] -= f[6];
			freq['I'-'A'] -= f[6];
			f[8] = freq['G'-'A'];
			freq['E'-'A'] -= f[8];
			freq['I'-'A'] -= f[8];
			freq['H'-'A'] -= f[8];
			freq['T'-'A'] -= f[8];
			//3,5,9: R,F,I
			f[3] = freq['R'-'A'];
			freq['T'-'A'] -= f[3];
			freq['H'-'A'] -= f[3];
			freq['E'-'A'] -= f[3]*2;
			f[5] = freq['F'-'A'];
			freq['I'-'A'] -= f[5];
			freq['V'-'A'] -= f[5];
			freq['E'-'A'] -= f[5];
			f[9] = freq['I'-'A'];
			freq['N'-'A'] -= f[9]*2;
			freq['E'-'A'] -= f[9];
			//7: V
			f[7] = freq['V'-'A'];
			freq['S'-'A'] -= f[7];
			freq['E'-'A'] -= f[7]*2;
			freq['N'-'A'] -= f[7];
			//1
			f[1] = freq['O'-'A'];
			System.out.print("Case #"+a+": ");
			for(int i=0;i<10;i++){
				for(int j=0;j<f[i];j++){
					System.out.print(i);
				}
			}
			System.out.println();
		}
		sc.close();
	}
}