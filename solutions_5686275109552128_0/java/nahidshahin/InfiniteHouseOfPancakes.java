import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.TreeSet;


public class InfiniteHouseOfPancakes {
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		//System.setIn(new FileInputStream("B-small-attempt1.in"));
		//System.setOut(new PrintStream(new BufferedOutputStream(new FileOutputStream("InfiniteHouseOfPancakes_Small.out")), true));
		Comparator cmp = new Comparator<Integer>() {
	        public int compare(Integer i1, Integer i2) {
	            return i2 - i1; 
	        }
	    };
		
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int totalCaseNumber = Integer.parseInt( reader.readLine() );
		for(int caseNo=1 ; caseNo<=totalCaseNumber ; caseNo++ ) {
			int D = Integer.parseInt( reader.readLine() );
			String line = reader.readLine();
			String[] parts = line.split(" ");
			
			PriorityQueue<Integer> plates = new PriorityQueue<Integer>(1000, cmp);
			
			for(String part : parts) {
				plates.add( Integer.parseInt(part) );
			}
			
			int second = 0, tmp, m1, m2;
			int highestElem = plates.poll();
			int optimalResult = highestElem;
			
			while( true ) {
				tmp = second + highestElem;
				if( tmp < optimalResult ) {
					optimalResult = tmp;
				}
				if( highestElem <= 3 ) {
					break;
				}
				m1 = highestElem / 2;
				m2 = highestElem - m1;
				plates.add(m1);
				plates.add(m2);
				highestElem = plates.poll();
				second++;
			}
			
			System.out.println("Case #" + caseNo + ": " + optimalResult);
		}
		reader.close();
	}
}
