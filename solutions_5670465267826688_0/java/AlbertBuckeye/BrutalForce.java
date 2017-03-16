package Qualification;

import java.io.IOException;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;

public class BrutalForce {
	public static void main(String[] args) throws NumberFormatException, IOException {
		File inFile = new File("input.txt");
		File outFile = new File("output.txt");
		BufferedReader reader = new BufferedReader(new FileReader(inFile));
		PrintWriter pw = new PrintWriter(outFile);
		int numTest = Integer.parseInt(reader.readLine().trim());
//		//ijk = 0 1 2
		char table[][] = new char[3][3];
		table[0][0] = table[1][1]= table[2][2] = '#';//-1
		table[0][1] = 'k'; table[1][0] = 'K';//-k
		table[1][2] = 'i'; table[2][1] = 'I';//-I
		table[2][0] = 'j'; table[0][2] = 'J';//-J
		for(int i=1; i<=numTest; i++){
			int repeat = Integer.parseInt(reader.readLine().split(" ")[1]);
			char unit[] = reader.readLine().trim().toCharArray();
			pw.println("Case #"+i+": "+getResult(unit, repeat, table));
		}
		pw.flush();
		pw.close();
		reader.close();
		System.out.println(getResult("jkkiij".toCharArray(), 9, table));
	}
	public static String getResult(char unit[], int X, char[][] table){
		int repeat = X;
		char arr[] = new char[unit.length*repeat];
		for(int i=0; i<arr.length; i++)
			arr[i] = unit[i%unit.length];
		char dp[] = new char[arr.length];
		boolean sign[] = new boolean[arr.length];//negative = false;
		dp[0] = arr[0];//should be i, j, k or #
		sign[0] = true;
//		ArrayList<Integer> idx4I = new ArrayList<>();
		int idx4I = -1;
		if(arr[0]=='i')
			idx4I = 0;
		for(int i=1; i<arr.length; i++){
			if(dp[i-1] == '#'){//value is 1.
				dp[i] = arr[i];
				sign[i] = sign[i-1]; 
			}
			else{
				char tmp = table[dp[i-1]-'i'][arr[i]-'i'];
				if(tmp == '#'){
					sign[i] = sign[i-1] ^ true;//flip the sign
					dp[i] = '#';
				}
				else if(tmp>='I' && tmp<='K'){
					sign[i] = sign[i-1] ^ true;//flip the sign
					dp[i] = Character.toLowerCase(tmp);
				}
				else{
					sign[i] = sign[i-1];
					dp[i] = tmp;
				}
			}
			if(dp[i]=='i' && idx4I==-1 && sign[i]==true){// && sign[i]
				idx4I = i;}
		}
		char unitProd = dp[unit.length-1];
		boolean unitSign = sign[unit.length-1];
		System.out.println(unitProd + " " + unitSign);
		if(dp[arr.length-1] != '#' || sign[arr.length-1] != false){
			return "NO";
		}
//		if(unitProd == '#'){
//			if(unitSign == true)
//				return "NO";
//			if(X%2 == 0)//even
//				return "NO";
//		}
//		else{//if(unitProd >= 'i' && unitProd <= 'k')
//			if(X%2 != 0)//odd
//				return "NO";
//			//sign does not matter in the following
//			if((X/2) % 2 == 0)
//				return "NO";
//		}
		
		int idx4K = -1;
		int length = arr.length;
		if(arr[length-1]=='k')
			idx4K = length-1;
		dp = new char[arr.length];
		sign = new boolean[arr.length];
		dp[length-1] = arr[length-1];
		for(int i=length-2; i>=0; i--){
			if(dp[i+1] == '#'){//value is 1.
				dp[i] = arr[i];
				sign[i] = sign[i+1]; 
			}
			else{
				char tmp = table[arr[i]-'i'][dp[i+1]-'i'];
				if(tmp == '#'){
					sign[i] = sign[i+1] ^ true;//flip the sign
					dp[i] = '#';
				}
				else if(tmp>='I' && tmp<='K'){
					sign[i] = sign[i+1] ^ true;//flip the sign
					dp[i] = Character.toLowerCase(tmp);
				}
				else{
					sign[i] = sign[i+1];
					dp[i] = tmp;
				}
			}
			if(dp[i]=='k'&& idx4K == -1 && sign[i]==true){//&& sign[i]
				idx4K = i;}
		}
		if(idx4I < idx4K)
			return "YES";
		else return "NO";
	}
}