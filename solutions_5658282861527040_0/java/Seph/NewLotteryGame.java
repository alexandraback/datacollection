import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class NewLotteryGame {
	public static void main(String[] args) throws IOException {
		System.out.println(args[0]);
		System.out.println(args[1]);
		
		Scanner s = new Scanner(new File(args[0]));
		File out = new File(args[1]);
		if(!out.exists()) {
			out.createNewFile();
		} else {
			out.delete();
			out.createNewFile();
		}
		FileWriter fw = new FileWriter(out);
		
		int numCases = s.nextInt();
		for(int i=1; i<=numCases; i++) {
			int A = s.nextInt();
			int B = s.nextInt();
			int K = s.nextInt();
			
			long results = 0;
			for(int a=0; a<A; a++) {
				for(int b=0; b<B; b++) {
					for(int k=0; k<K; k++) {
						if((a&b) == k) {
							results++;
						}
					}
				}
			}
			fw.write("Case #"+i+": " + results + "\n");
		}
		
		fw.close();
	}
	
	
	
}
