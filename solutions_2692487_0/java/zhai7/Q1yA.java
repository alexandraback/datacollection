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



public class Q1yA {

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
		
		Q1yA q = new Q1yA();
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
		int init;
		int num;
		int[] tar;
		
		Child(Scanner in){
			Scanner line = new Scanner(in.nextLine());
			init = line.nextInt();
			num = line.nextInt();
			line.close();
			tar = new int[num];
			line = new Scanner(in.nextLine());
			for(int i = 0; i < num; i++)
				tar[i] = line.nextInt();
			line.close();
		}
		
		void init(){
			Arrays.sort(tar);
			int i;
			for(i = 0; i < num; i++){
				if(init > tar[i])
					init += tar[i];
				else
					break;
			}
			tar = Arrays.copyOfRange(tar, i, num);
			num -= i;
		}
		
		int Calc(){
			init();
			if (num == 0)
				return 0;
			int[] ben = new int[num];
			int[] ach = new int[num];
			int me = init;
			int fin = 0;
			int i = 0;
			int j;
			while(i < num && fin < num){
				me += me - 1;
				for(j = fin; j < num; j++){
					if(me > tar[j])
						me += tar[j];
					else
						break;
				}
				ben[i] = j - fin;
				ach[i] = fin = j;
				i++;
			}
			int cb = 0;
			boolean[] ch = new boolean[num];
			do{
				i--;
				cb += ben[i] - 1;
				if(cb > 0)
					ch[i] = true;
				else{
					ch[i] = false;
					cb = 0;
				}
			}while(i > 0);
			j = 0;
			while(j < num && ch[j]){
				j++;
			}
			return j + num - (j > 0 ? ach[j-1] : 0);
		}
		
		@Override
		public void run() {
			result = Calc() + "";
		}
		
	}
}