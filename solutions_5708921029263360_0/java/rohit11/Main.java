package FashionPolice;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(new BufferedReader(new InputStreamReader(
				System.in)));
		int testcases = scanner.nextInt();
		for (int testcase = 1; testcase <= testcases; testcase++) {
			int[] array = new int[3];
			for(int i = 0; i < 3; i++){
				array[i] = scanner.nextInt();
			}
			int maxAllowed = scanner.nextInt();
			
			int small, mid, big;
			if(array[0] >= array[1] && array[0] >= array[2]){
				big = 0;
				if(array[1] >= array[2]){
					mid = 1;
					small = 2;
				}else{
					mid = 2;
					small = 1;
				}
			}else if(array[1] >= array[0] && array[1] >= array[2]){
				big = 1;
				if(array[0] >= array[2]){
					mid = 0;
					small = 2;
				}else{
					mid = 2;
					small = 0;
				}
			}else{
				big = 2;
				if(array[0] >= array[1]){
					mid = 0;
					small = 1;
				}else{
					mid = 1;
					small = 0;
				}
			}
			
			int midCounter = 1;
			int bigCounter = 1;
			int timesCounter = 0;
			int midUsedCounter = 0;
			int totals = 0;
			List<String> midAnswersList = new ArrayList<String>();
			while(true){
				String answer = "";
				answer += midCounter + "";
				answer += bigCounter + "";
				//System.out.println(answer);
				midAnswersList.add(answer);
				midUsedCounter++;
				bigCounter++;
				totals++;
				if(totals == array[big] * array[mid]){
					break;
				}
				if(bigCounter > array[big]){
					bigCounter = 1;
					
					timesCounter++;
					if(timesCounter > maxAllowed){
						break;
					}
					
					/*midCounter++;
					if(midCounter > array[mid]){
						break;
					}

					midUsedCounter = 0;*/
					
					if(midUsedCounter >= array[big]){
						midCounter++;
						if(midCounter > array[mid]){
							break;
						}

						midUsedCounter = 0;
					}
					
				}
				if(midUsedCounter >= maxAllowed){
					midCounter++;
					if(midCounter > array[mid]){
						break;
					}

					midUsedCounter = 0;
					
				}
			}
			
			List<String> answersList = new ArrayList<String>();
			
				if(mid == 0 && big == 1){
					for(int i = 1; i <= maxAllowed && i <= array[small]; i++){
						for(int j = 0; j < midAnswersList.size(); j++){
							String midAnswer = midAnswersList.get(j);
							answersList.add(midAnswer + i);
						}
					}
				}else if(mid == 0 && big == 2){
					for(int i = 1; i <= maxAllowed && i <= array[small]; i++){
						for(int j = 0; j < midAnswersList.size(); j++){
							String midAnswer = midAnswersList.get(j);
							answersList.add(String.valueOf(midAnswer.charAt(0)) + i + String.valueOf(midAnswer.charAt(1)));
						}
					}
				}else if(mid == 1 && big == 2){
					for(int i = 1; i <= maxAllowed && i <= array[small]; i++){
						for(int j = 0; j < midAnswersList.size(); j++){
							String midAnswer = midAnswersList.get(j);
							answersList.add(String.valueOf(i + midAnswer));
						}
					}
				}else if(mid == 1 && big == 0){
					for(int i = 1; i <= maxAllowed && i <= array[small]; i++){
						for(int j = 0; j < midAnswersList.size(); j++){
							String midAnswer = midAnswersList.get(j);
							midAnswer = new StringBuilder(midAnswer).reverse().toString();
							answersList.add(midAnswer += i);
						}
					}
				}else if(mid == 2 && big == 0){
					for(int i = 1; i <= maxAllowed && i <= array[small]; i++){
						for(int j = 0; j < midAnswersList.size(); j++){
							String midAnswer = midAnswersList.get(j);
							String temp = new StringBuilder(midAnswer).reverse().toString();
							answersList.add(String.valueOf(temp.charAt(0)) + i + String.valueOf(temp.charAt(1)));
						}
					}
				}else if(mid == 2 && big == 1){
					for(int i = 1; i <= maxAllowed && i <= array[small]; i++){
						for(int j = 0; j < midAnswersList.size(); j++){
							String midAnswer = midAnswersList.get(j);
							midAnswer = new StringBuilder(midAnswer).reverse().toString();
							answersList.add(String.valueOf(i + midAnswer));
						}
					}
				}
			
			
			System.out.println("Case #" + testcase + ": " + answersList.size());
			for(int i = 0 ; i < answersList.size(); i++){
				String str = answersList.get(i);
				System.out.println(str.charAt(0) + " " + str.charAt(1) + " " + str.charAt(2));
			}
		}
		scanner.close();
	}
}
