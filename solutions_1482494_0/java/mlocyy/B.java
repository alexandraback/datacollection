package R1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class B {

	/**
	 * @param args
	 */
	static Scanner s;
	/**
	 * @param args
	 */
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		s = new Scanner(new File("a.txt"));
		int T = s.nextInt();
		for(int t=1;t<=T;t++) {
			int N = s.nextInt();
			ArrayList<Integer> P = new ArrayList<Integer>();
			for (int i=0; i<N; i++) {
				P.add(s.nextInt());
				P.add(s.nextInt());
				P.add(0);
				P.add(0);
			}
			int count = 0;
			int stars = 0;
			boolean toobad = false;
			while(!P.isEmpty() && !toobad) {
				boolean found = false;
				for (int i=1; i<P.size(); i+=4) {
					if (stars >= P.get(i)) {
						if (P.get(i+1) == -1) stars++;
						else stars+=2;
						P.remove(i+2);P.remove(i+1);P.remove(i);
						P.remove(i-1);
						i=-3;
						count++;
						found = true;
 					}
				}
				for (int i=0; i<P.size(); i+=4) {
					if (stars >= P.get(i) && P.get(i+2) != -1) {
						stars++;
						count++;
						found = true;
						P.set(i+2, -1);
						break;
					}
				}
				if (!found) toobad = true;
			}
			if (toobad)
				System.out.println("Case #"+t+": Too Bad");
			else
				System.out.println("Case #"+t+": "+count);
		}
		s.close();
	}

	
	
}
