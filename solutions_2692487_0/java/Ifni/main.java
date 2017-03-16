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
		int A,  B; int compteur=0;
		int T = sc.nextInt();
		int[][] matrix;
		long a, b; 
		int[] mote;
		String result;
		int coup;
		
		for (int i=1; i<=T;i++){
			result="Case #"+i+": ";
			coup=0;
			A=sc.nextInt();
			N=sc.nextInt();
			mote = new int[N];
			for (int j=0; j<N;j++)
				mote[j]=sc.nextInt();
			Arrays.sort(mote);
			coup = contmote(A, mote, 0, 0, 10);
					
			
			
			
			ecrire("../result1.txt", result+coup+"\n");
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
