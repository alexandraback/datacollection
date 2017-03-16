import java.io.*;
import java.lang.*;
class Solution {

	public static void main (String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			int cases = Integer.parseInt(br.readLine());
			String[] line;
			String sequence;
			int length;
			int reps;
			String[] multiplied;
			String previous;
			int counter;
			boolean foundi;
			boolean foundk;
			for (int i = 1; i <= cases; i++) {
				line=br.readLine().trim().split(" ");
				length = Integer.parseInt(line[0]);
				if (line[1].length() > 5) {
					reps = Integer.parseInt(line[1].substring(line[1].length()-2,line[1].length()));
				}
				else {
					reps = Integer.parseInt(line[1]);
				}
				sequence = br.readLine().trim();
				if (length*reps < 3) {

					System.out.println("Case #"+i+": "+"NO");
					continue;
				}
				
				if (reps > 8) {
					reps = 8 + reps%4;
				}
				multiplied = new String[reps*length];
				previous = "1";
				counter = 0;
				foundi = false;
				foundk = false;
				//System.out.println("reps: "+reps);
				for (int j = 0; j < reps; j++) {
					for (int k = 0; k < length; k++) {
						multiplied[counter] = multiply(previous, (sequence.charAt(k)+""));
						previous = multiplied[counter];
						//System.out.println("multiplied[counter] "+multiplied[counter]+" foundi "+foundi+" foundk "+foundk);
						//System.out.print(multiplied[counter]+" ");
						if (!foundi && multiplied[counter].equals("i")) {
							foundi = true;
							//System.out.println("foundi");
						}
						else if (foundi && !foundk && multiplied[counter].equals("k")) {
							foundk = true;
							//System.out.println("foundk");
						}
						counter++;
					}
					
				}
				//System.out.println();
				//System.out.println("length "+length+" counter-1 "+(counter-1)+" multiplied[counter-1] "+multiplied[counter-1]);
				if (foundi && foundk && multiplied[counter-1].equals("-1")) {
					System.out.println("Case #"+i+": "+"YES");
				}
				else {
					System.out.println("Case #"+i+": "+"NO");
				}
				
			}
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
	static String multiply(String a, String b) {
		if (a.equals("1")) {
			return b;
		}
		if (b.equals("1")) {
			return a;
		}
		if (a.equals("-1")) {
			if (b.length()==2) {
				return b.charAt(1)+"";
			}
			return "-"+b;
		}
		if (b.equals("-1")) {
			if (a.length()==2) {
				return a.charAt(1)+"";
			}
			return "-"+a;
		}
		boolean positive = true;
		String ans="0";
		if (a.length() == 2) {
			positive = !positive;
			a = a.charAt(1)+"";
		}
		if (b.length() == 2) {
			positive = !positive;
			b = b.charAt(1)+"";
		}
		if (a.equals(b)) {
			if (!positive) {
				return "1";
			}
			return "-1";
		}
		if ((a.equals("i") && b.equals("j"))) {
			ans = "k";
		}
		if (a.equals("j") && b.equals("i")) {
			ans = "k";
			positive = !positive;
		}

		if (a.equals("k") && b.equals("i")) {
			ans = "j";
		}
		if (a.equals("i") && b.equals("k")) {
			ans = "j";
			positive = !positive;
		}

		if (a.equals("j") && b.equals("k")) {
			ans = "i";
		}
		if (a.equals("k") && b.equals("j")) {
			ans = "i";
			positive = !positive;
		}

		if (!positive) {
			ans = "-"+ans;
		}
		return ans;
	}

}