import java.util.*;
import java.io.*;
public class QualProblemC {
	public static void main(String[] args)throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		ArrayList<Long> good2 = new ArrayList<Long>();
		for(long i = 1;i<=1e7;i++){
			if(isPalin(i) && isPalin(i*i)){
				good2.add(i);
			}
		}
		System.out.println(good2);
		for(int c = 1;c<=t;c++){
			String line = br.readLine();
			StringTokenizer st = new StringTokenizer(line, " ");
			long low = Long.parseLong(st.nextToken());
			long high = Long.parseLong(st.nextToken());
			long count2 = 0;
			for(long i : good2){
				if(i*i >= low && i*i <= high){
					count2++;
				}
			}
			System.out.println("Case #"+c+": "+count2);
		}
	}
	public static boolean isPalin(long num){
		String cur = ""+num;
		int left = 0;
		int right = cur.length()-1;
		while(left <= right && cur.charAt(left) == cur.charAt(right)){
			left++;
			right--;
		}
		return right < left;
	}
}
