package magictrick;

import java.util.Scanner;

public class Omino {
	public static void main(String[] args){
	Scanner in = new Scanner(System.in);
	int T = in.nextInt();

		for (int i = 0;i<T ;i++){
			
			double x = in.nextInt();
			double r = in.nextInt();
			double c = in.nextInt();
			
			int bummed = 0;
			
			//tnay 1
			if (x<r+1 || x<c+1)
				bummed++;
			
			
			//tnay 2

			double b = (r*c/x);

			if (b%1 == 0)
				bummed++;
			
			
			//tnay 3
			double e = ((x+1)/2)-((x+1)/2)%1;
			if (e <= r && e <= c)
				bummed++;
			
			
			//tnay 4
			if (x<7)
				bummed++;
			
			//tnay 5
			if (x==4 && (r==2 || c==2))
				bummed--;
			
			
			String ans;
			
			if (bummed == 4)
				ans = "GABRIEL";
			else
				ans = "RICHARD";
			
			
			
			//ArrayList am = new ArrayList();
			//System.out.format("Case #%d: %f\n",i+1 , time);
			//check if arrays are equal: Arrays.equals(ar, arr)
			System.out.println("Case #" + (i+1) + ": " + ans);
		}	
	}
}
