import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

import javax.swing.RowFilter.ComparisonType;

public class Problem1 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int lines = scan.nextInt();
		
		for (int l = 0 ; l < lines ; l++) {
			int num = scan.nextInt();
			int sum = 0;
			int score[] = new int[num];
			
			int index[] = new int[num];
			Judge[] list = new Judge[num];
			for(int i = 0 ; i < num ; i++) {
				score[i] = scan.nextInt();
				list[i] = new Judge(score[i], i);
				sum += score[i];
			}
			Arrays.sort(list, new NewComparator1());
			
			double per[] = new double[num];
			double min = 200.0 / (double)num;
			
			double sumForMin = 100.0;
			int divide = 0;
			for(int i = 0 ; i < num ; i++) {
				per[i] = (double)score[i] / (double)sum * 100.0;
				if(min > per[i]) {
					sumForMin += per[i];
					divide++;
				}
			}
//			Arrays.sort(per);
			min = sumForMin / divide;
			
			double pass[] = new double[num];
			
			System.out.printf("Case #%d: ", l+1);
			for(int i = 0 ; i < num ; i++) {
				if(min - per[i] < 0)
					System.out.printf("%.6f", 0.0);
				else
					System.out.printf("%.6f", min - per[i]);
				if(i != num - 1) System.out.printf(" ");
				else  System.out.println();
			}
		}
	}
	
	

}

class Judge {
	int score;
	int index;
	
	public Judge(int score, int index) {
		this.score = score;
		this.index = index;
	}
}

class NewComparator1 implements Comparator<Judge> {

	@Override
	public int compare(Judge arg0, Judge arg1) {
		return arg1.score - arg0.score;
	}
}

class NewCompartor2 implements Comparator<Judge> {
	@Override
	public int compare(Judge o1, Judge o2) {
		// TODO Auto-generated method stub
		return o1.index - o2.index;
	}
}
