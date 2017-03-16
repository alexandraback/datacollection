import java.util.*;
class A2{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int testcase, numtyped, lengthpass,real, k;
    double totalprob, minimum, tries;
    double[] chance;
    testcase = sc.nextInt();
    for(int i=1;i<=testcase;i++){
      numtyped = sc.nextInt();
      lengthpass = sc.nextInt();
      totalprob = 1;
      minimum = 2+lengthpass;
      real = lengthpass-numtyped +1;
      chance = new double[numtyped];
      for(int j=0;j<numtyped;j++){
        chance[j] = sc.nextDouble();
        totalprob*=chance[j];
       
      }
       tries = totalprob*(real) + (1-totalprob)*(real + lengthpass + 1);
        if(minimum>tries)
          minimum = tries;
      k = numtyped - 1;
      for(int j=1;j<=numtyped;j++){
        totalprob= totalprob/chance[k];
        tries = totalprob*(2*j + real) + (1-totalprob)*(2*j + real + lengthpass + 1) ;
        if(minimum>tries)
          minimum = tries;
        k--;
      }
      
      System.out.print("Case #"+i+": ");
      System.out.printf("%.6f\n",minimum);
    }
  }
}