package codejam;

import java.io.RandomAccessFile;
import java.util.StringTokenizer;

public class CookieClicker {
	
	double farmPrice, farmProduce, target;
	public CookieClicker(RandomAccessFile rafin) throws Exception{
		String inputline;
		StringTokenizer st;
		
		inputline = rafin.readLine();
		st = new StringTokenizer(inputline," ");
		farmPrice = Double.parseDouble(st.nextToken());
		farmProduce = Double.parseDouble(st.nextToken());
		target = Double.parseDouble(st.nextToken());
	}
	
	public CookieClicker() {
		// TODO Auto-generated constructor stub
	}

	public double getStatus() {
		double cookies = 0;
		double seconds = 0;
		double speed = 2;
		double gap,t;
		
		while (cookies < target) {
			if (cookies >= farmPrice) {
				gap = target-cookies;
				if (gap/speed > (gap+farmPrice)/(speed+farmProduce)) {
					cookies = cookies - farmPrice;
					speed += farmProduce;
				} else {
					seconds += gap/speed;
					cookies = target;
				}
			} else {
				t = Math.min(farmPrice, target);
				seconds += (t - cookies)/speed;
				cookies = t;
			}
		}
		
		return seconds;
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			/*
			CookieClicker bull = new CookieClicker();
			bull.radius = 2;
			bull.t = 4;
			System.out.println(bull.getStatus());
			
			if (true) return;
			*/
			String infilename="d:/codejam/data/CookieClicker.in";
			String outfilename="d:/codejam/data/CookieClicker.out";
			RandomAccessFile rafin = new RandomAccessFile(infilename, "r");
			RandomAccessFile rafout = new RandomAccessFile(outfilename, "rw");
			rafout.setLength(0);
			
			int count = Integer.parseInt(rafin.readLine().trim());
			CookieClicker o;
			System.out.println(count + " cases.");
			for (int i=1; i<=count; i++) {
				o = new CookieClicker(rafin);
				rafout.writeBytes("Case #" + i + ": " + o.getStatus());
				if (i<count)
					rafout.writeBytes("\r\n");
				System.out.println("Case " + i + " dealed!");
				System.gc();
			}
			
			rafin.close();
			rafout.close();
		} catch (Exception e) {
			e.printStackTrace(System.out);
		}

	}

}
