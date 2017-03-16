package round1a;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class ProblemB {
	
    public static String input = "B-small-attempt1.in";

	public static void main(String[] args) throws Exception{
//		Scanner in = new Scanner(System.in);
		Scanner in = new Scanner(new FileReader(input));
//		PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new FileWriter(input + ".out"));
		
		int num = in.nextInt();
		for (int i = 0; i < num; i++){
			int level = in.nextInt();
			ArrayList<Turple> star1 = new ArrayList<Turple>();
			ArrayList<Turple> star2 = new ArrayList<Turple>();
			for (int j = 0; j < level; j++)
			{
				star1.add(new Turple(j, in.nextInt()));
				star2.add(new Turple(j, in.nextInt()));
			}
			
			Collections.sort(star1);
			Collections.sort(star2);
			boolean[] finished1 = new boolean[level];
			for (int j = 0; j < level; j++)
				finished1[j] = false;
			
			int starNow = 0;
			int star2index = 0;
			int star1index = 0;
			int tempt = 0;
			
			boolean flag = true;
			while (star2index < star2.size() && flag){
				if (starNow >= star2.get(star2index).require)
				{
					if (!finished1[star2.get(star2index).levelNum])
					{
						starNow += 2;
						finished1[star2.get(star2index).levelNum] = true;
					}	
					else
						starNow += 1;
//					starNow -= star2.get(star2index).require;
					star2index++;
					tempt++;
				}else if (star1index < star1.size()){
					while ((star1index < star1.size()) && finished1[star1.get(star1index).levelNum])
						star1index++;
					if (star1index < star1.size() && starNow >= star1.get(star1index).require){
						starNow += 1;
						finished1[star1.get(star1index).levelNum] = true;
//						starNow -= star1.get(star1index).require;
						star1index++;
						tempt++;
					}else
						flag = false;
				}else
					flag = false;
			}
			
			if (star2index == star2.size())
				out.write("Case #" + (i+1) + ": " + tempt + "\n");
			else
				out.write("Case #" + (i+1) + ": " + "Too Bad\n");
		}
		
		out.close();
	}

}

class Turple implements Comparable<Turple>{
	int levelNum;
	int require;
	public Turple(int levelNum, int require){
		this.levelNum = levelNum;
		this.require = require;
	}
	@Override
	public int compareTo(Turple t) {
		if (t.require < this.require)
			return 1;
		else if (t.require == this.require)
			return 0;
		else return -1;
	}
}
