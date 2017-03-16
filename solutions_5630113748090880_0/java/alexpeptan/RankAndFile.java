package round1A_Problem2;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class RankAndFile {

	public static void main(String[] args) throws NumberFormatException, IOException {
		PrintWriter writer = new PrintWriter("/Users/alexpeptan/Desktop/Eclipse Workspace/Google Code Jam 2016/src/round1A_Problem2/1A2.out", "UTF-8");
		Scanner scanner = new Scanner(new File("/Users/alexpeptan/Desktop/Eclipse Workspace/Google Code Jam 2016/src/round1A_Problem2/1A2.in"));
		
		int t = scanner.nextInt();
		
		for(int k=0; k<t; k++){
			int n = scanner.nextInt();
			int[] v = new int[2501];
			for(int i=0; i<=2500; i++){
				v[i] = 0;
			}
			for(int i=0; i<n*(2*n - 1); i++){
				v[scanner.nextInt()]++;
			}
			writer.print("Case #" + (k+1) + ":");
			for(int i=1; i<=2500; i++){
				if(v[i] % 2 == 1){
					writer.print(" " + i);
				}
			}
			writer.println();
		}
		writer.close();
	}

}
