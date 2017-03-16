import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.MathContext;


public class ProblemaGranjas {
	private static BigDecimal baseProduction = new BigDecimal(2.0);
	private BigDecimal C; //Farm Cost
	private BigDecimal F; //Farm production
	private BigDecimal X; //Goal


	public ProblemaGranjas(BigDecimal c, BigDecimal f, BigDecimal x){
		C = c;
		F = f;
		X = x;
	}

	public BigDecimal estimateTime(int nFarm, BigDecimal goal){
		return goal.divide(((F.multiply(new BigDecimal(nFarm)).add(baseProduction))),MathContext.DECIMAL64);
	}
	public BigDecimal solve(){ //Find optimal
		int n = 0;
		BigDecimal time = estimateTime(n, X);//total time last iteration
		BigDecimal acum = BigDecimal.ZERO;
		while(true){
			acum = acum.add(estimateTime(n, C));//times to take to build a new farm with current production
			n++;
			BigDecimal timeToReachGoalAfterBuyingFarm = estimateTime(n, X);
			BigDecimal totalTime = timeToReachGoalAfterBuyingFarm.add(acum);
			if(totalTime.compareTo(time)>0){
				//new time is bigger, last iteration is better
				return time;
			}
			time = totalTime;	
		}
	}
	static public void main(String[] args) throws IOException{
		BufferedReader bf = new BufferedReader(new FileReader("input_cookies.txt"));
		int nTest = Integer.parseInt(bf.readLine());
		for(int t = 1;t<=nTest;t++){
			String[] fila = bf.readLine().split(" ");
			BigDecimal c = new BigDecimal(fila[0]);
			BigDecimal f = new BigDecimal(fila[1]);
			BigDecimal x = new BigDecimal(fila[2]);
			ProblemaGranjas test = new ProblemaGranjas(c, f, x);
			System.out.println("Case #"+t+": "+test.solve());
		}
		bf.close();
	}
}
