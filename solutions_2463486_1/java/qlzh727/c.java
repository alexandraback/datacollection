import java.util.Arrays;
import java.util.Scanner;


public class FairAndSquare {

	public Long nextPalindromes(Long input){
		String s = String.valueOf(input);
		int palPosition1 = (s.length() +1) / 2 - 1;
		int palPosition2 = s.length() - (s.length() +1) /2;
		while(palPosition1 >= 0 && s.charAt(palPosition1) == '9'){
			palPosition1 --;
			palPosition2++;
		}
		
		if(palPosition1 >= 0){
			char[] cs = s.toCharArray();
			cs[palPosition1] += 1;
			if(palPosition1 != palPosition2)
				cs[palPosition2] += 1;
			for(int i = palPosition1+1; i < palPosition2; i++)
				cs[i] = '0';
			return Long.valueOf(new String(cs));
		} else {
			char[] cs= new char[s.length()+1];
			Arrays.fill(cs, '0');
			cs[0] = '1';
			cs[cs.length-1] = '1';
			return Long.valueOf(new String(cs));
		}
	}
	
	public boolean isPalindromes(Long input){
		char[] cs = String.valueOf(input).toCharArray();
		for(int i = 0; i <= cs.length / 2; i++){
			if(cs[i] != cs[cs.length - 1 -i])
				return false;
		}
		return true;
	}
	
	public long lowBound(long input){
		char[] cs = new char[String.valueOf(input).length()];
		Arrays.fill(cs, '0');
		cs[0] = '1';
		cs[cs.length-1] = '1';
		return Long.valueOf(new String(cs));
	}
	
	public void solve(int caseNo, long lowBound, long upBound){
		long result = 0;
		long low = (long)Math.sqrt((double)lowBound);
		low = lowBound(low);
		
		while(low * low <= upBound){
			if(low * low < lowBound){
				low = nextPalindromes(low);
				continue;
			}
			if(isPalindromes(low * low))
				result ++;
			low = nextPalindromes(low);
		}
		System.out.println("Case #"+caseNo+": "+result);
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		FairAndSquare f = new FairAndSquare();
		Scanner sc = new Scanner(System.in);
		int totalCase = Integer.parseInt(sc.nextLine());
		for(int i =1; i <= totalCase; i++){
			String s = sc.nextLine();
			long low = Long.valueOf(s.split(" ")[0]);
			long high = Long.valueOf(s.split(" ")[1]);
			f.solve(i, low, high);
		}
	}

}
