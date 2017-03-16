import java.io.File;
import java.io.FileNotFoundException;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;


public class main {
	 static public void publishResult(float[] minimal, int N){
		 System.out.print("Case #"+N+":");
		 for(int i = 0; i<minimal.length; i++)
			 System.out.print(" "+minimal[i]);
		 System.out.println();
	 }
	
	
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);
		//Scanner res = new Scanner( new File("/home/loic/INF422/workspace/CodeJam1/bin/Result.txt"));
		int T = sc.nextInt(); int N; int[] score; float[] minimal; int[] trié; int somme, borne, temp, temp2; float result;
		HashMap<Integer, Float> table = new HashMap<Integer, Float>();
		for(int i = 0; i<T;i++){
			somme = 0;
			table.clear();
			N = sc.nextInt();
			score = new int[N]; minimal = new float[N];trié = new int[N];
			for(int j = 0; j<N; j++){
				score[j]=sc.nextInt();trié[j]=score[j];}
			Arrays.sort(trié);
			for(int j = 0; j< N; j++)
				somme+=trié[j];
			for(int j = 0; j<trié.length;j++)
				if(!table.containsKey(trié[N-1-j])){
					temp = N*trié[N-1];borne = 2*somme;
					temp2 = N-1;
					while(temp2>=N-j && temp > borne ){
						temp2--; temp =(temp2+1)* trié[temp2]; borne -= trié[temp2+1];
					}
					if (temp > borne)
						table.put(trié[N-1-j], (float) 0);
					else{
						temp = 2*somme;
						for(int k = N-1 ;k>temp2;k--)
							temp-=trié[k];
						table.put(trié[N-1-j], (((float) temp)/((float) (temp2+1))-trié[N-1-j])/((float)somme));
					}
				}
			for (int j = 0; j<N; j++)
				minimal[j]=100*table.get(score[j]);
			publishResult(minimal, i+1);			
		}			
	}
}
