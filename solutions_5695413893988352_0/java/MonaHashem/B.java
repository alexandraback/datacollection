import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;


public class B {
	static int len;
	static String s;
	static ArrayList<Integer> ar;
	static ArrayList<Integer> ar2;
	public static void num(int ind, int n){
		if(ind==len){
			ar.add(n);
			//System.out.println(n);
			return;
		}
		
		
		n*=10;
		char c= s.charAt(ind);
		if(c=='?')
			for(int i=0; i<10; i++)
				num(ind+1,n+i);
		else
			num(ind+1,n+(c-'0'));
	
	}
	
	public static void num2(int ind, int n){
		//System.out.println("hey");
		if(ind==len){
			ar2.add(n);
			return;
		}
		
		
		n*=10;
		char c= s.charAt(ind);
		if(c=='?')
			for(int i=0; i<10; i++)
				num2(ind+1,n+i);
		else
			num2(ind+1,n+(c-'0'));
	
	}
	
	
	public static void main(String[] args) throws IOException {
		BufferedReader bf= new BufferedReader(new FileReader("B-small-attempt0.in"));
		int t= Integer.parseInt(bf.readLine());
		PrintWriter out= new PrintWriter(new FileWriter("SmallB.txt"));
		for(int c=1; c<=t; c++){
			StringTokenizer st= new StringTokenizer(bf.readLine());
			String s1= st.nextToken();
			String s2= st.nextToken();
			len= s1.length();
			s=s1;
			ar= new ArrayList<Integer>();
			num(0,0);
			Collections.shuffle(ar);
			Collections.sort(ar);
			ar2= new ArrayList<Integer>();
			s=s2;
			num2(0,0);
			//System.out.println(ar2.size());
			Collections.shuffle(ar2);
			Collections.sort(ar2);
			int min=999999;
			int n1=0;
			int n2=0;
			int last=0;
			int len2= ar2.size();
			for(int x:ar){
				for(int i=0; i<len2; i++){
					int y=ar2.get(i);
//					if(y==23)
//						System.out.println("yes"+ x);
					if(y>x){
						if(y-x<min){
							min=y-x;
							n1=x;
							n2=y;
							//System.out.println(x+" "+y);
						}
						else{
							last=i;
							break;
						}
					}
					else{
						if(x-y<min){
							min=x-y;
							n1=x;
							n2=y;
							//System.out.println(x+" "+y);
						}
					}
						
				}
			}
			//System.out.println(min);
			String out1=n1+"";
			String out2= n2+"";
			if (len>1 && n1<10)
				out1="0"+n1;
			if(len>1 && n2<10)
				out2="0"+n2;
			if(len==3 && n1<100)
				out1="0"+out1;
			if(len==3 && n2<100)
				out2="0"+out2;
			out.printf("Case #%d: "+out1+" " +out2+"\n",c);
			
		}
		out.flush();
		out.close();
		
	}

}
