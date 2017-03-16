import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class B {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		

		Scanner sc = null;
		if (args != null && args.length > 0) {
			
			try {
				sc = new Scanner(new File(args[0]));
					
				if (args.length > 1) {
					System.setOut(new PrintStream(new BufferedOutputStream(new FileOutputStream(new File(args[1])), 128)));
				}
			} catch (FileNotFoundException e) {
				
				// e.printStackTrace();
				sc = new Scanner(System.in);
			}
			
		} else {
			
			sc = new Scanner(System.in);
		}

		int T = Integer.valueOf(sc.nextLine());
		
		for (int i = 0; i < T; i++) {
			
			int N = sc.nextInt();
			List<Level> level = new LinkedList<Level>();
			for (int j = 0; j < N; j++) {
				Level l = new Level();
				
				l.needfor1 = sc.nextInt();
				l.needfor2 = sc.nextInt();
				level.add(l);
			}
			int answer = solve(N, level);
			if (answer != 0) { 
				System.out.printf("Case #%d: %s\n", i + 1, answer);
			} else {
				System.out.printf("Case #%d: %s\n", i + 1, "Too Bad");
			}
			
		}
		System.out.close();

	}
	
	public static int solve(int N, List<Level> level) {
		int answer = 0;
		int stars = 0;
		passLevel:while (stars < 2 * N && level.size() > 0) {
			
			// find if we can pass a level by star 2
			for (Iterator<Level> it = level.iterator(); it.hasNext();) {
				Level l = it.next();
				if (stars >= l.needfor2 && l.passed2 != true) {
					
					if (!l.passed1) {
						stars += 2;
					} else {						
						stars++;
					}
					l.passed2 = true;
					answer++;
					it.remove();
					continue passLevel;
				}			
			}
			
			// no star2 find
			for (Iterator<Level> it = level.iterator(); it.hasNext();) {
				Level l = it.next();
				if (stars >= l.needfor1 && l.passed1 != true) {
					
					stars++;
					l.passed1 = true;
					answer++;
					
					continue passLevel;
				}			
			}
			
			break;
		}	
		
		return answer;
	}
	
	
	static class Level {
		
		int needfor1 = 0;
		int needfor2 = 0;
		boolean passed1 =false;
		boolean passed2 = false;
		
	}
}
