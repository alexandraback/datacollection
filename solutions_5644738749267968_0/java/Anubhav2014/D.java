package qualification2014;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class D {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int N;
		ArrayList<Float> nw,kw;
		for (int i = 1; i <= T; i++) {
			N = sc.nextInt()	;
			nw = new ArrayList<Float>();
			kw = new ArrayList<Float>();
			for (int j = 0; j < N; j++) {
				nw.add(new Float(sc.next()));
			}
			for (int j = 0; j < N; j++) {
				kw.add(new Float(sc.next()));
			}
			ArrayList<Float> ntemp = new ArrayList<Float>(nw);
			ArrayList<Float> ktemp = new ArrayList<Float>(kw);
			int np = 0,kp = 0;
			System.out.print("Case #"+i+": ");
			Collections.sort(kw);
			Collections.sort(nw);
			
			for (int j = 0; j < N; j++) {
				if(nw.get(nw.size()-1)>kw.get(kw.size()-1)){
					np++;
					nw.remove(nw.get(nw.size()-1));
					kw.remove(kw.get(kw.size()-1));
				}
				else
				if(nw.get(nw.size()-1)<kw.get(kw.size()-1)){
					if(nw.size()!=1){
						kp++;
						kw.remove(kw.get(nw.size()-1));
						nw.remove(nw.get(0));
					}
					else
					{
						kp++;
						kw.remove(kw.get(nw.size()-1));
						nw.remove(nw.get(nw.size()-1));
						
					}
				}	
			}
			System.out.print(np+" ");
			kw = new ArrayList<Float>(ktemp);
			nw = new ArrayList<Float>(ntemp);
			np=0;kp=0;
			Collections.sort(kw);
			Collections.sort(nw);
			for (int j = 0; j < N; j++) {
				if(nw.get(nw.size()-1)<kw.get(kw.size()-1)){
					kp++;
					nw.remove(nw.get(nw.size()-1));
					kw.remove(kw.get(kw.size()-1));
				}
				else
				{
					np++;
					nw.remove(nw.get(nw.size()-1));
					kw.remove(kw.get(0));
				}
			}
			
			System.out.println(np);
			/*Collections.sort(kw);
			Collections.sort(nw);
			np=0;kp=0;
			for (int j = 0; j < N; j++) {
				if(nw.get(nw.size()-1)>kw.get(kw.size()-1)){
					np++;
					nw.remove(nw.get(nw.size()-1));
					kw.remove(kw.get(kw.size()-1));
				}
				else
				if(nw.get(nw.size()-1)<kw.get(kw.size()-1)){
					if(nw.size()!=1){
						np++;
						kw.remove(kw.get(nw.size()-1));
						nw.remove(nw.get(0));
					}
					else
					{
						kp++;
						kw.remove(kw.get(nw.size()-1));
						nw.remove(nw.get(nw.size()-1));
						
					}
				}	
			}*/
			
		}

	}

}
