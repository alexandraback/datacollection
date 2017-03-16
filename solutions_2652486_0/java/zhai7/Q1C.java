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



public class Q1C {
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
		
		Q1C q = new Q1C();
		q.ReadInput(fi);
		
		boolean large = fi.getName().contains("large");
		q.PrintOutput(ps, large);
		ps.close();
	}
	
	void ReadInput(File fi) throws IOException{
		Scanner in = new Scanner(fi);
		in.nextLine();
		in.nextLine();
		cn = 100;
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
			ps.format("Case #1:\n");
			for(int c = 0; c < cn; c++){
				ch[c].run();
				ps.format("%s\n", ch[c].result);
			}
		}
	}
	
	static class Child implements Runnable{
		String result = "";
		int[] pp = new int[7];
		int[] prime = {2, 3, 5};
		
		Child(Scanner in){
			Scanner line = new Scanner(in.nextLine());
			for(int i = 0; i < 7; i++)
				pp[i] = line.nextInt();
			line.close();
		}
		
		int[] fact(int p){
			int[] res = new int[3];
			for(int i = 0; i < prime.length && p != 1; i++){
				while(p % prime[i] == 0){
					p /= prime[i];
					res[i]++;
				}
			}
			return res;
		}
		
		String Calc(){
			int[][] ff = new int[7][];
			int[] fm = new int[3];
			for(int i = 0; i < 7; i++){
				ff[i] = fact(pp[i]);
				for(int j = 0; j < 3; j++)
					if (fm[j] < ff[i][j])
						fm[j] = ff[i][j];
			}
			int[] res = new int[6];
			String rs = "";
			if(fm[1] == 1){
				rs += 3;
			}else if(fm[1] == 2){
				rs += 33;
			}else if(fm[1] == 3){
				rs += 333;
			}
			if(fm[2] == 1){
				rs += 5;
			}else if(fm[2] == 2){
				rs += 55;
			}else if(fm[2] == 3){
				rs += 555;
			}
			if(res.length == 2){
				if(fm[0] == 1)
					rs += 2;
				if(fm[0] == 2)
					rs += 4;
			}
			if(res.length == 1){
				if(fm[0] == 4)
					rs += 44;
				if(fm[0] == 3)
					rs += 24;
				if(fm[0] == 2)
					rs += 22;
			}
			for(int i = rs.length(); i < 3; i++)
				rs += 2;
			return rs;
		}
		
		@Override
		public void run() {
			result = Calc();
		}
		
	}
}