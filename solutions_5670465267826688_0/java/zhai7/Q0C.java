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



public class Q0C {

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
		
		Q0C q = new Q0C();
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
		static int[][] multiply = {
				{0,0,0,0,0},
				{0,1,2,3,4},
				{0,2,-1,4,-3},
				{0,3,-4,-1,2},
				{0,4,3,-2,-1}};
		String result = "";
		int ll;
		long xx;
		int[] s;
		
		Child(Scanner in){
			Scanner line = new Scanner(in.nextLine());
			ll = line.nextInt();
			xx = line.nextLong();
			String str = in.nextLine();
			s = new int[ll];
			for(int i = 0; i < ll; ++i)
				s[i] = str.charAt(i) - 'i' + 2;
		}
		
		static int mul(int a, int b){
			return (a * b > 0 ? 1 : -1) * multiply[Math.abs(a)][Math.abs(b)]; 
		}
		
		static int ldiv(int p, int l){
			boolean pos = p * l > 0;
			for(int i = 1; i < 5; ++i)
				if(Math.abs(p) == multiply[Math.abs(l)][i])
					return pos ? i : -i;
			throw new RuntimeException("Not Found");
		}
		
		static int rdiv(int p, int r){
			boolean pos = p * r > 0;
			for(int i = 1; i < 5; ++i)
				if(Math.abs(p) == multiply[i][Math.abs(r)])
					return pos ? i : -i;
			throw new RuntimeException("Not Found");
		}
		
		static int pow(int x, long e){
			switch((int)(e % 4)){
			case 0: return 1;
			case 1: return x;
			case 2: return mul(x, x);
			case 3: return Math.abs(x) == 1 ? x : -x;
			}
			throw new RuntimeException("Not Found");
		}

		boolean Calc(){
			int[] prefix = new int[ll], suffix = new int[ll];
			prefix[0] = s[0];
			suffix[ll-1] = s[ll-1];
			for(int i = 1; i < ll; ++i){
				prefix[i] = mul(prefix[i-1], s[i]);
				suffix[ll-1-i] = mul(s[ll-1-i], suffix[ll-i]);
			}
			int prod = suffix[0];
			if(pow(prod, xx) != -1)
				return false;
			int left, right;
			for(left = 0; left < ll * 4; ++left)
				if(mul(pow(prod, left / ll), prefix[left % ll]) == 2)
					break;
			if(left == ll * 4)
				return false;
			for(right = 0; right < ll * 4; ++right)
				if(mul(suffix[ll - right % ll - 1], pow(prod, right / ll)) == 4)
					break;
			if(right == ll * 4)
				return false;
			if(left + right + 2 < ll * xx)
				return true;
			else
				return false;
		}
		@Override
		public void run() {
			result = Calc() ? "YES" : "NO";
		}
		
	}
}