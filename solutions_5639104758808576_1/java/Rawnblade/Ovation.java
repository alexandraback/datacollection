import java.io.File;
import java.io.PrintWriter;
import java.util.*;

public class Ovation{
	public static void main(String[] args) throws Exception{
		Scanner reader = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new File("a.out"));
		
		int times = reader.nextInt();
		for(int t = 1; t <= times; t++){
			int n = reader.nextInt();
			char[] e = reader.next().toCharArray();
			
			int add = 0;
			int cnt = (int)(e[0] - '0');
			for(int i = 1; i < e.length; i++){
				int extra = Math.max(0, i - cnt);
				add += extra;
				cnt += extra + (int)(e[i] - '0');
			}
			
			out.println("Case #"+t+": "+add);
		}
		
		out.close();
	}
}
