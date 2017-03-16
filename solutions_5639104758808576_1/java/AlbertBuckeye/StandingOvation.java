package Qualification;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class StandingOvation {
	public static void main(String[] args) throws NumberFormatException, IOException {
		File inFile = new File("input.txt");
		File outFile = new File("output.txt");
		BufferedReader reader = new BufferedReader(new FileReader(inFile));
		PrintWriter pw = new PrintWriter(outFile);
		int numTest = Integer.parseInt(reader.readLine().trim());
		for(int i=1; i<=numTest; i++){
			String strSplit[] = reader.readLine().trim().split(" ");
			int max = Integer.parseInt(strSplit[0]);
			char ch[] = strSplit[1].toCharArray();
			int arr[] = new int[ch.length];
			for(int j=0; j<ch.length; j++){
				arr[j] = ch[j]-'0';
			}
			pw.println("Case #"+i+": "+ getInvitation(max, arr));
			System.out.println("Case #"+i+": "+ getInvitation(max, arr));
		}
		pw.flush();
		pw.close();
		reader.close();
	}
	public static int getInvitation(int max, int arr[]){
		int invitation = 0;
		int current = arr[0];
		for(int i=1; i<=max; i++){//need i audience to stand up. 
			if(arr[i] != 0){
				if(current < i){
					invitation += i-current;
					current = i+arr[i];
//					current += (i-current) + arr[i];
				}else{
					current += arr[i];
				}
			}
		}
		return invitation;
	}
}
