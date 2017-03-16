

import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

/*
 * From array to list.
 *  Object[] array = new Object[]{"12","23","34"};
 *  java.util.List list = Arrays.asList(array);
 *
 * java.util.Collections --> (some functions, not all)
 *  binarySearch(List list, Object key) 
 *  copy(List dest, List src)        
 *  max(Collection coll), min(Collection coll)   
 *  reverse(List list) 
 *  sort(List list) 
 *  swap(List list, int i, int j) 
 */

/*
 * data = input.nextLine();
				String[] intS = Pattern.compile(" ").split(data);
				int[] numbers = new int[intS.length];
				for (int j = 0; j < intS.length; j++) {
					numbers[j] = Integer.parseInt(intS[j]);
				}
 */

/*
 * String manipulation, example
 * int j = 123456;
   String x = Integer.toString(j);
   x = x.substring(0, 4) + "." + x.substring(4, x.length());
 */

public class ProblemB {

	public static void main(String[] args) {
		try {
			Scanner input = new Scanner(new FileReader("A-small-attempt2.in"));
			PrintWriter output = new PrintWriter(new FileWriter("output2.txt"));

			int numberCases = input.nextInt();  
			String data = input.nextLine(); 

			for (int i = 0; i < numberCases; i++) {
				output.print("Case #" + (i + 1) + ": ");

				// SOLVE PROBLEM
				int vertices = input.nextInt();
				int[][] graph = new int[vertices][vertices];
				for(int j = 0; j < vertices; j++) {
					int elements = input.nextInt();
					for(int e = 0; e < elements; e++) {
						int element = input.nextInt();
						graph[j][element - 1] = 1;
					}
				}
				
				
				for(int j = 0; j < vertices; j++) {
					for(int k = 0; k < vertices; k++) {
						System.out.print(graph[j][k] + " ");
					}
					System.out.println("");
				}
				
				boolean solved = false;
				for(int j = 0; j < vertices; j++) {
					for(int k = 0; k < vertices; k++) {
						if (graph[j][k] != 0) {
							//System.out.println("Again");
							Queue q = new LinkedList();
							q.add(j);
							ArrayList a = new ArrayList();
							a.add(j);
							//a.add(k);
							while(!q.isEmpty()) {
								int currentNode = (Integer) q.poll();
								//System.out.println("C " + currentNode + " " + a);
								for(int h = 0; h < vertices; h++) {
									if (graph[currentNode][h] != 0) {
										q.add(h);
										if (a.contains(h)) {
											//System.out.println(" :)");
											solved = true;
										} else { 
											a.add(h);
										}
											
									}
								}
							}
						}
					}
				}
				if (solved)
					output.print("Yes");
				else 
					output.print("No");
				
				output.print("\n");
			}

			output.flush();
			output.close();
			input.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}


}


