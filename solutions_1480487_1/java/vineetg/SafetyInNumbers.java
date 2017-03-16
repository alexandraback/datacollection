import java.io.File;
import java.io.PrintWriter;
import java.util.*;

public class SafetyInNumbers {
	public static void main(String[] args) throws Exception{
		Scanner scanner = new Scanner(new File("A-large.in"));
		int num = scanner.nextInt();
		scanner.nextLine();
		PrintWriter writer = new PrintWriter(new File("Safety.txt"));
		for (int a = 1; a <= num; a++) {
			int N = scanner.nextInt();
			int[] scores = new int[N];
			int[] sorted = new int[N];
			int total = 0;
			for(int i = 0;i<N;i++) {
				scores[i]=scanner.nextInt();
				sorted[i]=scores[i];
				total+=sorted[i];
			}
			Map<Integer,Double> answers = new HashMap<Integer,Double>();
			Arrays.sort(sorted);
			for(int i = 0;i<N;i++) {
				int[] tmp = new int[N-1];
				int index=0;
				for(int j = 0;j<N-1;j++) {
					if(index==i) {
						index++;
						j--;
						continue;
					}
					tmp[j]=sorted[index++];
				}
				int[] array = new int[N];
				for(int j = 0;j<N-1;j++) {
					if(j==0) {
						array[0]=sorted[i]-tmp[0];
					} else {
						array[j]=array[j-1]+sorted[i]-tmp[j];
					}
					//System.out.println(sorted[i] + " "  + array[j]);
					double fin = (1.0*total - array[j])/(j+2);
					
					if(j==0 || fin/total*100<answers.get(sorted[i])) {
						answers.put(sorted[i],Math.max(fin/total*100,0));
					}
				}
			}
			String string = "";
			for(int j = 0;j<N;j++) {
				string+=answers.get(scores[j]) + " ";
			}
			writer.println("Case #" + a + ": " + string.trim());
			System.out.println("Case #" + a + ": " + string.trim());
			writer.flush();

		}
		writer.close();
	}
}
