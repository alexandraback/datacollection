import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class DancingGooglers {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("input.in"));
		BufferedWriter bfrw = new BufferedWriter(new FileWriter("output.out"));
		
		int N = in.nextInt();
		String output = "";
		for(int i = 0; i < N;i++){
			
			int n = in.nextInt();
			int s = in.nextInt();
			int p = in.nextInt();
			
			int [] num = new int[n];
			for(int j = 0; j < n;j++){
				num[j] = in.nextInt();
			}
			output += "Case #"+(i+1)+": " + solve(num,s,p) + "\n";
		}
		
		bfrw.write(output);
		in.close();
		bfrw.close();
	}
	
	private static int solve(int [] num, int S, int P){
		int ans = 0;
		
		for(int x = 0; x < num.length;x++) {
			int N = num[x];
			ArrayList<String> al = new ArrayList<String>();
			for(int i = 10; i >= 0; i--){
				for(int j = 10; j >= 0; j--){
					for(int k = 10; k >= 0; k--){
						if(i+j+k == N && Math.max(Math.max(i,j), k) >= P && isValid(i, j, k)){
							
							//System.out.println(i + " " + j +" " + k);
							al.add(i+","+j+","+k);
							//break here;
						}
					}
				}
			}
			
			if(al.size() > 0 && !isSurprizeTrue(al)){
				ans++;
			} else if (al.size() > 0 && isSurprizeTrue(al) && S > 0) {
				ans++;
				S--;
			}
			//System.out.println();
		}
		return ans;
	}
	
	private static boolean isSurprizeTrue(ArrayList<String> al){
		for(int i = 0; i < al.size();i++){
			String[] s = al.get(i).split(",");
			if(!isSurprize(Integer.parseInt(s[0]),Integer.parseInt(s[1]),Integer.parseInt(s[2]))) return false;
		}
		return true;
	}
	
	private static boolean isValid(int i,int j, int k){
		if(Math.abs(i-j) > 2) return false;
		if(Math.abs(i-k) > 2) return false;
		if(Math.abs(j-k) > 2) return false;
		return true;
	}
	
	private static boolean isSurprize(int i,int j, int k){
		if(Math.abs(i-j) == 2) return true;
		if(Math.abs(i-k) == 2) return true;
		if(Math.abs(j-k) == 2) return true;
		return false;
	}
}
