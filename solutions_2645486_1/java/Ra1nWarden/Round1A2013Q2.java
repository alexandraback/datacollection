import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class Round1A2013Q2 {

	public static void main(String[] args) throws Exception {
		Scanner reader = new Scanner(new File("B-large.in.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("Blarge.txt"));
		int cases = Integer.parseInt(reader.nextLine());
		int count = 1;
		long start = System.currentTimeMillis();
		while (cases >= count) {
			String[] firstline = reader.nextLine().split(" ");
			int max = Integer.parseInt(firstline[0]);
			int gain = Integer.parseInt(firstline[1]);
			int[] activities = new int[Integer.parseInt(firstline[2])];
			String[] secondline = reader.nextLine().split(" ");
			for(int i = 0; i < activities.length; i++)
				activities[i] = Integer.parseInt(secondline[i]);
			int group = (int) Math.ceil((double) max / (double) gain);
			BigInteger maxgain = new BigInteger("0");
			// first operation
			for(int i = 0; i < activities.length; i++) {
				if(i == 0) {
					int pointer = 0;
					while(pointer < group) {
						int maxvalue = submax(activities, 0, pointer);
						if(pointer < group - 1)
							maxgain = maxgain.add(new BigInteger(Integer.toString(maxvalue * gain))) ;
						else {
							int remain = max - ((group - 1) * gain);
							maxgain = maxgain.add(new BigInteger(Integer.toString(remain * maxvalue)));
						}
						pointer++;
					}
				}
				else if (i < activities.length - group) {
					int maxvalue = submax(activities, i, i + group - 1);
					maxgain = maxgain.add(new BigInteger(Integer.toString(maxvalue * gain))) ;
				}
				else {
					int maxvalue = submax(activities, i, activities.length - 1);
					maxgain = maxgain.add(new BigInteger(Integer.toString(maxvalue * gain))) ;
				}
			}
			pw.println("Case #" + count + ": " + maxgain);
			System.out.println("Case #" + count + ": " + maxgain);
			count++;
		}
		long end = System.currentTimeMillis();
		System.out.println((end - start) / 1000);
		pw.close();	
	}
	
	public static int submax(int[] array, int start, int end) {
		int result = Integer.MIN_VALUE;
		if(end > array.length - 1) {
			for(int i = start; i < array.length; i++) {
				if(array[i] > result)
					result = array[i];
			}
		}
		else {
			for(int i = start; i <= end; i++) {
				if(array[i] > result)
					result = array[i];
			}
		}
		return result;
	}

}
