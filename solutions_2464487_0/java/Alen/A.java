package cn.zhoushuyan.codejam._2013.r1a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.math.RoundingMode;
import java.util.ArrayList;

public class A {

	public static void main(String[] args) throws Exception {
		// TODO input file path
		String filePath = "/Users/Alen/Documents/CodeJam/2013/R1A/A-Small.in";

		BufferedReader br = new BufferedReader(new FileReader(filePath));
		String outFile = filePath.substring(0, filePath.lastIndexOf('.'))
				+ ".out";
		BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));
		
		String line = br.readLine();
		int T = Integer.valueOf(line);
		for (int i = 0; i < T; i++) {
			// TODO main logical
			// ...
			line = br.readLine();
			String[] strs = line.split(" ");
			BigDecimal r = new BigDecimal(strs[0]);
			BigDecimal t = new BigDecimal(strs[1]);
			
			BigDecimal a = new BigDecimal(2);
			BigDecimal b = r.multiply(new BigDecimal(2)).subtract(new BigDecimal(1));
			BigDecimal c = t.negate();
			
			BigDecimal b2_4ac = b.pow(2).subtract(c.multiply(a).multiply(new BigDecimal(4)));
			
			BigDecimal s_b2_4ac = bigSqrt(b2_4ac, new MathContext(40));
			
			BigDecimal max = b.negate().add(s_b2_4ac).divide(a.multiply(new BigDecimal(2)));
			
			// TODO output
			bw.write(String.format("Case #%d: %d\r\n", i + 1, max.longValue()));
		}

		bw.flush();
		bw.close();
		br.close();

	}
	
	/**
	   * Returns the correctly rounded square root of a positive BigDecimal. 


	   * The algorithm for taking the square root of a BigDecimal is most
	   * critical for the speed of your application. This method performs the fast
	   * Square Root by Coupled Newton Iteration algorithm by Timm Ahrendt,
	   * from the book "Pi, unleashed" by Jšrg Arndt in a neat loop.
	   *
	   * @param squarD   number to get the root from (called "d" in the book)
	   * @param rootMC   precision and rounding mode (for the last root "x")
	   *
	   * @return the root of the argument number
	   *
	   * @throws ArithmeticException       if the argument number is negative
	   * @throws IllegalArgumentException  if rootMC has precision 0
	   */

	  public static BigDecimal bigSqrt(BigDecimal squarD, MathContext rootMC)
	  {
	    // Static constants - perhaps initialize in class Vladimir!
	    BigDecimal TWO = new BigDecimal(2);
	    double SQRT_10 = 3.162277660168379332;


	    // General number and precision checking
	    int sign = squarD.signum();
	    if(sign == -1)
	      throw new ArithmeticException("\nSquare root of a negative number: " + squarD);
	    else if(sign == 0)
	      return squarD.round(rootMC);

	    int prec = rootMC.getPrecision();           // the requested precision
	    if(prec == 0)
	      throw new IllegalArgumentException("\nMost roots won't have infinite precision = 0");

	    // Initial precision is that of double numbers 2^63/2 ~ 4E18
	    int BITS = 62;                              // 63-1 an even number of number bits
	    int nInit = 16;                             // precision seems 16 to 18 digits
	    MathContext nMC = new MathContext(18, RoundingMode.HALF_DOWN);


	    // Iteration variables, for the square root x and the reciprocal v
	    BigDecimal x = null, e = null;              // initial x:  x0 ~ sqrt()
	    BigDecimal v = null, g = null;              // initial v:  v0 = 1/(2*x)

	    // Estimate the square root with the foremost 62 bits of squarD
	    BigInteger bi = squarD.unscaledValue();     // bi and scale are a tandem
	    int biLen = bi.bitLength();
	    int shift = Math.max(0, biLen - BITS + (biLen%2 == 0 ? 0 : 1));   // even shift..
	    bi = bi.shiftRight(shift);                  // ..floors to 62 or 63 bit BigInteger

	    double root = Math.sqrt(bi.doubleValue());
	    BigDecimal halfBack = new BigDecimal(BigInteger.ONE.shiftLeft(shift/2));

	    int scale = squarD.scale();
	    if(scale % 2 == 1)                          // add half scales of the root to odds..
	      root *= SQRT_10;                          // 5 -> 2, -5 -> -3 need half a scale more..
	    scale = (int)Math.floor(scale/2.);          // ..where 100 -> 10 shifts the scale

	    // Initial x - use double root - multiply by halfBack to unshift - set new scale
	    x = new BigDecimal(root, nMC);
	    x = x.multiply(halfBack, nMC);                          // x0 ~ sqrt()
	    if(scale != 0)
	      x = x.movePointLeft(scale);

	    if(prec < nInit)                 // for prec 15 root x0 must surely be OK
	      return x.round(rootMC);        // return small prec roots without iterations

	    // Initial v - the reciprocal
	    v = BigDecimal.ONE.divide(TWO.multiply(x), nMC);        // v0 = 1/(2*x)


	    // Collect iteration precisions beforehand
	    ArrayList<Integer> nPrecs = new ArrayList<Integer>();

	    assert nInit > 3 : "Never ending loop!";                // assume nInit = 16 <= prec

	    // Let m be the exact digits precision in an earlier! loop
	    for(int m = prec+1; m > nInit; m = m/2 + (m > 100 ? 1 : 2))
	      nPrecs.add(m);


	    // The loop of "Square Root by Coupled Newton Iteration" for simpletons
	    for(int i = nPrecs.size()-1; i > -1; i--)
	    {
	      // Increase precision - next iteration supplies n exact digits
	      nMC = new MathContext(nPrecs.get(i), (i%2 == 1) ? RoundingMode.HALF_UP :
	                                                        RoundingMode.HALF_DOWN);

	      // Next x                                                 // e = d - x^2
	      e = squarD.subtract(x.multiply(x, nMC), nMC);
	      if(i != 0)
	        x = x.add(e.multiply(v, nMC));                          // x += e*v     ~ sqrt()
	      else
	      {
	        x = x.add(e.multiply(v, rootMC), rootMC);               // root x is ready!
	        break;
	      }

	      // Next v                                                 // g = 1 - 2*x*v
	      g = BigDecimal.ONE.subtract(TWO.multiply(x).multiply(v, nMC));

	      v = v.add(g.multiply(v, nMC));                            // v += g*v     ~ 1/2/sqrt()
	    }

	    return x;                        // return sqrt(squarD) with precision of rootMC
	  }

}
