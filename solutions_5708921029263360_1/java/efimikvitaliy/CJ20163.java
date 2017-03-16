import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class CJ20163 {
	public static void main(String[] args) throws FileNotFoundException{
		Scanner sc = new Scanner(new File("input.txt"));
		PrintWriter file = new PrintWriter(new File("output.txt"));
	
		int[] alf = new int[3];
		int[][] obh = new int[1000000][3];
		int ind1, ind2, ind3;
		int max;
		int c;
		int K;
		int count;
		int ind;
		int Q = sc.nextInt();
		for(int t=0; t< Q; ++t){
			System.out.print("Case #" + (t+1) + ": ");
			
			file.print("Case #" + (t+1) + ": ");
		count = 0;
		K=0;
		c = 0;
		
		ind1=ind2=ind3=0;
		max = 0;
		for(int i=0; i<3; ++i)
		{
			alf[i] = sc.nextInt();
		}
		K = sc.nextInt();
		System.out.println("{" + alf[0] + " " + alf[1] + " " + alf[2] + " " + K + "}");
		for(int i=0; i<3; ++i){
			if(max < alf[i]){
				max = alf[i];
				ind3 = i;
			}
		}
		max = 0;
		for(int i=0; i<3; ++i){
			if(max < alf[i] && ind3 != i){
				max = alf[i];
				ind2 = i;
			}
		}
		ind1 = 3 - ind2 - ind3;
		
		count = Math.min(alf[ind3],K);
		c = alf[ind1]*alf[ind2]*count;
		System.out.println(c);
		file.println(c);
		ind = 0;
		for(int i=0; i<alf[ind1];++i){
			for(int k = 0 ; k < alf[ind2] ; ++k){
				for(int j= 0; j<count; ++j ){
					obh[ind][ind1] = i+1;
					obh[ind][ind2] = k+1;
					ind++;
				}
			}
		}
		
		count = alf[ind3];
		if(K == 1)
			count = alf[ind2];
		
		for(int i=0; i<c; ++i){
			obh[i][ind3] = (i/count + i)%count+1;
		}
		
		for(int i=0; i<c; ++i){
		 System.out.println(obh[i][0] + " " + obh[i][1] + " " + obh[i][2]);
		 file.println(obh[i][0] + " " + obh[i][1] + " " + obh[i][2]);
		}
		}
		file.close();
		
		
	}
}
