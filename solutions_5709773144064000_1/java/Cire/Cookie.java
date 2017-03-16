import java.io.*;
import java.util.*;

public class Cookie {
	//private DataInputStream in;
	private PrintWriter out;
	private Scanner in;
	
	Cookie() throws IOException {
		out = new PrintWriter(new FileWriter("output.txt"), true);		
	
		in = new Scanner(new File("input.txt"));
	}
	
	public void run() throws IOException {
		double c = in.nextDouble();
		double f = in.nextDouble();
		double x = in.nextDouble();
		double r = 2;
		
		int b = Math.max(0, (int) Math.ceil(x/c - r/f - 1) );
		
		double time = 0;
		
		for(int i = 0; i < b; i ++) {
			time += c/(r+i*f);
		}
		time+= x/(r+b*f);
		out.println(time);
		
	}
	
	public static void main(String[] args) throws IOException {

		Cookie m = new Cookie();

		int T = m.in.nextInt();
		for(int i=1; i<=T; i++) {
			m.out.print("Case #" + i + ": ");
			m.run();
		}
		return;
	}
}
