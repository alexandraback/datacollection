package G2015;



import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashSet;

public class Q3 {

	public static void main(String[] args) throws IOException {
		String path="I:\\google\\2015\\q1\\C-small-attempt0.in";
		String path1="I:\\google\\2015\\q1\\C-small-attempt0.out";
		readData(path);
		writeData(path1);
		
		
	}
	
	
	
	private static void writeData(String path) throws IOException {
		
		OutputStreamWriter fr = new OutputStreamWriter(new FileOutputStream(path));
		BufferedWriter br = new BufferedWriter(fr);
		for (int i=1;i<=ans.length;i++){
			String s="";
			s="Case #"+Integer.toString(i)+": "+ans[i-1];
			br.write(s);
			br.newLine();
		}
		br.close();
		
	}



	


	static String[] ans;
	private static void readData(String path) throws IOException {
		InputStreamReader fr = new InputStreamReader(new FileInputStream(path));
		BufferedReader br = new BufferedReader(fr);
		String rec = br.readLine();
		ans=new String[Integer.parseInt(rec)];
		int k=0;
		try {
			while ((rec = br.readLine()) != null) {
				String[] temp=rec.split(" ");
				int l=Integer.parseInt(temp[0]);
				long x=Long.parseLong(temp[1]);
				
				rec = br.readLine();
				
				solution(l,x,rec,k++);
			}
		}catch(Exception e){
			
		}
	}



	private static void solution(int l, long x, String rec, int k) {
		if (x>11){
			x=x%4+12;
			
		}
		String qqq=rec;
		rec="";
		for (int i=0;i<x;i++){
			rec=rec+qqq;
		}
		l=rec.length();
		
		
		
		
		
		HashSet<String> mid=new HashSet<String>();
		HashSet<String> side=new HashSet<String>();
		//HashSet<String> all=new HashSet<String>();
		String pre="1";
		side.add(pre);
		String cur="";
		for (int i=0;i<l;i++){
			cur=next(pre,""+rec.charAt(i));
			for (String s:side){
				String last=s+","+rev(cur,s);
				mid.add(last);
			}
			side.add(cur);
			pre=cur;
		}
		
		if (k==1){
			System.out.println(cur);
		}
		
		
		for (String s:mid){
			
			String[] temp=s.split(",");
			String a=temp[0];
			String b=temp[1];
			
			String c=rev(cur,next(a,b));
			
			if (k==1){
				System.out.println(a+" "+b+" "+c);
			}
			
			
			
			if (a.equals("i") && b.equals("j") && c.equals("k")){
				ans[k]="YES";
				return;
			}
						
		}
		ans[k]="NO";
	}
	private static String next(String cur, String a) {
		boolean ne=false;
		if (cur.length()==2)ne=!ne;
		if (a.length()==2)ne=!ne;
		
		String aaa=next1(cur,a);
		if (ne){
			if (aaa.length()==2){
				return aaa.substring(1,2);
			}else{
				return "-"+aaa;
			}
		}
		return aaa;
		
	}
	private static String next1(String cur, String a) {
		if (cur.length()==2)cur=cur.substring(1,2);
		if (a.length()==2)a=a.substring(1,2);
		
		if (cur.equals("1")){
			return a;
		}else if (a.equals("1")){
			return cur;
		}else if (cur.equals("i")){
			if (a.equals("j")){
				return "k";
			}else if (a.equals("i")){
				return "-1";
			}else if (a.equals("k")){
				return "-j";
			}
		}else if (cur.equals("j")){
			if (a.equals("j")){
				return "-1";
			}else if (a.equals("i")){
				return "-k";
			}else if (a.equals("k")){
				return "i";
			}
		}else if (cur.equals("k")){
			if (a.equals("j")){
				return "-i";
			}else if (a.equals("i")){
				return "j";
			}else if (a.equals("k")){
				return "-1";
			}
		}
		return "1";
		
	}



	private static String rev(String cur, String a) {
		boolean ne=false;
		if (cur.length()==2)ne=!ne;
		if (a.length()==2)ne=!ne;
		
		String aaa=rev1(cur,a);
		if (ne){
			if (aaa.length()==2){
				return aaa.substring(1,2);
			}else{
				return "-"+aaa;
			}
		}
		return aaa;
	}



	private static String rev1(String cur, String a) {
		if (cur.length()==2)cur=cur.substring(1,2);
		if (a.length()==2)a=a.substring(1,2);
		
		if (a.equals("1")){
			return cur;
		}else if (cur.equals("i")){
			if (a.equals("j")){
				return "k";
			}else if (a.equals("i")){
				return "1";
			}else if (a.equals("k")){
				return "-j";
			}
		}else if (cur.equals("j")){
			if (a.equals("j")){
				return "1";
			}else if (a.equals("i")){
				return "-k";
			}else if (a.equals("k")){
				return "i";
			}
		}else if (cur.equals("k")){
			if (a.equals("j")){
				return "-i";
			}else if (a.equals("i")){
				return "j";
			}else if (a.equals("k")){
				return "1";
			}
		}else{
			if (a.equals("j")){
				return "-j";
			}else if (a.equals("i")){
				return "-i";
			}else if (a.equals("k")){
				return "-k";
			}
		}
		return "1";
	}
	
	
}
