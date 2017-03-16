import java.io.File;
import java.io.FileWriter;
import java.math.BigDecimal;
import java.util.Scanner;


public class first {

	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception { 
		Scanner sc = new Scanner(new File("in.txt"));
		FileWriter out = new FileWriter(new File("out.txt"));
		int T = new Integer(sc.nextLine());
		for(int i = 1 ; i < T+1 ; i++)
		{
			BigDecimal r = new BigDecimal(sc.next());
			BigDecimal t = new BigDecimal(sc.next());
			int res=0;
			BigDecimal mintwo = new BigDecimal("-2");
			BigDecimal two = new BigDecimal("2");
			BigDecimal four = new BigDecimal("4");
			BigDecimal eight = new BigDecimal("8");
			BigDecimal ikirbir = r.multiply(two).subtract(BigDecimal.ONE);
			BigDecimal result = 
				(mintwo.multiply(r).add(BigDecimal.ONE) .add( (
					 sqrt( 
										(	(ikirbir.multiply(ikirbir) )   .add(eight.multiply(t))  )   , 12
							)
					
					))).divide(four);
			
			System.out.println(result);
			System.out.println("Case #"+i+": "+result.intValue());
			out.write("Case #"+i+": "+result.intValue()+"\n");
			try{ sc.nextLine();}
			catch(Exception e){}

		}
		out.flush();
		sc.close();
		out.close(); 
}
	 public static BigDecimal sqrt(BigDecimal n, int s) {
		    BigDecimal TWO = BigDecimal.valueOf(2);

		    // Obtain the first approximation
		    BigDecimal x = n
		        .divide(BigDecimal.valueOf(3), s, BigDecimal.ROUND_DOWN);
		    BigDecimal lastX = BigDecimal.valueOf(0);

		    // Proceed through 50 iterations
		    for (int i = 0; i < 500; i++) {
		      x = n.add(x.multiply(x)).divide(x.multiply(TWO), s,
		          BigDecimal.ROUND_DOWN);
		      if (x.compareTo(lastX) == 0)
		        break;
		      lastX = x;
		    }
		    return x;
		  }
}
