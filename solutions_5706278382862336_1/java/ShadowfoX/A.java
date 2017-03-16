import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Arrays;


public class A {

	private static BufferedReader br;

	private static int numberOfTestCases;
	
	private static PrintWriter writer;	
	
	public static void readStringFile(String fileName) throws IOException{   	    
    	ClassLoader classLoader = A.class.getClassLoader();
        File classpathRoot = new File(classLoader.getResource("").getPath());
        String fileLocation = classpathRoot.getPath();        
        boolean found = false;
		try {
			br = new BufferedReader(new FileReader(fileLocation + "\\" + fileName));
			found = true;
		} catch (FileNotFoundException e) {
			try {
				br = new BufferedReader(new FileReader(fileLocation.substring(0, fileLocation.length() - 4) + "\\src\\" + fileName));
				found = true;
			}catch(FileNotFoundException e1){
				e1.printStackTrace();
			}
			if(!found)
				e.printStackTrace();
		}
    }

	public static void main(String[] args) throws IOException {		
		if(args.length != 0 && args[0] != null){
			readStringFile(args[0]);	
    	}else{
    		readStringFile("A-large.in");
    	}    
    	
		try {
			writer = new PrintWriter("Output.txt", "UTF-8");
		} catch (FileNotFoundException | UnsupportedEncodingException e) {			
			e.printStackTrace();
		}    		
		numberOfTestCases = Integer.valueOf(br.readLine());		
		int testCaseNumber = 1;
		while(testCaseNumber <= numberOfTestCases){
			findNearestPureAncestor(testCaseNumber);
			testCaseNumber++;
		}
		writer.close();
	}

	private static void findNearestPureAncestor(int testCaseNumber) throws IOException {
		// TODO Auto-generated method stub
		String x = br.readLine();
		String[] xArray = x.split("/");
		Long N = Long.valueOf(xArray[0]);
		Long D = Long.valueOf(xArray[1]);
		Long gcd = findGCD(N, D);
		N = N/gcd;
		D = D/gcd;
		System.out.println("Case #" + testCaseNumber + ": " +N+"/"+D);
		int count = 0;
		System.out.println((double)D/N);
		while((double)D/N > 2){
			count++;
			if(D%2 != 0){
				System.out.println("Case #" + testCaseNumber + ": impossible");
				writer.println("Case #" + testCaseNumber + ": impossible" );
				return;
			}
			D = D/2;
		}
		boolean possible = false;
		if(D%2 != 0){
			System.out.println("Case #" + testCaseNumber + ": impossible");
			writer.println("Case #" + testCaseNumber + ": impossible" );
			return;
		}else{
			while(true){
				if(D == 2 && N == 1){
					possible = true;
					break;
				}
				if(D%2 != 0){
					possible = false;
					break;
				}
				D = D/2;
				if(N > D){
					N = N-D;
				}
			}
		}
		count++;
		if(possible){
			System.out.println("Case #" + testCaseNumber + ": " + count );
			writer.println("Case #" + testCaseNumber + ": " + count );	
		}else{
			System.out.println("Case #" + testCaseNumber + ": impossible");
			writer.println("Case #" + testCaseNumber + ": impossible" );
		}
	}


	private static Long findGCD(Long number1, Long number2) {
        //base case
        if(number2 == 0){
            return number1;
        }
        return findGCD(number2, number1%number2);
    }

}

