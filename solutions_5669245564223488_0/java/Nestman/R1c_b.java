package r1c_b;

import java.io.*;
import java.util.*;

public class R1c_b {
	
	static String s2;
	static String[] s=new String[102];
	static String out="";
	static boolean[] f=new boolean[28];
	static boolean[] u=new boolean[101];
	static int ans,n;
	public static void main(String[] args) throws FileNotFoundException, IOException{
		// TODO Auto-generated method stubScanner 
	Scanner sc=new Scanner(new BufferedReader(new InputStreamReader (new FileInputStream("CodeJam2014/r1c_b/B-small-attempt0 (1).in"))));
	//	Scanner sc=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter ou=new PrintWriter(new FileWriter("CodeJam2014/r1c_b/testb.out"));
		int res,rep,i,j,t,c;
		
		int[] le=new int[28];
		int[][] te=new int[102][28];
		boolean vis;
		int[][] g=new int[102][102];
		char ch;
		res=sc.nextInt();
		s2=sc.nextLine();
		for(rep=1;rep<=res;rep++){
			n=sc.nextInt();
			s2=sc.nextLine();
			s2=sc.nextLine();
			s=s2.split(" ");
	//		for(i=0;i<n;i++) System.out.println(s[i]);
			Arrays.fill(u,true);
			out=""; ans=0;
			search(0);
			System.out.println("Case #"+rep+": "+ans);
			ou.println("Case #"+rep+": "+ans);
			ou.close();
/*			Arrays.fill(le,0);
			vis=true;
			for(i=0;i<n;i++){
				Arrays.fill(te[i],0);
				for(j=0;j<s[i].length();j++){
					ch=s[i].charAt(j);
					t=(int)ch-(int)'a';
					le[t]++;
					if ((te[i][t]!=0)&&(ch!=s[i].charAt(j-1))) {
						vis=false;
						break;
					}
					te[i][t]++;
				}
				if (!vis) break;
			}
			
			for(i=0;i<=n;i++) Arrays.fill(g[i],0);
			for(i=0;i<n;i++){
				ch=s[i].charAt(0);
				t=(int)ch-(int)'a';
				if (le[t]==te[i][t]){
					for(j=0;j<n;j++)
						g[i][j]=j;
					g[i][101]=n;
				}
				else{
					c=-1;
					for(j=0;j<n;j++)
						if (s[j].charAt(s[j].length()-1)==ch){
							c++;
							g[i][c]=j;
							
						}
					g[i][101]=c;
				}
			}
			System.out.println(n);
			for(i=0;i<n;i++) System.out.println(s[i]);
			for(i=0;i<n;i++){
				for(j=0;j<g[i][101];j++) System.out.print(g[i][j]);
				System.out.println(i);
			}*/
		}
	}
	public static void search(int depth){
		int i,j,t;
		char ch;
		String str;
		boolean vis;
		if (depth==n) {
			Arrays.fill(f,false);
//			System.out.println(out);
			vis=true;
			for(i=0;i<out.length();i++){
				ch=out.charAt(i);
				t=(int)ch-(int)'a';
				if (!f[t]) f[t]=true;
				else if (ch!=out.charAt(i-1)) {vis=false; break;}
			}
			if (vis) ans++;
		}
//		System.out.println(out);
		for(i=0;i<n;i++)
			if ((u[i])){
				u[i]=false;
				str=out;
				out+=s[i];
				search(depth+1);
				out=str;
				u[i]=true;
			}
	}
}
