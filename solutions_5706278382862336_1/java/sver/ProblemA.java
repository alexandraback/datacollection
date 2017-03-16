import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class ProblemA {
	
	public static long recalc(long p, long q){
		if(p == 0)
			return 0;
		long count = 1;
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
		long res = recalc(p,q);
		if(res >= 0)
			return count;
		return res;	
			
	}

	public static void main(String[] args) throws Exception{
		Scanner scanner = new Scanner(new File("A-large.in"));
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("out1.txt")));
		int cases = scanner.nextInt();
		for(int i = 0; i < cases; i++){
			String next = scanner.next(); 
			long p = new Long(next.split("/")[0]);
			long q = new Long(next.split("/")[1]);
			String str = "Case #"+(i+1)+": ";
			long res = recalc(p, q);
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
