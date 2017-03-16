import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class Elf {
	public static int solve(double number) {
		int counter=0;
		while(counter<40&&number<1)
		{
			number*=2;
			counter++;
		}
		double rest = number-1;
		int counter2=0;
		while(rest!=0&&counter2<(40-counter)){
			while(counter2<(40-counter)&&rest<1)
			{
				rest*=2;
				counter2++;
			}
			rest=rest-1;
		}
		if(counter2<(40-counter))
			return counter;
		return 40;
	}
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new File("textfile.txt"));
		PrintWriter out = new PrintWriter("output" + ".out");
//		Scanner input = new Scanner(System.in);
		int cases = Integer.parseInt(input.nextLine());
		for(int i=0;i<cases;i++)
		{
			String line = input.nextLine();
			String split [] = line.split("/");
			double num = Long.parseLong(split[0])*1.0/ Long.parseLong(split[1])*1.0;
			int res =solve(num);
			if(res<40)
			out.write("Case #"+(i+1)+": "+res+"\n");
			else
				out.write("Case #"+(i+1)+": impossible\n");
		}
		out.close();
	}


}
