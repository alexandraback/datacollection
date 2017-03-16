import java.util.*;

public class B{
  public static void main(String[] args){
    Scanner scanner=new Scanner(System.in);
    int cases=scanner.nextInt();
    for(int c=1;c<=cases;c++){
      System.out.println("Case #"+c+": "+solve(scanner.next()));
    }
  }


  private static String reduceEnd(String stack){
    int n=0;
    int len=stack.length();
    while(n<stack.length() && stack.charAt(len-1-n)=='+')
      n++;
    return stack.substring(0,len-n);
  }

  private static int solve(String stack){
    stack=reduceEnd(stack);
    if(stack.length()==0)
      return 0;
    int ret=1;
    char now=stack.charAt(0);
    for(int i=1;i<stack.length();i++){
      if(stack.charAt(i)!=now){
        ret++;
        now=stack.charAt(i);
      }
    }
    return ret;
  }
}
