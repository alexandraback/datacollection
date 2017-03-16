package codejam2014.r1b;

import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
	
		long t = Long.parseLong(scn.nextLine());
	
		double P,Q;
		String str;
		String arr[];
		double data = 0.0;
		for(int i = 1; i <= t; i++){
			
			str = scn.nextLine();
			arr = str.split("/");
			
			P = Double.parseDouble(arr[0]);
			Q = Double.parseDouble(arr[1]);
			data = P/Q;
			int anc = -1;
			boolean finished = false;
			
			for(int j = 0; j < 40; j++){
				data = data*2;
				
				if(data >= 1 ){
					
					data = data-1;
					if( anc == -1)
						anc = j + 1;
				}
				if(data == 0){
					finished  = true;
					break;
				}
				
			}
			if(finished)
				System.out.println("Case #"+i+": "+anc);
			else
				System.out.println("Case #"+i+": impossible");
			
		}
	}
}