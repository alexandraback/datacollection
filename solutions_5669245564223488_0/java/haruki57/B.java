package googleCodeJam2014r1c;

import java.util.Scanner;
import java.util.Stack;

public class B {

	static int N;
	static String[] strs;
	static S[] s;
	static Stack<String>stack;
	static int MOD = 1000000007;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		L:for(int t=1;t<=T;t++){
			System.out.print("Case #"+t+": ");
			N=sc.nextInt();
			stack=new Stack<String>();
			strs = new String[N];
			s=new S[N];
			boolean f = false;
			for(int i=0;i<N;i++){
				strs[i]=sc.next();
				if(isValid(strs[i])==false){
					f=true;
				}
				s[i]=new S(strs[i]);
			}
			if(f){
				System.out.println(0);
				continue L;
			}
			System.out.println(perm(0,new boolean[N],0,(char)0));
		}
	}

	static int perm(int dep,boolean used[],int bit,char t){
//		System.out.println(dep+" "+Integer.toBinaryString(bit)+" "+t);
		int res = 0;
		if(dep==N){
			return 1;
		}
		for(int i=0;i<N;i++){
			if(used[i])continue;
			used[i]=true;
			
			int ibit= s[i].bit;
			if(s[i].h==t){
				int a = t-'a';
				ibit = ibit - (1<<a);
//				System.out.println(Integer.toBinaryString(ibit));
			}
			if((bit&ibit)>0){
				used[i]=false;
				continue;
			}
			ibit=bit|ibit;
			res =  ((res + perm(dep+1,used,ibit,s[i].t))%MOD);
			
			used[i]=false;
		}
		return res;
	}
	/*
	static int perm(int dep,boolean used[]){
		int res = 0;
		if(dep==N){
			StringBuffer sb=new StringBuffer();
			for(String str:stack){
				sb.append(str);
			}
			if(isValid(sb.toString())){
				return 1;
			}
			else{
				return 0;
			}
		}
		for(int i=0;i<N;i++){
			if(used[i])continue;
			used[i]=true;
			stack.add(strs[i]);
			res += perm(dep+1,used)%MOD;
			stack.pop();
			used[i]=false;
		}
		return res;
	}
	*/
	static boolean isValid(String str){
		for(char c = 'a';c <= 'z';c++){
			for(int i=0;i<str.length();i++){
				if(str.charAt(i)==c){
					while(i<str.length()){
						if(str.charAt(i)!=c){
							break;
						}
						i++;
					}
					while(i<str.length()){
						if(str.charAt(i)==c){
							return false;
						}
						i++;
					}
				}
				
			}
		}
		return true;
	}
	static class S{
		char h,t;
		int bit;
		S(String s){
			h=s.charAt(0);
			t=s.charAt(s.length()-1);
			for(int i=0;i<s.length();i++){
				int c = s.charAt(i)-'a';
				bit |= (1<<c);
			}
		}
		public String toString(){
			return h+" "+t+" "+bit;
		}
		
	}
}
