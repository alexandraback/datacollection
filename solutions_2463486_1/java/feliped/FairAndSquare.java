import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

public class FairAndSquare{
	
	int upper;
	private boolean[] palindromes;
	private Set<Integer> palindromeRoots;
	
	public FairAndSquare(){
		this.upper = 10000000;
		this.palindromes = new boolean[upper +1];
		this.palindromeRoots = new HashSet<Integer>();
		this.findPalindromes();
		this.findSquares();
	}//FairAndSquare.FairAndSquare()
	
	
	public int countInRange(long A, long B){
		int a = Integer.valueOf((int) Math.ceil(Math.sqrt(A)));
		int b = Integer.valueOf((int) Math.floor(Math.sqrt(B)));
		
		int count = 0;
		for(int i = a; i <= b; i++){
			if(palindromeRoots.contains(i)){
				count++;
			}
		}
		
		
		return count;
	}//FairAndSquare.countInRange()
	
	private void findSquares(){
		for(int i = 0; i < upper; i++){
			if(palindromes[i]){
				if(isPalindrome(((long) i)*((long) i))){
					this.palindromeRoots.add(i);
				}
			}
		}
	}//FairAndSquare.findSquares
	
	private void findPalindromes(){
		for(int i = 1; i < 10; i++){
			this.palindromes[i] = true;
		}
		
		for(int i = 10; i <= upper; i++){
			this.palindromes[i] = this.isPalindrome((long) i);
		}
	}//FairAndSquare.findPalindromes
	
	private boolean isPalindrome(long number){
		String n = "" + number;
		int l = n.length();
		for(int i = 0; i <= l / 2; i++){
			if(n.charAt(i) != n.charAt(l-i-1)){
				return false;
			}
		}
		return true;
	}//FairAndSquare.isPalindrome()
	
	public static void main(String[] args) throws IOException{
		// IO preliminaries
		String filename = args[0];
		File file = new File(filename + ".in");
		BufferedReader reader = new BufferedReader(new FileReader(file));
		BufferedWriter writer = new BufferedWriter(new FileWriter(filename + ".out"));
		
		FairAndSquare fs = new FairAndSquare();
		
		// Actually reading the input and solving
		int numCases = Integer.parseInt(reader.readLine());
		for (int i = 1; i <= numCases; i++){
			int caseNumber = i;
			String[] size = reader.readLine().split(" ");
			long A = Long.valueOf(size[0]);
			long B = Long.valueOf(size[1]);
			
			writer.write("Case #" + caseNumber + ": " + fs.countInRange(A, B));
			writer.newLine();
		}
		reader.close();
		writer.close();
	}//FairAndSquare.main()
}//FairAndSquare
