import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
public class qwe{
public static void main(String [] s) throws FileNotFoundException
	{ 
File f = new File("file.txt");
Scanner f1= new Scanner(f);

int n = f1.nextInt();


for(int i = 1;i<=n;++i)
	
{
	int n1 = f1.nextInt();
	
	
	int n2 = f1.nextInt();
	
	System.out.println("Case #"+i+": "+eval(n1,n2));

}
}

static String eval(int x,int y){
	
String s = "";

 int min ;
 
 if(x>y){min = Math.abs(y);} else {min = Math.abs(x);}
 
 for(int i = 1;i<=min;++i)
	 
 {
	 if(x>0 && y>0){ s =s +"WESN";--x;--y;}
	 if(x>0 && y<0){s =s +"WENS";--x;++y;}
	 if(x<0 && y<0){s =s +"EWNS";++x;++y;}
	 if(x<0 && y>0){s =s +"EWSN";++x;--y;}
	 
 }
 
 
if(x==y) {return s;}

if(x == 0) {for(int i = 1;i<=Math.abs(y);++i){
	if(y<0){s =s +"NS";}
	if(y>0){s =s +"SN";}
	
	
}}
 
if(y == 0) {for(int i = 1;i<=Math.abs(x);++i){
	if(x<0){s =s +"EW";}
	if(x>0){s =s +"WE";}
	
	
}}
	


return s;	
	}


}