import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;

/*
UTILS :

ArrayList<Long>[] sol = (ArrayList<Long>[]) new ArrayList[size];
Collections.sort();
System.out.println("");
(String).toCharArray();

sc.nextLong();
sc.nextBigInteger();
sc.nextLine();
sc.nextDouble();
sc.nextInt();
sc.nextInt(int radix);
sc.nextBoolean();
 */


public class C {
	public static void main(String [] args) throws Exception
	{		
		Scanner sc = new Scanner(new File("C/small.txt"));
		PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(new File("src/C.txt"))));
		int size = sc.nextInt();
		sc.nextLine();
		
		HashMap<String, Integer> h1 = new HashMap<String, Integer>();
		HashMap<String, Integer> h2 = new HashMap<String, Integer>();
		
		for (int i=0; i<size; i++) {
			// Case #
			writer.print("Case #" + (i+1) + ": ");
			System.out.print("Case #" + (i+1) + ": ");

			// Solve
			
			int num = sc.nextInt();
			sc.nextLine();
			
			String[][] sheet = new String[num][2];
			for(int j = 0; j<num; j++) {
				String line = sc.nextLine();
				String[] parts = line.split(" ");
				String part1 = parts[0];
				String part2 = parts[1];
				
				sheet[j][0] = part1;
				sheet[j][1] = part2;
				
				if(h1.containsKey(part1)) {
					int count = h1.get(part1);
					h1.put(part1, ++count);
				}
				else {
					h1.put(part1, 1);
				}
				
				if(h2.containsKey(part2)) {
					int count = h2.get(part2);
					h2.put(part2, ++count);
				}
				else {
					h2.put(part2, 1);
				}
			}			
			
			int max = 0;
			for(int j = 0; j<num; j++) {
				if(h1.get(sheet[j][0])>1 && h2.get(sheet[j][1])>1) {
					max++;
					
					int v1 = h1.get(sheet[j][0]);
					h1.put(sheet[j][0], --v1);
					
					int v2 = h2.get(sheet[j][1]);
					h2.put(sheet[j][1], --v2);
				}
				
			}

			// Print result
			writer.println(max);
			System.out.println(max);
		}

		writer.close();
		sc.close();
	}
}






