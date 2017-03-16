import java.util.*;
import java.io.*;

public class GarbledEmail {
	static class Hash{
		int a, b;
		Hash(int a, int b){
			this.a = a;
			this.b = b;
		}
		@Override
		public int hashCode() {
			final int prime = 10007;
			int result = 1;
			result = prime * result + a;
			result = prime * result + b;
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Hash other = (Hash) obj;
			if (a != other.a)
				return false;
			if (b != other.b)
				return false;
			return true;
		}
	}
	
	static ArrayList<String> dictionary = new ArrayList<String>();
	static char[] string;
	static HashMap<Hash, Integer> memo = new HashMap<Hash, Integer>();
	
	static int solve(int index, int last){
		Hash hh = new Hash(index, last);
		if(memo.containsKey(hh)) return memo.get(hh);
		if(index == string.length) return 0; 
		
		int answer = 1000000;
		eachstr: for(String str : dictionary){
			if(index + str.length() > string.length) continue;
			int recent = last;
			int count = 0;
			for(int i=0; i<str.length(); i++){
				if(string[index+i] != str.charAt(i)){
					if(recent+5 > index+i){
						continue eachstr;
					}else{
						recent = index+i;
						count++;
					}
				}
			}
			int temp = solve(index+str.length(), recent) + count;
			answer = Math.min(temp,  answer);
		}
		
		memo.put(hh, answer);
		return answer;
	}
	public static void main(String[] args) throws FileNotFoundException{
		Scanner dsc = new Scanner(new File("dictionary.txt"));
		while(dsc.hasNext()){
			dictionary.add(dsc.nextLine());
		}
		
		Scanner sc = new Scanner(System.in);
		//PrintStream out = new PrintStream(new BufferedOutputStream(System.out));
		PrintStream out = new PrintStream(System.out);
		int cases = sc.nextInt();
		for(int ctr=0; ctr<cases; ctr++){
			string = sc.next().toCharArray();
			memo.clear();
			int answer = solve(0, -5);
			out.printf("Case #%d: %d\n", ctr+1, answer);
			//out.flush();
		}
		
		out.flush();
	}
}
