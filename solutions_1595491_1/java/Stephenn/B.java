package info.stephenn.codejam2012.qualify;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class B {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		int cases = sc.nextInt();
		
		for(int caseX=1; caseX <= cases; caseX+=1){
			int nGoogles = sc.nextInt();
			int s = sc.nextInt();
			int p = sc.nextInt();
			List<Integer> gTot = new ArrayList<Integer>();
			for (int i = 0; i < nGoogles; i++){
				gTot.add(sc.nextInt());
			}
			int y = doit(gTot, s,p);
			System.out.println("Case #"+caseX+": "+y);
		}
	}
	
	public static int doit(List<Integer> gTot, int s, int p){
		Collections.sort(gTot);
		
		int y=0;
		
		for (int i=0; i < gTot.size(); i++){
			if (greatestNonSurprising(gTot.get(i)) < p){
				if (s > 0){
					if (greatestSurprising(gTot.get(i)) >= p){
						y +=1;
						s -=1;
					}
				}
			} else {
				y += ((gTot.size()) - (i));
				break;
			}
		}
		
		return y;
	}
	
	public static int greatestSurprising(int gTot){
		int x = gTot / 3;
		if ((gTot %3) == 0 && gTot > 2 ) x +=1;
		if ((gTot % 3) == 1) x+=1;
		else if ((gTot % 3) == 2) x+=2;
		return x;
	}
	
	public static int greatestNonSurprising(int gTot){
		int x = gTot/3;
		if ((gTot % 3) > 0) x+=1;
		if (x > 10){
			//shouldnt happen, .
			return 10;
		} else{
			return x;
		}
	}
}