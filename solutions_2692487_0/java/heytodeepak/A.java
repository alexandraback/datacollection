package Y2013;

import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader("A.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("A.out"));
		
		int ntest = sc.nextInt();
		sc.nextLine();
		for(int test=1;test<=ntest;++test) {	
			
			InputData data = getData(sc);
			long result = process(data);
			
			//System.out.println("Case #" + test + ": " + result);
			pw.print("Case #" + test + ": ");
			pw.print(result);
			pw.println();
		}
		pw.close();
		sc.close();
	}

	private static long process(InputData data) {	
		Collections.sort(data.in);
		//System.out.print(data.A + " -->");
		/*for (int i=0; i<data.in.size(); ++i) {
			System.out.print(" " + data.in.get(i));
		}*/
		//System.out.println();
		
		int index = 0;
		long count = getMinSteps(data.A, data.in, index);
		return count;
	}


	private static long getMinSteps(long a, List<Integer> in, int index) {
		long count = 0;
		for (int i=index; i<in.size(); ++i) {
			if (a > in.get(i)){
				a = a + in.get(i);
			} else {
				
				long bb = getMinSteps(a, in, i+1);
				long aa = 0;
				if (a == 1) {
					aa = bb;
				} else {
					aa = getMinSteps(2*a-1, in, i);
				}
				
				
				count = Math.min(aa, bb) + 1;
				break;
			}
		}
		return count;
	}

	//2 2
	//2 1
	private static InputData getData(Scanner sc) {
		int A = sc.nextInt();
		int N = sc.nextInt();
		sc.nextLine();
		
		InputData data = new InputData();
		
		data.in = new ArrayList<Integer>(); 
		data.A  = A;
		for(int index=0; index<N; ++index){
			data.in.add(sc.nextInt());
		}
		sc.nextLine();
		return data;
		
	}
	
	public static class InputData {
		long A;
		List<Integer> in;
	}
}

