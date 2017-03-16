import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.Struct;
import java.util.Arrays;
import java.util.HashMap;

import javax.swing.text.html.MinimalHTMLWriter;


public class P1 {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader bReader  = new BufferedReader(new InputStreamReader(System.in));
		String number = bReader.readLine();
		int num = Integer.parseInt(number);
		for (int i = 0; i < num; i++) {		
			
			StringBuilder  builder = new StringBuilder();
			builder.append("Case #"+(i+1)+": ");
			
			int n = Integer.parseInt(bReader.readLine());
			int[][] graph = new int[n][n];
			for (int j = 0; j < n; j++) {
				String[] nStrings = bReader.readLine().split(" ");
				for (int k = 1; k < nStrings.length; k++) {
					graph[j][Integer.parseInt(nStrings[k])-1]=1;
				}
			}
			boolean found = false;
			for (int j = 0; j < n; j++) {
				for (int j2 = 0; j2 < n; j2++) {
					for (int k = 0; k < n; k++) {
						graph[j2][k]+=graph[j2][j]*graph[j][k];
						if(graph[j2][k]>1)
						{
							found = true;
							break;
						}
					}
					if(found)
						break;
					
				}
				if(found)
					break;
			}
			if(found)
			{
				builder.append("Yes");
			}
			else {
				builder.append("No");
			}
			System.out.println(builder.toString());
				}
				
			}

	}

