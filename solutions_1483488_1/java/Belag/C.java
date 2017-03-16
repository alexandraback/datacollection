package qualification;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;

public class C {
	public static void main(String[] Args) throws IOException {
		Scanner sc = new Scanner(new FileReader("C-small.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
//		int caseCnt=1;
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			System.out.println(caseNum);
			int A=sc.nextInt();
			int B=sc.nextInt();
//			int A = 1234567;
//			int B =1234567;
			HashMap<Integer, LinkedList<Integer>> visited = new HashMap<Integer, LinkedList<Integer>>();
			long total=0;
			for(int i=A;i<=B;i++){
				if(!visited.containsKey(i))
					visited.put(i, new LinkedList<Integer>());
				String stringI=String.valueOf(i);
				for(int j=1;j<stringI.length();j++) {
					String test = stringI.substring(j)+stringI.substring(0, j);
					int testInt = Integer.parseInt(test);
					if(testInt>=A && testInt<=B && testInt!=i){
						if(!visited.containsKey(testInt))
							visited.put(testInt, new LinkedList<Integer>());
						if(!visited.get(testInt).contains(i)) {
							total++;
							visited.get(testInt).add(i);
							visited.get(i).add(testInt);
						}
					}
				}
			}
			System.out.println(total);
			pw.println("Case #" + caseNum + ": " + total);
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}

}
