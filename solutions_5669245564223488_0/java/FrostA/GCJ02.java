import java.io.*;
import java.util.*;


public class GCJ02 {
	public static boolean[] used=new boolean[10];
	public static int ct;
	public static void main(String[] args) throws FileNotFoundException{
		Scanner s = new Scanner(new File("GCJ02.txt"));
		PrintStream out = new PrintStream(new File("GCJ02.out.txt"));
		int t=s.nextInt();
		String[] st=new String[10];
		for(int i=0;i<t;i++){
			out.print("Case #");
			out.print(i+1);
			out.print(": ");
			init();
			int n=s.nextInt();
			for(int j=0;j<n;j++){
				st[j]=reduce(s.next());
			}
			check(-1,n,st,0,"");
			out.println(ct);
		}
	}
	public static void init(){
		for(int i=0;i<10;i++){
			used[i]=false;
			ct=0;
		}
	}
	public static boolean valid(String str){
		Set<String> s = new HashSet<String>();
		s.clear();
		s.add(""+str.charAt(0));
		for(int i=1;i<str.length();i++){
			String ch=""+str.charAt(i);
			String chh=""+str.charAt(i-1);
			if(s.contains(ch))
				if(!ch.equals(chh))
					return false;
			s.add(ch);
		}
		return true;
	}
	public static void check(int pr,int n,String[] st,int num,String str){
		if(num==n){
			if(valid(str))
				ct++;
			return;
		}
		for(int i=0;i<n;i++){
			if(used[i])continue;
			used[i]=true;
			check(i,n,st,num+1,str+st[i]);
			used[i]=false;
		}
	}
	public static String reduce(String s){
		String r=""+s.charAt(0);
		for(int i=1;i<s.length();i++){
			if(s.charAt(i)!=s.charAt(i-1))
				r=r+s.charAt(i);
		}
		return r;
	}
}
