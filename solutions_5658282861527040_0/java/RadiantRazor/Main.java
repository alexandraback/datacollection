package ramanvesh.codejam.newLotteryGame;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;

public class Main {
	
	public static void main(String[] args) {
		String path = System.getProperty("user.dir");
		try{
			@SuppressWarnings("resource")
			BufferedReader fileReader = new BufferedReader(new FileReader(new File(path + "/input" )));
			int noOfCases = Integer.parseInt(fileReader.readLine().trim());
			for(int caseNum =1; caseNum<=noOfCases; caseNum++){
				String[] numbers = fileReader.readLine().trim().split(" ");
				int A = Integer.parseInt(numbers[0]);
				int B = Integer.parseInt(numbers[1]);
				int K = Integer.parseInt(numbers[2]);
				String aString = make32Length(Integer.toBinaryString(A));
				String bString = make32Length(Integer.toBinaryString(B));
				String kString = make32Length(Integer.toBinaryString(K));
				boolean[] AArray = new boolean[32];
				int numPairs = 0;
				for(int i = 0; i< A; i++){
					for (int j = 0; j < B; j++) {
						int and = i&j;
						if( 0<=and && and < K){
							numPairs++;
						}
					}
				}
				System.out.println("Case #"+caseNum+": "+numPairs);
				
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private static String make32Length(String binaryString) {
		int diff = 32 - binaryString.length();
		for(int i=0;i<diff;i++){
			binaryString = "0"+binaryString;
		}
		return binaryString;
	}
}