import java.util.*;
import java.io.*;

public class A
{
	public static void main(String[] args) throws Exception
	{
		//Scanner in = new Scanner(System.in);
		Scanner in = new Scanner(new File("A-large.in"));
		PrintStream out = new PrintStream(new File("A-large.out"));
		int t = in.nextInt();
		for (int i = 1; i <= t; i++) 
		{
			String s = in.next();
			
			int[] freq = new int[26];
			int[] a = new int[10];
			for (int j = 0; j < s.length(); j++) {
				freq[s.charAt(j)-'A']++;
			}

			String ans = "";
			
			int zero = freq['Z'-'A'];
			if (zero > 0) {
				freq['Z'-'A'] -= zero;
				freq['E'-'A'] -= zero;
				freq['R'-'A'] -= zero;
				freq['O'-'A'] -= zero;
				a[0] = zero;
			}

			int two = freq['W'-'A'];
			if (two > 0) {
				freq['T'-'A'] -= two;
				freq['W'-'A'] -= two;
				freq['O'-'A'] -= two;
				a[2] = two;
			}

			int six = freq['X'-'A'];
			if (six > 0) {
				freq['S'-'A'] -= six;
				freq['I'-'A'] -= six;
				freq['X'-'A'] -= six;
				a[6] = six;
			}

			int ei = freq['G'-'A'];
			if (ei > 0) {
				freq['E'-'A'] -= ei;
				freq['I'-'A'] -= ei;
				freq['G'-'A'] -= ei;
				freq['H'-'A'] -= ei;
				freq['T'-'A'] -= ei;
				a[8] = ei;
			}
			
			six = freq['S'-'A'];
			if (six > 0) {
				freq['S'-'A'] -= six;
				freq['E'-'A'] -= 2*six;
				freq['V'-'A'] -= six;
				freq['N'-'A'] -= six;
				a[7] = six;
			}

			six = freq['V'-'A'];
			if (six > 0) {
				freq['F'-'A'] -= six;
				freq['I'-'A'] -= six;
				freq['V'-'A'] -= six;
				freq['E'-'A'] -= six;
				a[5] = six;
			}

			six = freq['F'-'A'];
			if (six > 0) {
				freq['F'-'A'] -= six;
				freq['O'-'A'] -= six;
				freq['U'-'A'] -= six;
				freq['R'-'A'] -= six;
				a[4] = six;
			}

			six = freq['R'-'A'];
			if (six > 0) {
				freq['T'-'A'] -= six;
				freq['H'-'A'] -= six;
				freq['R'-'A'] -= six;
				freq['E'-'A'] -= 2*six;
				a[3] = six;
			}	

			six = freq['O'-'A'];
			if (six > 0) {
				freq['O'-'A'] -= six;
				freq['N'-'A'] -= six;
				freq['E'-'A'] -= six;
				a[1] = six;
			}

			six = freq['I'-'A'];
			if (six > 0) {
				freq['N'-'A'] -= 2*six;
				freq['I'-'A'] -= six;
				freq['E'-'A'] -= six;
				a[9] = six;
			}

			out.print("Case #"+i+": ");
			for (int j = 0; j < 10; j++) {
				char c = (char)(j+48);
				for (int kk = 0; kk < a[j]; kk++) {
					out.print(c);
				}
			}
			out.println();
		}
	}
}