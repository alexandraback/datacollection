import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.*;



import static java.lang.Math.*; 
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Character.*;  



public class C {
	static class Sol implements Runnable{
		static char[][]D = new char[521196][];
		boolean started = false;
		Scanner scan;
		int caseN;
		char[]C;
		int intLine(){
			return parseInt(scan.nextLine());
		}
		
		
		int res = 0;

		void readInput() {
			C = scan.next().toCharArray();
		}
		int[][]M = new int[4002][7];
		int doit(int p, int lastChange){
			if(p==C.length)return 0;
			if(M[p][lastChange]>-1)return M[p][lastChange];
			int res = 1000000;
			for(char[]s:this.D){
				if(s.length+p > C.length)continue;
				int lt = lastChange;
				boolean ok = true;
				int r =0;
				for(int i=0;i<s.length;i++){
					lt ++;
					if(s[i]!=C[p+i]){
						if(lt < 5){ok = false;break;}
						else{
							lt =0;
							r++;
						}
					}
				}
				if (ok){
					int r2 = doit(p+s.length, min(lt,5)) + r;
					res = min(res,r2);
				}
			}
			
			return M[p][lastChange]=res;
		}
		
		public void run(){
			int[]D = new int[C.length+1];
			for(int[]a:M)fill(a,-1);
			this.res = doit(0, 5);
			System.err.println(caseN+" finished");
		}

		void printResult(PrintStream out) {
			out.format("Case #%d: %d\n",caseN+1, res);
		}
	}

    static Sol[] solvers;
    
    static synchronized Sol getNext() {
    	for(int i=0;i<solvers.length;i++) {
    		if(!solvers[i].started){
    			solvers[i].started = true;
    			return solvers[i];
    		}
    	}
    	return null;
    }
    
    static class Worker extends Thread {
    	public void run() {
    		while(true) {
    			Sol sol = getNext();
    			if (sol == null)break;
    			sol.run();
    		}
    	}
    }
    
	public static void main(String[] args) throws Exception{
		Locale.setDefault(Locale.US);
		String cn = C.class.getName();
		String sampleName = cn+"-sample.in";
		String smallName = cn+"-small-attempt1.in";
		String largeName = cn+"-large.in";
		String name = largeName;
		String outName = name.substring(0, name.indexOf('.'))+".out";
		InputStream in = new BufferedInputStream(new FileInputStream(name));
		Scanner scan = new Scanner(in);
		BufferedInputStream din = new BufferedInputStream(new FileInputStream("dictionary.txt"));
		Scanner scan2 = new Scanner(din);
		for(int i=0;i<Sol.D.length;i++){
			Sol.D[i]=scan2.next().toCharArray();
		}
		int N = parseInt(scan.nextLine());
		//Sol.D=new char[][]{"aaa".toCharArray()};
		solvers = new Sol[N];
		for(int i=0;i<solvers.length;i++) {
			solvers[i] = new Sol();
			solvers[i].scan = scan;
			solvers[i].caseN = i;
			solvers[i].readInput();
		}
		Thread[]threads = new Thread[32];
		for(int i=0;i<threads.length;i++){
			threads[i]=new Worker();
			threads[i].start();
		}
		for(int i=0;i<threads.length;i++){
			threads[i].join();
		}
		PrintStream out = new PrintStream(new File(outName));
		//PrintStream out = System.out;
		for(Sol s:solvers)s.printResult(out);
		System.err.println("All done");
		
	}

}


