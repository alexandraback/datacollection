package gcj;


import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class TP1 {

	Scanner scio=new Scanner(System.in);
	int caseNum=0;
	int R, C, W;
	
	int maxN=21;
	int a[][] = new int[maxN][2];
	
	void work() {
		R=scio.nextInt();
		C=scio.nextInt();
		W=scio.nextInt();
		init();
		
		int out=(R-1)*a[C][0]+a[C][1];
		
		System.out.println("case #"+this.caseNum+": " + out);
	}
	
	int calYes(int n, int k) {
		if (n<W) return 1000;
		if (W==1) return 1;
		if (k==1 || k==n) return W;
		if (n==W) return W;
		return (W+1);
	}
	
	int probe(int n, int k) {
		int probeYes=calYes(n, k);
		int probeNo=1000;
		int left=k-1, right=n-k;
		probeNo=Math.min(a[left][0]+a[right][1], a[left][1]+a[right][0])+1;
		//if (probeYes>n) probeYes=0;
		if (probeNo>n) probeNo=0;
		return Math.max(probeYes, probeNo);
	}
	
	void init() {
		for(int i=0;i<maxN;++i) {
			for(int j=0;j<2;++j) a[i][j]=1000;
		}
		for(int i=0;i<=C;++i) {
			a[i][0]=i/W; 
		}
		for(int i=W;i<=C;++i) {
			int tmp=1000;
			for(int j=1;j<=i;++j) {
				tmp=Math.min(tmp, probe(i, j));
				//System.out.println("tmp["+i+","+j+"]="+probe(i,j));
			}
			a[i][1]=tmp;
		}
	}
	
	void run() {
		
		try {
			File file=new File("A-small-attempt1.in");
			//File file=new File("input.txt");
			this.scio=new Scanner(file); 
		} catch (FileNotFoundException e) {}
		
		
		
		int t=scio.nextInt();
		for(int i=0;i<t;++i) {
			this.caseNum=i+1;
			work();
		}
	}
	
	public static void main(String[] args) {
		new TP1().run();
	}

}
