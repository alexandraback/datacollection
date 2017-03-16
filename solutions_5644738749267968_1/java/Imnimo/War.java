import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class War {
	public static void main(String[] args) throws Exception {
		double[] ken = new double[]{0.916,0.728,0.271,0.520,0.700,0.521,0.215,0.341,0.458};
		double[] naomi = new double[]{0.186,0.389,0.907,0.832,0.959,0.557,0.300,0.992,0.899};
		
		Scanner s = new Scanner(new File("D-large.in"));
		String firstLine = s.nextLine();
		int numCases = Integer.parseInt(firstLine);
		for(int c = 1;c<=numCases;c++) {
			s.nextLine();
			String naomiString = s.nextLine();
			String kenString = s.nextLine();
			String[] nArr = naomiString.split(" ");
			String[] kArr = kenString.split(" ");
			ken = new double[kArr.length];
			naomi = new double[nArr.length];
			for(int i = 0;i<kArr.length;i++) {
				naomi[i] = Double.parseDouble(nArr[i]);
				ken[i] = Double.parseDouble(kArr[i]);
			}
			int dScore = deceitfulScore(ken,naomi);
			int rScore = regularScore(ken,naomi);
			System.out.println("Case #" + c + ": " + dScore + " " + rScore);
		}
		
	
		
	}
	public static int regularScore(double[] ken,double[] naomi) {
		Arrays.sort(ken);
		Arrays.sort(naomi);
		int nScore = 0;
		
		
		ArrayList<Double> kList = new ArrayList<Double>();
		ArrayList<Double> nList = new ArrayList<Double>();
		for(double d : ken) {
			kList.add(d);
		}
		for(double d : naomi) {
			nList.add(d);
		}
		while(nList.size()>0) {
			boolean beaten = false;
			double nPlay = nList.remove(0);
			for(int i = 0;i<kList.size();i++) {
				if(kList.get(i)>nPlay) {
					kList.remove(i);
					beaten = true;
					break;
				}
			}
			if(!beaten) {
				nScore++;
			}
		}
		return nScore;
	}
	public static int deceitfulScore(double[] ken, double[] naomi) {
		Arrays.sort(ken);
		Arrays.sort(naomi);
		int kMin = 0;
		int kMax = ken.length-1;
		int nMin = 0;
		int nMax = naomi.length -1;
		int kScore = 0;
		int nScore = 0;
		int round = 0;
		while(round < ken.length) {
			while(round < ken.length && naomi[nMin]<ken[kMin]) {
				//System.out.println("Naomi plays " + naomi[nMin] + " vs Ken's " + ken[kMax]);
				kScore++;
				kMax--;
				nMin++;
				round++;
			}
			
			while(round < ken.length && naomi[nMin]>ken[kMin] ) {
				//System.out.println("Naomi plays " + naomi[nMin] + " vs Ken's " + ken[kMin]);
				nScore++;
				nMin++;
				kMin++;
				round++;
			}
		}
		return nScore;
	}
}
