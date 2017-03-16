

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

// Using the Google Guava library.
public class B {

	public static void main(String [] args) throws IOException {
		String inputFile = "src/B-small-0.in";
		Scanner in = new Scanner(new File(inputFile));
		PrintStream out = new PrintStream(inputFile.substring(0, inputFile.length()-2)+"out");
		int cases = in.nextInt();
		for (int cs = 1; cs <= cases; cs++) {
		    int k = in.nextInt();
		    int l = in.nextInt();
		    int s = in.nextInt();
		    String K = in.next();
		    String L = in.next();
		    
		    Map<State, Double> p = new HashMap<>();
		    p.put(new State(0, 0), 1.);
		    int bananas = 0;
		    
		    for (int i = 0; i < s; i++) {
		        Map<State, Double> n = new HashMap<>();
		        for (Entry<State, Double> e : p.entrySet()) {
		            State state = e.getKey();
		            String sub = L.substring(0, state.loc);
                    double pAdd = e.getValue() / K.length();
		            for (char c : K.toCharArray()) {
		                String sofar = sub + c;
		                int startLoc = startLoc(L, sofar);
		                int cAdd = sofar.equals(L) ? 1 : 0;
		                State nextState = new State(startLoc, state.correct + cAdd);
		                bananas = Math.max(bananas, nextState.correct);
		                Double prev = n.get(nextState);
		                if (prev == null) { prev = 0.; }
		                n.put(nextState, prev + pAdd);
		            }
		        }
		        p = n;
		    }
		    
		    double expV = 0;
            for (Entry<State, Double> e : p.entrySet()) {
                expV += e.getKey().correct * e.getValue();
            }
		    
			String ans = "Case #"+cs+": "+String.format("%.6f", bananas-expV);
			out.println(ans);
			System.out.println(ans);
		}
		out.close();
		in.close();
	}
	
	// best start loc for substr of sofar
	static int startLoc(String L, String sofar) {
	    if (L.startsWith(sofar) && L.length() > sofar.length()) {
	        return sofar.length();
	    }
	    for (int i = 1; i < sofar.length(); i++) {
	        String s = sofar.substring(i);
	        if (L.startsWith(s)) {
	            return s.length();
	        }
	    }
	    return 0;
	}
	
	static class State {
	    int loc;
	    int correct;
        public State(int loc, int correct) {
            this.loc = loc;
            this.correct = correct;
        }
        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + correct;
            result = prime * result + loc;
            return result;
        }
        @Override
        public boolean equals(Object obj) {
            if (this == obj)
                return true;
            if (obj == null)
                return false;
            if (getClass() != obj.getClass())
                return false;
            State other = (State) obj;
            if (correct != other.correct)
                return false;
            if (loc != other.loc)
                return false;
            return true;
        }
        @Override
        public String toString() {
            return "State [loc=" + loc + ", correct=" + correct + "]";
        }
	    
	}
}
