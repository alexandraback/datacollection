import java.io.*;
import java.util.*;
import java.awt.*;
import static java.lang.System.*;

public class C {
	public static void main (String [] args) throws IOException {new C().run();}
	public void run() throws IOException{
		Scanner file = new Scanner(new File("C-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("C.out")));
		
		int times = file.nextInt();
		for(int asdf = 0; asdf<times; asdf++){
			int a = file.nextInt(), b = file.nextInt();
			HashSet<Point> set = new HashSet<Point>();
			for(int i = a; i<=b; i++){
				String s = ""+i;
				for(int j = 1; j<s.length(); j++){
					if( s.charAt(j) >= s.charAt(0) ){
						int x = Integer.parseInt(s.substring(j,s.length()) +s.substring(0,j));
						if( i<x && x<=b ){set.add(new Point(i,x));
						//System.out.println (i +" " + x);
						}
					}
				}
			}
			out.println("Case #"+(asdf+1)+": "+set.size());
		}
		out.close();
		System.exit(0);
	}
}