package codejam1c;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.TreeSet;

public class A {
	
	String filePrefix = "src/codejam1c/A-small-attempt1";
//	String filePrefix = "src/codejam1c/A";
	
	String input = "";
	int n = 0;
	int result;
	
	public String solve() {
		TreeSet<Integer> ccIndex;
//		HashSet<Integer> 
		int indices[];
		result = 0;
		ccIndex = new TreeSet<Integer>();
		
		// Scan for index of substring with at least n consecutive consonants
		indices = new int[input.length()];
		System.out.println("length = "+input.length()+" n="+n);
		for (int i=0; i<input.length(); i++) {
			if (input.charAt(i) != 'a' && input.charAt(i) != 'e' && 
					input.charAt(i) != 'i' && input.charAt(i) != 'o' &&
					input.charAt(i) != 'u') {
				if (i==0) {
					indices[i] = 1;
				} else {
					indices[i] = indices[i-1]+1;
				}
			} else {
				indices[i] = 0;
			}
			if (indices[i] >= n) {
				ccIndex.add(i-(n-1));
			}
		}
		System.out.println(Arrays.toString(indices));
		// Count
		int startIndex = 0;
		for (Integer c: ccIndex) {
//			int count = input.length()-1-c;
			int count = input.length()-c-n+1;
			System.out.println("c="+c+" first count = "+count);
			result += count;
			
			count = (input.length()-c-n+1)*(c-startIndex);
			System.out.println("c="+c+" second count = "+count);
			result += count;
			
			//startIndex++;
			startIndex = c+1;
		}
		
		return Integer.toString(result);
	}

	public void go() {
		Scanner scanner = null;
		BufferedWriter bw = null;
		try {
			scanner = new Scanner(new File(filePrefix+".in"));
			int numOfInput = Integer.parseInt(scanner.nextLine());
			bw = new BufferedWriter(new FileWriter(new File(filePrefix+".out")));
			for (int i=0; i<numOfInput; i++) {
				bw.write("Case #");
				bw.write(Integer.toString(i+1));
				bw.write(": ");
				input = scanner.next();
				n = scanner.nextInt();
				String result = solve();
				bw.write(result);
				if (i < numOfInput-1) {
					bw.write('\n');
				}
				System.out.println("Case #"+(i+1)+": "+result);
			}
			scanner.close();
			bw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		A go = new A();
		go.go();
	}

}
