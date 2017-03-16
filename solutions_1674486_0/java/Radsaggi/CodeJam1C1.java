import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class CodeJam1C1 {
	
	static BufferedReader br;
	static PrintWriter pw;
	
	static int n;
	static ArrayList<Clazz> heads,claz;
	
	public static void main(String[] args)throws Exception{
		br=new BufferedReader (new FileReader ("in.txt"));
		pw=new PrintWriter (new FileWriter("out.txt"));
		
		int t=Integer.parseInt( br.readLine() );
		for (int i=1;i<=t;i++){
			input();
			String str=work()?"Yes":"No";
			pw.printf ("Case #%d: %s",i,str);
			
			pw.println();
		}
		
		pw.close();
	}
	
	public static void input()throws Exception{
		n=Integer.parseInt(br.readLine());
		
		Clazz[] cl=new Clazz[n];
		for (int i=0;i<n;i++){
			cl[i]=new Clazz(i+1);
			cl[i].children=new ArrayList<>();
		}
		
		heads=new ArrayList<>();
		for (int i=0;i<n;i++){
			StringTokenizer data=new StringTokenizer(br.readLine());
			int c=Integer.parseInt(data.nextToken());
			cl[i].n=c;
			for (int j=0;j<c;j++){				
				int idx=Integer.parseInt(data.nextToken());
				idx-=1;
				cl[idx].children.add(cl[i]);
			}
			if (c==0){
				heads.add(cl[i]);
			}
		}
		claz=new ArrayList<>();
		Collections.addAll(claz,cl);
	}
	
	public static boolean work(){
		for (Clazz head:heads){
			StringBuffer sbuf=new StringBuffer (n*5);
			sbuf.append(head.id+",");
			
			if (addString(head,sbuf))
				return true;
		}
		
		return false;
	}
	
	public static boolean addString(Clazz cl, StringBuffer sb){
		
		for (Clazz c:cl.children){
			if (sb.indexOf(c.id)!=-1){
				return true;
			}
				
			sb.append(c.id+",");
			if (addString(c,sb))
				return true;
		}
		
		
		return false;
	}
	
	private static class Clazz {
		public int n;
		public String id;
		public ArrayList<Clazz> children;
		
		public Clazz(int idx){
			id=" "+Integer.toString(idx)+" ";
		}
		
	
		public String toString(){
			return "ID:"+id;
		}
	}
}