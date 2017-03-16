package round1b;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C {

	
	private static final int MAXS = 5000;
	private static final int MINDIF = 5;
	private static int minChanges[][] = new int[MAXS][MINDIF];
	private static String s;
	private static int minLength;
	private static int maxLength;
	
	private static Set<String> dict[] = new HashSet[20];
	
	
	private static final int calc(int pos, int minChangePos) {
		if (minChangePos < 0 || minChangePos >= MINDIF) throw new RuntimeException("Minchangepos is " + minChangePos);
		//System.out.println("Checking position " + pos);
		if (minChanges[pos][minChangePos] != -1) return minChanges[pos][minChangePos];
		
		int startSize = minLength;
		int endSize = Math.min(s.length() - pos, maxLength);
		int min = 10000;
		for(int i=startSize;i<=endSize;i++) {
			Set<String> set = dict[i]; 
			int changeCount = 0;
			if (i <= minChangePos) changeCount = 0; else {
				if (minChangePos + MINDIF < i) changeCount = 2; else changeCount = 1;
			}
			
			//System.out.println("Checking match of " + s.substring(pos, pos + i) + " " + set.contains(s.substring(pos, pos + i)));
			if (set.contains(s.substring(pos, pos + i))) {
				int inner = calc(pos + i, minChangePos <= i ? 0 : minChangePos - i);
				if (inner < min) min = inner;
			}
			
			if (changeCount >= 1) {
				char [] data = s.substring(pos, pos + i).toCharArray();
				for(int j=minChangePos;j<i;j++) {
					char origChar = data[j]; 
					for(int k=0;k<26;k++) {
						data[j] = (char)('a' + k);
						if (origChar != data[j] && set.contains(String.valueOf(data))) {
							int inner = calc(pos + i, Math.max(0, MINDIF - (i - j)));
							if (inner + 1 < min) min = inner + 1;
						}
					}
					data[j] = origChar;
				}
				
				if (changeCount >= 2) {
					for(int j=minChangePos;j<i;j++) {
						char origChar = data[j]; 
						for(int k=0;k<26;k++) {
							data[j] = (char)('a' + k);
							if (origChar != data[j]) {
								for(int j2=j+MINDIF;j2<i;j2++) {
									char origChar2 = data[j2];
									for(int k2=0;k2<26;k2++) {
										data[j2] = (char)('a' + k2);
										if (origChar2 != data[j2] && set.contains(String.valueOf(data))) {
											int inner = calc(pos + i, Math.max(0, MINDIF - (i - j2)));
											if (inner + 2 < min) min = inner + 2;
										}
									}
									data[j2] = origChar2;
								}
							}
						}
						data[j] = origChar;
					}
				}
			}
		}

		//System.out.println("Result at " + pos + ", " + minChangePos + " is " + min);
		minChanges[pos][minChangePos] = min;
		return min;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("garbled_email_dictionary.txt "));
		String line = "";
		maxLength = 0;
		minLength = Integer.MAX_VALUE;
		while ((line = br.readLine()) != null) {
			Set<String> set = dict[line.length()];
			if (set == null) {
				set = new HashSet<String>();
				dict[line.length()] = set;
			}
			set.add(line);
			if (line.length() > maxLength) maxLength = line.length();
			if (line.length() < minLength) minLength = line.length();
		}
		br.close();

		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int tt = 0;tt<t;tt++) {
			s = sc.next();
			for(int i=0;i<s.length();i++) for(int j=0;j<MINDIF;j++) minChanges[i][j] = -1;
			for(int i=0;i<MINDIF;i++) minChanges[s.length()][i] = 0;
			System.out.println("Case #" + (tt + 1) + ": " + calc(0, 0));
		}
		sc.close();
	}

}
