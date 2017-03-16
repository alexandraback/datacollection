import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Scanner;

public class leadingZero {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader read = new BufferedReader(new InputStreamReader(
				System.in));
		String ll;
		ll = read.readLine();
		int a = Integer.parseInt(ll);
		for (int k = 0; k < a; k++) {
			Scanner scn=new Scanner(read.readLine());
			int A = scn.nextInt();
			int B = scn.nextInt();
			
			int[] s = new int[20000000];
			for (int i = A; i <= B; i++) {
				String r = i + "";
				int l = i;
				LinkedList<Integer>list=new LinkedList<Integer>();
				
				for (int j = 0; j < r.length() - 1; j++) {
					int b = l % 10;
					l = l / 10 + (int) Math.pow(10, r.length() - 1) * b;
					if (l > i && !list.contains(l))
					{
						s[l]++;
						list.add(l);
					}
				}
			}
			int sum = 0;
			for (int i = A; i <= B; i++) {
				if (s[i] > 0) {
					sum += s[i];
					//System.out.println(i+"  ..  "+s[i]);
				}
			}
			System.out.println("Case #"+(k+1)+": "+sum);
		}
	}

}
