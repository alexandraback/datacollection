import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;


public class main {
	public static void main(String[] args) throws FileNotFoundException {
		File f =new File("../input.in");
		Scanner sc = new Scanner(f);
		int N;
		char[] numb;
		boolean isOk, finished;
		int X,Y; int compteur=0;
		int T = sc.nextInt();
		int[][] matrix;
		int a, b; 
		int[] mote;
		String result;
		double p;
		int sum;
		int n;
		
		for (int i=1; i<=T;i++){
			result="Case #"+i+": ";
			p=0;
			N=sc.nextInt();
			X=sc.nextInt();
			Y=sc.nextInt(); 
			sum = Math.abs(X)+Y;
			a=(sum-1)*(sum)/2; b=(sum+1)*(sum+2)/2;
			if (X==0 && N<=b-1)
				p=0;
			else if (N <= a + Y ){
				p = 0;
				
			}
			else if(N>=b-Math.abs(X)){
				p=1;
				System.out.println(b);
			}
			else if (N<= a + sum+Y){
				n=N-a;
				p=0;
				for (int l =Y+1; l<=n; l++)
					p+=combination(l, n);
				
			}
			else {
				n=N-a;
				p=0;
				System.out.println(p+' '+i);
				for (int l =sum; n-l>sum; l--)
					p+=combination(l,n);
				
				p=p+1/Math.pow(2, sum);
				}
			ecrire("../result1.txt", result+p+"\n");
		}		
		
	}
		
	public static int min(int a, int b){
		if(a<b)
			return a;
		return b;
	}
		
	public static int contmote( int A, int[] mote, int current, int compt, int max){
		if(compt > max)
			return compt;
		if(current== mote.length)
			return compt;
		if( mote[current]<A)
			return contmote(A+mote[current], mote, current+1, compt, max);
		else return min(contmote(A, mote, current+1, compt+1, max), contmote(A+A-1, mote, current, compt+1, max));
	}
	
	public static double combination(int k, int n){
		double l=1;
		for (int i = 0; i<n-k; i++)
			l=l/2;
		for (int i = 1; i<=k; i++)
			l=l*(n-(k-i))/i/2;
		return l;
	}
		


	
	public static void ecrire(String pathTo, String tab) {
		try {
			FileWriter fos = new FileWriter(pathTo, true);
			BufferedWriter bufferWritter = new BufferedWriter(fos);
			bufferWritter.write(tab);
	        bufferWritter.close();
		} catch (FileNotFoundException ex) {
			ex.printStackTrace();
		} catch (IOException ioe) {
			ioe.printStackTrace();
		}
	}
	
	/*compteur=0; A=sc.nextInt(); B=sc.nextInt();
	a=(int) Math.sqrt(A); b=(int) Math.sqrt(B)+1;
	for (int j=a; j<=b;j++){
		if(ispal(j) && ispal(j*j) && j*j>=A && j*j<=B)
			compteur++;					
	}
	ecrire("../result1.txt", result+compteur+"\n");
		
}*/

}
