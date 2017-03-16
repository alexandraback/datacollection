import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;


public class GoodLuck {

	private int r;
	private int m;
	private int n;
	private int k;
	
	private PrintWriter pw;
	
	private ArrayList<ArrayList<Long>> products;

	public GoodLuck() throws IOException {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		int numberOfCases=Integer.parseInt(sc.nextLine());		
		
		
		 pw = new PrintWriter(new FileWriter("output.txt"));

		
		for(int i=0; i<numberOfCases; i++){
			readData(sc);

			pw.println("Case #"+ (i+1) +":");
			solve();
		}

		sc.close();
		pw.close();
	}


	private void solve() throws IOException {
		for (int i = 0; i < r; i++) {
			ArrayList<Long> temp=products.get(i);
			ArrayList<ArrayList<Integer>> allPrimes=new ArrayList<>();
			
			boolean solved=false;
			
			for (int j = 0; j < temp.size(); j++) {
				ArrayList<Integer> primes=primeFactors(temp.get(j));
		
				
				//Found Solution
				if (primes.size()==n) {
					for (int k = 0; k < n; k++) {
						pw.print(primes.get(k));
					}
					solved=true;
					break;
				}else{
					if (primes.size()>0) {
						allPrimes.add(primes);	
					}
				}
			}	
			
			if (!solved) {
				if (allPrimes.size()>0) {
					//Choose using Primes
					choosePrimes(allPrimes);
				}else{
					//Guess
					for (int j = 0; j < n; j++) {
						pw.print(2);
					}
				}	
			}
			
			pw.println();
		}
	}
	
	
	private void choosePrimes(ArrayList<ArrayList<Integer>> allPrimes) throws IOException{
		
		for (ArrayList<Integer> prime : allPrimes) {
			ArrayList<ArrayList<Integer>> temp= new ArrayList<ArrayList<Integer>>();
			temp.add(prime);
			
			ArrayList<ArrayList<Integer>> permutations=findPermutations(allPrimes, temp, prime.size());
			if (permutations!=null) {
				for (ArrayList<Integer> arrayList : permutations) {
					for (Integer integer : arrayList) {
						pw.print(integer);
					}
				}
				
				return;
			}
		}
		
		for (int j = 0; j < n; j++) {
			pw.print(2);
		}
		
	}
	
	
	private ArrayList<ArrayList<Integer>> findPermutations(ArrayList<ArrayList<Integer>> allPrime, ArrayList<ArrayList<Integer>> permutation, int size){
		
		
		for (ArrayList<Integer> prime : allPrime) {
			
			if (!permutation.contains(prime)) {
				if (prime.size()+size < n) {
					permutation.add(prime);
					
					ArrayList<ArrayList<Integer>> a=findPermutations(allPrime, permutation, size + prime.size());
					
					if (a==null) {
						permutation.remove(prime);
					}else{
						return a;
					}
					
				}else if(prime.size()+size == n){
					
					permutation.add(prime);
					return permutation;
				
				}else{
					return null;
				}
			}
			
		}
		
		
		return null;
	}
	
	
	private ArrayList<Integer> primeFactors(long number){
		
		ArrayList<Integer> primeFactor= new ArrayList<Integer>();
		
		if (number==1) {
			return primeFactor;
		}
		
		for (int i = m; i >= 2; i--) {
			if ((number%i==0)) {
				primeFactor.add(i);
				number/=i;
				i=m+1;
			}
		}
		
		
		return primeFactor;
	}
	
	
	private void readData(Scanner sc){

		products=new ArrayList<ArrayList<Long>>();
		
		StringTokenizer token=new StringTokenizer(sc.nextLine());
		r=Integer.parseInt(token.nextToken());
		n=Integer.parseInt(token.nextToken());
		m=Integer.parseInt(token.nextToken());
		k=Integer.parseInt(token.nextToken());
		
		for (int i = 0; i < r; i++) {
			token=new StringTokenizer(sc.nextLine());
			ArrayList<Long> temp=new ArrayList<Long>();
			
			for (int j = 0; j < k; j++) {
				temp.add(Long.parseLong(token.nextToken()));
			}
			
			products.add(temp);
		}
	
	}

	public static void main(String[] args) {
		try {
			new GoodLuck();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}