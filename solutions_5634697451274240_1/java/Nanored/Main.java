import java.io.*;

public class Main {
	
	public static boolean test(boolean[] b) {
		for(boolean bo : b)
			if(!bo) return false;
		return true;
	}

  public static void main(String[] args) {
		try {
			FileReader f = new FileReader(args[0]);
			FileWriter f2 = new FileWriter(args[0].replaceAll(".in", ".out"));
			String s = "";
			int i = 0;
			while((i = f.read()) != 10)
				s += (char)i;
			int t = Integer.valueOf(s);
			s = "";
			for (int j = 1; j <= t; j++) {
				while((i = f.read()) != 10)
					s += (char)i;
				;
				char[] s2 = s.toCharArray();
				s = "";
				char c = '+';
				int r = 0;
				for(int n = s2.length-1; n >= 0; n--) {
					if(s2[n] != c) {
						r ++;
						c = s2[n];
					}
				}
				f2.write("Case #" + j + ": " + r + "\n");
		    }
			f.close();
			f2.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
  }
 
}