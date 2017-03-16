// Google Code Jam 2012 Round 1C
// Problem C. Box Factory

import java.util.*;
import java.io.*;

class BoxFactory{
    static String inname = "C-small-attempt1.in";    // input file name here
    static String outname = "C-small-attempt1.out";  // output file name here
    //static int[] a, A, b, B;
    public static void main(String[] args){
        try{
            Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
        	//Scanner in = new Scanner(System.in);
            BufferedWriter out = new BufferedWriter(new FileWriter(outname));
            int t = in.nextInt();
            in.nextLine();
            for (int cas = 1; cas <= t; cas++){
            	//String ans = "";
            	long ans = 0;
                int n = in.nextInt();
                int m = in.nextInt();
                long[]a = new long[n];
                int[]A = new int[n];
                long[]b = new long[m];
                int[]B = new int[m];
                for (int i = 0; i < n; i++){
                	a[i] = in.nextLong();
                	A[i] = in.nextInt();
                }
                for (int i = 0; i < m; i++){
                	b[i] = in.nextLong();
                	B[i] = in.nextInt();
                }
                ans = maxBoxed(a, A, b, B, 0, 0);
                //System.out.print("Case #" + cas + ": " + ans + "\n");
                out.write("Case #" + cas + ": " + ans + "\n");
            }
            in.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
	public static long maxBoxed(long[]a, int[]A, long[]b, int[]B, int as, int bs){
		//System.out.println(a.length + " " + b.length + " " + as + " " + bs);
		if (as >= a.length || bs >= b.length) return 0;
		long ans = 0;
		while (!(as >= a.length || bs >= b.length) && A[as] == B[bs]){
			if (a[as] > b[bs]){
				ans += b[bs];
				a[as] -= b[bs];
				b[bs] = 0;
				bs++;
			} else if (b[bs] > a[as]){
				ans += a[as];
				b[bs] -= a[as];
				a[as] = 0;
				as++;
			} else if (b[bs] == a[as]){
				ans += a[as];
				a[as] = 0;
				b[bs] = 0;
				as++; bs++;
			}
		}
		long ansThrowBox = maxBoxed(Arrays.copyOf(a, a.length), A, Arrays.copyOf(b, b.length), B, as+1, bs);
		long ansThrowToy = maxBoxed(Arrays.copyOf(a, a.length), A, Arrays.copyOf(b, b.length), B, as, bs+1);
		//System.out.println("ansthrowbox " + ansThrowBox + " throwToy " + ansThrowToy);
		ans += Math.max(ansThrowToy, ansThrowBox);
		return ans;
	}
}