package round1B;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;

public class Osmos {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader("C:\\temp\\osmos.txt") );
		BufferedWriter writer = new BufferedWriter(new FileWriter("c:\\temp\\osmos.out"));
		int numCases = Integer.parseInt( reader.readLine() );
		for ( int caseNum = 0; caseNum < numCases; caseNum++ ) {
			processCase( caseNum, reader, writer );
		}
		
		reader.close();
		writer.close();
	}
	
	private static void processCase( int caseNum, BufferedReader reader, BufferedWriter writer) throws IOException {
		String line = reader.readLine();
		String[] tokens = line.split(" ");
		int mote = Integer.parseInt(tokens[0]);
		int numOthers = Integer.parseInt(tokens[1]);
		
		String[] otherMotes = reader.readLine().split(" ");
		assert( otherMotes.length == numOthers );
		ArrayList<Integer> otherMoteSizes = new ArrayList<>(numOthers);
		for ( int i = 0; i < otherMotes.length; i++ ) {
			otherMoteSizes.add( Integer.valueOf(otherMotes[i]));
		}
		otherMotes = null; // ASsist GC by freeing memory
		
		// Sort otherMotes.
		Collections.sort(otherMoteSizes);
		
		writer.append("Case #" + (caseNum+1) + ": " + solve( mote, otherMoteSizes, 0) + "\n" );
		
	}
	
	private static int solve( int size, ArrayList<Integer> others, int depth ) {
		// First we consume as many as we can
		while ( others.size() > 0 && others.get(0) < size ) {
			size += others.get(0);
			others.remove(0);
		}
		
		// Did we solve it without making any changes? If so, return depth.
		if ( others.size() == 0 ) {
			return depth;
		}
		
		// We have two options: remove the largest mote and recurse, or we can add enough new motes to get us to the next others.
		// We want to return the lesser of those two options.
		
		// Add motes to the head of the list; convert the ArrayList to a LinkedList
		LinkedList<Integer> ll = new LinkedList<Integer>();
		ll.addAll(others);
		ll.addFirst(size - 1); // size - 1 is the largest mote we can add that will get consumed
		
		int addSmallest = size > 1 ? solve ( size, new ArrayList<Integer>(ll), depth + 1) : Integer.MAX_VALUE;
		
		// Remove largest
		others.remove(others.size()-1);
		int removeLargest = solve( size, others, depth + 1);
		
		return Math.min( removeLargest, addSmallest );
		
	}

}
