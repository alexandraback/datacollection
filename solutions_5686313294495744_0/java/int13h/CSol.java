import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;


public class CSol {


	public static void main(String[] args) {
		
		
		
		
		
		Date d1 = new Date();
		//solveC("c.in", "c.out");
		//solveC("C-large.in", "C-large.out");		
		solveC("C-small-attempt1.in", "C-small-attempt1.out");
		
		Date d2 = new Date();
		System.out.println("time: " + (d2.getTime() - d1.getTime()));

	}



	

	

	
	private static void solveC(String in, String out) {
		try {
			
			FileWriter fw = new FileWriter(out);
			BufferedWriter bw = new BufferedWriter(fw);
			
			Scanner sc = new Scanner(new File(in));

			long t = sc.nextLong();
			sc.nextLine();
			
			
			

			for (long i2 = 0; i2 < t; i2++) {
				
				int n = sc.nextInt();
				
				
				
				ArrayList<String> topicsA = new ArrayList<String>();
				ArrayList<String> topicsB = new ArrayList<String>();
				
				for (int i = 0; i < n; i++) {
					String c= sc.next();
					String j= sc.next();
					
					topicsA.add(c);
					topicsB.add(j);

				}
				
				int rez = solve(topicsA, topicsB);
				bw.write("Case #" + (i2+1) + ": " + rez + "\n");
				//System.out.println("result: " + rez);
				
				
			}				
				
			
			bw.flush();
			bw.close();
			fw.close();
			sc.close();
		} catch (FileNotFoundException e) {
			
		} catch (IOException e) {
			
		} finally {
			
		}
	}








	private static int solve(ArrayList<String> topicsA, ArrayList<String> topicsB) {
		
		HashMap<String, Integer> countsA = new HashMap<String, Integer>();
		HashMap<String, Integer> countsB = new HashMap<String, Integer>();
		for (String topic : topicsA) {
			
			if (countsA.get(topic) == null) {
				countsA.put(topic, 1);
			} else {
				countsA.put(topic, countsA.get(topic)+1);
			}
			
			
		}
		for (String topic : topicsB) {
			
			if (countsB.get(topic) == null) {
				countsB.put(topic, 1);
			} else {
				countsB.put(topic, countsB.get(topic)+1);
			}

		}
		Collection<Integer> v1 = countsA.values();
		Collection<Integer> v2 = countsB.values();
		
		List<Integer> l1 = new ArrayList<Integer>(v1);
		List<Integer> l2 = new ArrayList<Integer>(v2);
		Collections.sort(l1);
		Collections.reverse(l1);
		Collections.sort(l2);
		Collections.reverse(l2);
		
		
		//System.out.println();
		//System.out.println(l1);
		//System.out.println(l2);
		
		int words = 0;
		for (int i = 0; i < l1.size(); i++) {
			int s = l1.get(i);
			if (s > 1) {
				
				List<Integer> l22 = new ArrayList<Integer>();
				for (int j = 0; j < l2.size(); j++) {
					int s2 = l2.get(j);
					if ((j < s-1) && (s2 > 1)) {
						l22.add(s2-1);
						words++;
					} else {
						if (s2 > 1) {
							l22.add(s2);
						}
					}
				}
				
				Collections.sort(l22);
				Collections.reverse(l22);
				
				
				//System.out.println(l22);
				l2 = l22;
				
			} else {
				break;
			}
		}
		
		//System.out.println(words);
	

		return words;
	}








	









}
