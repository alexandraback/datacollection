import java.util.*;
public class a {
	public static void main(String[] args){
		Scanner br = new Scanner(System.in);
		int t = br.nextInt();
		for(int c = 1;c<=t;c++){
			String s = br.next();
			
			String res = ""+s.charAt(0);
			for(int i = 1;i<s.length();i++){
				if(s.charAt(i) > res.charAt(0)){
					res = s.charAt(i)+res;
				}
				else if(s.charAt(i) < res.charAt(0)){
					res = res+s.charAt(i);
				}
				else{
					char cur = s.charAt(i);
					String f1 = cur+res;
					String f2 = res+cur;
					if(f1.compareTo(f2) >= 0){
						res = f1;
					}
					else{
						res = f2;
					}
				}
			}
			System.out.println("Case #"+c+": "+res);
		}
	}
}
