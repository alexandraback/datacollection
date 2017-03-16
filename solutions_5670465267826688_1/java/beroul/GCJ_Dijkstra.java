import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;
import java.util.StringTokenizer;



class GCJ_Dijkstra {

	void log(long[] X){
		int L=X.length;
		for (int i=0;i<L;i++){
			logWln(X[i]+" ");
		}
		log("");
	}

	void log(double[] X){
		int L=X.length;
		for (int i=0;i<L;i++){
			logWln(X[i]+" ");
		}
		log("");
	}

	void log(int[] X){
		int L=X.length;
		for (int i=0;i<L;i++){
			logWln(X[i]+" ");
		}
		log("");
	}
	void log(Object[] X){
		int L=X.length;
		for (int i=0;i<L;i++){
			logWln(X[i]+" ");
		}
		log("");
	}


	void log(Object o){
		logWln(o+"\n");
	}

	void logWln(Object o){
		System.out.print(o);
		//	outputWln(o);

	}
	void info(Object o){
		System.out.println(o);
		//output(o);
	}


	// Global vars
	StringTokenizer st;
	BufferedReader in;
	BufferedWriter out;

	int I=2;
	int J=3;
	int K=4;
	String[] name={"ZERO","ONE","I","J","k"};

	void solve(){
		
	}
	
	int map(int x,int y){
		return map[x-1][y-1];
	}
	
	int[][] map={{1,I,J,K},{I,-1,K,-J},{J,-K,-1,I},{K,J,-I,-1}};
	
	String YES="YES";
	String NO="NO";
	

	/*
	String solveSubtil(String s,long X,int L){
		int x=s.charAt(0)-'i'+I;
		int mult=1;
		int step=0;
		int sign=1;
		HashSet<Integer> values=new HashSet<Integer>();
		
		int lastPos=0;
		int nit=0;
		
		for (int i=0;i<L*X && (step==0);i++){
			int y=(s.charAt(i%L)-'i')+I;
			mult=map(mult,y);
			values.add(mult);
			if (mult<0){
				mult*=-1;
				sign*=-1;
			}
			if (step==0 && mult==I){
				step++;
				mult=1;
				lastPos=i;
			}
		}
		
		if (step==0){
			// on refait des passes tant qu'on peut et que cela change
			
			boolean changed=true;
			while (nit<X && step==0 && changed==true){
				changed=false;
				int NB=values.size();
				for (int i=0;i<L*X && (step==0);i++){
					if (i==0)
						nit++;
					int y=(s.charAt(i%L)-'i')+I;
					mult=map(mult,y);
					values.add(mult);
					if (mult<0){
						mult*=-1;
						sign*=-1;
					}
					if (step==0 && mult==I){
						step++;
						mult=1;
						lastPos=i;
					}
				}
				if (NB==values.size()){
					changed=false;
				} 
			}
			if (step==0)
				return NO;
		}
		
		
	}
	*/

