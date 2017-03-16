package by.amitrofanov82.google.codeJam.apr_9_2016.task3;

import java.io.File;
import java.io.IOException;
import java.math.BigInteger;
import java.util.LinkedList;
import java.util.List;

import org.apache.commons.io.FileUtils;
import org.apache.commons.io.IOUtils;
import org.apache.commons.math3.primes.Primes;

public class Main {
	private final static String FILES_ENCODING="UTF-8";
	private final static String LINE_ENDING=IOUtils.LINE_SEPARATOR_UNIX;
	private final static boolean DONT_APPEND_OUTPUT=false;
	private final static File INPUT_FILE = new File("./resources/input.txt");
	private final static File OUTPUT_FILE = new File("./resources/output.txt");
	
	
	public static void main(String[] args) throws IOException {
		List<String> inputLines = FileUtils.readLines(INPUT_FILE, FILES_ENCODING); 
		List<String> outputLines = new LinkedList<String>(); 
		resolveTask(inputLines, outputLines);
		FileUtils.writeLines(OUTPUT_FILE, FILES_ENCODING, outputLines, LINE_ENDING, DONT_APPEND_OUTPUT);
	}

	private static void resolveTask(List<String> inputLines, List<String> outputLines) {
		int numOfCases = Integer.parseInt(inputLines.get(0));
		List<String> caseAnswer;
		for (int i =1; i<=numOfCases;i++){
			caseAnswer = resolveCase(inputLines.get(i));
			outputLines.add("Case #" + i + ":");
			outputLines.addAll(caseAnswer);
		}
	}

	private static List<String> resolveCase(String caseInput) {
		int N = Integer.parseInt(caseInput.split(" ")[0]);
		int J = Integer.parseInt(caseInput.split(" ")[1]);
		List<String> jamCoins = new LinkedList<String>();
		int allOptionsNumber = (int) Math.pow(2, N-2);
		for (int i=0; i<allOptionsNumber; i++){
			String currentOption = Integer.toString(i, 2);
			if (currentOption.length()<N-2){
				char[] zeros = new char[N-2-currentOption.length()];
				for (int j=0; j<zeros.length; j++) zeros[j]='0';
				currentOption=new String(zeros) + currentOption;
			}
			List<BigInteger> factors =getJamCoinInfo("1"+currentOption+"1");
			if (factors != null){
				StringBuffer outputLine = new StringBuffer("1"+currentOption+"1 ");
				for (int j=0; j<8; j++){
					outputLine.append(factors.get(j)+ " ");
				}
				outputLine.append(factors.get(8));
				jamCoins.add(outputLine.toString());
				if (jamCoins.size() == J){
					System.out.println("enough");
					return jamCoins;
				}
			}
		}
		return jamCoins;
	}

	private static List<BigInteger>  getJamCoinInfo(String extendedOption) {
		List<BigInteger> factors = new LinkedList<BigInteger>();
		for(int base = 2; base<=10; base++){
			BigInteger value = new BigInteger(extendedOption, base);
			int n=2;
			while(n<15000){
				BigInteger mayBeFactor = BigInteger.valueOf(n);
				if (value.mod(mayBeFactor).equals(BigInteger.ZERO) && !mayBeFactor.equals(value)){
					factors.add(mayBeFactor);
					break;
				}
				n = Primes.nextPrime(n+1);
			}
			if (factors.size() != base-1){
				System.out.println("no factors found for " + extendedOption + ", base="+base + " value=" +value);
				return null;
			}
		}
		if (factors.size() == 9){
			System.out.print("Here it is: " + extendedOption + " ");
			for (int i =0; i< factors.size(); i++){
				System.out.print(factors.get(i) + " ");
			}
			System.out.println();
			return factors;
		}
		return null;
	}
	
	
}
