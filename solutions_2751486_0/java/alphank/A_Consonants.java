package round1C2013;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class A_Consonants {

	public static boolean checkN(String str, int n, boolean[] isCons) {
		//System.out.println(str);
		int curCons = 0;
		for (int i = 0; i < str.length(); i++) {
			if(isCons[str.charAt(i)]) {
				curCons = 0;
			}
			else {
				if(++curCons == n) {
					return true;
				}
			}
		}
		return false;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader("aSample.txt"));
			BufferedWriter bw = new BufferedWriter(new FileWriter("aOutput.txt"));

			Scanner in = new Scanner(br);
			
			boolean[] isVowel = new boolean[256];
			isVowel[(int)'a'] = true;
			isVowel[(int)'e'] = true;
			isVowel[(int)'i'] = true;
			isVowel[(int)'o'] = true;
			isVowel[(int)'u'] = true;

			int T = in.nextInt();
			for (int t = 0; t < T; t++) {
				String sName = in.next();
				int n = in.nextInt();

				long nValue = 0;
				for (int i = 0; i < sName.length(); i++) {
					for (int j = i+1; j < sName.length() + 1; j++) {
						if(checkN(sName.substring(i, j), n, isVowel)) {
							nValue++;
						}
					}
				}

				bw.write("Case #" + (t + 1) + ": " + nValue + "\n");
				System.out.println("Case #" + t + ": " + nValue);
			}
			in.close();
			br.close();
			bw.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (NumberFormatException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
