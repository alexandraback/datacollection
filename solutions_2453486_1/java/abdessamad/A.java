import java.io.File;import java.io.FileOutputStream;import java.io.FileReader;
import java.io.IOException;import java.io.PrintStream;import java.io.PrintWriter;
import java.util.ArrayList;import java.util.Arrays;import java.util.Scanner;

public class A {
    
	public static String s1; public static String s2; public static String s3; public static String s4;
    public static void main(String[] arg)throws IOException{
    	Scanner in=new Scanner(new File("A.in"));
    	PrintStream o=System.out;
    	int N=Integer.parseInt(in.nextLine()); 
    	for ( int i=1; i<=N ; i++){
    		if(i!=1)in.nextLine();
    		s1=in.nextLine(); s2=in.nextLine(); s3=in.nextLine(); s4=in.nextLine();
    		if(testX()){
    			o.println("Case #"+i+": X won");
    		}
    		else if(testO()){
    			o.println("Case #"+i+": O won");
    		}
    		else{
    			if(dotexist()){
    				o.println("Case #"+i+": Game has not completed");
    			}
    			else{
    				o.println("Case #"+i+": Draw");
    			}
    		}
    		
    	}
    }
    
    private static boolean dotexist() {
		for(int i=0; i<4; i++) if(s1.charAt(i)=='.') return true;
		for(int i=0; i<4; i++) if(s2.charAt(i)=='.') return true;
		for(int i=0; i<4; i++) if(s3.charAt(i)=='.') return true;
		for(int i=0; i<4; i++) if(s4.charAt(i)=='.') return true;
		return false;
	}

	private static boolean testO() {
		if(LineO(f(1,2,3,4))) return true;
		if(LineO(f(5,6,7,8))) return true;
		if(LineO(f(9,10,11,12))) return true;
		if(LineO(f(13,14,15,16))) return true;
		if(LineO(f(1,5,9,13))) return true;
		if(LineO(f(2,6,10,14))) return true;
		if(LineO(f(3,7,11,15))) return true;
		if(LineO(f(4,8,12,16))) return true;
		if(LineO(f(1,6,11,16))) return true;
		if(LineO(f(4,7,10,13))) return true;
		return false;
	}

	private static boolean testX() {
		if(LineX(f(1,2,3,4))) return true;
		if(LineX(f(5,6,7,8))) return true;
		if(LineX(f(9,10,11,12))) return true;
		if(LineX(f(13,14,15,16))) return true;
		if(LineX(f(1,5,9,13))) return true;
		if(LineX(f(2,6,10,14))) return true;
		if(LineX(f(3,7,11,15))) return true;
		if(LineX(f(4,8,12,16))) return true;
		if(LineX(f(1,6,11,16))) return true;
		if(LineX(f(4,7,10,13))) return true;
		return false;
	}

	private static boolean LineX(String f) {
		char x=f.charAt(0);char y=f.charAt(1);char z=f.charAt(2);char w=f.charAt(3);
		if(   ( x=='X' | x=='T') & ( y=='X' | y=='T') & ( z=='X' | z=='T') & ( w=='X' | w=='T') ) 
			return true;
		return false;
	}
	private static boolean LineO(String f) {
		char x=f.charAt(0);char y=f.charAt(1);char z=f.charAt(2);char w=f.charAt(3);
		if(   ( x=='O' | x=='T') & ( y=='O' | y=='T') & ( z=='O' | z=='T') & ( w=='O' | w=='T') ) 
			return true;
		return false;
	}

	public static char  t(int i){
    	if(i<=4) return s1.charAt(i-1);
    	if(i<=8) return s2.charAt(i-5);
    	if(i<=12) return s3.charAt(i-9);
    	return s4.charAt(i-13);
    }
    public static String f(int a, int b, int c, int d){
    	return ""+t(a)+t(b)+t(c)+t(d);
    }
    
    
}
