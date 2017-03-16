import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

public class A{

	static String s;
	static int n;
	
	public static void run(){	
		int T = nextInt();
		for(int i=1; i<=T; i++){
			//sc.nextLine();
			print("Case #"+i+": ");
			// Scan more
			s = sc.next();
			n = nextInt();
			// println(n);
			execute();
		}
	}
	
	public static void execute(){
		long num=0;
      int length = s.length();   

      // System.out.println("Substrings of \""+s+"\" are :-");
	int c,i;
	String sub;
      for( c = 0 ; c < length ; c++ )
      {
         for( i = 1 ; i <= length - c ; i++ )
         {
            sub = s.substring(c, c+i);
			int count =0;
			for(int j=0; j<sub.length(); j++){
				if(!isVowel(sub.charAt(j))){
					count++;
				}
				else{
					count = 0;
				}
				if(count ==n){
					num++;
					break;
				}
			}
            // System.out.println(sub);
			
         }
      }
	println(num);
	}

	public static boolean isVowel(char c){
		if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
			return true;
		else
			return false;
	}

	static PrintWriter pw;
	static Scanner sc;
	static boolean useFile = false;

	public static void main(String[] args)throws Exception {
		useFile = false;
		if(args.length>0){
			sc = new Scanner(new FileReader(args[0]));
		}
		else{
			sc = new Scanner(new FileReader("/Users/Puneet/docs/codejam/eclipse/1c/src/"+Thread.currentThread().getStackTrace()[1].getClassName()+"-prac.in"));
		}
		if(args.length>1){
			pw = new PrintWriter(new FileWriter(args[1]));
			useFile=true;
		}
		
        // ****************************
		// 			   RUN!
		// ****************************
		run();
		
		
		if(pw!=null){
			pw.flush();
        	pw.close();
		}
        sc.close();
	}
	
	static void println(String s){
		if(useFile==true){
			pw.println(s);
		}
		else{
			System.out.println(s);
		}
	}
	static void print(String s){
		if(useFile==true){
			pw.print(s);
		}
		else{
			System.out.print(s);
		}
	}
	static void println(int s){
		if(useFile==true){
			pw.println(s);
		}
		else{
			System.out.println(s);
		}
	}
	static void print(int s){
		if(useFile==true){
			pw.print(s);
		}
		else{
			System.out.print(s);
		}

	}
	static void println(long s){
		if(useFile==true){
			pw.println(s);
		}
		else{
			System.out.println(s);
		}
	}
	static void print(long s){
		if(useFile==true){
			pw.print(s);
		}
		else{
			System.out.print(s);
		}	
	}
	static int nextInt(){
		return sc.nextInt();
	}
	static long nextLong(){
		return sc.nextLong();
	}
	static String next(){
		return sc.next();
	}
}