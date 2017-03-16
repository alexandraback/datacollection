import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class CountingSheep {
	public static void main(String[] args) throws IOException{
		Scanner kb = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new FileWriter("countingsheep.out"));
		int cases = kb.nextInt();
		for(int n=0; n < cases; n++)
			out.println("Case #" + (n + 1) + ": " + getAns(kb.nextInt()));
		out.close();
	}
	
	public static String getAns(int num) {
		if (num==0)
			return "INSOMNIA";
		boolean[] digits = new boolean[10];
		boolean allFound = false;
		int myNum = num;
		while(!allFound) {
			int temp = myNum;
			while (temp != 0) {
				digits[temp % 10] = true;
				temp /= 10;
			}
			allFound = true;
			for (int i=0; i < 10; i++)
				if (!digits[i])
					allFound = false;
			myNum += num;
		}
		return (myNum - num) + "";
	}
}