import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;

public class B {
	public static void main(String args[]) {
		try (BufferedReader reader = new BufferedReader(new FileReader("B-small-attempt0(1).in"))) {
			
		    int T = Integer.parseInt(reader.readLine());
		    String s;
		    for (int t = 1; t <= T; t++) {
		    	s = reader.readLine();
		    	String a = s.split(" ")[0];
		    	String b = s.split(" ")[1];
		    	if (a.equals(b)) {
		    		a = a.replace('?', '0');
		    		b = a;
		    		System.out.println("Case #"+t+": "+a+" "+b);
		    	} else {
		    		String temp = a + b;
		    		ArrayList<String> p = new ArrayList<String>();
		    		p.add(temp);
		    		while (p.get(0).indexOf("?") != -1) {
		    			int size = p.size();
		    			ArrayList<String> np = new ArrayList<String>();
		    			for (int i = 0; i < p.size(); i++) {
		    				String tempp = p.get(i);
				    		for (int j = 0; j < 10; j++) {
				    			np.add(tempp.replaceFirst("\\?", ""+j));
				    		}
		    			}
		    			p = np;
		    		}
		    		String mins = "";
		    		int min = Integer.MAX_VALUE;
		    		for (String pos : p) {
		    			int diff = Math.abs(
		    						Integer.parseInt(pos.substring(0, a.length())) -
		    						Integer.parseInt(pos.substring(a.length(), a.length()*2))
		    					);
		    			if (diff < min) {
		    				min = diff;
		    				mins = pos;
		    			}
		    		}
		    		System.out.println("Case #"+t+": "+mins.substring(0, a.length())+" "+mins.substring(a.length(), a.length()*2));

		    	}
		    	//System.out.println("here");
		    }
		} catch (Exception e) {
			System.out.println(e.toString());
		}
		
	}
}
