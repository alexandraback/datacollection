import java.util.Scanner;

public class LastWord {
	
	public static String lastWord(String S){
		if (S.equals("") || (S.length() == 1)) { return S;}
		else{
			int max_ind = 0;
			for (int i=0; i < S.length(); i++){
				if (S.charAt(i) >= S.charAt(max_ind)) { max_ind = i;}
			}
			//System.out.println("S = " + S+"; maxind = "+max_ind);
			return  S.charAt(max_ind) + lastWord(S.substring(0, max_ind)) + S.substring(max_ind+1);
		}
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i=0; i < T; i++)
		{
			String S = sc.next();
			System.out.println("Case #" + (i+1) +": " + lastWord(S));
		}
		sc.close();
		
	}
}
