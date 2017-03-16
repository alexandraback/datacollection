import java.io.*;
import java.util.*;

public class A {
	public static void main (String[]args)throws IOException{
		BufferedReader x=new BufferedReader(new FileReader("Asmall3.in"));
		//BufferedReader x=new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Asmall3.out")));
		int t=Integer.parseInt(x.readLine());
		for (int cases=1; cases<=t; cases++){
			String s=x.readLine();
			if (s.length()==1){
				out.println("Case #"+cases+": "+s);
				continue;
			}
			long[]digits=new long[16];
			long add=19;
			digits[2]=10;
			digits[3]=29;
			for (int i=4; i<=15; i++){
				digits[i]=add+digits[i-1]+i%2+9*(long)Math.pow(10,i/2-1);
				add+=i%2+9*Math.pow(10,i/2-1);
			}
			long ans=digits[s.length()];
			for (int i=0; i<s.length()/2; i++){
				if (i==0){
					if (s.charAt(0)=='1'){
						ans+=(s.charAt(i)-'0')+(s.charAt(s.length()-1)-'0')-1;
					}else{
						if (s.charAt(s.length()-1)=='0'){
							ans+=(s.charAt(0)-'1')*Math.pow(10,s.length()-1);
						}else{
							ans+=(s.charAt(i)-'0')+(s.charAt(s.length()-1)-'0');
						}
					}
				}else{
					if (s.charAt(i)=='0'){
						ans+=(s.charAt(s.length()-1-i)-'0')*Math.pow(10,i);
					}else if(s.charAt(s.length()-1-i)=='0'){
						ans+=(s.charAt(i)-'0')*Math.pow(10,s.length()-1-i);
					}else{
					ans+=((s.charAt(i)-'0')+(s.charAt(s.length()-1-i)-'0'))*Math.pow(10,i)+1;
					}
				}
			}
			if (s.length()%2==1){
				ans+=(s.charAt(s.length()/2)-'0')*Math.pow(10,s.length()/2);
			}
			out.println("Case #"+cases+": "+ans);
		}
		out.close();
		System.exit(0);
	}
}