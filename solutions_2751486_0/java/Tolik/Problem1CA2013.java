import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.regex.Pattern;


public class Problem1CA2013 {
	private static Pattern p = Pattern.compile(" ");
	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		InputStream is = new FileInputStream("A-small-attempt3.in");
		Scanner sc = new Scanner(is);
		
		OutputStream os = new FileOutputStream("A-result.txt");
		PrintWriter pw = new PrintWriter(os);
		
		int n = Integer.parseInt(sc.nextLine());
		
		Set<Character> set = new HashSet<Character>();
		set.add('a');
		set.add('e');
		set.add('i');
		set.add('o');
		set.add('u');
		
		for (int i = 1; i <= n; i++){
			String tmp = sc.nextLine();
			String[] tmpAr = p.split(tmp);			
			
			String str = tmpAr[0];
			int m = Integer.parseInt(tmpAr[1]);
			
			int[] ar = new int [str.length()];
			
			if (set.contains(str.charAt(0))){
				ar[0] = 0;
			} else{
				ar[0] = 1;
			}
			
			for (int j = 1; j < ar.length; j++){
				if (set.contains(str.charAt(j))){
					ar[j] = 0;
				} else{
					ar[j] = ar[j-1] + 1;
				}
			}
			
			int[] ar2 = new int [str.length()];
			
			for (int j = ar.length - 1; j > ar.length - m; j--){
				ar2[j] = ar2.length;
			}
			
			for (int j = ar.length - m; j >= 0; j--){
				if (m == 1){
					if (ar[j] > 0){
						ar2[j] = j;
					} else{
						if ( j == ar2.length - 1){
							ar2[j] = ar2.length;
						} else{
							ar2[j] = ar2[j+1];
						}
					}
				}  else{
					if (ar[j + m - 1] - ar[j] >= m - 1 && ar[j] > 0){
						ar2[j] = j + m - 1;
					} else{
							ar2[j] = ar2[j+1];
					}
				}
			}
			
			int count = 0;
			for (int j = 0; j < ar2.length; j++){
				count += ar2.length - ar2[j];
			}	
			
			pw.println("Case #" + i + ": " + count);
			System.out.println("Case #" + i + ": " + count);
			System.out.println(Arrays.toString(ar2));
		}
		
		
		
		
		pw.close();
		
		sc.close();
		System.out.println("finished");
		
	}
}
