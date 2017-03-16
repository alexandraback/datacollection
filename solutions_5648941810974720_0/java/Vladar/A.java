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


public class A {
	public static void main(String [] args) throws Exception
	{		
		Scanner sc = new Scanner(new File("A/small.txt"));
		PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(new File("src/A.txt"))));
		int size = sc.nextInt();
		sc.nextLine();

		for (int i=0; i<size; i++) {
			
			String line = sc.nextLine();
			System.out.println(line);
			
			// Case #
			writer.print("Case #" + (i+1) + ": ");
			System.out.print("Case #" + (i+1) + ": ");

			// Solve
			char[] s = line.toCharArray();
			
			int[] chars = new int[10000];
			for(int j = 0; j<line.length(); j++) {
				chars[Character.toLowerCase(s[j])]++;
			}

			int[] nums = new int[10];
			
			nums[0] = chars['z'];
			chars['z']-=nums[0];
			chars['e']-=nums[0];
			chars['r']-=nums[0];
			chars['o']-=nums[0];

			nums[6] = chars['x'];
			chars['s']-=nums[6];
			chars['i']-=nums[6];
			chars['x']-=nums[6];

			nums[8] = chars['g'];
			chars['e']-=nums[8];
			chars['i']-=nums[8];
			chars['g']-=nums[8];
			chars['h']-=nums[8];
			chars['t']-=nums[8];

			nums[2] = chars['w'];
			chars['t']-=nums[2];
			chars['w']-=nums[2];
			chars['o']-=nums[2];

			nums[7] = chars['s'];
			chars['s']-=nums[7];
			chars['e']-=nums[7];
			chars['v']-=nums[7];
			chars['e']-=nums[7];
			chars['n']-=nums[7];

			nums[5] = chars['v'];
			chars['f']-=nums[5];
			chars['i']-=nums[5];
			chars['v']-=nums[5];
			chars['e']-=nums[5];

			nums[4] = chars['f'];
			chars['f']-=nums[4];
			chars['o']-=nums[4];
			chars['u']-=nums[4];
			chars['r']-=nums[4];

			nums[3] = chars['r'];
			chars['t']-=nums[3];
			chars['h']-=nums[3];
			chars['r']-=nums[3];
			chars['e']-=nums[3];
			chars['e']-=nums[3];

			nums[1] = chars['o'];
			chars['o']-=nums[1];
			chars['n']-=nums[1];
			chars['e']-=nums[1];

			nums[9] = chars['n']/2;
			chars['n']-=nums[9];
			chars['i']-=nums[9];
			chars['n']-=nums[9];
			chars['e']-=nums[9];

			// Print result

			for(int k=0; k<10; k++) {
				for(int l=0; l<nums[k]; l++) {
					writer.print(k);
					System.out.print(k);
				}
			}
			writer.println("");
			System.out.println("");
		}

		writer.close();
		sc.close();
	}
}