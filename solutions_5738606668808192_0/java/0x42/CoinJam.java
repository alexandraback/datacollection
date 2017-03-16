import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.StreamTokenizer;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class CoinJam {


    public static void main(String[] args) throws Exception {
    	CoinJam object = new CoinJam();
        String className = object.getClass().getSimpleName();

        FileReader fileReader = new FileReader(new File(className.toLowerCase()
                + ".in"));
        StreamTokenizer st = new StreamTokenizer(new BufferedReader(fileReader));

        FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

        st.nextToken();
        int testCases = (int) st.nval;
        
        List<Integer> primes = generatePrimes(1000);

        for (int tc = 1; tc <= testCases; tc++) {

            System.out.println("At test " + tc + "/" + testCases);

            st.nextToken();
            int N = (int) st.nval;
            
            st.nextToken();
            int J = (int) st.nval;
            
            String result = object.solve(N, J, primes);
            wr.write("Case #" + tc + ": \r\n" + result);
        }

        wr.close();
    }

    private static List<Integer> generatePrimes(int N) {
    	List<Integer> primes = new ArrayList<>();
    	
		for(int i=2; i<=N; i++)
			if(isPrime(i)){
				primes.add(i);
			}
		
		return primes;
	}

	private static boolean isPrime(int N) {
		if(N < 4){
			return true;
		}
		
		if(N % 2 == 0){
			return false;
		}
		
		for(int i=3; i*i <= N; i+=2)
			if(N % i == 0){
				return false;
			}
		
		return true;
	}

	public String solve(int N, int J, List<Integer> primes) {

		StringBuilder sb = new StringBuilder();
		int printed = 0;
		
    	for(int i=0; i<(1 << (N - 2)); i++){
    		
    		int certainty = 10;
    		String number = "1" + prepend(Long.toString(i, 2), N - 2) + "1";
    		
    		BigInteger base2 = new BigInteger(number, 2);
    		BigInteger base3 = new BigInteger(number, 3);
    		    		
    		if(base2.isProbablePrime(certainty) || base3.isProbablePrime(certainty)){
    			continue;
    		}
    		
    		BigInteger base4 = new BigInteger(number, 4);
    		BigInteger base5 = new BigInteger(number, 5);
    		BigInteger base6 = new BigInteger(number, 6);
    		
    		if(base4.isProbablePrime(certainty) || base5.isProbablePrime(certainty) || base6.isProbablePrime(certainty)){
    			continue;
    		}
    		
    		BigInteger base7 = new BigInteger(number, 7);
    		BigInteger base8 = new BigInteger(number, 8);
    		BigInteger base9 = new BigInteger(number, 9);
    		BigInteger base10 = new BigInteger(number, 10);
    		
    		if(base7.isProbablePrime(certainty) || base8.isProbablePrime(certainty) || base9.isProbablePrime(certainty) || base10.isProbablePrime(certainty)){
    			continue;
    		}
    		
    		int divisor2 = findDivisor(base2, primes);
    		int divisor3 = findDivisor(base3, primes);
    		int divisor4 = findDivisor(base4, primes);
    		int divisor5 = findDivisor(base5, primes);
    		int divisor6 = findDivisor(base6, primes);
    		int divisor7 = findDivisor(base7, primes);
    		int divisor8 = findDivisor(base8, primes);
    		int divisor9 = findDivisor(base9, primes);
    		int divisor10 = findDivisor(base10, primes);
    		
    		if(divisor2 > 1 && divisor3 > 1 && divisor4 > 1 && divisor5 > 1)
    			if(divisor6 > 1 && divisor7 > 1 && divisor8 > 1 && divisor9 > 1 && divisor10 > 1){
    				sb.append(number + " " + divisor2 + " " + divisor3 + " " + divisor4 + " " + divisor5 + " ");
    				sb.append(divisor6 + " " + divisor7 + " " + divisor8 + " " + divisor9 + " " + divisor10 + "\r\n");
    				
    				printed++;
    				if(printed == J){
    					return sb.toString();
    				}
    				
    			}
    	}
    
    	return "";
    }

	private String prepend(String string, int N) {
		while(string.length() < N)
			string = "0" + string;
		
		return string;
	}

	private int findDivisor(BigInteger number, List<Integer> primes) {
		
		for(Integer prime : primes) {
			if(number.compareTo(BigInteger.valueOf(prime)) <= 0){
				return -1;
			}
		
			BigInteger[] division = number.divideAndRemainder(BigInteger.valueOf(prime));
			if(division[1].equals(BigInteger.ZERO)){
				return prime;
			}
		}
		
		return -1;
	}
	
}
