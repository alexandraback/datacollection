import java.io.*;
import java.util.*;
import java.math.*;

public class ProblemC {
	static ArrayList<String> primes = new ArrayList<String>();
	

	public static void main(String[] args) throws NumberFormatException, IOException {
		generatePrimes(999999);
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int numCases = Integer.parseInt(in.nextLine());
		for (int caseNum = 1; caseNum <= numCases; caseNum++) {
			String line = in.nextLine();
			Scanner sc = new Scanner(line);
			int n = Integer.parseInt(sc.next());
			int j = Integer.parseInt(sc.next());
			int found = 0;
			printAnswer("", caseNum);
			for(long i = (long)Math.pow(2, n - 1) + 1; i < Math.pow(2, n); i+=2){
				String s = Long.toBinaryString(i);
				String result = "";
				boolean pass = true;
				for(int base = 2; base <= 10; base++){
					BigInteger x = new BigInteger(s, base);
					String factor = getFactor(x);
					if(factor.length() == 0){
						pass = false;
						break;
					} else {
						result += factor + " ";
					}
				}
				if(pass){
					found++;
					result = s + " " + result;
					System.out.println(result.trim());
				}
				if(found == j) break;
			}
		}
	}
	public static String getFactor(BigInteger x){
		for(int i = 0; i < primes.size(); i++){
			if(x.mod(new BigInteger(primes.get(i))).intValue() == 0 && !x.equals(new BigInteger(primes.get(i)))) return primes.get(i);
		}
		return "";
	}
	public static void printAnswer(String answer, int caseNumber) throws IOException {
		System.out.println("Case #" + caseNumber + ": " + answer);
	}
	public static void generatePrimes(int max){
		boolean[] isComposite = new boolean[max + 1];
		for(int i = 2; i <= max/2; i++){
			if(!isComposite[i]){
				primes.add("" + i);
				for(int multiplier = 2 ; multiplier <= max/i; multiplier++){
					isComposite[i * multiplier] = true;
				}
			}
		}
		for(int i = max/2 + 1; i < max; i++){
			if(!isComposite[i]){
				primes.add("" + i);
			}
		}
	}
}
