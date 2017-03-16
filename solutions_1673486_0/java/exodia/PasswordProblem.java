package _2012.round1A;

import java.math.BigDecimal;
import java.util.Scanner;

public class PasswordProblem {
	public static void main(String[] args) {
		Scanner consola = new Scanner(System.in);
		double []probCorr;
		double min, prob, acum;
		int nTypped, longPass, times = consola.nextInt();
		for(int t = 1; t <= times; t++){
			nTypped = consola.nextInt();
			longPass = consola.nextInt();
			probCorr = new double[nTypped];
			prob = 0;
			for(int i = 0; i < nTypped; i++){
				probCorr[i] = Double.parseDouble(consola.next());
				prob *= probCorr[i];
			}
			
			// reset
			min = longPass + 2;
			// continue
			acum = (longPass - nTypped + 1) * prob;
			acum += ((longPass) * 2 - nTypped + 2) * (1 - prob);
			if(acum < min)
				min = acum;
			// backspace
			prob = 1;
			for(int i = 1; i <= nTypped; i++){
				prob *= probCorr[i - 1];
				acum = (longPass - (i * 2) + 1 + nTypped) * prob;
				acum += ((longPass * 2) - (i * 2) + 2 + nTypped) * (1 - prob);
				if(acum < min)
					min = acum;
			}
			
			System.out.println("Case #" + t + ": " + new BigDecimal(min).setScale (6, BigDecimal.ROUND_HALF_UP));
		}
	}
}