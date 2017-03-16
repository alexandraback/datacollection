import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Lastword {
	public static char[] findlastword(String s)
	{
		int l=s.length();
		char[] a= new char[l];
		char[] amax= new char[l];
		amax[0]=s.charAt(0);
		char max=s.charAt(0);
		for(int k=1;k<l;k++)
		{
			if(amax[k-1]<s.charAt(k))
			{
				amax[k]=s.charAt(k);
				max=s.charAt(k);
			}
			else
				amax[k]=amax[k-1];
		}
		int i=0;
		int j=s.length()-1;
		for(int k=l-1;k>0;k--)
		{
			if(s.charAt(k)!=max)
			{
				a[j]=s.charAt(k);
				j--;
				max=amax[k-1];
			}
			else
			{
				a[i]=s.charAt(k);
				i++;
				max=amax[k-1];
			}
		}
		a[i]=s.charAt(0);
		return a;
	}
	 public static void main(String args[]) throws IOException {
		    Scanner scanner = new Scanner(new File("A-large.in"));
			//int [] tall = new int [100];
			int total =Integer.parseInt( scanner.nextLine());
			System.out.println(total);
			FileWriter fw = new FileWriter("out.txt");
			for(int i=0;i<total;i++){	
			   String e = scanner.nextLine();
			   char[] ans=findlastword(e);
			   fw.write("Case #"+(i+1)+": ");
			   int l=ans.length;
			   for(int j=0;j<l;j++){
			   fw.write(ans[j]);	
			   }
			   fw.write("\n");
			}
	        fw.close();
	 }
}
