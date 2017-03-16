import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.File;
import java.util.Scanner;
import java.io.PrintWriter;
class CDX {
  public static void main(String args[]) throws Exception {
    new CDX().run();
  }
  int n;
  int	k;
  int we=0;
  boolean[] we1=new boolean[20000];
  Scanner sc;
  PrintWriter out;
  public void run() throws Exception {
    sc = new Scanner(new FileInputStream(new File("D:\\Cs.in")));
    out = new PrintWriter(new FileOutputStream("D:\\Cs.txt"));
    sc.nextInt();
    n=sc.nextInt();
    k=sc.nextInt();
    out.println("Case #1:");
    f(0,new int[n-2]);
    out.flush();
    out.close();
    System.out.println("*==end==*");
  }
  public void f(int we12, int[] d){
    if(we>=k) return;
    if(we12==n-2){
      boolean we123=true;
      long[] we123v=new long[9];
      for(int we1234=2;we1234<=10;we1234++){
        long v=1; 
        long p=we1234;
        for(int i=n-3;i>=0;i--){
          v+=d[i]*p;
          p*=we1234;
        }
        v+=p;
        long we123456=we12345(v);
        if(we123456==-1){we123=false;
          break;
        }else{
        we123v[we1234-2]=we123456;
        }
      }
      if(we123){
        we++;
        out.print("1");
        for(int i=0;i<n-2;i++){out.print(d[i]);}
        out.print("1");
        out.print(" ");
        for(int j=0;j<9;j++){
          out.print(we123v[j] + " ");
        }
        out.println();
      }
      return;
    }
    
    f(we12+1,d);
    d[we12]=1;f(we12+1, d);
    d[we12]=0;
  }
  public long we12345(long a){for(long i=2;i*i<=a;i++){if(a%i==0){return i;}}
    return -1;
  }
}