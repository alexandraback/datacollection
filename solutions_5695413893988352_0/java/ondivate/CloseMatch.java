import java.util.LinkedList;
import java.util.Scanner;

public class CloseMatch {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		for(int cn=1; cn<=T;cn++){
			String C=sc.next();
			String J=sc.next();
			
			l=C.length();
			posc=new LinkedList[l];
			posj=new LinkedList[l];
			for(int i=0;i<l;i++){
				posc[i]=new LinkedList<Integer>();
				posj[i]=new LinkedList<Integer>();
			}
			for(int i=0;i<l;i++){
				if(C.charAt(i)=='?'){
					if(J.charAt(i)=='?'){
						posc[i].add(0);
						posc[i].add(9);
					}
					else{
						int a=J.charAt(i)-'0';
						posc[i].add(a);
						posc[i].add((a+1)%10);
						posc[i].add((a+9)%10);
						posj[i].add(0);
					}
				}
				else{
					posc[i].add(C.charAt(i)-'0');
				}
				if(J.charAt(i)=='?'){
					if(C.charAt(i)=='?'){
						posj[i].add(0);
						posj[i].add(9);
					}
					else{
						int a=C.charAt(i)-'0';
						posj[i].add(a);
						posj[i].add((a+1)%10);
						posj[i].add((a+9)%10);
						posj[i].add(0);
					}
				}
				else{
					posj[i].add(J.charAt(i)-'0');
				}
			}
			init();
			solve("","",0);
			
			
			
			
			System.out.print("Case #"+cn+": "+c+" "+j); 
			System.out.println();
		}
	}
	static int l;

	static LinkedList<Integer> posc[];
	static LinkedList<Integer> posj[];
	
	static long c;
	static long j;
	static void init(){
		String C="";
		String J="";
		for(int i=0;i<l;i++){
			C=C+posc[i].getFirst();
			J=J+posj[i].getFirst();
		}
//		System.out.println(C);
//		System.out.println(J);
		c=Long.parseLong(C);
		j=Long.parseLong(J);
	}
	static void solve(String sa, String sb, int i){
		if(i==l){
			long tc=Long.parseLong(sa);
			long tj=Long.parseLong(sb);
			if(Math.abs(c-j)>Math.abs(tc-tj)){
				c=tc;
				j=tj;
			}
			else if(Math.abs(c-j)==Math.abs(tc-tj)&&c>tc){
				c=tc;
				j=tj;
			}
			else if(Math.abs(c-j)==Math.abs(tc-tj)&&c==tc&&j>tj){
				c=tc;
				j=tj;
			}
			return;
		}
		for(int a:posc[i]){
			for(int b:posj[i]){
				solve(sa+a,sb+b,i+1);
			}
		}
		return;
	}
	
}
