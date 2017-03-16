import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Q13 {

	public static void main(String[] args) {
		try {
			Scanner in = new Scanner(new File("C-small-attempt0.in"));
			PrintWriter out = new PrintWriter("C-small-attempt0.out");
			int numberOfCases = Integer.parseInt(in.nextLine());
			for (int caseNum = 1; caseNum <= numberOfCases; caseNum++) {
                long c = in.nextLong();
                long d = in.nextLong();
                long v = in.nextLong();
                ArrayList<Long> coins = new ArrayList<Long>();
                for(long i = 0; i < d; i++){
                	coins.add(in.nextLong());
                }
                long added = 0;
                long currentCount = 0;
                int currentIndex = 0;
                for(long i = 1; i <= v; i++){
                    for(int j = 0; currentIndex < coins.size() && coins.get(currentIndex) <= i; currentIndex++){
                        currentCount += coins.get(currentIndex)*c;
                    }
                    if ( i > currentCount){
                    	added ++;
                        currentCount += i * c;
                    }
                }
  				out.println("Case #" + caseNum + ": " + added);
			}
			in.close();
			out.close();
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}
}
