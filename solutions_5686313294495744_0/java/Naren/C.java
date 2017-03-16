import java.lang.*;
import java.util.*;
import java.io.*;

public class C {
	private static final String prefix = "C:\\Users\\sivasub\\Downloads\\".replace("\\", "/");
	private static final String fileName = prefix + "C-small-attempt2";
	
	static class tuple {
		public String first;
		public String second;
	}
	
	public static boolean valid(Set<tuple> fakes, Set<tuple> orig, Set<String> allOrig,
			Set<String> allFirst, Set<String> allSecond) {
		for(tuple t : fakes) {
			if(orig.contains(t)) {
				return false;
			}
			
			if(allFirst.contains(t.first) && 
			   allSecond.contains(t.second)) {
			
			} else {
				return false;
			}
		}
		
		return true;
	}
	
	public static void main(String args[]) throws Exception {
	
		 
		
		try(InputStream input = new FileInputStream(fileName + ".in");
			Scanner sc = new Scanner(input);
			PrintStream output = new PrintStream(fileName + ".out")) {
			
			int T = sc.nextInt();
			for(int t = 1; t <= T; t++) {
				//Input
				int n = sc.nextInt();
				tuple[] tuples = new tuple[n];
				for(int i = 0; i< n; i++) {
					tuple tup = new tuple();
					tup.first = sc.next();
					tup.second = sc.next();
					tuples[i] = tup;
				}
				int bestFakes = 0;
				for(int i = 0; i < 1<<n; i++) {
					Set<tuple> fakes = new HashSet<>();
					Set<tuple> orig = new HashSet<>();
					Set<String> allOrig = new HashSet<>();
					Set<String> allFirst = new HashSet<>();
					Set<String> allSecond = new HashSet<>();
					
					for(int k = 0; k < n; k++) {
						if((i & (1<<k)) > 0) {
							fakes.add(tuples[k]);
						} else {
							orig.add(tuples[k]);
							allOrig.add(tuples[k].first);
							allOrig.add(tuples[k].second);
							allFirst.add(tuples[k].first);
							allSecond.add(tuples[k].second);
						}
					}
					
					if(valid(fakes, orig, allOrig, allFirst, allSecond) && fakes.size() > bestFakes) {
						bestFakes = fakes.size();
					}
				}
				
				//Output
				output.println("Case #" + t + ": " + bestFakes);
			}
		}
	}
}
