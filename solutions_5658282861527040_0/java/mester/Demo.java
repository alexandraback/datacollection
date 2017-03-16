import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Demo {

	public static void main(String[] args) throws FileNotFoundException {

		Scanner scanner = new Scanner(new File("D:\\DEV\\Eclipse\\workspace_11.04.2014\\Q2\\src\\input.txt"));

		// eat T
		scanner.next();
		
		int curCaseNo = 1;
		while (scanner.hasNext()) {
			long A = scanner.nextLong();
			long B = scanner.nextLong();
			long K = scanner.nextLong();
			
			int num = 0;
			for ( long a = 0; a < A; a++ ) {
				for ( long b = 0; b < B; b++ ) {
					long result = a & b;
					if ( result < K ) {
						num++;
					}
				}
			}
			
			System.out.println("Case #" + curCaseNo + ": " + num);
			
			curCaseNo++;
		}

	}

}
