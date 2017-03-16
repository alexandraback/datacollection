import java.util.*;
public class a {
	public static void main(String[] Args){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int k =0;k<t;k++){
			String s = sc.next();
			int n = sc.nextInt();
			int[] vals = new int[s.length()+1];
			vals[0] = 0;
			for(int j=0;j<s.length();j++)
				if(isCon(s.charAt(j)))
					vals[j+1] = vals[j]+1;
				else
					vals[j+1] = 0;
			long ans = 0;
			int last = -1;
			for(int j =s.length()-n;j>=0;j--){
				if(vals[j+n]-vals[j]==n)
					last = j+n-1;
				if(last!=-1)
					ans+=(s.length()-last);
				
			}
			System.out.printf("Case #%d: %d%n",k+1,ans);
		}
	}
	public static boolean isCon(char i){
		return !(i=='a'||i=='e'||i=='u'||i=='i'||i=='o');
	}
}
