import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class ProblemA {
	
	public static int recalc(int p, int q){
		if(p == 0)
			return 0;
		int count = 1;
		while(true){
			if(q%2 == 1)
				return -1;
			q = q/2;
			if(p >= q){
				p-=q;
				break;
			}
			count++;
		}
		int res = recalc(p,q);
		if(res >= 0)
			return count;
		return res;	
			
	}

	public static void main(String[] args) throws Exception{
		Scanner scanner = new Scanner(new File("A-small-attempt3.in"));
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("out1.txt")));
		int cases = scanner.nextInt();
		for(int i = 0; i < cases; i++){
			String next = scanner.next(); 
			int p = new Integer(next.split("/")[0]);
			int q = new Integer(next.split("/")[1]);
			String str = "Case #"+(i+1)+": ";
			int res = recalc(p, q);
			if(res < 1)
				str += "impossible";
			else
				str += ""+res;
			str += "\n";
			System.out.println(str);
			writer.write(str);
		}
		writer.flush();
		writer.close();
		scanner.close();
	}

}
