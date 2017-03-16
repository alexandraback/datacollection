import java.io.BufferedOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class EqualSums {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		PrintStream out = new PrintStream(new BufferedOutputStream(System.out));
		int cases = sc.nextInt();
		for(int ctr=0; ctr<cases; ctr++){
			int n = sc.nextInt();
			int[] arr = new int[n];
			for(int i=0; i<n; i++)
				arr[i] = sc.nextInt();
			int lim = 2<<n;
			HashMap<Integer, Integer> ans = new HashMap<Integer, Integer>();
			boolean success = false;
			ArrayList<Integer> a1=null, a2=null;
			done: for(int i=0; i<lim; i++){
				int sum = 0;
				for(int k=0; k<n; k++){
					if(((i>>k)&1) == 1){
						sum += arr[k];
					}
				}
				if(ans.containsKey(sum)){
					int answer = ans.get(sum);
					int common = (answer&i);
					int ans1 = answer^common;
					int ans2 = i^common;
					a1 = new ArrayList<Integer>();
					for(int k=0; k<n; k++){
						if(((ans1>>k)&1) == 1){
							a1.add(arr[k]);
						}
					}
					a2 = new ArrayList<Integer>();
					for(int k=0; k<n; k++){
						if(((ans2>>k)&1) == 1){
							a2.add(arr[k]);
						}
					}
					
					success = true;
					break done;
				}else{
					ans.put(sum, i);
				}
			}
			out.printf("Case #%d:\n", ctr+1);
			if(success){
				boolean first = true;
				for(int i=0; i<a1.size(); i++){
					if(!first)
						out.print(" ");
					else
						first = false;
					out.print(a1.get(i));
				}
				out.println();
				
				first = true;
				for(int i=0; i<a2.size(); i++){
					if(!first)
						out.print(" ");
					else
						first = false;
					out.print(a2.get(i));
				}
				out.println();
			}else{
				out.println("Impossible");
			}
		}
		out.flush();
	}
}
