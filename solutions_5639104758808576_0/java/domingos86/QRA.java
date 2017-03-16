package codejam.CJ2015;

import java.util.Scanner;

public class QRA {

	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int i=1; i<=t; i++){
			int sMax = in.nextInt();
			String readString = in.next();
			int clapping = 0;
			int additional = 0;
			for(int j=0; j<=sMax; j++){
				int numRead = Integer.parseInt(readString.substring(j, j+1));
				if(numRead > 0){
					if(clapping < j){
						additional+= j-clapping;
						clapping = j;
					}
					clapping += numRead;
				}
			}
			
			
			System.out.print("Case #" + i + ": " + additional);
			
			System.out.println();
		}
		
		in.close();
	}
}
