package codejam.CJ2016.R1B;

import java.util.Scanner;

public class R1BA {
	
	private static void remove(int times, int[] frequencies, String characters) {
		for (int k = 0; k< characters.length(); k++) {
			frequencies[characters.charAt(k)-'A']-=times;
		}
	}
	
	public static void main(String[] args){
		try(Scanner in = new Scanner(System.in)) {
			int t = in.nextInt();
			in.nextLine();
			for(int i=1; i<=t; i++){
				String s = in.nextLine();
				int[] frequencies = new int[26];
//				System.out.println(s);
				for (int k = 0; k<s.length(); k++) {
					frequencies[s.charAt(k)-'A']++;
				}
				int[] numFreq = new int[10];
				//ZERO
				numFreq[0] = frequencies['Z'-'A'];
				remove(numFreq[0], frequencies, "ZERO");
				//TWO
				numFreq[2] = frequencies['W'-'A'];
				remove(numFreq[2], frequencies, "TWO");
				//FOUR
				numFreq[4] = frequencies['U'-'A'];
				remove(numFreq[4], frequencies, "FOUR");
				//EIGHT
				numFreq[8] = frequencies['G'-'A'];
				remove(numFreq[8], frequencies, "EIGHT");
				//THREE
				numFreq[3] = frequencies['H'-'A'];
				remove(numFreq[3], frequencies, "THREE");
				//SIX
				numFreq[6] = frequencies['X'-'A'];
				remove(numFreq[6], frequencies, "SIX");
				//FIVE
				numFreq[5] = frequencies['F'-'A'];
				remove(numFreq[5], frequencies, "FIVE");
				//ONE
				numFreq[1] = frequencies['O'-'A'];
				remove(numFreq[1], frequencies, "ONE");
				//SEVEN
				numFreq[7] = frequencies['V'-'A'];
				remove(numFreq[7], frequencies, "SEVEN");
				//NINE
				numFreq[9] = frequencies['I'-'A'];
				remove(numFreq[9], frequencies, "NINE");
				
				System.out.print("Case #" + i + ": ");
				for (int k = 0; k<=9; k++) {
					for(int j = 0; j<numFreq[k]; j++) {
						System.out.print(k);
					}
				}
				
				System.out.println();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
