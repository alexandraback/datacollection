package aj;

import java.math.BigInteger;
import java.util.Scanner;

public class Aj {
    static final BigInteger TWO = new BigInteger("2");
    static final BigInteger MINUS_ONE = new BigInteger("-1");
    
    static BigInteger r;
    static BigInteger t;

    /*
        bool good(int i) {
                int paintSheNeeds = (2 * i + (2 * r - 1)) * i;
                return paintSheNeeds <= t;
        }
     */
    static boolean good(BigInteger i) {
	BigInteger x1 = i.multiply(TWO);
        BigInteger x2 = (r.multiply(TWO)).add(MINUS_ONE);
        BigInteger x3 = x1.add(x2);
        BigInteger paintSheNeeds = x3.multiply(i);
        return paintSheNeeds.compareTo(t) <= 0;
    }
    
    public static void main(String[] args) {
        int T;
        Scanner in = new Scanner(System.in);
        T = in.nextInt();
        for (int t_ = 0; t_ != T; ++t_) {
            r = in.nextBigInteger();
            t = in.nextBigInteger();
            
            BigInteger rangeMin = new BigInteger("1");
            BigInteger rangeMax = new BigInteger("2");
            while (good(rangeMax)) {
                rangeMax = rangeMax.multiply(TWO);
            }
            BigInteger rangeMaxMinusOne = rangeMax.add(MINUS_ONE);
            while (rangeMin.compareTo(rangeMaxMinusOne) < 0) {
                BigInteger mid = rangeMin.add(rangeMax);
                mid = mid.divide(TWO);
                if (good(mid))
                    rangeMin = mid;
                else
                    rangeMax = mid;
                rangeMaxMinusOne = rangeMax.add(MINUS_ONE);
            }
            System.out.println("Case #" +
                    (new Integer(t_ + 1)).toString() +
                    ": " + rangeMin.toString());
        }
    }
}

/*

int main(int argc, char* argv[])
{
	cin >> T;
	for (int t_ = 0; t_ != T; ++t_) {
		cin >> r >> t;
		int rangeMin = 1;
		int rangeMax = 2;
		while (good(rangeMax))
			rangeMax *= 2;
		while (rangeMin < rangeMax - 1) {
			int mid = (rangeMin + rangeMax) / 2;
			if (good(mid))
				rangeMin = mid;
			else
				rangeMax = mid;
		}
		cout << "Case #" << (t_ + 1) << ": " << rangeMin << "\n";
	}	
	return 0;
}
*/