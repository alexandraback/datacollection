import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * 
 */

/**
 * @author Anvesh Kumar Mallick
 * email - warcops@gmail.com
 * Date of Creation - 06-May-2012
 *
 */
public class ProblemA {
	
	private static int[][] matrix;

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			Scanner sc = new Scanner(System.in);
			int noOfCases = sc.nextInt();
			FileWriter fstream = new FileWriter("C:/Users/Anvesh/Desktop/outA.txt");
			BufferedWriter out = new BufferedWriter(fstream);

			for(int i = 1; i <= noOfCases; i++) {
				int noOfClasses = sc.nextInt();
				int[] inherits;
				matrix = new int[noOfClasses][];
				int noOfInherits;
				for(int j = 0; j< noOfClasses; j++) {
					noOfInherits = sc.nextInt();
					inherits = new int[noOfInherits];
					for(int k = 0; k < noOfInherits; k++) {
						inherits[k] = sc.nextInt();
					}
					matrix[j] = inherits;
				}
				boolean found = false;
				for(int j = 0; j < matrix.length; j++) {
					for(int k = 0; k < matrix.length; k++) {
						if(j != k) {
							if(hasTwoPaths(j, k)) {
								found = true;
								break;
							}
						}
					}
					if(found) {
						break;
					}
				}
				if(found) {
					System.out.println("Case #" + i + ": Yes");
				} else {
					System.out.println("Case #" + i + ": No");
				}
				
				
			}

			out.close();
			fstream.close();
			sc.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	private static boolean hasTwoPaths(int start, int end) {
		boolean hasAlreadyReached = false;
		ArrayList<Integer> queue = new ArrayList<Integer>();
		if(matrix[start].length > 0) {
			for(int i = 0; i < matrix[start].length; i++) {
				queue.add(matrix[start][i]);
			}
		}
		int processing = -1, queueInd = 0;
		while(queue.size() > 0 && queue.size() > queueInd) {
			processing = queue.get(queueInd);
			processing--;
			queueInd++;
			if(processing == end && hasAlreadyReached) { 
				return true;
			} else if(processing == end) {
				hasAlreadyReached = true;
			}
			for(int i = 0; i < matrix[processing].length; i++) {
				queue.add(matrix[processing][i]);
			}
		}
		return false;
	}

}
