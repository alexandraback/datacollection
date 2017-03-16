import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;


public class RecycledNumbers {


	public static void main(String[] args) throws IOException {
		
		String inputName = "C-large";
		
		FileReader fr = new FileReader(inputName+".in");
		Scanner sc = new Scanner(fr);
		
		FileWriter fstream = new FileWriter(inputName+".out");
		BufferedWriter out = new BufferedWriter(fstream);
				
		int T = sc.nextInt();
		for(int i = 0; i < T; i++){
			int A = sc.nextInt();
			int B = sc.nextInt();
			int ans = 0;
			for(int n = A; n <= B; n++){
				String s = ""+n;
				ArrayList<Integer> mlist = new ArrayList<Integer>();
				for(int k = 1; k < s.length(); k++){
					String s2 = s.substring(k) + s.substring(0, k);
					int m = Integer.parseInt(s2);
					if(m > n && m <= B && !mlist.contains(m)){
						//System.out.println(s + " " + s2);
						ans++;
						mlist.add(m);
					}
				}
			}
			print(out, "Case #" + (i+1) + ": " + ans);
		}

		fr.close();
		out.close();
	}
	
	public static void print(BufferedWriter out, String s) throws IOException{
		out.write(s);
		out.newLine();
		System.out.println(s);
	}
}
