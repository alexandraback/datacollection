import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;


public class mainC {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try(Scanner sc = new Scanner(new File("./C-small-attempt1.in"))) {
			System.setOut(new PrintStream(new File("C-small-attempt1.out")));
			
			int T = sc.nextInt();
			
			CASE_LOOP:
			for (int t = 1; t <= T; t++) {
				System.err.format("Case #%d%n", t);
				int N = sc.nextInt();
				int S[] = new int[N];
				for (int i = 0; i < N; i++) {
					S[i] = sc.nextInt();
				}
				
				Map<Integer,Set<Integer>> f = new HashMap<>();
				
				for (int i = 0; i < N; i++) {
					Set<Integer> s = new HashSet<>();
					s.add(S[i]);
					f.put(S[i], s);
				}
				
				for (int k = 0; k < N; k++) {
					Set<Integer> sums = new HashSet<>(f.keySet());
					for (int sum : sums) {
						for (int i = 0; i < N; i++) {
							if(f.get(sum).contains(S[i])) continue;
							
							if(!f.containsKey(sum+S[i])) {
								Set<Integer> s = new HashSet<>(f.get(sum));
								s.add(S[i]);
								f.put(sum+S[i], s);
							} else if(!f.get(sum+S[i]).contains(S[i])) {
								
								System.out.format("Case #%d:%n", t);
								for (int s : f.get(sum+S[i])) {
									System.out.format("%d ", s);
								}
								System.out.println();
								for (int s : f.get(sum)) {
									System.out.format("%d ", s);
								}
								System.out.format("%d ", S[i]);
								System.out.println();
								
								continue CASE_LOOP;
							}
						}
					}		
				}
				
				System.out.format("Case #%d:%nImpossible%n", t);
			}			
		} catch (FileNotFoundException e) {			
			e.printStackTrace();
		}
	}
}