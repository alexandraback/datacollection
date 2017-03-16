   import java.util.Arrays;
   import java.util.Scanner;
   import java.util.*;
   import java.io.*;
   public class Repeaters
   {
      public static String[] a1;
      public static void main(String[] args) throws FileNotFoundException 
      {
         File input= new File("A-small-attempt1.in");
         Scanner scan = new Scanner(input);
         int NUM = scan.nextInt();
			scan.nextLine();
         for(int i=0;i<NUM; i++)
         {
           String a= scan.nextLine();
           a1=a.split("/");
			  int[] arr= new int[2];
			  arr[0]= Integer.parseInt(a1[0]);
			  arr[1]= Integer.parseInt(a1[1]);
			  if(!check2(arr[1]))
			  System.out.println("Case #"+(i+1)+": impossible");
			  else
			  System.out.println("Case #"+(i+1)+": "+dot(arr));
         }
         scan.close();
      }
      public static int dot(int[] all)
      {
         int i=0;
			while(((double)(all[0]/all[1]))<1)
			{
			 all[0]=all[0]*2;
			 i++;
			}
			return i;
      }
      public static boolean check2(int number)
      {
        
        if(number <=0){
            throw new IllegalArgumentException("number: " + number);
        }
        if ((number & -number) == number) {
            return true;
        }
        return false;
      }



   
      public static boolean compareStrings(ArrayList<HashMap<Character,Integer>> max) 
      {
         Set<Character> lol= max.get(0).keySet();
         for(int i=0; i<max.size(); i++)
            if(!max.get(i).keySet().equals(lol))
               return false;
           
         return true;
           
      }
      public static int doTheThings(ArrayList<HashMap<Character,Integer>> max) 
      {
            Set<Character> lol= max.get(0).keySet();
      		HashMap<Character,Integer> miss= new HashMap<Character,Integer>();
      		int total=0;
      		for(char a: lol)
      		   {
      			 int avg=(int)numcharacter(max,a)/max.size();
      			 int f=0;
      			 for(int i=0; i<max.size(); i++)
      			     f= f+Math.abs(max.get(i).get(a)-avg);
      			 total=total+f;
      			}	  
      		 return total;
      			
      		   
      		
      }
      public static int numcharacter(ArrayList<HashMap<Character,Integer>> max, char a)
   	{
   	   int total=0;
   	      for(int i=0; i<max.size(); i++)
   			{
   			 total= total+max.get(i).get(a);
   			}
   			return total;
   	}

   }