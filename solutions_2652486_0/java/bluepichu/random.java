//Program by Matthew Savage
//With help from the TJHSST SCT Grader Example Class

import java.io.*;
import java.util.*;

public class random{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("C-small-1-attempt6.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("random.out")));
		
		br.readLine();
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int testCases = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		pw.println("Case #1:");
		for(int t = 1; t <= testCases; t++){
			System.out.println(t);
			int[] tot = {0, 0, 0};
			int[] max = {0, 0, 0};
			int dLeft = n;
			HashSet<Integer> solved = new HashSet<Integer>();
			st = new StringTokenizer(br.readLine(), " ");
			for(int i = 0; i < n; i++){
				int val = Integer.parseInt(st.nextToken());
				int[] exp = {0, 0, 0};
				
				if(val < 6 && val != 1){
					solved.add(val);
				}
				
				while(val % 2 == 0){
					val /= 2;
					exp[0]++;
				}
				while(val % 3 == 0){
					val /= 3;
					exp[1]++;
				}
				while(val % 5 == 0){
					val /= 5;
					exp[2]++;
				}
				
				tot[0] += exp[0];
				tot[1] += exp[1];
				tot[2] += exp[2];
				
				max[0] = Math.max(max[0], exp[0]);
				max[1] = Math.max(max[1], exp[1]);
				max[2] = Math.max(max[2], exp[2]);
			}
			
			dLeft -= solved.size();
			
			for(int i : solved){
				if(i < 2){
					break;
				}
				
				pw.print(i);
				
				while(i % 2 == 0){
					i /= 2;
					max[0]--;
				}

				
				while(i % 3 == 0){
					i /= 3;
					max[1]--;
				}
				
				while(i % 5 == 0){
					i /= 5;
					max[2]--;
				}
			}
			
			while(max[1] > 0){
				pw.print(3);
				max[1]--;
				dLeft--;
			}
			
			while(max[2] > 0){
				pw.print(5);
				max[2]--;
				dLeft--;
			}
			
			if(dLeft > 0){
				if(dLeft == 1){
					pw.print((int)(Math.pow(2, max[0]) * Math.pow(3, max[1]) * Math.pow(5, max[2])));
				} else { //aww crap
					while(dLeft > 0){
						if(max[0] > 1){
							pw.print(4);
							dLeft--;
						} else if(max[0] == 1){
							pw.print(2);
							dLeft--;
						} else {
							if(Math.random() < .25){
								pw.print(5);
							} else if(Math.random() < .25){
								pw.print(4);
							} else if(Math.random() < .25){
								pw.print(3);
							} else {
								pw.print(2);
							}
							dLeft--;
						}
					}
				}
			}
			
			pw.println();
		}
		
		br.close();
		pw.close();
	}
}