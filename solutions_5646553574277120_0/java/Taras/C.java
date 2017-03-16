import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class C {
	
	public static void main(String[] args) {	
	Scanner in;
	try {
			//in = new Scanner(new FileReader("/home/taras/workspace/GoogleCodeJam_1C/src/c.in"));
			in = new Scanner(new FileReader("/home/taras/workspace/GoogleCodeJam_1C/src/C-small-attempt0.in"));
			//in = new Scanner(new FileReader("/home/taras/workspace/GoogleCodeJam_1C/src/C-large.in"));
			
			int t = in.nextInt();
			
			StringBuilder resultBuilder = new StringBuilder();
			
			int[] coins;
			
			for(int i = 0; i < t; i++){
				int c = in.nextInt();
				int d = in.nextInt();
				int v = in.nextInt();
				coins = new int[d];
				for(int j=0;j<d; j++)
					coins[j] = in.nextInt();
				
				resultBuilder.append("Case #"+(i+1)+": "+findSolution(c,d,v, coins)+"\n");
			}
			
			
			System.out.println(resultBuilder.toString());
			String content = resultBuilder.toString();
			 
			File file = new File("/home/taras/workspace/GoogleCodeJam_1C/src/c.out");
	
			// if file doesnt exists, then create it
			if (!file.exists()) {
				file.createNewFile();
			}
	
			FileWriter fw = new FileWriter(file.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);
			bw.write(content);
			bw.close();
	
			System.out.println("Done");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}


private static int findSolution(int c, int d, int v, int[] coins){
	System.out.println("findSolution: c:"+c+" d:"+d+" v:"+v);
	int result = 0;
	
	boolean[] used = new boolean[v+1];
	boolean[] nextUsed = new boolean[v+1];
	nextUsed[0] = true;
	for(int i=0;i<coins.length;i++){
		
		for(int j=0;j<=v;j++){
			used[j] = nextUsed[j];
		}
		
		for(int j=0;j<=v;j++){
			int next = coins[i]+j;
			if(next<=v && used[j]==true){
				nextUsed[next] = true;
			}
		}
		System.out.println("coin:"+coins[i]);
		for(int j=0;j<=v;j++){
			System.out.print(" "+j+":"+nextUsed[j]);
		}
		System.out.println();
	}
	
	boolean findNext = false;
	
	findNext = false;
	for(int i=0;i<=v;i++){
		if(!nextUsed[i]) findNext = true;
	}
	
	while(findNext){
		result++;
		for(int j=0;j<=v;j++){
			used[j] = nextUsed[j];
		}
		
		int nextCoin = 0;
		for(int j=0;j<=v;j++)
			if(!used[j]){
				nextCoin = j;
				break;
			}
		
		for(int j=0;j<=v;j++){
			int next = nextCoin+j;
			if(next<=v && used[j]==true){
				nextUsed[next] = true;
			}
		}
		
		findNext = false;
		for(int i=0;i<=v;i++){
			if(!nextUsed[i]) findNext = true;
		}
	}
	
	return result;
}

}
