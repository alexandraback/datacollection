import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.*;

/*
public class FizzBuzz{	public FizzBuzz(){for(int a=1;a<=100;a++){if(a%3==0&&a%5!=0)System.out.println("Fizz");else if(a%3==0&&a%5!=0)System.out.println("Buzz");else if(a%3==0&&a%5==0)System.out.println("FizzBuzz");else System.out.println(a);}}public static void main(String[]args){FizzBuzz f=new FizzBuzz();}}

 */

public class F{
	
	static int[]  typen;
	static int[]  typem;
	static long[] sizen;
	static long[] sizem;
	
	static int  li,ri;
	static long lt,rt;
	
	static long smallcase(){
		if(li>=typen.length||ri>=typem.length){
			return 0;
		}
		
		long tk  = take();
		long drop = drop();
		//System.out.println("Li: "+li+ " Ri: " + ri + " Tk: " + tk + " drop: " + drop);
		return Math.max(tk, drop);
	}
	
	
  private static long drop() {
	  long lttemp=lt;
	  li++;lt=0;
	  long out = smallcase();
	  li--;lt=lttemp;
	  return out;
  }


private static long take() {
		int litemp=li,ritemp = ri;long rttemp=rt,lttemp=lt;
		long out = 0;
		while(true){
			if(ri>=typem.length||li>=typen.length){
				break;
			}
			
			if(typem[ri]!=typen[li]){
				ri++;
				rt=0;
				continue;
			}
			long tak = Math.min(sizen[li]-lt, sizem[ri]-rt);
			lt += tak;
			rt += tak;
			if(lt==sizen[li]){
				li++;lt=0;
			}
			if(rt==sizem[ri]){
				ri++;rt=0;
			}
			
			out = smallcase()+tak;
			li=litemp;ri=ritemp;rt=rttemp;lt=lttemp;
			return out;
		}
		li=litemp;ri=ritemp;rt=rttemp;lt=lttemp;
		return out;
	}


public static void main(String[] arg0) throws FileNotFoundException{
    System.setOut(new PrintStream(new File("output.txt")));
	Scanner sc = new Scanner(new File("jinput.txt"));
    int nocases = sc.nextInt();
    cases: for(int cse = 1;cse<=nocases;cse++){
    	int n=sc.nextInt(),m=sc.nextInt();
    	typen = new int [n];
    	typem = new int [m];
    	sizen = new long[n];
    	sizem = new long[m];
    	for(int i=0;i<n;i++){
    		sizen[i]=sc.nextLong();
    		typen[i]=sc.nextInt();
    	}
    	for(int i=0;i<m;i++){
    		sizem[i]=sc.nextLong();
    		typem[i]=sc.nextInt();
    	}
    	
    	System.out.println("Case #"+cse+": "+smallcase());
    }
  }
}