	String solveSubtil(String s,long X,int L){

		int mult=1;
		int step=0;
		int sign=1;
		int pos=0;
		long nit=0;
		int[] cnt=new int[8*L+1];
		int t=0;
		HashSet<Integer> values=new HashSet<Integer>();
		while (nit<X && step<2) {
		//	log("prev:"+name[mult*sign]+" sign:"+sign);
			int y=(s.charAt(pos)-'i')+I;
		//	log("read y:"+name[y]);
		//	log("mult:"+mult+" sign:"+sign);
			mult=sign*map(mult*sign,y);
			values.add(mult);
			
			if (mult<0) 
				sign=-1;
			else
				sign=1;
			//log("current:"+name[mult*sign]+" sign:"+sign);
			if (step==0 && mult==I){
			//	log("ok step 1");
				step++;
				mult=1;
				sign=1;
				t=0;
				values=new HashSet<Integer>();
				
			} else {
				if (step==1 && mult==J){
			//		log("ok step 2");
					step++;
					mult=1;
					sign=1;
					t=0;
					values=new HashSet<Integer>();
				}
			}
			cnt[t]=values.size();
			if (t>=L && cnt[t-L]==cnt[t]) {
		//		log("Stopping before");
				return NO;
			}
			t++;
			pos++;
			if (pos==L){
				pos=0;
				nit++;
			}
				
		}
	//	log("nit:"+nit+" pos:"+pos);
		if (step<2)
			return NO;
		
	//	log("La suite");
		// il faut calculer le restant
		for (int u=pos;u<L;u++){
			int y=(s.charAt(u)-'i')+I;
			mult=sign*map(mult*sign,y);
			if (mult<0) 
				sign=-1;
			else
				sign=1;
		}
		if (pos<L)
			nit++;
		int full=1;
		int fullSign=1;
	
		if (nit<X){
			for (int u=0;u<L;u++){
				int y=(s.charAt(u)-'i')+I;
				full=fullSign*map(full*fullSign,y);
				if (full<0) 
					fullSign=-1;
				else
					fullSign=1;
			}
		}
		int Y=(int)(X-nit)%8;
		for (int u=0;u<Y;u++){
			mult=sign*fullSign*map(mult*sign,full*fullSign);
			if (mult<0)
				sign=-1;
			else
				sign=1;
		}
		if (step==2 && mult==K)
			return YES;
		else
			return NO;
		
	}
	
	
	String solveBourrin(String s,long X,int L){
	
		int x=s.charAt(0)-'i'+I;
		int mult=1;
		int step=0;
		int sign=1;
		for (int i=0;i<L*X;i++){
			int y=(s.charAt(i%L)-'i')+I;
			//log("sign:"+sign+" mult:"+mult);
			mult=sign*map(sign*mult,y);
			if (mult<0)
				sign=-1;
			else
				sign=1;
			if (step==0 && mult==I){
				step++;
				mult=1;
			} else {
				if (step==1 && mult==J){
					step++;
					mult=1;
				}
			}
		}
		if (step==2 && mult==K)
			return YES;
		else
			return NO;
		
		
		
	}
	

	// BUGGE 
	String solveBourrinOld(String s,long X,int L){
	
		int x=s.charAt(0)-'i'+I;
		int mult=1;
		int step=0;
		int sign=1;
		for (int i=0;i<L*X;i++){
			int y=(s.charAt(i%L)-'i')+I;
			mult=map(mult,y);
			if (mult<0){
				mult*=-1;
				sign*=-1;
			}
			if (step==0 && mult==I){
				step++;
				mult=1;
			} else {
				if (step==1 && mult==J){
					step++;
					mult=1;
				}
			}
		}
		if (step==2 && mult==K && sign==1)
			return YES;
		else
			return NO;
		
	}
	
	void process() throws Exception {
		Locale.setDefault(Locale.US);




		//File inputFile=new File("C-large.in");
		File inputFile=new File("C-large.in");
		
		

		//		PrintWriter outputFile= new PrintWriter("C-large.out","UTF-8");
		PrintWriter outputFile= new PrintWriter("C-large.out","UTF-8");


		Scanner sc=new Scanner(inputFile);
		sc.useLocale(Locale.US);

		long startTime,endTime;
		
		
		int T=sc.nextInt();
		for (int t=1;t<=T;t++){
			int L=sc.nextInt();
			Long X=sc.nextLong();
			String s=sc.next();
			startTime = System.currentTimeMillis();
			String ss=solveSubtil(s,X,L);
			endTime   = System.currentTimeMillis();
			log("subtil processing time:"+(endTime-startTime));
		
			/*
			startTime = System.currentTimeMillis();
			String tt=solveBourrin(s,X,L);
			endTime   = System.currentTimeMillis();
			log("bourrin processing time:"+(endTime-startTime));
			
			if (!ss.equals(tt)){
				log("----------------------------------------------ERROR");
				return;
			}
			*/
			System.out.println("Case #"+t+": "+ss);
			outputFile.println("Case #"+t+": "+ss);


		}



		sc.close();
		outputFile.close();


	}



	public static void main(String[] args) throws Exception {
		GCJ_Dijkstra J=new GCJ_Dijkstra();

		J.process();


	}




}