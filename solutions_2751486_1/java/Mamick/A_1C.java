import java.io.*;
import java.util.*;
import java.lang.*;
 
public class A_1C {
    public static void main(String[] args) {
		try 
		{
			Scanner s = new Scanner(new File("A-large(1).in"));
			
			FileOutputStream out = new FileOutputStream(new File("lawn2.txt"));
			PrintStream p = new PrintStream(out);
			
			int num = s.nextInt();
			for(int nt=1;nt<=num;nt++)
			{
				String st=s.next();
				int n = s.nextInt();
				int [] numConso = new int [st.length()+1];
				int psum=0;
				for(int i=0;i<st.length();i++)
				{
					char c =st.charAt(i);
					if(c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u')
						psum++;
					numConso[i+1]=psum;
				}
//				int count=0;
//				for(int i=0-n+1;i<st;i++){
//					int effx = (i<0)?0:i;
//					int effy = (i+n>=st.length())?st.length()-1:i
				long count = 0;
				int previousi=0;
				for(int i=0;i+n<=st.length();i++){
					boolean works=true;
					works=(numConso[i+n]-numConso[i]==n);
//					System.out.println(works+" "+i+" "+(long)(i+1-previousi)*(long)(st.length()-i-n+1));
					if(works){
						count+=((long)(i+1-previousi))*((long)(st.length()-i-n+1));
						previousi=i+1;
					}
				}
				p.println("Case #"+nt+": "+count);
			}
			
			p.close();
		}
		catch(IOException e)
		{
			System.out.println("There was a problem:" + e);
		
		}
    }
}
