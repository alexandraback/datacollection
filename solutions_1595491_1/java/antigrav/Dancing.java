package codejam2.dancing;

import java.util.Scanner;

import codejam2.CodejamCase;
import codejam2.CodejamRunner;

public class Dancing extends CodejamRunner implements CodejamCase {

	private int nGooglers;
	private int surprising;
	private int pointMin;
	private int[] points;
	private String result;
	@Override
	public void compute() {
		int ns = 0;
		int s = 0;
		
		for(int i = 0; i < nGooglers; i++) {
			if(points[i] >= 3*pointMin-2)
				ns++;
			else if(pointMin>1 && points[i] >= 3*pointMin-4)
				s++;
		}
		result = String.valueOf(ns + Math.min(s, surprising));

	}

	@Override
	public String getOutput() {
		return result;
	}

	@Override
	public CodejamCase parseCase(Scanner s) {
		Dancing d = new Dancing();
		d.nGooglers = s.nextInt();
		d.surprising = s.nextInt();
		d.pointMin = s.nextInt();
		d.points = new int[d.nGooglers];
		for(int i = 0; i < d.nGooglers; i++)
			d.points[i] = s.nextInt();
		return d;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new Dancing().run(args);
	}

}
