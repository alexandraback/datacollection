import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Set;
import java.util.TreeSet;


public class ProblemC {
	
	static Set<Long> preloaded = new TreeSet<>();
	
	static boolean isPalindrome(long num) {
		String str = Long.toString(num);
		int len = str.length();
		for(int i = 0; i < len / 2; i++) {
			if(str.charAt(i) != str.charAt(len - i - 1)) return false;
		}
		return true;
	}
	
	static long limit = 100000000000000L;
	
	public static void main(String[] args) {
		Thread preloadOdd = new Thread() {
			@Override public void run() {
				for(long num = 1; num < Math.sqrt(limit) + 1; num += 2L) {
					long sqr = num*num;
					// if(sqr > limit) break;
					
					if(isPalindrome(num) && isPalindrome(sqr)) preloaded.add(sqr);
				}
			}
		};
		preloadOdd.start();
		
		Thread preloadEven = new Thread() {
			@Override public void run() {
				for(long num = 2; num < Math.sqrt(limit) + 1; num += 2L) {
					long sqr = num*num;
					// if(sqr > limit) break;
					
					if(isPalindrome(num) && isPalindrome(sqr)) preloaded.add(sqr);
				}
			}
		};
		preloadEven.start();
		
		while(preloadOdd.isAlive() || preloadEven.isAlive()) {
			try { Thread.sleep(500); } catch(InterruptedException iex) { }
		}
		
		try {
			BufferedReader reader = new BufferedReader(new FileReader("c.in"));
			BufferedWriter writer = new BufferedWriter(new FileWriter("c.out"));
			
			int N = Integer.parseInt(reader.readLine());
			for(int idx = 0; idx < N; idx++) {
				String limits = reader.readLine();
				long A = Long.parseLong(limits.split("\\s+")[0]);
				long B = Long.parseLong(limits.split("\\s+")[1]);
				
				long count = 0L;
				for(long num : preloaded) {
					if(num >= A && num <= B) count++;
				}
				
				System.out.println("Case #" + (idx+1) + ": " + count);
				
				writer.append("Case #" + (idx+1) + ": " + count);
				writer.newLine();
			}
			
			writer.close();
			reader.close();
		} catch(Throwable t) {
			t.printStackTrace();
		}
	}
	
}
