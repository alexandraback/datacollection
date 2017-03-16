import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = null;
		BufferedWriter bw = null;
		try{
			sc = new Scanner(new File("input.txt"));
			bw = new BufferedWriter(new FileWriter("gcj2b.txt"));
			
			int T = sc.nextInt();
			int N, p, s, x;
			int minNormal=0, minSur=0, totNor=0, totSur=0;
			for(int i=0;i<T;i++){
				totNor = 0; totSur = 0;
				N = sc.nextInt();
				s = sc.nextInt();
				p = sc.nextInt();
				minNormal = 3*p-2;minSur = 3*p-4;
				minSur = (minSur>p)?minSur:p;
				for(int j=0;j<N;j++){
					x = sc.nextInt();
					if(x>=minNormal)	totNor++;
					else if(x>=minSur)	totSur++;
				}
				
				totNor += s>totSur?totSur:s;
				bw.write("Case #"+(i+1)+": "+totNor);bw.newLine();
			}
		}catch(Exception e){}
		finally{
			try{
				sc.close();bw.close();
			}catch(Exception e){}
		}
	}

}
