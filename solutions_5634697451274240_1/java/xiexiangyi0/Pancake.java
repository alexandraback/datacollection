import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;
/*
5
-
-+
+-
+++
--+-

Case #1: 1
Case #2: 1
Case #3: 2
Case #4: 0
Case #5: 3
*/

public class Pancake {
	public static int smallestFlip(String s){
		return RecurUtil(s, 0, s.length()-1);
	}
	
	public static int RecurUtil (String s, int start, int end){
		if(start > end){
			return 0;
		}
		int len = end - start + 1;
		int i = end;
		while(i >= start){
			if(s.charAt(i) == '+'){
				if(i==end){
					return RecurUtil(s, start, end-1);
				}else{
					int leftCount = RecurUtil(s, start, i-1);
					return (leftCount+2);
				}
			}
			--i;
		}
		if(i==start-1){
			return 1;
		}
		return -1;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			//A-small-attempt0.in
		    Scanner scanner = new Scanner(new File("/Users/xiangyixie/Documents/eclipse_workspace/2016Codejam/input/B-large.in"));
		    FileWriter writer = new FileWriter(new File("/Users/xiangyixie/Documents/eclipse_workspace/2016Codejam/output/B_output_large.txt"), false);
		    int T = scanner.nextInt();
		    scanner.nextLine();
		    for (int i=0; i<T; ++i) {
		    	String S = scanner.nextLine();
		    	int o = smallestFlip(S);
		    	System.out.println("Case #" + (i+1) + ": " + S + " " + o);
		    	writer.write("Case #" + (i+1) + ": " + o + "\n");
		    }
		    
		    scanner.close();
		    writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			return;
		}
		
		System.out.println("done");

	}
}
