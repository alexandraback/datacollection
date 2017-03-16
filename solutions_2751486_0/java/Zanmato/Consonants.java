import java.io.BufferedReader;
import java.io.FileReader;


public class Consonants {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new FileReader("c:\\A-small-attempt0.in"));
		
		int testcase = Integer.parseInt(br.readLine());
		
		for(int i=0;i<testcase;i++){
			String[] inputs  = br.readLine().split(" ");
			String l = inputs[0];
			int n = Integer.parseInt(inputs[1]);
			
			int ans = 0;
			
			for(int j=0; j<l.length()-n+1; j++){
				for(int k=j+n; k<=l.length(); k++){
					if(isConsecutive(l.substring(j,k), n)){
						ans += l.length()-k+1;
						break;
					}
				}
			}
			
			System.out.println("Case #"+(i+1)+": "+(ans));
		}

	}
	
	public static boolean isConsecutive(String str, int n){
		int count = 0;
		for(int i=0; i<str.length(); i++){
			if(str.charAt(i) == 'a' || str.charAt(i) == 'e' || str.charAt(i) == 'i' || str.charAt(i) == 'o' || str.charAt(i) == 'u'){
				count = 0;
			}
			else {
				count++;
			}
			
			if(count>=n){
				return true;
			}
		}
		return false;
	}

}
