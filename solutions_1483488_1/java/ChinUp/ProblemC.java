package QualificationC;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Arrays;
import java.util.HashSet;

public class ProblemC {
	
	public static void main(String args[]) throws Exception{
//		System.out.println(args[0]);
		FileReader fr = new FileReader(args[0]);
		BufferedReader br = new BufferedReader(fr);	
		
		int T = Integer.parseInt(br.readLine());
		
//		System.out.println(T);
		
		for(int t=0;t<T;t++) {
			String[] input = br.readLine().split(" ");
			int result = 0;
			
			int A = Integer.parseInt(input[0]);
			int B = Integer.parseInt(input[1]);
			int size = B - A;
			
			for(int i = 0; i<= size; i++) {
				String string = String.valueOf(i + A);
				int val = Integer.parseInt(string);
				
				String foo[] = permute(string);
				if(foo == null) continue;
				
				for(int j=0;j<foo.length;j++) {
					int swapval = Integer.parseInt(foo[j]);
					
					if(swapval < A || swapval > B) continue;
					if(swapval <= val) continue;
					
					result++;
					
//					System.out.println(swapval);
				}
			}
			
			System.out.println("Case #" + (t+1) + ": " + result);
			
		}
	}
	
	
	public static String shiftString(String a) {
		return a.substring(1) + a.charAt(0);
	}
	
	public static String[] permute(String a) {
		int len = a.length();
		
		if(len <= 1) return null;
		
		
		String[] result = new String[len - 1];
		result[0] = shiftString(a);
		for(int i=1;i<len - 1;i++) {
			result[i] = shiftString(result[i-1]);
		}
		
		HashSet<String> set = new HashSet<String>(Arrays.asList(result));
		result = set.toArray(new String[0]);
		
//		String[] answer = set.toArray(new String[0]);	
//		if(set.size() != result.length) {
//			System.out.println("--b4--");
//			System.out.println(Arrays.toString(result));
//			
//			System.out.println("--after--");
//			System.out.println(Arrays.toString(answer));
//			System.out.println("-----");
//		}
		
//		System.out.println(Arrays.toString(result));
		return result;
	}
	
}
