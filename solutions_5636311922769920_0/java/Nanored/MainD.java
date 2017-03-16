import java.io.*;

public class MainD {
	
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
				while((i = f.read()) != 10) {
					s += (char)i;
					if(i == 32) s = "";
				}
				f2.write("Case #" + j + ":");
				int a = Integer.valueOf(s);
				for(int m = 1; m <= a; m++)
					f2.write(" " + m);
				f2.write("\n");
				s = "";
		    }
			f.close();
			f2.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}