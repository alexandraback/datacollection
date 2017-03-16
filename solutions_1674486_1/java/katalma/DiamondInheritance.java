package hu.hke.gcj1c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.List;

public class DiamondInheritance {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		readAndDecide(args[0], args[1]);
//		System.out.println(args[0]);

	}

	private static void readAndDecide(String inputF, String outputF) {
		BufferedReader input = null;
		BufferedWriter output = null;
		try {
			String line1 = null;
			String[] line2 = null;
			input = new BufferedReader(new FileReader(inputF));
			output = new BufferedWriter(new FileWriter(outputF));
			int expectedCases = 0;
			int actualtestCaseRow=-1;
			int actualExpectedTestCaseRow = -1;
			int actualCase = -1;
			while (((line1 = input.readLine()) != null)
					) {
				if (actualCase == -1) {
					expectedCases = Integer.parseInt(line1);
					actualCase++;
				} else  if (actualtestCaseRow == actualExpectedTestCaseRow) {
					if  (actualCase > 0) {
						output.write("Case #" + (actualCase) + ": "
								+ diamond(actualExpectedTestCaseRow,line2) + "\n");	
					}
					actualExpectedTestCaseRow  = Integer.parseInt(line1);
					line2 = new String[actualExpectedTestCaseRow];
					actualtestCaseRow = 0;
					actualCase++;
				} else {
					line2[actualtestCaseRow] = line1;
					actualtestCaseRow++;
				} 
			}
			output.write("Case #" + (actualCase) + ": "
					+  diamond(actualExpectedTestCaseRow,line2)+ "\n");	

			input.close();
			output.close();
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
		}

	}

	private static String diamond(int classNumber, String[] line2) {
		String result = "No";
		int[][] graph = new int[classNumber][];
		System.out.println(classNumber + " " +line2.length + "------------");
		for (int i = 0 ; i< classNumber; i++ ) {
			//System.out.println(line2[i]);
			String[] iP = line2[i].split(" ");
			graph[i] = new int[iP.length - 1];
			// most a graph[i][0] az õsök száma, elveszik...
				for (int j = 1; j<iP.length; j++) {
					graph[i][j-1] = Integer.parseInt(iP[j]) -1;
					//System.out.print (" " + graph[i][j-1]);
				}
				//System.out.println();
		}
		boolean diamond = false;
		for (int i = 0; i<classNumber && !diamond ; i++ ){
			List ancestors = new ArrayList();
			ancestors.add(i);
			System.out.print(i +" : " );
			diamond = calculateAncestors(ancestors, graph, i);
			System.out.println(diamond);
		}
		if (diamond) {
			return "Yes";
		}
		return result;
	}

	private static boolean calculateAncestors(List ancestors, int[][] graph, int i) {
		boolean result  = false;
		if (graph[i] == null ) {return false;}
		for (int j = 0; j < graph[i].length; j++) {
			if (ancestors.contains(graph[i][j])) {
				return true;
			}
			System.out.print( graph[i][j] + " ");
			ancestors.add(graph[i][j]);
			result = result || calculateAncestors(ancestors, graph, graph[i][j]);
		}
		return result;
	}

}
