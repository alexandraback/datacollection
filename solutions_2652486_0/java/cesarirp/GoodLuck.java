import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;


public class GoodLuck {

	private int r;
	private int m;
	private int n;
	private int k;
	
	private ArrayList<ArrayList<Integer>> products;

	public GoodLuck() throws FileNotFoundException {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		int numberOfCases=Integer.parseInt(sc.nextLine());		
		for(int i=0; i<numberOfCases; i++){
			readData(sc);

			System.out.println("Case #"+ (i+1) +":");
			solve();
		}

		sc.close();
	}


	private void solve() {
		for (int i = 0; i < r; i++) {
			ArrayList<Integer> temp=products.get(i);
			ArrayList<ArrayList<Integer>> allPrimes=new ArrayList<>();
			
			boolean solved=false;
			
			for (int j = 0; j < temp.size(); j++) {
				ArrayList<Integer> primes=primeFactors(temp.get(j));
				
				//Found Solution
				if (primes.size()==n) {
					for (int k = 0; k < n; k++) {
						System.out.print(primes.get(k));
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
					System.out.print(222);
				}	
			}
			
			System.out.println();
		}
	}
	
	private void choosePrimes(ArrayList<ArrayList<Integer>> allPrimes){
		System.out.print(222);
	}

	
	private ArrayList<Integer> primeFactors(int number){
		
		ArrayList<Integer> primeFactor= new ArrayList<Integer>();
		
		if (number==1) {
			return primeFactor;
		}
		
		
		for (int i = m; i >= 2; i--) {
			if (number%i==0) {
				primeFactor.add(i);
				number/=i;
				i=m+1;
			}
		}
		
		
		return primeFactor;
	}
	
	
	private void readData(Scanner sc){

		products=new ArrayList<ArrayList<Integer>>();
		
		StringTokenizer token=new StringTokenizer(sc.nextLine());
		r=Integer.parseInt(token.nextToken());
		n=Integer.parseInt(token.nextToken());
		m=Integer.parseInt(token.nextToken());
		k=Integer.parseInt(token.nextToken());
		
		for (int i = 0; i < r; i++) {
			token=new StringTokenizer(sc.nextLine());
			ArrayList<Integer> temp=new ArrayList<Integer>();
			
			for (int j = 0; j < k; j++) {
				temp.add(Integer.parseInt(token.nextToken()));
			}
			
			products.add(temp);
		}
	
	}

	public static void main(String[] args) {
		try {
			new GoodLuck();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
}