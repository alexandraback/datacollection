import java.util.*;

class prog3{
  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    for(int i=1;i<=n;i++){
      int N = in.nextInt();
      int M = in.nextInt();
      int K = in.nextInt();
      System.out.println("Case #"+i+": "+q1(N,M,K));
    }
    System.out.println(q1(20,1,17));
  }

  public static int space(int n, int m, int p){//p stones, assume n>m
    if(p >= 2*m+2*n-4)//can cover whole thing
      return m*n;
    if((2*(m-1)+2*(n-1))-p <= 4)//can cover whole thing, except maybe corners
      return m*n-Math.max((2*(m-1)+2*(n-1))-p, 0);
    int edgesize = (p/4);
    int diagonal = 2*edgesize+1;
    int s = 0;
    if(m >= diagonal){//we don't hit edge
      s = edgesize*edgesize+(edgesize+1)*(edgesize+1);
      if(p % 4 != 0)
        s += edgesize*(p%4)+(p%4 - 1);
      return s;
    }
    //we don't have space for optimal, must round corners
    s = m*n;
    int needed = 2*(m-1)+2*(n-1);
    int diff = needed-p;

    p -= 2*(m-2);//math is easier & must cover ends.
    {
      if(m % 2 == 1)
        s = ((m-3)/2+1)*((m-3)/2+1);
      else s = (m-2)/2*((m-2)/2+1);
      diagonal = (m-2)/2*2+p/2;
      if(diagonal < n)
        return 2*s+p/2*m+(p%2);
    }
    s = m*n;
    s -= 4*(diff/4*(diff/4+1)/2);
    s += (diff%4)*(diff/4);
    return s;
  }
  public static int q1(int n, int m, int k){
    if(k <= 4 || m <= 2 || n <= 2)//no savings
      return k;
    if(m*n-k <= 4)//must cover everything except possibly corners
      return (2*(m-1)+2*(n-1)-(m*n-k));
    int hi = k;
    int lo = 4;
    int stop = 21;
    while(hi != lo){
      int mid = (hi+lo)/2;
      int out = space(Math.max(m,n),Math.min(m,n),mid);
      if(out == k)
        return mid;
      if(out > k)
        hi = mid;
      lo = mid;
      if(stop-- < 0)
        break;
    }
    return hi;
  }
}
