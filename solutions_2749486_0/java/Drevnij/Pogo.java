import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Set;



public class Pogo {

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
				String[] s = line.split(" ");
				int x = new Integer(s[0]);
				int y = new Integer(s[1]);
				String result = "";
				int n=1;
				int curX = 0;
				int curY=0;
				if (sums.contains(Math.abs(x))) {
					while (curX != x) {
						if (x>0) {
							result = result+"E";
							curX = curX+n;
							n++;
						} else {
							result = result+"W";
							curX = curX-n;
							n++;
						}
					}
				} else 	if (sums.contains(Math.abs(y))) {
					while (curY != y) {
						if (y>0) {
							result=result+"N";
							curY = curY+n;
							n++;
						} else {
							result=result+"S";
							curY = curY-n;
							n++;
						}
					}
				}
					if (x == curX + n) {
						result = result+"E";
						curX = curX+n;
						n++;
					}
					if (x == curX - n) {
						result = result+"W";
						curX = curX-n;
						n++;
					}
					if (y == curY + n) {
						result = result+"N";
						curY = curY+n;
						n++;
					}
					if (y == curY - n) {
						result = result+"S";
						curY = curY-n;
						n++;
					}

					while (curX != x) {
						if (x>curX&& Math.abs(x-curX)>=n) {
							result=result+"E";
							curX = curX+n;
							n++;
						} else {
							result=result+"W";
							curX = curX-n;
							n++;
						}
					}
					while (curY != y) {
						if (y>curY && Math.abs(y-curY)>=n) {
							result=result+"N";
							curY = curY+n;
							n++;
						} else {
							result=result+"S";
							curY = curY-n;
							n++;
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
    
    private static boolean isValid(String s, int n) {
    	int consecutive = 0;
    	for (int i=0; i<s.length(); i++) {
    		if (s.charAt(i) == 'a' ||s.charAt(i) == 'e' ||s.charAt(i) == 'i' ||s.charAt(i) == 'o' ||s.charAt(i) == 'u')
    			consecutive = 0;
    		else {
    			consecutive++;
    			if (consecutive == n) return true; 
    		}
    	}
    	return false;
    }
}
