import java.io.*;
import java.util.*;
import java.math.*;

public class B
{  
	public static void main(String[] args) throws Exception
	{
    int T;	
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		T=Integer.parseInt(in.readLine());
		
		//System.out.println(countOccurrence("AAAB","A")); T=0;

		for (int i=1; i<=T; i++)
		{
		  String[] temp=in.readLine().split("[ ]+");		  		  
		  int K=Integer.parseInt(temp[0]);    //keyboard length
		  int L=Integer.parseInt(temp[1]);    //target length
		  int S=Integer.parseInt(temp[2]);		//word length
		  
		  String keyboard=in.readLine();
		  String target=in.readLine();

      String ans=solve(keyboard,target,S);
      System.out.println("Case #"+i+": "+ans);
    }

		in.close();
	}
	
	
	public static String solve(String keyboard, String target, int S)
	{
    List<String> poss=generateAll(keyboard,S);
    //System.out.println("poss "+poss.size());
    
    int max=0;
    int total=0;
    
    
    for (String s : poss)
    {
      int count=countOccurrence(s,target);
      max=Math.max(max,count);
      total+=count;
    }

    
    double ans=(max*poss.size()-total)*1.0/poss.size();
    return ""+ans;
	}
	
	//how many times target appears?
	public static int countOccurrence(String s, String target)
	{
  	 int count=0;
	   int cur=0;
	 
    while(true)
    {	 
       int i=s.indexOf(target,cur);
       if (i<0) break;
       
       count++;
       cur=i+1;
    }
    
    return count;  
	}
	
	//TOO SLOW!
	/*
  public static List<StringBuffer> generateAll(String keyboard, int S)
  {
    char[] K=keyboard.toCharArray();
  
    List<StringBuffer> Q=new ArrayList<StringBuffer>();
    Q.add(new StringBuffer(""));
    
    List<StringBuffer> out=new ArrayList<StringBuffer>();
    
    while(Q.size()>0)
    {
      StringBuffer s=Q.remove(0);
      if (s.length()>=S)
      {
        //System.out.println(s);
        out.add(s);
        continue;
      }
      
      for (char c : K) Q.add(s.append(c));
    }
    
    return out;
  }
  */
  
  public static List<String> generateAll(String keyboard, int S)
  {
    char[] K=keyboard.toCharArray();

    List<String> out=new ArrayList<String>();
    
    int key=keyboard.length();
    
    char[] word=new char[S];
        
    for (int i=0; i<(int)(Math.pow(key,S)); i++)
    {
      int num=i;
      for (int k=0; k<S; k++)
      {
        word[k]=K[num%key];
        num/=key;
      }
      
      String cur=new String(word);
      out.add(cur);
    }
    
    return out;
  }
}