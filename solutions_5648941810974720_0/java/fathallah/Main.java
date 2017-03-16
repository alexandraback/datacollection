import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;


public class Main {
	static int[] letters = new int[26];
	static String s;
	static int[] temp = new int[26];
	
	static public boolean count(String str){
		Arrays.fill(temp,0);
		for(int i=0;i<str.length();i++){
			temp[str.charAt(i)-'A']++;
		}
		for(int i=0;i<temp.length;i++){
			if(letters[i]<temp[i])
				return false;
		}
		for(int i=0;i<temp.length;i++){
			letters[i]-=temp[i];
		}
		return true;
	}
	static public void main(String[] args)throws Exception{
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt1.in"));
		PrintWriter out = new PrintWriter("output.txt");
		
		int t = Integer.parseInt(br.readLine());
		String[] digits = new String[10];
		digits[0]="ZERO";
		digits[1]="ONE";
		digits[2]="TWO";
		digits[3]="THREE";
		digits[4]="FOUR";
		digits[5]="FIVE";
		digits[6]="SIX";
		digits[7]="SEVEN";
		digits[8]="EIGHT";
		digits[9]="NINE";
		int[] order = {0,2,6,8,3,4,5,7,9,1};

		for(int z=1;z<=t;z++){
			s = br.readLine();
			Arrays.fill(letters,0);
			for(int i=0;i<s.length();i++)
				letters[s.charAt(i)-'A']++;
			
			int[] res = new int[10];
			for(int i=0;i<10;i++){
				while(count(digits[order[i]])){
					res[order[i]]++;
				}
			}
			
			StringBuilder result = new StringBuilder();
			for(int i=0;i<10;i++){
				for(int j=0;j<res[i];j++){
					result.append(i);
				}
			}
			out.println("Case #"+z+": "+result.toString());
			for(int i=0;i<26;i++){
				if(letters[i]!=0){
					System.out.println((char)('A'+i) +" "+ letters[i] +" "+s+" "+result.toString());
				}
			}
		}
		br.close();
		out.close();
	}
}
