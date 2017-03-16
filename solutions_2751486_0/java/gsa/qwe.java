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
	String s1 = f1.next();
	
	
	int n1 = f1.nextInt();
	
	System.out.println("Case #"+i+": "+eval(s1,n1));

}
}

static int eval(String s,int n){
	
	 int ans =0;
	char[] c = s.toCharArray();
	
	
	
	int k = c.length;
	char [] j = new char[k];
		for(int i = 0;i<c.length;++i){
		if((c[i]=='a')||(c[i]=='e')||(c[i]=='i')||(c[i]=='o')||(c[i]=='u')){j[i] = 't';} 
		else {j[i]= 'f';}
		}
String s2 =	new String(j);
	char [] c1 = new char[n];
for(int i = 0;i<n;++i){c1[i] = 'f';}
String s3 = new String(c1);


	for(int i = 0;i<=k;++i){
		for(int j1 = i;j1<=k;++j1){
			

			String s4 = s2.substring(i,j1);	
			
if(s4.contains(s3)){++ans;}			
			
		}
		
	}

return ans;
}


}