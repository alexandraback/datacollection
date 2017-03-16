import java.util.*;

public class A {
	public static void main (String [] args) {
				
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		
		for (int t = 1; t <= T; t++) {
			int A = s.nextInt();
            int B = s.nextInt();
            double[] p = new double[A];
                        
            for (int i = 0; i < A; i++) {
                p[i] = s.nextDouble();
            }
			
            double ans = Double.MAX_VALUE;
            
            // 1: keep typing
            // 1A: all correct
            double tempP = 1;
            double tempA = 0;
            tempP = 1;
            for (int i = 0; i < A; i++)
                tempP *= p[i];
            tempA = tempP * (B - A + 1);
            
            // 1B: any of previous wrong
            tempP = 1 - tempP;
            tempA += tempP * (B - A + 1 + B + 1);
            if (tempA < ans)
                ans = tempA;
            
            // 2: backspace x times (1 <= x <= A)
            for (int i = 1; i < A; i++) {
                tempP = 1;
                tempA = 0;
                for (int k = 0; k < (A - i); k++)
                    tempP *= p[k];
                tempA = tempP * (i + B - A + i + 1);
                tempP = 1 - tempP;
                tempA += tempP * (i + B - A + i + 1 + B + 1);
                if (tempA < ans)
                    ans = tempA;
            }
            
            tempA = A + B + 1;
            if (tempA < ans)
                ans = tempA;
            
            
            // 3: press enter            
            tempA = 1 + B + 1;
            if (tempA < ans)
                ans = tempA;
            
            
			System.out.println("Case #" + t + ": " + ans);
		}
	}
}