import java.io.*;
import java.math.*;
import java.util.*;

public class osmos{
	public static void main (String [] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.txt"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("A-small-attempt0.out")));
		
		int testCases = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= testCases; t++){
			pw.print("Case #" + t + ": ");
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int moteSize = Integer.parseInt(st.nextToken());
			int numMotes = Integer.parseInt(st.nextToken());
			int[] motes = new int[numMotes];
			st = new StringTokenizer(br.readLine(), " ");
			for(int i = 0; i < numMotes; i++){
				motes[i] = Integer.parseInt(st.nextToken());
			}
			
			Arrays.sort(motes);
			
			int ans = 0;
			int fans = 100;
			
			for(int i = 0; i < numMotes; i++){
				if(motes[i] < moteSize){
					moteSize += motes[i];
					continue;
				}
				fans = Math.min(fans, ans + numMotes - i);
				if(moteSize < 2){
					ans = fans;
					break;
				}
				while(moteSize <= motes[i]){
					moteSize *= 2;
					moteSize--;
					ans++;
				}
				moteSize += motes[i];
			}
			
			fans = Math.min(ans, fans);
			
			pw.println(fans);
		}
		
		br.close();
		pw.close();
	}
}