package mine;

import java.io.*;
import java.util.*;

public class Mine {
	static char[][] map=new char[52][52];
	public static void main(String[] args) throws FileNotFoundException, IOException{
		// TODO Auto-generated method stubScanner 
	Scanner sc=new Scanner(new BufferedReader(new InputStreamReader (new FileInputStream("CodeJam2014/mine/C-small-attempt3.in"))));
		//Scanner sc=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter ou=new PrintWriter(new FileWriter("CodeJam2014/mine/mine.out"));
		int res,rep,i,j,r,c,m;
		String out="";
		
		res=sc.nextInt();
		for(rep=1;rep<=res;rep++){
			
			r=sc.nextInt(); c=sc.nextInt(); m=sc.nextInt();
			out+=out.format("Case #%d:", rep);
			for(i=1;i<=r;i++) Arrays.fill(map[i],'.');
			if (seek(r,c,m)) {
				for(i=1;i<=r;i++){
					out+="\n";
					for(j=1;j<=c;j++) out+=map[i][j];
				}
			}
			else out+="\nImpossible";
			if (rep!=res) out+="\n";
		}
		ou.print(out);
		ou.close();
	}
	public static boolean seek(int r,int c,int m){
		int lo,sh,i,j;
		boolean vis,bool;
		if (r<c) {vis=true; lo=c; sh=r;}
		else {vis=false; lo=r; sh=c;}
		if (sh==1) {
			if (vis) for (i=c-m+1;i<=c;i++) map[1][i]='*';
			else for(i=r-m+1;i<=r;i++) map[i][1]='*';
			map[1][1]='c'; //System.out.println(r+" "+c);
			return true;
		}
		if (sh==2){
			if (m==r*c-1) {
				for(i=1;i<=r;i++)
					for(j=1;j<=c;j++) map[i][j]='*';
			map[1][1]='c';
			return true;
			}
			if ((m%2==1)||(r*c-m==2)) return false;
			m=m/2;
			if (vis) for(j=c-m+1;j<=c;j++) {map[1][j]='*'; map[2][j]='*';}
			else for(i=r-m+1;i<=r;i++) {map[i][1]='*'; map[i][2]='*';}
			map[1][1]='c'; //System.out.println(r+" "+c+" "+m);
			return true;
			
		}
		if (m<=lo){
			if (m==lo) {
				if (vis) for(j=1;j<=m;j++) map[r][j]='*';
				else for(i=1;i<=m;i++) map[i][c]='*';
				map[1][1]='c';
				return true;
			}
			if (m<lo-1){
				if (vis) for(j=c-m+1;j<=c;j++) map[r][j]='*';
				else for(i=r-m+1;i<=r;i++) map[i][c]='*';
				map[1][1]='c';
				return true;
			}
			if (lo==sh){
				if (sh==3) return false;
				for(j=3;j<=c;j++) map[r][j]='*';
				map[r-1][c]='*'; map[1][1]='c';
				return true;
			}
			
		}
		bool=false;
		if (m>lo) {
			if (vis){ 
				bool=seek(r-1,c,m-c);
				if (bool) {for(j=1;j<=c;j++) map[r][j]='*';  return bool;}
				
			}
			else {
				bool=seek(r,c-1,m-r);
				if (bool) {for(i=1;i<=r;i++) map[i][c]='*'; return bool;}
			}
		}
		if (m>=sh) {
			if (vis) {
				bool=seek(r,c-1,m-r);
				if (bool) {for(i=1;i<=r;i++) map[i][c]='*'; return bool;}
			}
			else {
				bool=seek(r-1,c,m-c);
				if (bool) {for(j=1;j<=c;j++) map[r][j]='*'; return bool;}
			}
		}
		return bool;
	}
}