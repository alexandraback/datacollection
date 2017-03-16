package round1C;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	static Pair[] box;
	static Pair[] toy;
	static Triple[][] result;
	static boolean[][] seen;
	public static void main(String[] Args) throws IOException {
		Scanner sc = new Scanner(new FileReader("C-small2.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();sc.nextLine();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			System.out.println(caseNum);
			
			int N = sc.nextInt();
			int M = sc.nextInt();
			toy = new Pair[N];
			box = new Pair[M];
			result=new Triple[N][M];
			seen=new boolean[N][M];
			for(int i=0;i<N;i++) {
				for(int j=0;j<M;j++) {
					seen[i][j]=false;
				}
			}
			for(int i=0;i<N;i++) {
				toy[i]=new Pair(sc.nextLong(), sc.nextInt());
			}
			for(int i=0;i<M;i++) {
				box[i]=new Pair(sc.nextLong(),sc.nextInt());
			}
			pw.println("Case #" + caseNum + ": " + number(N-1,M-1).nombre);
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	static Triple number(int n, int m) {
		if(n==-1||m==-1)
			return new Triple(0,0,0);
		if(!seen[n][m]) {
			Triple result1 = number(n-1,m);
			Triple result2 = number(n,m-1);
			long toyOff1=result1.toyOff;
			long boxOff1=result1.boxOff;
			long toyOff2=result2.toyOff;
			long boxOff2=result2.boxOff;
			seen[n][m]=true;
			long add1=0;
			long add2=0;
			int numb=0;
			if(toy[n].type==box[m].type) {
				if(toy[n].nombre-toyOff1<box[m].nombre-boxOff1) {
					add1=toy[n].nombre-toyOff1;
					numb=1;
				} else if(toy[n].nombre-toyOff1>box[m].nombre-boxOff1) {
					add1=box[m].nombre-boxOff1;
					numb=2;
				} else {
					add1=box[m].nombre-boxOff1;
					numb=3;
				}
				if(toy[n].nombre-toyOff2<box[m].nombre-boxOff2) {
					add2=toy[n].nombre-toyOff2;
					numb=1;
				} else if(toy[n].nombre-toyOff2>box[m].nombre-boxOff2) {
					add2=box[m].nombre-boxOff2;
					numb=2;
				} else {
					add2=box[m].nombre-boxOff2;
					numb=3;
				}
//				result[n][m]= number(n-1,m, 2, toy[n].nombre-toyOff+boxOff) + toy[n].nombre-toyOff;
//				result[n][m]= number(n,m-1,1,box[m].nombre-boxOff+toyOff) + box[m].nombre-boxOff;
//				result[n][m]= number(n-1,m-1,0,0) + toy[n].nombre-toyOff;
			}
			if(result1.nombre+add1>result2.nombre+add2){
				long toyO;
				long boxO;
				if(numb==1) {
					toyO = 0;
					boxO = toy[n].nombre-toyOff1+boxOff1;
				} else if(numb==2) {
					toyO=box[m].nombre-boxOff1+toyOff1;
					boxO=0;
				} else {
					toyO = 0;
					boxO = 0;
				}
				result[n][m]= new Triple(result1.nombre+add1,toyO,boxO);
			} else {
				long toyO;
				long boxO;
				if(numb==1) {
					toyO = 0;
					boxO = toy[n].nombre-toyOff2+boxOff2;
				} else if(numb==2) {
					toyO=box[m].nombre-boxOff2+toyOff2;
					boxO=0;
				} else {
					toyO = 0;
					boxO = 0;
				}
				result[n][m]= new Triple(result2.nombre+add2,toyO,boxO);
			}
//			else {
//				if(t==1) {
//					if(result1>result2)
//						result[n][m]=result1;
//					else 
//						result[n][m]=result2;
//				} else if(t==2) {
//					long result1 = number(n-1,m,2,boxOff);
//					long result2 = number(n,m-1,0,0);
//					if(result1>result2)
//						result[n][m]=result1;
//					else 
//						result[n][m]=result2;
//				} else {
//					long result1 = number(n-1,m,0,0);
//					long result2 = number(n,m-1,0,0);
//					if(result1>result2)
//						result[n][m]=result1;
//					else 
//						result[n][m]=result2;
////				}
//			}
		}
		return result[n][m];
	}
}
class Pair {
	long nombre;
	int type;
	Pair(long n, int t) {
		this.nombre=n;
		this.type=t;
	}
}
class Triple {
	long nombre;
	long toyOff;
	long boxOff;
	Triple(long n, long t, long b) {
		this.nombre=n;
		this.boxOff=b;
		this.toyOff=t;
	}
}