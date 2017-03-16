
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.text.NumberFormat;



public class SafetyInNumbers {

	public static void main(String[] args) throws IOException 
	{
		//BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("A-small-attempt1.in")));
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("A-large.in")));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new FileWriter("SafetyInNumbers.txt"));
		int cases = Integer.parseInt(reader.readLine());
		NumberFormat formatter = new DecimalFormat("#0.000000");
		for(int i=1; i <= cases; i++)
		{
			String[] data = reader.readLine().split(" ");
			int numbers = Integer.parseInt(data[0]);
			int[] array = new int[numbers];
			int sum = 0;
			
			for(int j=1;j<=numbers;j++) {
				array[j-1] = Integer.parseInt(data[j]);
				sum += array[j-1];
			}
			String s = "";
			double votes = sum;
			double votesNeeded = ((double) sum) * 2 / numbers;
			int newSum=0, prevSum = sum;
			int counter=0;
			boolean change = false;
			do {
				change =false;
				newSum = sum;
				counter = numbers;
				for(int j=0;j<numbers;j++) {
					if(array[j] > votesNeeded) {
						counter--;
						newSum -= array[j];
					}
				}
				if(prevSum != newSum) {

					//System.out.println(votesNeeded +" " + newSum +" " + counter);
					votesNeeded = ((double)newSum + votes)/counter;
					//System.out.println(votesNeeded +" " + newSum +" " + counter);
					change = true;
					prevSum = newSum;
				}
					
				
			}while(change);
			
			for(int j=0;j<numbers;j++) {
				//s+= " " + formatter.format(Math.max(0,((X-array[j])/(double)(sum))*100));
//System.out.println(votesNeeded);
				s+= " " + formatter.format(Math.max(0,((votesNeeded-array[j])/votes)*100));
			}
			
			
			System.out.print("Case #" + i+ ":" + s+"\n");
			out.write("Case #" + i+ ":" + s+"\n");
		}
		out.close();
	}
}
/*
4
2
L 5 10
L 100 0
3
L 100 0
R 100 0
L 50 505
6
L 30 0
R 30 2
L 10 39
R 10 42
L 25 13
L 15 29
4
L 4 0
L 2 29
L 1 35
L 1 44
 */