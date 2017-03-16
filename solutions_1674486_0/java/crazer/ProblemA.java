package round2c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class ProblemA {
	public static void main(String args[]){
		try{
			FileInputStream fileInputStream = new FileInputStream(args[0] + ".in");
			DataInputStream in = new DataInputStream(fileInputStream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			
			FileWriter fstream = new FileWriter(args[0] + ".out");
			BufferedWriter out = new BufferedWriter(fstream);
			
			String[] inputs;
			String strLine;
			
			
			strLine = br.readLine();
			int T = Integer.parseInt(strLine);
			
			for(int t = 1; t <= T; t++){
				int[] M = new int[1001];
				int[] receivers = new int[1001];
				
				int[][] array = new int[1001][1001];
				int[][] initialArray = new int[1001][1001];
				ArrayList<ArrayList<Integer>> inherentsList = new ArrayList<ArrayList<Integer>>();
				ArrayList<Integer> moreThanTwoList = new ArrayList<>();
				
				
				inherentsList.add(new ArrayList<Integer>());
				strLine = br.readLine();
				int N = Integer.parseInt(strLine);
				
				for(int j = 1; j <= N; j++){
					strLine = br.readLine();
					inputs = strLine.split(" ");
					M[j] = Integer.parseInt(inputs[0]);
					
					ArrayList<Integer> sample = new ArrayList<Integer>();
					for(int k = 1; k <= M[j]; k++){
						int className = Integer.parseInt(inputs[k]);
						array[j][className] = 1;
						initialArray[j][className] = 1;
						
						receivers[className]++;
						if(receivers[className] == 2)
							moreThanTwoList.add(className);
						sample.add(className);
					}
					inherentsList.add(j, sample);
				}
				
				/*
				for(int i = 1; i <= N; i++){
					for(int j = 1; j <= N; j++){
						System.out.print("" + array[i][j]);
					}
					System.out.print("\n");
				}
				System.out.print("\n After \n");
				*/
				
				for(int k = 1; k <= N; k++){
					for(int i = 1; i <= N; i++){
						for(int j = 1; j <= N; j++){
							if(array[i][j] == 0){
								if(array[i][k] == 1 && array[k][j] == 1){
									array[i][j] = 1;
								}
							}
						}
					}
				}
				
				/*
				for(int i = 1; i <= N; i++){
					for(int j = 1; j <= N; j++){
						System.out.print("" + array[i][j]);
					}
					System.out.print("\n");
				}
				*/
				
				String result = "";
				int i;
				for(i = 1; i <= N; i++){
					if(M[i] >= 2){
						ArrayList<Integer> list = inherentsList.get(i);
						int j;
						for(j = 0; j < list.size(); j++){
							int k;
							for(k = j + 1; k < list.size(); k++){
								int l;
								for(l = 0; l < moreThanTwoList.size(); l++){
									int elementLeft = list.get(j);
									int elementRight = list.get(k);
									int elementEnd = moreThanTwoList.get(l);
									if(array[elementLeft][elementEnd] == 1 && array[elementRight][elementEnd] == 1){
										result = "Yes";
										break;
									}
									else if(array[elementLeft][elementEnd] == 1 && initialArray[i][elementEnd] == 1){
										result = "Yes";
										break;
									}
									else if(initialArray[i][elementEnd] == 1 && array[elementRight][elementEnd] == 1){
										result = "Yes";
										break;
									}
								}
							}
						}
					}
				}
				if("".equalsIgnoreCase(result)){
					result = "No";
				}
				
							
				System.out.println("Case #" + t + ": " + result);
				out.write("Case #" + t + ": " + result + "\n");
			}
			out.close();
		} catch (Exception e) {
			System.err.println("Error: " + e.getMessage());
		}
	}
}
