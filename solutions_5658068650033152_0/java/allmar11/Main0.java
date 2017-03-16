/*
 * This code is meant to run under the Java Runtime Environment, version 1.7 or
 * later.
 */

package round1c.c;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;

public class Main0 {
	
	// This is used to work around the inability of Eclipse to use a file as
	// System.in when running a program.
	private static final String IN_FILE_NAME = "C-small-attempt0.in";

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new BufferedReader(new FileReader(IN_FILE_NAME)));
		
		long numCases = in.nextLong();
		
		for (long i = 1; i <= numCases; i++) {
			int H = in.nextInt();
			int W = in.nextInt();
			int K = in.nextInt();
			
			int result = solve(W, H, K);
			String resultStr = ""+result;
			
			System.out.println(String.format("Case #%s: %s", i, resultStr));
		}
		
		in.close();
	}
	
	private static int solve(int W, int H, int K) {
		assert(K <= W * H);
		
		// Without loss of generality, assume W <= H.
		if (W > H) {
			int temp = W;
			W = H;
			H = temp;
		}
		
		// If both dimensions are less than 3, all points are on the border and
		// the number of stones required is K.
		if (W < 3) {
			return K;
		}
		
		// If the required number of enclosed spaces is less than 5, there is no
		// way to enclose the required spaces without putting a stone at each
		// space.
		if (K < 5) {
			return K;
		}
		
		// Handle other cases.
		EnclosureState enclosure = new EnclosureState(W, H);
		int bestSoFar = K;
		while (enclosure.getNumPts() <= K) {
			int newResult
				= enclosure.getNumBoundaryPts() + K - enclosure.getNumPts();
			if (newResult < bestSoFar) {
				bestSoFar = newResult;
			}
			boolean couldExpand = enclosure.expandInterior();
			if (!couldExpand) {
				break;
			}
		}
		
		return bestSoFar;
		
//		// In all other cases, start with a 5-space enclosure at the center of
//		// the board, and add spaces to it so as to minimize the increase in
//		// boundary size, until the required enclosure size is reached.
//		
//		// boundaryPts[i] is the set of boundary points that are not on the grid
//		// border and are adjacent to i points NOT in the enclosure.
//		// borderPts is the set of boundary points that are on the grid border.
//		// interiorPts is the set of non-boundary points in the enclosure.
//		Set<Space>[] boundaryPts = new Set[4];
//		for (int i = 0; i < boundaryPts.length; i++) {
//			boundaryPts[i] = new HashSet<Space>();
//		}
//		Set<Space> borderPts = new HashSet<Space>();
//		Set<Space> interiorPts = new HashSet<Space>();
//		
//		Space center = new Space(W/2, H/2);
//		interiorPts.add(center);
//		for (Space s : center.getNeighbors(W, H)) {
//			if (s.isBorderPt(W, H)) {
//				borderPts.add(s);
//			}
//			else {
//				boundaryPts[3].add(s);
//			}
//		}
//		int enclosureSize = 5;
//		
//		// Expand enclosure.
//		while (enclosureSize != K) {
//			// Pick a point to add to the interior.  Pick one with as many
//			// neighboring 
//			
//			
//		}
//		
//		// Count boundary points.
//		int result = borderPts.size();
//		for (Set<Space> pts : boundaryPts) {
//			result += pts.size();
//		}
//		
//		return result;
	}
	
	private static class EnclosureState {
		private final int W;
		private final int H;
		
		// Set of interior points.
		private Set<Space> interiorPts = new HashSet<Space>();
		
		// Set of all boundary points, including those that lie on the grid
		// border.
		private Set<Space> boundaryPts = new HashSet<Space>();
		
		// boundPtsWithOutNeighbors[i] is the set of boundary points that do NOT
		// lie on the grid border and have i neighbors outside the enclosure.
		private Set<Space>[] boundPtsWithExtNeighbors = new Set[4];
		{
			for (int i = 0; i < boundPtsWithExtNeighbors.length; i++) {
				boundPtsWithExtNeighbors[i] = new HashSet<Space>();
			}
		}
		
		// Creates an EnclosureState with interior size 1.
		public EnclosureState(int W, int H) {
			this.W = W;
			this.H = H;
			
			Space center = new Space(W/2, H/2);
			interiorPts.add(center);
			for (Space s : center.getNeighbors(W, H)) {
				boundaryPts.add(s);
				if (!s.isBorderPt(W, H)) {
					boundPtsWithExtNeighbors[3].add(s);
				}
			}
		}
		
		public int getNumInteriorPts() {
			return interiorPts.size();
		}
		
		public int getNumBoundaryPts() {
			return boundaryPts.size();
		}
		
		public int getNumPts() {
			return getNumInteriorPts() + getNumBoundaryPts();
		}
		
		// Increases enclosure interior size by one, while keeping boundary as
		// small as possible.  Returns true if interior size could be increased.
		public boolean expandInterior() {
			
			// Choose a point to add to the interior.  The point is chosen so as
			// to minimize the increase in boundary size.
			Space newInteriorPt = null;
			for (Set<Space> pts : boundPtsWithExtNeighbors) {
				if (!pts.isEmpty()) {
					Iterator<Space> iter = pts.iterator();
					newInteriorPt = iter.next();
					iter.remove();
					boundaryPts.remove(newInteriorPt);
					interiorPts.add(newInteriorPt);
					break;
				}
			}
			
			// Return false if no new interior point could be chosen.
			if (newInteriorPt == null) {
//				throw new RuntimeException("Expanded too far.");
				return false;
			}
			
			// Add new boundary points where appropriate.
			Set<Space> newIntPtNeighbors = newInteriorPt.getNeighbors(W, H);
			for (Space s : newIntPtNeighbors) {
				if (!interiorPts.contains(s)) {
					boundaryPts.add(s);
				}
			}
			
			// Update information about how many exterior neighbors each
			// boundary point has.
			Set<Space> boundPtsToUpdate = newIntPtNeighbors;
			boundPtsToUpdate.removeAll(interiorPts);
			for (Space s : boundPtsToUpdate) {
				// Ignore points on the grid border.
				if (s.isBorderPt(W, H)) {
					continue;
				}
				
				for (Set<Space> pts : boundPtsWithExtNeighbors) {
					pts.remove(s);
				}
				Set<Space> neighbors = s.getNeighbors(W, H);
				int numExtNeighbors = 0;
				for (Space n : neighbors) {
					if (!(interiorPts.contains(n) || boundaryPts.contains(n))) {
						numExtNeighbors++;
					}
				}
				boundPtsWithExtNeighbors[numExtNeighbors].add(s);
			}
			
			return true;
		}
	}
	
	private static class Space {
		private int x;
		private int y;
		
		public Space(int x, int y) {
			this.x = x;
			this.y = y;
		}
		
		public boolean isBorderPt(int W, int H) {
			return (x <= 0 || x >= W-1 || y <= 0 || y >= H-1);
		}
		
		public Set<Space> getNeighbors(int W, int H) {
			Set<Space> result = new HashSet<Space>();
			if (x > 0) {
				result.add(new Space(x-1, y));
			}
			if (x < W-1) {
				result.add(new Space(x+1, y));
			}
			if (y > 0) {
				result.add(new Space(x, y-1));
			}
			if (y < H-1) {
				result.add(new Space(x, y+1));
			}
			
			return result;
		}
		
		@Override
		public boolean equals(Object o) {
			if (!(o instanceof Space)) {
				return false;
			}
			
			Space spaceO = (Space) o;
			return (x == spaceO.x && y == spaceO.y);
		}
		
		@Override
		public int hashCode() {
			return x + 1000*y;
		}
		
		@Override
		public String toString() {
			return String.format("(%s, %s)", x, y);
		}
	}
}
