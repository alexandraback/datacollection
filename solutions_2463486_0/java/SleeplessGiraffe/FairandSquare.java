   import java.io.*;
   import java.lang.*;
   import java.math.BigInteger;

   public class FairandSquare
   {
      public static void main(String [] args)throws IOException
      {
         BufferedReader read = new BufferedReader(new FileReader("C-small-attempt0.in"));
         BufferedWriter write = new BufferedWriter(new FileWriter("ans.txt"));
         int T = Integer.valueOf(read.readLine());
         boolean exit = false;
         BigInteger count = new BigInteger("0");
         BigInteger min = new BigInteger("10");
         BigInteger max;
         BigInteger num;
         BigInteger square;
         String input, temp;
         for(int i = 0; i < T; i++)
         {
            input = read.readLine();
            temp = "";
            for(int j = 0; j < input.length(); j++)
            {
               if(input.charAt(j) == ' ')
               {
                  min = new BigInteger(temp);
                  temp = "";
               }
               else
               {
                  temp += input.charAt(j);
               }
            }
            max = new BigInteger(temp);
            num = new BigInteger("1");
            square = min.pow(2);
            count = count.multiply(new BigInteger("0"));
            //if(isPalindrome(new BigInteger("4")))
               //System.out.println("hey");
         	//count # of fair and square numbers in the interval
            exit = false;
            do
            {
            //create palindrome Type A
               square = palindromeA(num);
             //check if square is palindrome
               square = square.pow(2);
               if(max.subtract(square).signum() != -1 && square.subtract(min).signum() != -1 && isPalindrome(square))
               {
                  count = count.add(new BigInteger("1"));
                  //System.out.println(square);
               }
             
            //create palindrome Type B
               square = palindromeB(num);
               if(square.pow(2).subtract(max).signum() == 1)
                  exit = true;
             //check if square is palindrome
               square = square.pow(2);
               if(max.subtract(square).signum() != -1 && square.subtract(min).signum() != -1 && isPalindrome(square))
               {
                  count = count.add(new BigInteger("1"));
                  //System.out.println(square);
               }
               
               num = num.add(new BigInteger("1"));
            }while(!exit);
            write.write("Case #"+(i+1)+": "+count);
            write.newLine();
            System.out.println("Case #"+(i+1)+": "+count);
         }
         //System.out.println(palindromeB(new BigInteger("1")));
         write.close();
      }
      public static BigInteger palindromeB(BigInteger n)
      {
         String num = n.toString();
         String p = n.toString();
         for(int i = num.length()-2; i > -1; i--)
         {
            p += num.charAt(i);
         }
         return new BigInteger(p);
      }
      public static BigInteger palindromeA(BigInteger n)
      {
         String num = n.toString();
         String p = n.toString();
         for(int i = num.length()-1; i > -1; i--)
         {
            p += num.charAt(i);
         }
         return new BigInteger(p);
      }
      public static boolean isPalindrome(BigInteger n)
      {
         String num = n.toString();
         for(int i = 0; i < num.length()/2; i++)
         {
            if(num.charAt(i) != num.charAt(num.length()-i-1))
               return false;
         }
         return true;
      }
   }