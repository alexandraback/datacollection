import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class BullsEye {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception  {
		Scanner s = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(new File("output.txt"));
		
		int T = s.nextInt();
		int it=0;
		while(T-- > 0){
			it++;
			
			long r = s.nextInt();
			long t = s.nextInt();
			
			long tmp = 0;
			long i = 1;
			int cnt = 0;
			while(true){
				
				tmp += (r+i)*(r+i) - (r+i-1)*(r+i-1);
				
				if(tmp > t){
					break;
				}
				
				cnt++;				
				i += 2;
			}
			
			
			pw.printf("Case #%d: %d\n", it, cnt);
			
		}
		
		pw.close();
	}

}
