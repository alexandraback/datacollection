package deceitfulwar;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class DeceitfulWar {

	static Scanner in=null;
	static PrintWriter out=null;
	
	public static void main(String[] args) {
		
		try {
		File file = new File("deceitfulwarin.txt");
		File file2=new File("deceitfulwarout.txt");
		in = new Scanner(file);
		out = new PrintWriter(file2);
		int testCases = in.nextInt();
		for (int i=0;i<testCases;i++) {
			solveCase(i+1);
		}
		out.close();
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void solveCase(int caseNum) throws Exception {
		int n = in.nextInt();
		double[] nao = new double[n];
		double[] ken = new double[n];
		for (int i=0;i<n;i++) {
			nao[i]=in.nextDouble();
		}
		for (int i=0;i<n;i++) {
			ken[i]=in.nextDouble();
		}
		int pointsWar = calcPoints(nao,ken);
		int pointsDeceit = nao.length-calcPoints(ken,nao);
		out.println("Case #"+caseNum+": "+pointsDeceit+" "+pointsWar);
	}
	
	public static int calcPoints(double[] p1, double[] p2) {
		int points=0;
		for (int i=p1.length;i>0;i--) {
			int lowestP1Index=0;
			for (int j=0;j<i;j++) {
				if (p1[j]<p1[lowestP1Index]) {
					lowestP1Index=j;
				}
			}
			double lowestP1Val=p1[lowestP1Index];
			p1[lowestP1Index]=p1[i-1];
			p1[i-1]=lowestP1Val;
			int lowestGoodP2Index=0;
			int lowestOverallP2Index=0;
			double lowestGoodP2Val=2;
			double lowestOverallP2Val=1;
			for (int j=0;j<i;j++) {
				if (p2[j]<lowestGoodP2Val && p2[j]>lowestP1Val) {
					lowestGoodP2Index=j;
					lowestGoodP2Val=p2[j];
				}
				if (p2[j]<lowestOverallP2Val) {
					lowestOverallP2Index=j;
					lowestOverallP2Val=p2[j];
				}
			}
			if (lowestGoodP2Val>1) {
				p2[lowestOverallP2Index]=p2[i-1];
				p2[i-1]=lowestOverallP2Val;
				points++;
			} else {
				p2[lowestGoodP2Index]=p2[i-1];
				p2[i-1]=lowestGoodP2Val;
			}
		}
		return points;
	}
}