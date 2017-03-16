import java.io.BufferedReader;
import java.io.File;
import java.io.InputStreamReader;
import java.util.Scanner;


public class ProbA {
	public static void main(String[] args) throws Exception {
//		Scanner sc = new Scanner(System.in);
		Scanner sc = new Scanner(new File("A.in"));
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int numCases = Integer.parseInt(sc.nextLine());
		for(int caseNum=1; caseNum<=numCases; caseNum++){
			String[] inps = sc.nextLine().split("\\s+");
			int lenReq = Integer.parseInt(inps[1]);
			char[] word = inps[0].toCharArray();
			long total = 0;
			long lenLast = 0;
			long indLastCon = -1;
			for(int i=0; i<word.length; i++){
				total += indLastCon+1;
				if(isConsonant(word[i])){
					lenLast++;
					if(lenLast==lenReq){
						total -= indLastCon+1;
						total += i-lenReq+2;
						indLastCon = i-lenReq+1;
					}else if(lenLast>lenReq){
						total -= indLastCon+1;
						total += i-lenReq+2;
						indLastCon = i-lenReq+1;
					}
				}else{
					lenLast = 0;
				}
			}
			System.out.println("Case #"+caseNum+": "+total);
		}
	}
	public static boolean isVowel(char c){
		char d = Character.toLowerCase(c);
		return (d=='a'||d=='e'||d=='i'||d=='o'||d=='u');
	}
	public static boolean isConsonant(char c){
		char d = Character.toLowerCase(c);
		return !(d=='a'||d=='e'||d=='i'||d=='o'||d=='u');
	}
}
