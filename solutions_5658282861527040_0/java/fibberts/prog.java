import java.util.Scanner;

class prog{
  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    for(int i=1;i<=n;i++){
      int A = in.nextInt();
      int B = in.nextInt();
      int K = in.nextInt();
      System.out.println("Case #"+i+": "+q2(A,B,K));
    }
  }
  public static int q2(int a, int b, int k){
    if(a < k || b < k)
      return (a*b);
    int count = 0;
    for(int i=0;i<a;i++)
      for(int j=0;j<b;j++)
	if((i & j) < k)
	  count ++;
    return count;
  }
}
