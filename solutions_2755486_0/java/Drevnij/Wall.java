import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Set;



public class Wall {

    public static void main( String[] args ) {
		try {
	    	BufferedReader in = new BufferedReader(new FileReader("in.txt"));
			BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
			String line = in.readLine();
			int total = new Integer(line);
			Set<Integer> sums = new HashSet<Integer>();
			int sum = 0;
			for (int i=1; i<100; i++) {
				sum+=i;
				sums.add(sum);
			}
			
			for (int i=1; i<=total; i++) {
				line = in.readLine();
				int n = new Integer(line);
				List<Attack> attacks = new ArrayList<Attack>();
				
				for (int j=0; j<n; j++) {
					line = in.readLine();
					String[] s = line.split(" ");
					int day = new Integer(s[0]);
					int numOfAttacks = new Integer(s[1]);
					int w = new Integer(s[2]);
					int e = new Integer(s[3]);
					int str = new Integer(s[4]);
					int dDays = new Integer(s[5]);
					int dDis = new Integer(s[6]);
					int dStr = new Integer(s[7]);
					Attack a1 = new Attack();
					a1.day = day;
					a1.w = w;
					a1.e = e;
					a1.str = str;
					attacks.add(a1);
					for (int k=1; k<numOfAttacks; k++) {
						day = day+dDays;
						w = w+dDis;
						e=e+dDis;
						str=str+dStr;
						Attack ak = new Attack();
						ak.day = day;
						ak.w = w;
						ak.e = e;
						ak.str = str;
						attacks.add(ak);
					}
							
				}
				Collections.sort(attacks);
				int result = 0;
				HashMap<Integer,Integer> wall = new HashMap<Integer,Integer>();
				HashMap<Integer,Integer> newWall = new HashMap<Integer,Integer>();
				int lastDay = 0;
				for (Attack item: attacks) {
					int w = item.w;
					int e = item.e;
					int str = item.str;
					int day = item.day;
					if (day != lastDay)
						wall.putAll(newWall);
					lastDay = day;
					
					boolean success = false;
					for (int j=w; j<e; j++) {
						if (wall.get(j)== null || wall.get(j)<str)
							success = true;
							
					}
					if (success) {
						result++;
						for (int j=w; j<e; j++)
							if (newWall.get(j)== null || newWall.get(j)<str)
								newWall.put(j, str);
					}
				}
				
				out.write("Case #"+i+": "+result+"\n");

			}
			
			
			in.close();
			out.flush();
			out.close();
	} catch (Exception e) {
		e.printStackTrace();
	}
	
    }
    
    private static class Attack implements Comparable {
    	public int day;
    	public int w;
    	public int e;
    	public int str;
    	
    	public int compareTo(Object other) {
    		Attack oth = (Attack)other;
       		if (oth.day>this.day) return -1;
       		else if (oth.day<this.day) return 1;
       		return 0;
       	}
    	
    	
    }
    
}
