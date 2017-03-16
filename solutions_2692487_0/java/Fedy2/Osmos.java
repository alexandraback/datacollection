/**
 * 
 */
package org.codejam;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.LineNumberReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

/**
 * @author Federico De Faveri defaveri@gmail.com
 *
 */
public class Osmos {

	protected static final String DATA_FOLDER = "data";
	protected static final String PROBLEM = "A";

	protected static final String EXAMPLE_DATA_INPUT = DATA_FOLDER + File.separator + "example.in"; 
	protected static final String SMALL_DATA_INPUT = DATA_FOLDER + File.separator + PROBLEM + "-small-attempt2.in"; 
	protected static final String LARGE_DATA_INPUT = DATA_FOLDER + File.separator + PROBLEM + "-large.in";

	protected static final String EXAMPLE_DATA_OUTPUT = DATA_FOLDER + File.separator + "example.out"; 
	protected static final String SMALL_DATA_OUTPUT = DATA_FOLDER + File.separator + PROBLEM + "-small-attempt2.out"; 
	protected static final String LARGE_DATA_OUTPUT = DATA_FOLDER + File.separator + PROBLEM + "-large.out";

	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {
		LineNumberReader reader = new LineNumberReader(new FileReader(SMALL_DATA_INPUT));
		BufferedWriter writer = new BufferedWriter(new FileWriter(SMALL_DATA_OUTPUT));

		int t = Integer.parseInt(reader.readLine());
		System.out.println("t: "+t);
		System.out.println();

		for (int l = 0; l < t; l++) {

			int[] aMote = parseArray(reader.readLine());
			int arminMote = aMote[0];

			int[] motes = parseArray(reader.readLine());

			int operations = calculateMoves(arminMote, motes);

			String solution = "Case #"+(l+1)+": "+operations;
			System.out.println(solution);
			System.out.println();
			System.out.println();
			writer.write(solution);
			writer.newLine();
		}


		System.out.println("done");
		reader.close();
		writer.close();		
	}

	protected static int calculateMoves(int arminMoteSize, int[] motes)
	{
		Arrays.sort(motes);
		return calculateMoves(arminMoteSize, 0, motes);
	}

	protected static int calculateMoves(int current, int index, int[] motes)
	{
		System.out.println("calculateMoves current: "+current+ " index:"+index+" motes: "+Arrays.toString(motes));

		if (index==motes.length) return 0;

		int smallest = motes[index];
		System.out.println("smallest: "+smallest);

		if (smallest<current) {
			return calculateMoves(current + smallest, index+1, motes);
		} else {


			//if (smallest-current>=current) {
				//removing
				int removing = 1 + calculateMoves(current, index + 1, motes);
				int smallAdding = smallAdding(smallest, current, motes, index + 1);
				
				System.out.println("smallAdding: "+smallAdding + "removing: "+removing+" smallest: "+smallest);
				
				return Math.min(removing, smallAdding);

			/*} else {
				//adding
				System.out.println("adding");
				current += current - 1;
				return 1 + calculateMoves(current, index + 1, motes);
			}*/
		}
	}
	
	protected static int smallAdding(int target, int current, int[] motes, int index)
	{
		System.out.println("small adding target: "+target+ " current: "+current);
		if (current == 1) return Integer.MAX_VALUE;
		int ops = 0;
		while(current<=target) {
			current += current-1;
			ops++;
		}
		System.out.println("ops: "+ops);
		return ops + calculateMoves(current+target, index, motes);
	}

	/*protected static int calculateMoves(int arminMoteSize, int[] motes)
	{
		System.out.println("arminMoteSize: "+arminMoteSize+ " motes: "+Arrays.toString(motes));
		List<Integer> remainingMotes = new ArrayList<>(motes.length);
		for (int mote:motes) remainingMotes.add(mote);


		int current = arminMoteSize;
		int operations = 0;

		Collections.sort(remainingMotes);

		while(remainingMotes.size()>0) {
			System.out.println("current: "+current+" operations: "+operations);
			int smallest = remainingMotes.remove(0);
			System.out.println("smallest: "+smallest);

			if (smallest<current) current += smallest;
			else {
				if (smallest-current>=current) {
					//removing
					operations++;
					System.out.println("removing");
				} else {
					//adding
					current += current - 1;
					operations++;
					System.out.println("adding");
				}
			}
		}
		System.out.println("operations: "+operations);
		System.out.println();

		return operations;
	}*/


	protected static int[] parseArray(String line)
	{
		String[] tokens = line.split(" ");
		int[] array = new int[tokens.length];
		for (int i = 0; i < tokens.length; i++) {
			array[i] = Integer.parseInt(tokens[i]);
		}
		return array;
	}

}
