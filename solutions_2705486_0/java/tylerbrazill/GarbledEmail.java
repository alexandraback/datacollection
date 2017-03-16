import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;


public class GarbledEmail {
	int ct = 0;
	class Tri{
		Tri[] next;
		boolean isEnd;
		int id;
		Tri(){
			next = new Tri[26];
			isEnd = false;
			id = ct++;
		}
		void add(String s, int i){
			if(i == s.length()){
				isEnd = true;
				//wrd = s;
			}else{
				if(next[s.charAt(i)-'a'] == null)
					next[s.charAt(i)-'a'] = new Tri();
				next[s.charAt(i)-'a'].add(s, i+1);
			}
		}
		int search(int index, int lastEdit){
			if(index == str.length()){
				if(isEnd) return 0;
				return 987654321;
			}
			if(memo[lastEdit][index][id] != -1) return memo[lastEdit][index][id];
			int ans = 978654321;
			if(isEnd){
				ans = Math.min(ans, root.search(index, lastEdit));
				
			}
			if(lastEdit == 5){
				for(int i = 0; i<26; i++)
					if(next[i] != null)
						ans = Math.min(ans, next[i].search(index+1, 1)+1);
			}
			if(next[str.charAt(index)-'a'] != null)
				ans = Math.min(ans, next[str.charAt(index)-'a'].search(index+1, Math.min(5, lastEdit+1)));
			return memo[lastEdit][index][id] = ans;
		}
	}
	GarbledEmail() throws FileNotFoundException{
		init();
		Scanner in = new Scanner(System.in);
		int tests = in.nextInt();
		memo = new int[6][50][ct];
		for(int t = 1; t<=tests; t++){
			str = in.next();
			for(int[][] a: memo)
				for(int[] b: a)
					Arrays.fill(b, -1);
			//System.out.println("Searching...");
			int ans = root.search(0, 5);
			System.out.println("Case #"+t+": "+ans);
		}
		in.close();
	}
	Tri root;
	int[][][] memo;
	String str;
	void init() throws FileNotFoundException{
		Scanner dic = new Scanner(new File("garbled_email_dictionary.txt"));
		root = new Tri();
		while(dic.hasNext())
			root.add(dic.next().toLowerCase(), 0);
		dic.close();
		System.out.println(ct);
	}
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream(new File("garbled.in")));
		//System.setOut(new PrintStream(new File("garbled.out")));
		new GarbledEmail();
	}

}
