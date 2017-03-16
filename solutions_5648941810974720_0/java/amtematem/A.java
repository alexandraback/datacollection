import java.io.*;
import java.util.*;

class A {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("A.in"));
        PrintWriter out = new PrintWriter(new File("A.out"));
		
		int tt = in.nextInt();
		in.nextLine();
		for(int tc=1; tc<=tt; ++tc) {            
			String ss = in.nextLine();
			int z = 0;
			int e = 0;
			int r = 0;
			int o = 0;
			int n = 0;
			int t = 0;
			int w = 0;
			int h = 0;
			int f = 0;
			int u = 0;
			int i = 0;
			int v = 0;
			int s = 0;
			int x = 0;
			int g = 0;
			for (int c = 0; c < ss.length(); c++) {
				if (ss.charAt(c) == 'Z') z++;
				if (ss.charAt(c) == 'E') e++;
				if (ss.charAt(c) == 'R') r++;
				if (ss.charAt(c) == 'O') o++;
				if (ss.charAt(c) == 'N') n++;
				if (ss.charAt(c) == 'T') t++;
				if (ss.charAt(c) == 'W') w++;
				if (ss.charAt(c) == 'H') h++;
				if (ss.charAt(c) == 'F') f++;
				if (ss.charAt(c) == 'U') u++;
				if (ss.charAt(c) == 'I') i++;
				if (ss.charAt(c) == 'V') v++;
				if (ss.charAt(c) == 'S') s++;
				if (ss.charAt(c) == 'X') x++;
				if (ss.charAt(c) == 'G') g++;
			}
			int c0 = z;			
			z -= c0;
			e -= c0;
			r -= c0;
			o -= c0;
			int c2 = w;
			t -= c2;
			w -= c2;
			o -= c2;
			int c4 = u;
			f -= c4;
			o -= c4;
			u -= c4;
			r -= c4;
			int c6 = x;
			s -= c6;
			i -= c6;
			x -= c6;
			int c8 = g;
			e -= c8;
			i -= c8;
			g -= c8;
			h -= c8;
			t -= c8;
			int c1 = o;
			o -= c1;
			n -= c1;
			e -= c1;
			int c3 = h;
			t -= c3;
			h -= c3;
			r -= c3;
			e -= c3;
			e -= c3;
			int c5 = f;
			f -= c5;
			i -= c5;
			v -= c5;
			e -= c5;
			int c7 = s;
			s -= c7;
			e -= c7;
			v -= c7;
			e -= c7;
			n -= c7;
			int c9 = i;
			n -= c9;
			i -= c9;
			n -= c9;
			e -= c9;
			assert(z + e + r + o + n + t + w + h + f + u + i + v + s + x + g == 0);
			out.print("Case #"+tc+": ");
			for (int c = 0; c < c0; c++) out.print("0");
			for (int c = 0; c < c1; c++) out.print("1");
			for (int c = 0; c < c2; c++) out.print("2");
			for (int c = 0; c < c3; c++) out.print("3");
			for (int c = 0; c < c4; c++) out.print("4");
			for (int c = 0; c < c5; c++) out.print("5");
			for (int c = 0; c < c6; c++) out.print("6");
			for (int c = 0; c < c7; c++) out.print("7");
			for (int c = 0; c < c8; c++) out.print("8");
			for (int c = 0; c < c9; c++) out.print("9");
			out.println();
        }
		
		out.close();
		in.close();
	}
}