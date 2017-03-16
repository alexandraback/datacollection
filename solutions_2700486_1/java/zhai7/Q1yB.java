import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;
import org.apache.commons.math3.util.ArithmeticUtils;

import javax.swing.JFileChooser;
import javax.swing.filechooser.FileNameExtensionFilter;



public class Q1yB {

	int cn;
	Child[] ch;

	public static void main(String[] args) throws ExecutionException, Throwable{
		JFileChooser jfc = new JFileChooser("./iofile");
		jfc.setFileFilter(new FileNameExtensionFilter(null, "in"));
		while(jfc.showOpenDialog(null) != JFileChooser.APPROVE_OPTION);
		File fi = jfc.getSelectedFile();
		String fo = fi.getPath();
		fo = fo.substring(0, fo.length() - 2) + "out";
		PrintStream ps = new PrintStream(fo);
		
		Q1yB q = new Q1yB();
		q.ReadInput(fi);
		
		boolean large = fi.getName().contains("large");
		q.PrintOutput(ps, large);
		ps.close();
	}
	
	void ReadInput(File fi) throws IOException{
		Scanner in = new Scanner(fi);
		Scanner line = new Scanner(in.nextLine());
		cn = line.nextInt();
		line.close();
		ch = new Child[cn];
		for(int c = 0; c < cn; c++){
			ch[c] = new Child(in);
		}
		in.close();
	}
	
	
	void PrintOutput(PrintStream ps, boolean large) throws IOException, Throwable, ExecutionException{
		if(large){
			ExecutorService exec = Executors.newFixedThreadPool(Runtime.getRuntime().availableProcessors());
			Future[] fc = new Future[cn];
			for(int c = 0; c < cn; c++){
				fc[c] = exec.submit(ch[c]);
			}
			exec.shutdown();
			for(int c = 0; c < cn; c++){
				while(!fc[c].isDone())
					Thread.sleep(10000);
				ps.format("Case #%d: %s\n", c + 1, ch[c].result);
			}
		}
		else{
			for(int c = 0; c < cn; c++){
				ch[c].run();
				ps.format("Case #%d: %s\n", c + 1, ch[c].result);
			}
		}
	}
	
	static class Child implements Runnable{
		String result = "";
		int x, y, n;
		
		Child(Scanner in){
			Scanner line = new Scanner(in.nextLine());
			n = line.nextInt();
			x = line.nextInt();
			y = line.nextInt();
			line.close();
		}
		
		int count(int x){
			return 2 * x * x - x;
		}
		
		double Calc(){
			if(x < 0)
				x = -x;
			double lvl = (1.0 + Math.sqrt(1.0 + 8 * (double) n)) / 4;
			int min = (int) Math.floor(lvl);
			int max = (int) Math.ceil(lvl);
			if(count(min) > n)
				min--;
			if(count(max) < n)
				max++;
			int ll = (x + y) / 2 + 1;
			if(ll <= min)
				return 1;
			if(ll > max)
				return 0;
			int rem = n - count(min);
			int tar = y + 1;
			if(rem >= 2 * min + tar)
				return 1;
			if(rem < tar)
				return 0;
			if(tar == 2 * min + 1)
				return 0;
			double res = 0;
			for(int j = tar; j <= rem; j++)
				res += ArithmeticUtils.binomialCoefficientDouble(rem, j);
			return res / Math.pow(2, rem);
		}
		
		@Override
		public void run() {
			result = String.format("%.9g", Calc());
		}
		
	}
}