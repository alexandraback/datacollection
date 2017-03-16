import java.util.Scanner;

public class TheLastWord {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		for(int cn=1; cn<=T;cn++){
			String S=sc.next();
			String ans="";
			int l=S.length();
			for(int i=0;i<l;i++){
				if((ans+S.charAt(i)).compareTo(S.charAt(i)+ans)>0)
					ans=ans+S.charAt(i);
				else
					ans=S.charAt(i)+ans;
			}
			System.out.println("Case #"+cn+": "+ans); 
		}
	}

}
