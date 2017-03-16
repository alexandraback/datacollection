import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;


public class B {
	public static void main(String[] args) {
		new B().run();
	}

	private void run() {
		try {
			Scanner s = new Scanner(new File("A.in"));
			int n = s.nextInt();
			for (int i = 0; i < n; i++) {
				int m = s.nextInt();
				int []a = new int[m];
				int []b = new int[m];
				boolean []ad = new boolean[m];
				boolean []bd = new boolean[m];
				int totalStars = 0;
 				for (int j = 0; j < a.length; j++) {
					a[j] = s.nextInt();
					b[j] = s.nextInt();
				}
 				int trials = 0;
 				while(totalStars != 2*a.length){
 					trials++;
 					boolean found = false;
	 				for (int j = 0; j < bd.length; j++) {
						if(!bd[j] && b[j]<=totalStars){
//							System.out.println("b: "+j);
							found = true;
							if(!ad[j]){
								totalStars+=2;
							}else{
								totalStars+=1;
							}
							bd[j] = true;
							ad[j] = true;
							break;
						}
					}
	 				if(found) continue;
	 				int maxB = -1;
 					int minIndex = -1;
	 				for (int j = 0; j < bd.length; j++) {
	 					if(!ad[j] && a[j]<=totalStars && b[j] > maxB){
	 						maxB = b[j];
	 						minIndex = j;
	 						found = true;
	 					}
					}
	 				if(found){
	 					ad[minIndex] = true;
	 					totalStars+=1;
	 				}
	 				if(!found){
	 					System.out.println("Case #"+(i+1)+": Too Bad");
	 					break;
	 				}
 				}
 				if(totalStars == 2*b.length)
					System.out.println("Case #"+(i+1)+": "+trials);
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
