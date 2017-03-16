import java.util.*;
import java.io.*;
public class B {
	
	long max;
	int[] v;
	int e;
	int r;
	int n;
	long search(int ce,int ind){
		long ret=0;
		if(ind==n) return 0L;
		for(int i=0;i<=ce;i++){
			long tmp=search(Math.min(ce-i+r,e),ind+1)+i*v[ind];
			if(tmp>ret){
				ret=tmp;
			}
		}
		return ret;
	}
	/**************************************/
	void run(String inputfile){
	try{
		Scanner s;
		File file=new File("output.txt");
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(file)));
		if(inputfile.equals("test")) s=new Scanner(System.in);
		else s=new Scanner(new FileInputStream(new File(inputfile)));
		int cases=s.nextInt();
		for(int X=0;X<cases;X++){
			pw.print("Case #"+(X+1)+": ");
	/**************************************/
			max=0L;
			e=s.nextInt();
			r=s.nextInt();
			n=s.nextInt();
			v=new int[n];
			for(int i=0;i<n;i++) v[i]=s.nextInt();
			
			pw.println(search(e,0));
			
	/**************************************/
		}
		pw.close();
	}catch(IOException e){
		System.out.println(e);
		System.exit(0);
	}}
	/**************************************/
	public static void main(String[] args){
		
		new B().run(args[0]);
	}
}
