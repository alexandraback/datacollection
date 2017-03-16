import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

public class ProblemB {
	 public static int total;
	 public static int t;
	 static String[] tokens;
	 static boolean[] used;
     public static void main(String[] args) throws IOException {
    	 Scanner in = new Scanner(new File("B-small-attempt0.in"));
    	 PrintStream out=new PrintStream("B-small-attempt0.out");
          
     	 //Scanner in = new Scanner(System.in);
     	 //PrintStream out=new PrintStream(System.out);
     	 
     	 //System.out.println(satisfy("abbbbccd"));
    	 while(in.hasNext()) {
        	 int n=in.nextInt();
        	 for (int z=1;z<=n;z++)
        	 {
        		 t=in.nextInt();
        		 in.nextLine();
        		 String s=in.nextLine();
        		 tokens=s.split(" ");
            	 used=new boolean[tokens.length];
        		 
        		 total=0;
        		 String temp=new String();
        		 search(0,temp);
        		 
        		 out.println("Case #"+z+": "+total);
            	
        	 }
         }   
	}
	private static void search(int step,String temp) {
		// TODO Auto-generated method stub
		if (!satisfy(temp)) return;
		
		if (step==t)
		{
			//System.out.println();
			total++;
			return;
		}
		else
		{
			for (int i=0;i<t;i++) if (!used[i])
			{
				String news=temp+tokens[i];
				used[i]=true;
				search(step+1,news);
				used[i]=false;
			}
		}
	}
	private static boolean satisfy(String temp) {
		if (temp.length()==0) return true;
		boolean alpha[]=new boolean[26];
		alpha[temp.charAt(0)-'a']=true;
		for (int i=1;i<temp.length();i++)
		{
			//System.out.println(i);
			if (temp.charAt(i)!=temp.charAt(i-1))
			{
				if (alpha[temp.charAt(i)-'a']==true) return false;
				else alpha[temp.charAt(i)-'a']=true;
			}
		}
		return true;
	}
}
