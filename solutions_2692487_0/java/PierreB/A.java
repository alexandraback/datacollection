package y2013.Round1B;

import static java.util.Arrays.deepToString;
import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.TreeSet;
/**
 * 
 * @author PierreB
 * Notes:
 */
public class A {
	final String ROUND = "Round1B";

	int size, N, max;
	ArrayList<Integer> motes;
	void read(Scanner sc) {
		size = sc.nextInt();
		N = sc.nextInt();
		motes = new ArrayList<Integer>();
		for (int i = 0; i < N; i++) {
			motes.add( sc.nextInt() );
		}
		Collections.sort(motes);
	}
	// Check that it is solvable;
	void solve() {
		int operations = 0;
		int altops = 0;
		boolean alUsed = false;
		int total = size;
		while(total <= motes.get(motes.size()-1)) {
			// try adding a mote just smaller
			int curr = motes.get(0);
			if(curr < total) {
				total += curr;
				motes.remove(0);
			} else if(curr >= total + total -1 && !alUsed){
				altops += motes.size();
				alUsed = true;
			} else  {
				operations++;

				if(!alUsed) {
					altops++;					
				} else {
					if(operations > altops) {
						break;
					}
				}
				total += total-1;
			}
			// try removing one larger
		}
		int fin = operations;
		if(alUsed) {
			fin = Math.min(operations, altops);
		}
		System.out.println(fin);
	}
	
	// EXTRA METHODS

	void run() throws FileNotFoundException {
		Scanner sc = new Scanner(new File("y2013/"+ROUND+"/a.in"));
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			read(sc);
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args)  {
		try {
			new A().run();
		} catch (FileNotFoundException e) {
			System.out.println(e.getMessage());
			System.out.println(System.getProperty("user.dir"));
		}
	}
}
