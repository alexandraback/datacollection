import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;


public class A {

	public static void main(String[] args) {		
		Scanner in;
		try {
			//in = new Scanner(new FileReader("/home/taras/workspace/GoogleCodeJam_1B/src/A-small-attempt1.in"));
			//in = new Scanner(new FileReader("/home/taras/workspace/GoogleCodeJam_1B/src/A-large.in"));
			//in = new Scanner(new FileReader("/home/taras/workspace/GoogleCodeJam_1C/src/a.in"));
			//in = new Scanner(new FileReader("/home/taras/workspace/GoogleCodeJam_1C/src/A-small-attempt0.in"));
			in = new Scanner(new FileReader("/home/taras/workspace/GoogleCodeJam_1C/src/A-large.in"));
			
			int t = in.nextInt();
			
			StringBuilder resultBuilder = new StringBuilder();
			
			for(int i = 0; i < t; i++){
				int r = in.nextInt();
				int c = in.nextInt();
				int w = in.nextInt();
				
				//System.out.println("\n\nFind solution:"+);
				resultBuilder.append("Case #"+(i+1)+": "+findSolution(r,c,w)+"\n");
			}
			
			
			System.out.println(resultBuilder.toString());
			String content = resultBuilder.toString();
			 
			File file = new File("/home/taras/workspace/GoogleCodeJam_1C/src/a.out");
 
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

	
	private static int findSolution(int r, int c, int w){
		System.out.println("findSolution: r:"+r+" c:"+c+" w"+w);
		int result = (c/w)*r + w-1;
		if(c%w!=0) result++;
		return result;
	}

}
