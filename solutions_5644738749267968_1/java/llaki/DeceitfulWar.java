import java.util.*;
import java.io.*;

public class DeceitfulWar {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		PrintWriter pw = new PrintWriter(System.out);
		for(int i=1; i<=t; i++){
			n = sc.nextInt();
			a = new double[n];
			b = new double[n];
			for(int j=0; j<n; j++) a[j] = sc.nextDouble();
			for(int j=0; j<n; j++) b[j] = sc.nextDouble();
			Arrays.sort(a);
			Arrays.sort(b);
			pw.println("Case #"+i+": "+resultForDecWar()+" "+resultForWar());
		}
		pw.flush();
		pw.close();
	}
	
	
	
	
	static int resultForDecWar(){
		int p = 0;
		int res = 0;
		for(int i=0; i<n; i++){
			boolean found = false;
			for(int j=p; j<n; j++){
				if(a[j]>=b[i]){
					p = j;
					found = true;
					break;
				}
			}
			if(!found){
				return res;
			}
			res++;
			p++;
		}
		return res;
	}
	
	static int resultForWar(){
		int r = n-1;
		int res = 0;
		for(int i=n-1; i>=0; i--){
			double cur = a[i];
			if(b[r]>cur){
				r--;
			}
			else{
				res++;
			}
		}
		return res;
	}
	
	static double[] a, b;
	
	static int n;
	
}
