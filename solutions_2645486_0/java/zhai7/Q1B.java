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

import javax.swing.JFileChooser;
import javax.swing.filechooser.FileNameExtensionFilter;



public class Q1B {

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
		
		Q1B q = new Q1B();
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
		int ee, rr, nn;
		int[] vv;
		int[] cc;
		int[] aa;
		
		Child(Scanner in){
			Scanner line = new Scanner(in.nextLine());
			ee = line.nextInt();
			rr = line.nextInt();
			nn = line.nextInt();
			line.close();
			vv = new int[nn];
			cc = new int[nn];
			aa = new int[nn];
			line = new Scanner(in.nextLine());
			for(int i = 0; i < nn; i++)
				vv[i] = line.nextInt();
			line.close();
		}
		
		long Calc(){
			cc[0] = ee;
			aa[0] = rr;
			int j, th, mv;
			long res = (long) cc[0] * (long) vv[0];
			for(int i = 1; i < nn; i++){
				th = ee - rr;
				cc[i] = rr;
				aa[i] = rr;
				res += (long) vv[i] * (long) rr;
				for(j = i - 1; j >= 0; j--){
					if(vv[j] > vv[i])
						break;
					mv = th < cc[j] ? th : cc[j];
					th -= mv;
					cc[j] -= mv;
					cc[i] += mv;
					res += (long) (vv[i] - vv[j]) * (long) mv;
					if(th == 0 || j == 0 || vv[j-1] < vv[j])
						break;
				}
			}
			return res;
		}
		
		@Override
		public void run() {
			result = "" + Calc();
		}
		
	}
}