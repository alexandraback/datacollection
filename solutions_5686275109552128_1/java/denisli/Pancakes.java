import java.util.*;
import java.io.*;

public class Pancakes {
	// assumes that plates is sorted in reverse order
	static int numTurns(List<Integer> plates, int reference, int numSplits) {
		int referencePlateSize = plates.get(reference);
		int maxSizeOfSplit = (int) Math.ceil((float) referencePlateSize / (numSplits+1));
		int numTurns = maxSizeOfSplit + numSplits;
		for ( int i=0; i<plates.size(); i++ ) {
			if ( i == reference ) { continue; }
			int plateSize = plates.get(i);
			int numTimesToSplit = (int) Math.ceil( ((float) plateSize) / maxSizeOfSplit ) - 1;
			numTurns += numTimesToSplit;
		}
		return numTurns;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("pancakes.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("pancakes.out")));
		
		int T = Integer.parseInt(f.readLine());
		for ( int i=1; i<=T; i++ ) {
			System.out.println(i);
			int D = Integer.parseInt(f.readLine());
			StringTokenizer st = new StringTokenizer(f.readLine());
			List<Integer> plates = new ArrayList<Integer>();
			for ( int j=0; j<D; j++ ) {
				int size = Integer.parseInt(st.nextToken());
				plates.add(size);
			}
			int minTurns = 1000;
			for ( int reference=0; reference < plates.size(); reference++ ) {
				int referencePlateSize = plates.get(reference);
				for ( int numSplits=0; numSplits <= (referencePlateSize+1)/2 - 1; numSplits++ ) {
					int numTurns = numTurns(plates, reference, numSplits);
					minTurns = Math.min(minTurns, numTurns);
				}
			}
			out.println(String.format("Case #%d: %d",i,minTurns));
		}
		
		f.close();
		out.close();
	}
}
