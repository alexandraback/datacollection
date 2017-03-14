import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class HallOfMirrorsSmall {
	
	private static final double EPSILON = 10e-9;
	
	public static void main(String[] args) {
		try {
			System.setOut(new PrintStream(new FileOutputStream("output.txt")));
			Scanner scanner = new Scanner(new File(args[0]));
			int testsNum = scanner.nextInt();
			
			String solution;
			for (int i=1; i<=testsNum; i++) {
				solution = solve(scanner);
				System.out.println("Case #"+i+": "+solution);
				System.err.println("Case #"+i+": "+solution);
			}
		} catch (Exception e) {e.printStackTrace();}
	}
	
	private static String solve(Scanner scanner) {
		int h = scanner.nextInt();
		int w = scanner.nextInt();
		int d = scanner.nextInt();
		
		double x=0,y=0;
		String raw;
		for (int i=0; i<h; i++) {
			raw = scanner.next();
			if (raw.indexOf('X')>-1) {
				x=raw.indexOf('X')-0.5;
				y=i-0.5;
			}
		}
		w-=2;
		h-=2;
		
		int hRep = (int)Math.ceil((double)d/w);
		int vRep = (int)Math.ceil((double)d/h);
		
		int ret=0;
		double x2, y2;
		Set<Double> angles = new HashSet<Double>();
		for (int i=-hRep; i<=hRep; i++) {
			for (int j=-vRep; j<=vRep; j++) {
				if (i==0 && j==0) continue;
				
				x2=(i%2==0?x:w-x) + i*w;
				y2=(j%2==0?y:h-y) + j*h;
				// check distance
				if (Math.sqrt(Math.pow(Math.abs(x2-x), 2)+Math.pow(Math.abs(y2-y), 2)) <= d) {
					double angle = Math.atan2(y2-y, x2-x);
					boolean found=false;
					for (double a:angles) {
						if (Math.abs(a-angle)<EPSILON) found=true;
					}
					if (!found) {
						angles.add(angle);
						ret++;
					}
				}
			}
		}
		
		return ""+ret;
	}
}
