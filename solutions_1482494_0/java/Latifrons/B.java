import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class B {	
	static String in = "2s.in";
	static String out = "2s.out";
	
	
	public static String handle(){
		//solution place holder
		int N = s.nextInt();
		int[][] abs = new int[N][3];
		for (int i = 0 ; i < N ;i ++){
			int[] ab = new int[]{s.nextInt(),s.nextInt(),0};
			abs[i] = ab;
		}
		int s = 0; //stars
		int count = N; //2 stars needed
		int matches = 0; //matches
		while (count!= 0){
			boolean c = false;
			for (int[] ab : abs){
				if (ab[2] != 2 && ab[1] <= s){
					//count in
					s+=2-ab[2];
					ab[2] = 2;
					count --;
					matches ++;
					c = true;
				}
			}
			if (!c){
				if (count != 0){
					//buy star from 1
					for (int[] ab : abs){
						if (ab[2] == 0 && ab[0] <= s){
							//count in
							s+=1;
							ab[2] = 1;
							c = true;
							matches ++;
							break;
						}
					}
				}
			}
			if (!c){
				return "Too Bad";
			}
		}
		
		return Integer.toString(matches);
	}
	
	public static void init(){}
	static Scanner s;
	static FileWriter fw;
	public static void main(String[] args) throws IOException{
		s = new Scanner(new FileInputStream(in));
		fw = new FileWriter(out);
		
		init();
		
		int lines = s.nextInt();
		for (int i = 1 ; i <= lines ;i++){
			long start = System.currentTimeMillis();
			String result = handle();
			String output = String.format("Case #%d: %s\n", i,result);
			fw.write(output);
			System.out.printf("%3d %s",(System.currentTimeMillis()-start)/1000,output);
		}
		
		fw.close();
	}
}
