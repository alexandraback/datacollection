import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class ProblemC {

	public static void main(String[] args) {
		try (BufferedReader reader = new BufferedReader(new FileReader("C-small.in"))) {
			try (BufferedWriter writer = new BufferedWriter(new FileWriter("C-small.out"))) {
				String line = reader.readLine();
				int numCases = Integer.parseInt(line);
				
				Scanner scanner;
				for(int caseIdx = 0; caseIdx < numCases; caseIdx++) {
					scanner = new Scanner(reader.readLine());
					
					int A = scanner.nextInt();
					int B = scanner.nextInt();
					
					int result = 0;
					
					String sA = String.valueOf(A);
					String sB = String.valueOf(B);
					
					Set<String> vs = new HashSet<>();
					for(int t = A; t <= B; t++) {
						String st = String.valueOf(t);
						for(int s = 1; s < st.length(); s++) {
							if(st.charAt(s) == '0') continue; // no leading zeroes
							String ost = st.substring(s) + st.substring(0, s);
	
							if(st.compareTo(ost) > -1) continue;
							if(ost.compareTo(sB) > 0) continue;
							if(ost.compareTo(sA) < 0) continue;
							
							vs.add( st + "_" + ost);
							vs.add(ost + "_" + st);
						}
					}
					result = vs.size() / 2;
					
					String caseOutput = String.format("Case #%d: %d", caseIdx + 1, result);
					
					System.out.println(caseOutput);
					writer.append(caseOutput);
					writer.newLine();
				}
			}
		} catch(IOException ioEx) {
			ioEx.printStackTrace();
		}
	}

}
