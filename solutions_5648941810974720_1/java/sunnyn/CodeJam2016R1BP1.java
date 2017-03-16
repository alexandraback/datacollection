import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class CodeJam2016R1BP1 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int caseid=1; caseid<=T; caseid++)
		{
			String s = br.readLine();
			int count[] = new int[255];
			for(int i = 0; i < s.length(); i++) {
				count[s.charAt(i)]++;
			}
			int digits[] = new int[10];
			
			int numzero = count['Z'];
			digits[0] = numzero;
			count['Z'] -= numzero;
			count['E'] -= numzero;
			count['R'] -= numzero;
			count['O'] -= numzero;
			
			int numtwo = count['W'];
			digits[2] = numtwo;
			count['T'] -= numtwo;
			count['W'] -= numtwo;
			count['O'] -= numtwo;
			
			int numsix = count['X'];
			digits[6] = numsix;
			count['S'] -= numsix;
			count['I'] -= numsix;
			count['X'] -= numsix;
			
			int numeight = count['G'];
			digits[8] = numeight;
			count['E'] -= numeight;
			count['I'] -= numeight;
			count['G'] -= numeight;
			count['H'] -= numeight;
			count['T'] -= numeight;
			
			int numfour = count['U'];
			digits[4] = numfour;
			count['F'] -= numfour;
			count['O'] -= numfour;
			count['U'] -= numfour;
			count['R'] -= numfour;
			
			int nt = count['H'];
			digits[3] = nt;
			count['T'] -= nt;
			count['H'] -= nt;
			count['R'] -= nt;
			count['E'] -= nt;
			count['E'] -= nt;
			
			int f = count['F'];
			digits[5] = f;
			count['F'] -= f;
			count['I'] -= f;
			count['V'] -= f;
			count['E'] -= f;
			
			f = count['S'];
			digits[7] = f;
			count['S'] -= f;
			count['E'] -= f;
			count['V'] -= f;
			count['E'] -= f;
			count['N'] -= f;
			
			f = count['O'];
			digits[1] = f;
			count['O'] -= f;
			count['N'] -= f;
			count['E'] -= f;
			
			f = count['I'];
			digits[9] = f;
			count['N'] -= f;
			count['I'] -= f;
			count['N'] -= f;
			count['E'] -= f;

			System.out.print("Case #"+caseid + ": ");
			for(int i = 0; i < 10; i++) {
				for(int j = 0; j < digits[i]; j++) {
					System.out.print(i);
				}
			}
			System.out.println();
		}
	}

}
