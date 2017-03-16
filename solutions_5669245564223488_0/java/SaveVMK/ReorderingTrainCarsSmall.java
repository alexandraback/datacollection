import java.io.*;
import java.util.*;

public class ReorderingTrainCarsSmall {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/B-small.in"))));

		String output = "";
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			int n = sc.nextInt();
			List<String> list = new ArrayList<String>();
			for (int j = 0; j < n; j++) {
				list.add(sc.next());
			}
			int[] tot = new int[1];
			tot[0] = 0;
			permute(list, 0, tot);
			output += "Case #" + i + ": " + tot[0] + "\n";
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/B-small.out"), "utf-8"));
		bw.write(output);
		bw.close();
	}
	
	static void permute(java.util.List<String> arr, int k, int[] tot){
        for(int i = k; i < arr.size(); i++){
            java.util.Collections.swap(arr, i, k);
            permute(arr, k+1, tot);
            java.util.Collections.swap(arr, k, i);
        }
        if (k == arr.size() -1){
        	String answer = "";
            for (String s : arr) {
            	answer += s;
            }
            boolean[] hasSeenChar = new boolean[26];
            char lastChar = ' ';
            for (char c : answer.toCharArray()) {
            	if (hasSeenChar[c-'a'] && c != lastChar) {
            		return;
            	}
            	lastChar = c;
            	hasSeenChar[c-'a'] = true;
            }
            tot[0]++;
            return;
        }
    }
}