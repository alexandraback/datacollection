import java.util.*;

public class Password {
    
    public static void main(String[] args) {
	Password p = new Password();
        Scanner in = new Scanner(System.in);
        int cases = in.nextInt();
        for (int i = 0; i < cases; i++) {
            double answer = p.solve(in);
            System.out.printf("Case #%d: %f\n", i+1, answer);
        }
    }
    
    private double solve(Scanner in) {
      int typed = in.nextInt();
      int total = in.nextInt();
      double[] probs = new double[typed];
      for (int i = 0; i < typed; i++) probs[i] = in.nextDouble();
      double[] probone = new double[typed];
      for (int i = 0; i < typed; i++) {
	  double allright = probs[0];
	  for (int j = 1; j <= i; j++) {
	      allright *= probs[j];
	  }
	  probone[i] = 1 - allright;
      }
      double[] Eback = new double[typed];
      double Egiveup = 1 + total + 1;
      double Efinish = (total - typed) + 1 + probone[typed - 1] * (total + 1);
      for (int i = 0; i < typed; i++) {
	  Eback[i] = (i+1) + (total - typed + i) + (probone[typed - i - 1]) * (total + 1);
      }
      double min = 999999999999999999.99;
      for (int i = 1; i < Eback.length; i++) 
	  if (Eback[i] < min)
	      min = Eback[i];
      min = Math.min(min, Math.min(Efinish, Egiveup));
      return min;
    }
    
}