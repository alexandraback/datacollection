import java.util.*;
import java.io.*;
public class A {
	
	/**************************************/	
	void run(String inputfile){
	try{
		Scanner s;
		File file=new File("output.txt");
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(file)));
		if(inputfile.equals("test")) s=new Scanner(System.in);
		else s=new Scanner(new FileInputStream(new File(inputfile)));
		int cases=s.nextInt();
top:		for(int X=0;X<cases;X++){
			pw.print("Case #"+(X+1)+": ");
			/**************************************/
			int a=s.nextInt();
			int n=s.nextInt();
			int[] motes=new int[n];
			int[] eats=new int[n];
			for(int i=0;i<n;i++){
				motes[i]=s.nextInt();
			}
			Arrays.sort(motes);
			int ind=0;
			while(ind<n){
				if(a>motes[ind]){
					a+=motes[ind];
					ind++;
				}else{
					if(a-1==0){
						pw.println(n);
						continue top;
					}
					a+=a-1;
					eats[ind]++;
				}
			}
			int total=0;
			for(int i=0;i<n;i++){
				total+=eats[i];
			}
			int ret=total;
			for(int i=n-1;i>=0;i--){
				total=total-eats[i]+1;
				if(total<ret) ret=total; 
			}
			pw.println(ret);
			/**************************************/
		}
		pw.close();
	}catch(IOException e){
		System.out.println(e);
		System.exit(0);
	}}
	/**************************************/
	public static void main(String[] args){
		
		new A().run(args[0]);
	}
}
