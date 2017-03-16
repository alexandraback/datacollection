import java.util.*;

public class A{
  public static void main(String[] args){
    Scanner scanner=new Scanner(System.in);
    int cases=scanner.nextInt();
    for(int c=1;c<=cases;c++){
      System.out.println("Case #"+c+": "+solve(scanner.next()));
    }
  }

  private static String solve(String letters){
    int[] letterCounts=count(letters);
    String ret="";
    for(int i=0;i<LETTERS.length();i++){
      int letterCount=letterCounts[LETTERS.charAt(i)-'A'];
      for(int j=0;j<letterCount;j++)
        ret+=DIGITS.charAt(i);
      for(int j=0;j<NUMBERS[i].length();j++)
        letterCounts[NUMBERS[i].charAt(j)-'A']-=letterCount;
    }

    char[] ca=ret.toCharArray();
    Arrays.sort(ca);
    return new String(ca);
  }

  private static int[] count(String letters){
    int[] ret=new int[26];
    for(int i=0;i<letters.length();i++)
      ret[letters.charAt(i)-'A']++;
    return ret;
  }

  private static String LETTERS="ZWXUROGSFI";
  private static String[] NUMBERS=new String[]{"ZERO", "TWO", "SIX", "FOUR", "THREE", "ONE", "EIGHT", "SEVEN", "FIVE", "NINE"};
  private static String DIGITS="0264318759";
}

/*
zero    Z
two     W
six     X
four    U
three   R
one     O
eight   G
seven   S
five    F
nine    I
ten     T
*/
