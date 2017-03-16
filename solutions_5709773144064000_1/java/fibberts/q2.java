import java.util.Scanner;
import java.text.DecimalFormat;

class q2{
  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    for(int i=1;i<=n;i++){
      double c = in.nextDouble();
      double f = in.nextDouble();
      double x = in.nextDouble();
      System.out.println("Case #"+i+": "+(new DecimalFormat("#0.0000000").format(q2(c, f, x, 2))));
    }
  }
  public static double q2(double c, double f, double x, double i){
    double wait = 0;
    while(true){
      double waittime = x/i;
      double buytime = c/i+x/(i+f);
      if(waittime < buytime){
        wait += waittime;
        break;
      }
      else{
        wait += c/i;
        i += f;
      }
    }
    return wait;
  }
}
