import java.util.*;
import java.io.*;
public class C {

	
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
			System.out.println(X);
			long a=s.nextLong();
			long b=s.nextLong();
			long sqa=(long)(Math.sqrt((double)a));
			long sqb=(long)(Math.sqrt((double)b));
			if(sqa*sqa!=a) sqa++;
			long ans=0;
			while(sqa<=sqb){
				if(isP(Long.toString(sqa))){
					long powed=sqa*sqa;
					if(isP(Long.toString(powed))){
//						System.out.println(sqa+":"+powed);
						ans++;
					}
				}
				sqa++;
			}
			pw.println(ans);
			
			
	/**************************************/
		}
		pw.close();
	}catch(IOException e){
		System.out.println(e);
		System.exit(0);
	}}
	/**************************************/

	
	boolean isP(String tg){
		int a=0;
		int b=tg.length()-1;
		while(a<b){
			if(tg.charAt(a)!=tg.charAt(b)) return false;
			a++;
			b--;
		}
		return true;
	}
	
	
	public static void main(String[] args){
		
		new C().run(args[0]);
	}
}
