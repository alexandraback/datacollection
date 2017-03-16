   import java.util.Arrays;
   import java.util.Scanner;
   import java.util.*;
   import java.io.*;
   public class Repeaters
   {
      public static String[] a1;
      public static void main(String[] args) throws FileNotFoundException 
      {
         File input= new File("A-large.in");
         Scanner scan = new Scanner(input);
         int NUM = scan.nextInt();
         scan.nextLine();
         for(int i=0;i<NUM; i++)
         {
            String a= scan.nextLine();
            a1=a.split("/");
            long[] arr= new long[2];
            arr[0]= Long.parseLong(a1[0]);
            arr[1]= Long.parseLong(a1[1]);
            arr= simplify(arr);
            if(!check2(arr[1]))
               System.out.println("Case #"+(i+1)+": impossible");
            else
               System.out.println("Case #"+(i+1)+": "+dot(arr));
         }
         scan.close();
      }
      public static long dot(long[] all)
      {
         int i=0;
         while(((double)(all[0]/all[1]))<1)
         {
            all[0]=all[0]*2;
            i++;
         }
         return i;
      }
      public static boolean check2(long number)
      {
        
         if(number <=0){
            throw new IllegalArgumentException("number: " + number);
         }
         if ((number & -number) == number) {
            return true;
         }
         return false;
      }
   
   
   
   
      public static long[] simplify(long[] l)
      {
         long[] moose= new long[2];
         long li= greatestCommonFactor(l[0], l[1]);
      	moose[0]=l[0]/li;
      	moose[1]=l[1]/li;
      	return moose;
           
      }
      public static long greatestCommonFactor(long num, long den)
      {
         if(den == 0){
            return num;
         }
         return greatestCommonFactor(den, num % den);
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