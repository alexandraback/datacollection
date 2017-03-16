import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Collections;

public class A {
	static String[][] r = {
			{"Z", "W", "U", "X", "G"},
			{"O", "S"},
			{"V", "T", "N"}
	};
	static String[][] u = {
			{"ERO", "TO", "FOR", "SI", "EIHT"},
			{"NE", "EVEN"},
			{"FIE", "HREE", "INE"},
	};
	static Integer[][] n = {
			{0, 2, 4, 6, 8},
			{1, 7},
			{5, 3, 9},	
	};

	public static void main(String args[]) {
		try (BufferedReader reader = new BufferedReader(new FileReader("A-large.in"))) {
			
		    int T = Integer.parseInt(reader.readLine());
		    String s;
		    for (int t = 1; t <= T; t++) {
		    	s = reader.readLine();
		    	
		    	ArrayList<Integer> ans = new ArrayList<Integer>();
		    	
		    	int level = 0;
		    	while (!s.isEmpty()) {
		    		int found = -1;
		    		for (int i = 0; i < r[level].length; i++) {
		    			if (s.indexOf(r[level][i]) != -1) {
		    				found = i;
		    				break;
		    			}
		    		}
		    		if (found != -1) {
		    			s = s.replaceFirst(r[level][found], "");
		    			for (int i = 0; i < u[level][found].length(); i++) {
		    				s = s.replaceFirst(u[level][found].substring(i, i+1), "");
		    			}
		    			ans.add(n[level][found]);
		    		} else {
		    			level++;
		    		}
		    	}
		    	
		    	Collections.sort(ans);
		    	
		    	String s_ans = "";
		    	for (Integer i : ans) {
		    		s_ans = s_ans + i;
		    	}
		    	
		    	System.out.println("Case #"+t+": "+s_ans);
		    }
		} catch (Exception e) {
		}
		
	}
}
