import java.io.*;
import java.awt.*;
import java.awt.event.InputEvent;
import java.awt.image.BufferedImage;
import java.util.*;


public class B {
	public static void main (String[] args){
		Scanner sc = new Scanner (System.in);
		int T = sc.nextInt();
		for (int i=0;i<T;i++){
			System.out.print("Case #" + (1+i) + ": ");
			solve(sc);
			System.out.print("\n");
		}
	}

	private static void solve(Scanner sc) {
		int N = sc.nextInt();
		int X = sc.nextInt();
		int Y = sc.nextInt();
		int hex = (int) (1+Math.sqrt(1+8*(double)N))/4;
		// have hex+2 per side 
		int lb = hex*(2*hex-1);
		if (Math.abs(X)+Math.abs(Y)<=2*hex-2){
			System.out.print(1);
			return;
		}
		if (Math.abs(X)+Math.abs(Y)>=2*hex+2){
			System.out.print(0);
			return;
		}
		double[] probs = new double[hex*2];
		N=N-lb;

		if (X==0){
			System.out.print(0);
			return;
		}
		int lastfilled = 0;
		for (int i=0;i<N;i++){
			double[] newprobs = new double [hex*2];
			boolean topover = false;
			if (probs[hex*2-1]!=0){
				topover=true;
			}
			for (int j=0;j<hex*2;j++){
				if (j==0){
					newprobs[j]=probs[j]+(1-probs[j])*0.5;
				}
				else {
					newprobs[j]=probs[j]+(probs[j-1]-probs[j])*0.5;
				}
			}
			if (topover){
				newprobs[lastfilled]=1;
				lastfilled++;
			}
			probs=newprobs;
		}
		System.out.print(probs[Y]);
		
		
	}

}