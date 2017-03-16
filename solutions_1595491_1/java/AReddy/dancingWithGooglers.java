
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;



public class DancingWithGooglers{
	public static void main(String[] args) throws IOException{
		String testCases;
		//BufferedReader brTestCases = new BufferedReader(new InputStreamReader(System.in));
		File inFile = new File("C:/Users/AbhilashR/Downloads/B-large.in" ); 
		Scanner sc = new Scanner(inFile);
		testCases = sc.nextLine();//(String)brTestCases.readLine();
		Integer noOfTestCases = null;
		try{
			noOfTestCases = Integer.parseInt(testCases);
		}catch (NumberFormatException e){
			System.out.println("The entered value is not a Number");
		}
		ArrayList<String> inputData = new ArrayList<String>();
		for(int i =0;i<noOfTestCases;i++){
			//for line by line input
			//brTestCases = new BufferedReader(new InputStreamReader(System.in));
			testCases = sc.nextLine();//(String)brTestCases.readLine();
			inputData.add(testCases);
		}
		ArrayList<Object[]> inputDataObj = new ArrayList<Object[]>();
		for(int i =0;i<inputData.size();i++){
			inputDataObj.add(inputData.get(i).split(" "));
		}
		for(int i =0;i < inputDataObj.size();i++){
			Object[] dataObj = inputDataObj.get(i);
			int numberOfEmployees = Integer.parseInt((String)dataObj[0]);
			int numberOfSurprisingTriplets = Integer.parseInt((String)dataObj[1]);
			int minimumBestResult = Integer.parseInt((String)dataObj[2]);
			int numberOfPeopleWithMinimumBest = 0;
			List<Integer> scoreList = new ArrayList<Integer>();
			for(int j = 0; j< numberOfEmployees; j++){
				scoreList.add(Integer.parseInt((String)dataObj[j+3]));
			}
			Collections.sort(scoreList);
			for(int j =0;j<scoreList.size();j++){
				int totScore = scoreList.get(j);
				if((totScore%3)>0){
					if(totScore%3 == 1){
						if(totScore/3 >= minimumBestResult){
							numberOfPeopleWithMinimumBest++;
						}else if(1+totScore/3 >= minimumBestResult){
							numberOfPeopleWithMinimumBest++;
						}
					}else if(totScore%3 == 2){
						if(totScore/3 >= minimumBestResult){
							numberOfPeopleWithMinimumBest++;
						}else if(1+totScore/3 >= minimumBestResult){
							numberOfPeopleWithMinimumBest++;
						}else if(2+totScore/3 >= minimumBestResult && numberOfSurprisingTriplets >0){
							numberOfPeopleWithMinimumBest++;
							numberOfSurprisingTriplets--;
						}
					}
				}else{
					if(totScore/3 >= minimumBestResult){
						numberOfPeopleWithMinimumBest++;
					}else if(1+totScore/3 >= minimumBestResult && numberOfSurprisingTriplets >0 && totScore !=0){
						numberOfPeopleWithMinimumBest++;
						numberOfSurprisingTriplets--;
					}
				}
			}
			System.out.println("Case #"+(i+1)+": "+numberOfPeopleWithMinimumBest);
		}
	}
	
}