import java.util.Scanner;

class prog{
  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    for(int i=1;i<=n;i++){
      long A = in.nextLong();
      long B = in.nextLong();
      long K = in.nextLong();
      System.out.println("Case #"+i+": "+q2((long)Math.max(A,B),(long)Math.min(A,B),K, false));
    }
  }
  // a > b
  public static long q2(long a, long b, long k, boolean equal){
    if(a < k || b < k)
	return a*b;
/*    if(k<=1)
	return (equal ? 1:0);
    if(k % 2 == 1) //may make a 1 in which case we need everything strictly < or create a 0 in 3 ways in which case things may be = or <
      return q2(a/2,b/2,k/2, equal)+(equal ? 3*q2(a/2,b/2,k/2, true) : 0);
    if(k % 2 == 0) //may make a 0 in 3 ways in which case things must be strictly <, or create a 1 in which case things must be strictly <
      return 3*q2(a/2,b/2,k/2, equal) + q2(a/2,b/2,k/2, false);

/*
    int abits = bits(a, false)-1;
    int bbits = bits(b, false)-1;
    int kbits = bits(k, false)-1;
    long[] aray = new long[abits];
    long[] bray = new long[bbits];
    long[] kray = new long[kbits];
    long jump = (long)Math.pow(2,abits-bbits); //overhang a
    jump *= (long)Math.pow(3,bbits-kbits); //overhang a and b
    //for each valid config involving only last kbits bits, there are jump amount actually
    System.out.println("jump="+jump+", kbits="+kbits+", abits="+abits+", bbits="+bbits);
    long pow = (long)Math.pow(2,kbits);
    long total = 0;
    while(k > 0){
      System.out.print("pow=");
	bits(pow, true);
      System.out.print("  k=");
      bits(k, true);
      System.out.println();
      if(k/pow == 1)//a 0 in this position will be good
	total += jump*(long)Math.pow(2,kbits-1); //doesn't matter what happens to right
      k %= pow;
      pow /= 2;
    }
    System.out.println("  "+total);
*/
    long count = k*(a+b-k);
    for(long i=k;i<a;i++)
      for(long j=k;j<b;j++)
	if((i & j) < k)
	  count ++;
    return count;
  }
  public static int bits(long n, boolean print){
    int bits = 0;
    String out = "";
    while(n > 0){
      out = (n % 2)+out;
      n /= 2;
      bits ++;
    }
    if(print)
      System.out.println(out);
    return bits;
  }
}
