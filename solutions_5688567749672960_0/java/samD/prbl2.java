import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner;




public class prbl2 {
	static Random ran = new Random();
	
	
	
	
	public static int count(int n){

		int Min = Integer.MAX_VALUE;
		for(int i=0;i<10000 && Min !=0;i++){
			boolean cond = true;
			int curr = 0;
			int nb = 0;
			while(curr<n&&cond){
				
				if(Math.random()<0.5){
					int j = getReverseInt(curr);
					if(j<=n && j>curr) curr =  getReverseInt(curr);
					else curr++;
				}else{curr++;}
				
				nb ++;
				if(!(nb<Min)) cond = false;
			}
			if(nb<Min) Min = nb;
		}
		return Min;
	}
	
	public static int getReverseInt(int value) {
	    int resultNumber = 0;
	    for(int i = value; i !=0; i /= 10) {
	        resultNumber = resultNumber * 10 + i % 10;
	    }
	    return resultNumber;        
	}
	
	public static void main(String[] args) throws IOException {
		long startTime = System.currentTimeMillis();
		FileWriter fw = new FileWriter("out.txt");
		Scanner sc = new Scanner(new File("A-small-attempt0.in"));
		BufferedWriter out = new BufferedWriter(fw);
		int nb = sc.nextInt();
		// System.out.println(i);
	
		for (int i = 0; i < nb; i++) {
			int h =count(sc.nextInt());
			System.out.println(h);
			
			out.write("Case #"+(i+1)+": "+h+"\n");
		}
		//out.flush();
		out.close();
		long endTime = System.currentTimeMillis();
		System.out.println("That took " + (endTime - startTime)/1000 + " seconds");
	}
}
