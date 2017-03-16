import java.util.Scanner;

public class Main {
    public static void main(String[] args){

	Scanner stdin = new Scanner(System.in);
	int times = stdin.nextInt();
	for(int t = 1; t <= times; t++){
	    int A = stdin.nextInt();
	    int B = stdin.nextInt();
	    double p[] = new double[A];
	    for(int i = 0; i < A; i++){
		p[i] = stdin.nextDouble();
	    }

	    System.out.println("Case #" + t + ": " + solve(A, B, p));
	}	
    }

    static double solve(int A, int B, double[] p){
	double min_Keystroke = Double.MAX_VALUE;
	
	//i: the number of times we use backspace
	for(int i = 0; i < A; i++){
	    double prob = calcProb(p, i);
	    double expectedKeystroke =  prob * (B - A + 2 * i + 1) + (1 - prob) * (B - A + 2 * i + 1 + B + 1);
	    if (min_Keystroke > expectedKeystroke){
		min_Keystroke = expectedKeystroke;
	    }
	}
	//restart with enter
	if (2 + B < min_Keystroke){
	    min_Keystroke = 2 + B;
	}
	return min_Keystroke;
    }

    static double calcProb(double p[], int index){
	double ans = 1;
	for(int i = 0; i < p.length - index; i++){
	    ans *= p[i];
	}
	return ans;
    }
    
 }
	
