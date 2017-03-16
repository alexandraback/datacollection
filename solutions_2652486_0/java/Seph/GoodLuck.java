import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Random;
import java.util.Scanner;


public class GoodLuck {

	public static void main(String args[]) throws Exception {
		File file = new File("C:\\Users\\Seph\\Dropbox\\Google Code Jam\\input.txt");
		File out = new File("C:\\Users\\Seph\\Dropbox\\Google Code Jam\\out.txt");
		
		Scanner s = new Scanner(System.in);
		try {
			s = new Scanner(file);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		String output = "";
		
		int numCases = s.nextInt();
		for(int i=1; i<=numCases; i++) {
			output+="Case #"+i+":\n";
			int numSets = s.nextInt();
			int numDigits = s.nextInt();
			
			int maxDigit = s.nextInt();
			int numProducts = s.nextInt();
			
			for(int j=0; j<numSets; j++) {
				ArrayList<Integer> products = new ArrayList<Integer>();
				for(int k=0; k<numProducts; k++) {
					products.add(s.nextInt());
				}
				
				output += GetDigits(products,maxDigit,numDigits);
				if(j!=numSets) {
					output+="\n";
				}
				
			}
			
			
			if(i!=numCases)
				output+="\n";
		}
		
		FileWriter fw;
		try {
			fw = new FileWriter(out);
			fw.write(output);
			fw.close();
		} catch (IOException e) {
			e.printStackTrace();
		}		
	}
	
	
	
	public static String GetDigits(ArrayList<Integer> products, int maxDigit, int numDigits) {
		String result = "";
		while(result.length()<numDigits) {
			HashMap<Integer,Integer> divisors = new HashMap<Integer,Integer>();
			for(int divisor = 2; divisor<=maxDigit; divisor++) {
				divisors.put(divisor, 0);
			}
			for(Integer product : products) {
				if(product!=1) {
					for(int divisor = 2; divisor<=maxDigit; divisor++) {
						if(product % divisor == 0)
							divisors.put(divisor, divisors.get(divisor)+1);
					}
				}
			}
			
			
			int bestDivisor = 0;
			int bestDivisorNumOccurences = 0;
			for(int divisor = 2; divisor<=maxDigit; divisor++) {
				int numOccurences = divisors.get(divisor);
				if(numOccurences > bestDivisorNumOccurences) {
					bestDivisor = divisor;
					bestDivisorNumOccurences = numOccurences;
				}
			}
			
			for(int i=0; i<numDigits; i++) {
				result += bestDivisor;
			}
			
			/*
			if(bestDivisor != 0){
				result += bestDivisor;
			
				boolean stillReducing = true;
				while(stillReducing) {
					ArrayList<Integer> indexesOfDivisible = new ArrayList<Integer>();
					for(int i=0; i<products.size(); i++) {
						if(products.get(i)%bestDivisor==0)
						{
							int newProduct = products.get(i)/bestDivisor;
							products.set(i, newProduct);
						}
						//if(products.get(i)%bestDivisor ==0)
							//indexesOfDivisible.add(i);
					}
					//Random rng = new Random();
					//int reductionIndex = rng.nextInt(indexesOfDivisible.size());
					
					//int newProduct = products.get(reductionIndex)/bestDivisor;
					//products.set(reductionIndex, newProduct);
					stillReducing = false;
				}
				
				
			}
			else{
				if(result.equals("")){
					Random rng = new Random();
					result += 2+rng.nextInt(maxDigit-1);
				}
				else{
					while(result.length()<numDigits){
						Random rng = new Random();
						int index = rng.nextInt(result.length());
						result += (result.charAt(index));
					}
				}
			}*/
		}
		return result;
	}
	
}
