import java.util.*;

public class B {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int numCases = in.nextInt();
		for(int caseNum = 1; caseNum <= numCases; caseNum++) {
			int min;
            int A = in.nextInt();
            min = A;
            int B = in.nextInt();
            if ( B < min )
                min = B;
            int K = in.nextInt();
            if ( K < min )
                min = K;
            int numWins = 0;

            for ( int pickA = 0; pickA < A; pickA++ )
                for ( int pickB = 0; pickB < B; pickB++ )
                {
                    if ( (pickA & pickB) < K )
                        numWins ++;
                }

            // Take out the lower digits
//            int i = 1;
//            while ( Math.pow( i , 2) - 1 < min ) {
//                i++;
//            }



//            int digitsA = (int)(Math.log(A)/Math.log(2));
//            int digitsB = (int)(Math.log(B)/Math.log(2));
//            int digitsK = (int)(Math.log(K)/Math.log(2));


            // Print results
			System.out.format("Case #%d: %d\n", caseNum, numWins );
		}			
	}

    static double calcTime( double C, double F, double X, double R, int depth ) {
        double noBuy = X / R;
        double initialCostToBuy = C / R;

        if ( X <= C )   //Never cheaper to buy
            return noBuy;

        if ( depth > 4000 ) //no more
            return noBuy;

        double costToBuy = initialCostToBuy + calcTime( C, F, X, R + F, depth +1 );

        if ( noBuy < costToBuy )
            return noBuy;
        else
            return costToBuy;
    }

    static double calcTime2(double c, double f, double x, double r, double t) {
        //Geometric sequence - no need to recurse
        double costToBuy;
        double costToWait;
        int numBuys = 10; // Max times you might buy
        for ( ; numBuys >= 0; numBuys-- ) {
            double expRate = 1 / ( r + ( numBuys - 1 ) * f);
            costToWait = x / ( 2 + f * numBuys );
            if (numBuys == 0)
                costToBuy = 0;
            else
                costToBuy = (c) * ( (1 - Math.pow(expRate, numBuys))/(1-expRate));
            double newTime = costToBuy + costToWait;
            if ( t > 0 && newTime > t)
                break;
            t = newTime;
        }
        return t;
    }



}
