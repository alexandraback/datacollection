import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class CoinJam {

	public static void main(String[] args) throws NumberFormatException, IOException {
		//BufferedReader br = new BufferedReader(new FileReader("B-large.in"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		for(int ii = 1 ; ii <=n ; ii ++) {
			char[] r = br.readLine().toCharArray();
			int[] count = new int[28];
			int[] numCount = new int[10];
			
			for(int i = 0 ; i < r.length ; i ++){
				count[r[i] - 'A'] ++;
			}
			
			for(int i = 0 ; i < count.length; i ++){
				if (count[i] == 0)
					continue;
				switch(i){
					case ('Z'-'A') :// 0
						numCount[0] += count[i];
						
						count['E'-'A'] -= count[i];
						count['O' - 'A'] -= count[i];
						count['R'-'A'] -= count[i];
						count['Z'-'A'] -= count[i];
						break;
					case ('W'-'A'): //2
						numCount[2] += count[i];
						count['T'-'A'] -= count[i];
						count['O'-'A'] -= count[i];
						count['W'-'A'] -= count[i];
						break;
					case ('U'-'A'): //4
						numCount[4] += count[i];
						count['F'-'A'] -= count[i];
						count['O'-'A'] -= count[i];
						count['R'-'A'] -= count[i];
						count['U'-'A'] -= count[i];
						break;
					case ('X'-'A'): //6
						numCount[6] += count[i];
						count['S'-'A'] -= count[i];
						count['I'-'A'] -= count[i];
						count['X'-'A'] -= count[i];
						break;
					case ('G'-'A'): //8
						numCount[8] += count[i];
						count['E'-'A'] -= count[i];
						count['I'-'A'] -= count[i];
						count['H'-'A'] -= count[i];
						count['T'-'A'] -= count[i];
						count['G'-'A'] -= count[i];
						break;
				}
								
			}
			
			//1 3 5 7 9

			for(int i = 0 ; i < count.length; i ++){
				if (count[i] == 0)
					continue;
				switch(i){
					case ('O'-'A') :// 1
						numCount[1] += count[i];
						
						count['N'-'A'] -= count[i];
						count['E' - 'A'] -= count[i];
						count['O'-'A'] -= count[i];
						break;
					case ('R'-'A'): //3
						numCount[3] += count[i];
						count['T'-'A'] -= count[i];
						count['H'-'A'] -= count[i];
						count['E'-'A'] -= count[i];
						count['E'-'A'] -= count[i];
						count['R'-'A'] -= count[i];
						break;
					case ('F'-'A'): //5
						numCount[5] += count[i];
						count['I'-'A'] -= count[i];
						count['V'-'A'] -= count[i];
						count['E'-'A'] -= count[i];
						count['F'-'A'] -= count[i];
						break;
				}
								
			}

			for(int i = 0 ; i < count.length; i ++){
				if (count[i] == 0)
					continue;
				switch(i){
					case ('V'-'A') :// 7
						numCount[7] += count[i];
						
						count['S'-'A'] -= count[i];
						count['E' - 'A'] -= count[i];
						count['E'-'A'] -= count[i];
						count['N' - 'A'] -= count[i];
						count['V'-'A'] -= count[i];
						break;
					case ('I'-'A'): //9
						numCount[9] += count[i];
						count['N'-'A'] -= count[i];
						count['N'-'A'] -= count[i];
						count['E'-'A'] -= count[i];
						count['I'-'A'] -= count[i];
						break;
				}
								
			}
			ArrayList<Integer> list = new ArrayList<Integer>();
			
			for(int i = 0 ; i < numCount.length; i ++){
				for(int j = 0 ; j < numCount[i]; j++)
					list.add(i);
			}
			Integer[] x = list.toArray(new Integer[]{});
			Arrays.sort(x);
			System.out.print("Case #"+ii + ": ");
			for(int i : x){
				System.out.print(i);
			}
			System.out.println();
		}
	}
}
