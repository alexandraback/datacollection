import java.util.Arrays;
import java.util.Scanner;
import java.text.DecimalFormat;

class q4{
  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    for(int i=1;i<=n;i++){
      int size = in.nextInt();
      double[] nao = new double[size];
      for(int j=0;j<size;j++)
        nao[j] = in.nextDouble();
      Arrays.sort(nao);
      double[] ken = new double[size];
      for(int j=0;j<size;j++)
        ken[j] = in.nextDouble();
      Arrays.sort(ken);
      System.out.println("Case #"+i+": "+q4(nao, ken));
    }
  }
  public static String q4(double[] n, double[] k){
    return (n.length-honest(k, n))+" "+honest(n,k);
  }
  public static int honest(double[] n, double[] k){
    int score = 0;
    for(int indexN=0, indexK = 0; indexK<k.length; indexK++){
      if(n[indexN] > k[indexK])
        score ++;
      else indexN ++;
    }
    return score;
  }
}
