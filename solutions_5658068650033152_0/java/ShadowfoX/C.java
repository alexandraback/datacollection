import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Arrays;


public class C {

	private static BufferedReader br;

	private static int numberOfTestCases;
	
	private static PrintWriter writer;	
	
	public static void readStringFile(String fileName) throws IOException{   	    
    	ClassLoader classLoader = C.class.getClassLoader();
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
    		readStringFile("C-small-attempt8.in");
    	}    
    	
		try {
			writer = new PrintWriter("Output.txt", "UTF-8");
		} catch (FileNotFoundException | UnsupportedEncodingException e) {			
			e.printStackTrace();
		}    		
		numberOfTestCases = Integer.valueOf(br.readLine());		
		int testCaseNumber = 1;
		while(testCaseNumber <= numberOfTestCases){
			findMinimumNumberOfStones(testCaseNumber);
			testCaseNumber++;
		}
		writer.close();
	}

	private static void findMinimumNumberOfStones(int testCaseNumber) throws IOException {
		// TODO Auto-generated method stub
		String x = br.readLine();
		String[] xArray = x.split(" ");
		int N = Integer.valueOf(xArray[0]);
		int M = Integer.valueOf(xArray[1]);
		int K = Integer.valueOf(xArray[2]);
		
		if(N*M < K){
			System.out.println("Case #" + testCaseNumber + ": impossible");
			writer.println("Case #" + testCaseNumber + ": impossible" );
			return;
		}
		if(K == 0){
			System.out.println("Case #" + testCaseNumber + ": 0");
			writer.println("Case #" + testCaseNumber + ": 0" );
			return;
		}
		if(K<=4){
			System.out.println("Case #" + testCaseNumber + ": " + K);
			writer.println("Case #" + testCaseNumber + ": " + K );
			return;
		}
		if(M==1 || N==1){
			System.out.println("Case #" + testCaseNumber + ": " + K);
			writer.println("Case #" + testCaseNumber + ": " + K );
			return;
		}
		if(M==2 || N==2){
			System.out.println("Case #" + testCaseNumber + ": " + K);
			writer.println("Case #" + testCaseNumber + ": " + K );
			return;
		}
		int temp = (int) Math.sqrt(K);
		
		if(temp*temp == K){
			temp = temp -1;
		}
		if(temp + 2 > M)
			temp = M-2;
		int p = 1;
		int q = 1;
		int overhead = 0;
		int count = p*2 + q*2 + p*q;
		while(count < K){
			if(K-count <= 4){
				if(p+2 == M && q+2 == N){
					if(K-count == 1)
						overhead = 2;
					if(K-count == 2)
						overhead = 1;
					if(K-count == 3)
						overhead = 3;
					if(K-count == 4)
						overhead = 4;	
				}						
			}
			if(q + 2 < N){				
				q++;
				
			}
			else if (p +2 < M)
				p++;
			else{
				overhead = K - count;
			}
			
			count = p*2 + q*2 + p*q + overhead;				
		}
		System.out.println("Case #" + testCaseNumber + ": " + (p*2 + q*2 + overhead));
		writer.println("Case #" + testCaseNumber + ": " + (p*2 + q*2 + overhead) );
		
	}

	

}

