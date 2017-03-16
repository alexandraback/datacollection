/** @author Dalda */
import java.util.*;
import java.io.*;

public class ProblemA {
	public static void main(String[] args) throws IOException{
	
		BufferedWriter fw = new BufferedWriter(new FileWriter("output.txt"));
		Scanner sc = new Scanner(new File("input.in"));
		
		int t = sc.nextInt();
		for(int cas=1; cas<=t;cas++){
			int ak = sc.nextInt();
			long a = ak;
			int n = sc.nextInt();
			int[] pole = new int[n];
			for(int i =0;i<n;i++){
				pole[i] = sc.nextInt();
			}
			if( a == 1){
				fw.write("Case #"+cas+": "+n+"\n");
				continue;
			}
			Arrays.sort(pole);
			int num = 0; //kolik proskrtla
			for(int i=0;i<n;i++){
				if(pole[i] < a){
					a += pole[i];
					num++;
				}
			}
			if(num == n){
				fw.write("Case #"+cas+": "+0+"\n");
				continue;
			}
			//System.out.println(num);
			int celkem = 0;
			int min = n-num;
			for(int i=num;i<n;i++){
				min = Math.min(min, celkem+n-i);
				while(a <= pole[i]){
					a = 2*a-1;
					celkem++;
				}
				a = a+pole[i];
				
				//int j;
//				for(j=i;j<n;j++){
//					if(pole[j] >= a) break;
//					a += pole[j];
//				}
//				//na j seknul
//				if(j-i >= 2){
//					celkem++;
//					i = j-1;
//				}
			}
			int vysledek = Math.min(min, celkem);
			fw.write("Case #"+cas+": "+vysledek+"\n");
		}
		fw.close();
	}
}
