import java.util.HashMap;
import java.util.Scanner;
import java.util.concurrent.ArrayBlockingQueue;


public class GCJ_3 {
	

	public static HashMap<String, Object> pairs = new HashMap<String, Object>();
	
	//private static final String EMPTY_STR = "";

	public static int combinations(long n1, Long B) {
		int combinations = 0;
		
		StringBuffer Nstr = new StringBuffer(String.valueOf(n1));
		int nInt = Integer.valueOf(Nstr.toString());
		
		ArrayBlockingQueue<Character> queue = new ArrayBlockingQueue<Character>(15);
		for (int i = 0; i < Nstr.length(); i++) {
			queue.add(Nstr.charAt(i));
		}
		
		for (int i = 0; i < Nstr.length(); i++) {
			queue.add(queue.poll());
			Object[] numbers = (Object[]) queue.toArray();
			StringBuffer comb = new StringBuffer();
			for (int j = 0; j < numbers.length; j++) comb.append(numbers[j]);
			if (comb.charAt(0) == '0') continue;
			int p1 = Integer.valueOf(comb.toString());
			if ((p1 > nInt) && (p1 <= B)) {
				combinations++;
				pairs.put(Nstr.toString() + comb.toString(), new Object());
			}
			
		}
		
		
		
		/*StringBuffer Nstr = new StringBuffer(String.valueOf(n1));
		for (int i = 1; i < Nstr.length(); i++) {
			 StringBuffer sb = new StringBuffer(Nstr.subSequence(i, Nstr.length()));
			 sb.append(Nstr.subSequence(0, i));
			 if (Long.valueOf(Nstr.charAt(i) + EMPTY_STR) == 0) {
				 continue;
			 }

			 if (Long.valueOf(Nstr.toString()) >= Long.valueOf(sb.toString())) {
				 continue;
			 }
			 
			 if ((Long.valueOf(sb.toString()) >= B)) {
				 continue;
			 } else {
				 combinations++;
			 }
			 
		}*/
				 

		return combinations;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		scan.nextLine();
		int nCase = 1;
		while (T-- > 0) {
			
			

			StringBuffer Astr = new StringBuffer(scan.next());
			StringBuffer Bstr = new StringBuffer(scan.next());
			Long A = new Long(Astr.toString());
			Long B = new Long(Bstr.toString());
			
			pairs.clear();

			for (long n = A; n < B; n++) {

				int c = GCJ_3.combinations(n, B);
				
			}
			
			scan.nextLine();
			System.out.println("Case #" + (nCase++) + ": " + pairs.size());

		}

	}

}
