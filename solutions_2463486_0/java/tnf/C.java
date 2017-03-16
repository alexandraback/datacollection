import java.util.*;

class C{

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		sc.nextLine();		
		for(int kase = 1; kase<=T; kase++){
			int A = sc.nextInt();
			int B = sc.nextInt();
			sc.nextLine();
			int count = 0;
			for(int i = A; i<=B; i++){
				if(isPal(i)){
					int j = sqrt(i);
					if(j!=-1 && isPal(j)) count++;
				}
			}
			System.out.println("Case #"+kase+": "+count);
		}
	}

	static boolean isPal(int a){
		String s = ""+a;
		for(int i = 0; i<s.length()/2; i++)
			if(s.charAt(i)!=s.charAt(s.length()-i-1))return false;
		return true;
	}

	static int sqrt(int i){
		double d = Math.sqrt((double) i);
		int j = (int) d;
		if(j*j==i || (j+1)*(j+1)==i) return j;
		else return -1;
	}
	

}
