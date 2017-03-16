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
		for(int X=0;X<cases;X++){
			pw.print("Case #"+(X+1)+": ");
			/**************************************/

			int r=s.nextInt();
			int t=s.nextInt();
			int ret=0;
			while(true){
				if(2*r+1>t){
					pw.println(ret);
					break;
				}else{
					t-=2*r+1;
					r+=2;
					ret++;
				}
			}
			
			
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
