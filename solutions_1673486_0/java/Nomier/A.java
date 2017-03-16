import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class A1 {
	public static void main(String[] args) {
		new A1().run();
	}

	private void run() {
		try {
			Scanner s = new Scanner(new File("A.in"));
			int n = s.nextInt();
			for (int i = 0; i < n; i++) {
				int a = s.nextInt();
				int b = s.nextInt();
				float ps[] = new float[a];
				for (int j = 0; j < ps.length; j++) {
					ps[j] = s.nextFloat();
				}
				int strokes[] = new int[a+2];
				strokes[0] = b - a +1;
				strokes[1] = b + 2;
				for (int j = 2; j < strokes.length; j++) {
					strokes[j] = strokes[0] + (j-1)*2;
				}
				int wrong[] = new int[a+2];
				wrong[0] = strokes[0] + b+1;
				wrong[1] = 0;
				for (int j = 2; j < strokes.length; j++) {
					wrong[j] = strokes[j] + b+1;
				}
				float p1[]=new float[a+2];
				float p2[]=new float[a+2];
				float expected[] = new float[a+2];
				float totalP = 1; 
				for (int j = 0; j < ps.length; j++) {
					totalP*=ps[j];
				}
				p1[0] = totalP;
				p2[0] = 1-totalP;
				p1[1] = 1;
				p2[1] = 0;
				for (int j = 2; j < p1.length; j++) {
					totalP=1;
					for (int j2 = 0; j2 < ps.length-j+1; j2++) {
						totalP*=ps[j2];
					}
					p1[j] = totalP;
					p2[j] = 1-totalP;
				}
				float min = p1[0] * strokes[0]  + p2[0]* wrong[0];
				for (int j = 0; j < expected.length; j++) {
					min = Math.min(min, expected[j] = p1[j] * strokes[j]  + p2[j]* wrong[j]);
				}
				System.out.println("Case #"+(i+1)+": "+min);
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
