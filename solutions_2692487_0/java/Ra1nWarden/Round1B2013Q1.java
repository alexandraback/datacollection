import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class Round1B2013Q1 {

	public static void main(String[] args) throws Exception {
		Scanner reader = new Scanner(new File("A-small-attempt2.in.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("Asmall.txt"));
		int cases = Integer.parseInt(reader.nextLine());
		int count = 1;
		long start = System.currentTimeMillis();
		while (cases >= count) {
			String[] firstline = reader.nextLine().split(" ");
			BigInteger startnumber = new BigInteger(firstline[0]);
			
			ArrayList<BigInteger> list = new ArrayList<BigInteger>();
			String[] secondline = reader.nextLine().split(" ");
			for(int i = 0; i < secondline.length; i++)
				list.add(new BigInteger(secondline[i]));
			Collections.sort(list);
			int result = 0;
			if(startnumber.compareTo(BigInteger.ONE) > 0) {
				ArrayList<Integer> increase = new ArrayList<Integer>();
				for(int i = 0; i < list.size(); i++) {
					int increasecount = 0;
					BigInteger nexttarget = list.get(i);
					while(!(startnumber.compareTo(nexttarget) > 0)) {
						startnumber = startnumber.multiply(new BigInteger("2"));
						startnumber = startnumber.subtract(BigInteger.ONE);
						increasecount++;
					}
					increase.add(increasecount);
					startnumber = startnumber.add(nexttarget);
				}
			
				for(int i = increase.size() - 1; i >= 0; i--) {
					result += increase.get(i);
					int compare = increase.size() - i;
					if(result > compare)
						result = compare;
				}
			}
			else
				result = secondline.length;
			pw.println("Case #" + count + ": " + result);
			System.out.println("Case #" + count + ": " + result);
			count++;
		}
		long end = System.currentTimeMillis();
		System.out.println((end - start) / 1000);
		pw.close();	
	}

}
