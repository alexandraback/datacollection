import java.io.BufferedReader;
import java.io.File;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main2 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(
				System.in)));
		in = new Scanner(new File("B-small-attempt1.in"));
		
		int T = in.nextInt();
		in.nextLine();
		for (int i=1; i<=T; i++) {
			String[] temp = in.nextLine().split(" ");
			String C = temp[0];
			String J = temp[1];
			
			List<String> possibleC = getPossibles(C, J);
			List<String> possibleJ = getPossibles(J, C);
			
			int newC = Integer.parseInt(possibleC.get(0));
			int newJ = Integer.parseInt(possibleJ.get(0));
			int min = Math.abs(newC-newJ);
			for (int j=0; j<possibleC.size(); j++) {
				int tempC = Integer.parseInt(possibleC.get(j));
				for (int k=0; k<possibleJ.size(); k++) {
					int tempJ = Integer.parseInt(possibleJ.get(k));
					int abs = Math.abs(tempC-tempJ);
					if (abs < min) {
						min = Math.abs(tempC-tempJ);
						newC = tempC;
						newJ = tempJ;
					} else if (abs == min) {
						if (tempC < newC || (tempC == newC && tempJ < newJ)) {
							newC = tempC;
							newJ = tempJ;
						}
					}
				}
			}
			
			System.out.printf("Case #%d: %0"+C.length()+"d %0"+C.length()+"d\n", i, newC, newJ);
		}
	}
	
	private static List<String> getPossibles(String s, String other) {
		List<String> possibles = new ArrayList<String>();
		possibles.add(s);
		
		while (possibles.get(0).contains("?")) {
			StringBuilder sb = new StringBuilder(possibles.remove(0));
			int idx = sb.indexOf("?");
			char jpart = other.charAt(idx);
			if (jpart == '?') {
				sb.setCharAt(idx, '0');
				possibles.add(sb.toString());
				sb.setCharAt(idx, '1');
				possibles.add(sb.toString());
				sb.setCharAt(idx, '9');
				possibles.add(sb.toString());
			} else {
				sb.setCharAt(idx, jpart);
				possibles.add(sb.toString());
				if (idx != 0) {
					sb.setCharAt(idx, '0');
					possibles.add(sb.toString());
					sb.setCharAt(idx, '9');
					possibles.add(sb.toString());
				}
				if (jpart != '0') {
					sb.setCharAt(idx, (char)(jpart-1));
					possibles.add(sb.toString());
				}
				if (jpart != '9') {
					sb.setCharAt(idx, (char)(jpart+1));
					possibles.add(sb.toString());
				}
			}
		}
		return possibles;
	}
}