import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Iterator;
import java.util.Locale;
import java.util.Scanner;


public class DeceitfulWar {


	String round="Qualification";
	String exercice="D";

	// global var
	int N;
	double[] nao,ken;
	
	void log(String s) {
		System.out.println(s);
	}
	
	void info(String s) {
		System.out.println(s);
	}
	
	void error(String s) {
		System.out.println(s);
	}

	
	
	class MyList{
		ArrayList<Integer> list;
		
		MyList(){
			list=new ArrayList<Integer>();
		}
		
		public String toString(){
			if (list!=null) {
				String res="";
				for (int i=0;i<list.size();i++)
					res=res+list.get(i)+" ";
				return res;
			}
			return null;
		}
	}
	
	 ArrayList<MyList> generate(int pos){
		 if (pos==N-1){
			 ArrayList<MyList> res=new ArrayList<MyList>();
			 for (int i=0;i<N;i++){
				 MyList l=new MyList();
				 l.list.add(i);
				 res.add(l);
			 }
			 return res;
		 } else {
			 ArrayList<MyList> res0=generate(pos+1);
			 ArrayList<MyList> res=new ArrayList<MyList>();
			 for (int i=0;i<res0.size();i++){
				 MyList l=res0.get(i);
				 for (int x=0;x<N;x++) {
					 if (l.list.indexOf(x)==-1) {
						 MyList l2=new MyList();
						 l2.list=new ArrayList<Integer>(l.list);
						 l2.list.add(x);
						 res.add(l2);
					 }
				 }
			 }
			 return res;
		 }
	 }

	 /*
	 int warBourrin(){
		 int max=0;
		 ArrayList<MyList> res=generate(0);
		 log("res size:"+res.size());
		 for (int i=0;i<res.size();i++){
			 MyList l=res.get(i);
			 int score=getScore(l);
			 max=Math.max(score,max);
		 }
		 return max;
	 }
	*/
	 
	 String solveBourrin(){
		 ArrayList<MyList> res=generate(0);
		 int maxW=0;
		 for (int i=0;i<res.size();i++){
			 MyList l=res.get(i);
			 int score=getScoreW(l);
			 maxW=Math.max(score,maxW);
		 }
		 int maxDw=0;
		 for (int i=0;i<res.size();i++){
			 MyList l=res.get(i);
			 int score=getScoreDw(l);
			 maxDw=Math.max(score,maxDw);
		 }
		 return maxDw+" "+maxW;
	 }
	 
	 int getScoreW(MyList list){
		// log("Getting score for "+list);
		 ArrayList<Integer> res=list.list;
		 if (res.size()!=N) {
			 error("problème de taille liste");
			 return -1;
		 }
		 int count=0;
		boolean[] kused=new boolean[N];
		Arrays.fill(kused,false);
		 for (int i=0;i<N;i++){
			 int n=res.get(i);
			 int k=kwin(nao[n],kused);
			 if (k==-1) {
				 count++;
			 } else {
				 kused[k]=true;
			 }
		 }
		 return count;
	 }
	 
	 int getScoreDw(MyList list){
			// log("Getting score for "+list);
			 ArrayList<Integer> res=list.list;
			 if (res.size()!=N) {
				 error("problème de taille liste");
				 return -1;
			 }
			 int count=0;
			boolean[] kused=new boolean[N];
			boolean[] nused=new boolean[N];
			Arrays.fill(kused,false);
			Arrays.fill(nused,false);
			 
			 for (int i=0;i<N;i++){
				 int n=res.get(i);
				 int m=N-1;
				 while (nused[m]==true)
					 m--;
				 int k=kwin(nao[m],kused);
				 while ((k==-1)&&(m>=n)) {
					 m--;
					 k=kwin(nao[m],kused);
				 }
				 k=kwin(nao[m],kused);
				 if (k==-1) {
					 count++;
				 } else {
					 kused[k]=true;
				 }
				 nused[m]=true;
			 }
			 return count;
		 }
	 
	 
	int kwin(double a,boolean[] kused){
		for (int i=0;i<N;i++){
			if ((ken[i]>a)&&(!kused[i]))
				return i;
		}
		return -1;	
	}
	
	class Composite implements Comparable<Composite> {
		double d;
		boolean nao;
		
		Composite(double d,boolean nao){
			this.d=d;
			this.nao=nao;
		}
		
		public int compareTo(Composite X){
			if (X.d>d)
				return -1;
			if (X.d<d)
				return 1;
			return 0;
		}
	}
	
	String solveLight(){
		int max=0;
		Composite[] big=new Composite[2*N];
		for (int i=0;i<N;i++) {
			big[i]=new Composite(nao[i],true);
			big[i+N]=new Composite(ken[i],false);
		}
		Arrays.sort(big);
		
		for (int n=2*N-1;n>=0;n--){
			int w=0;
			int l=0;
					
			for (int i=n;i<2*N;i++) {
				if (big[i].nao)
					w++;
				else
					l++;
			}
			max=Math.max(max,w-l);
		}
		int warLight=max;
		int j=N-1;
		int ilow=0;
		int ihi=N-1;
		int count=0;
		boolean[] kused=new boolean[N];
		Arrays.fill(kused,false);
		while ((j>=0)&&(ilow<=ihi)){
			if (ken[j]>nao[ihi]) {
					j--;
					ilow++;
				}
			 else {
				count++;
				j--;
				ihi--;
			}
		}
		int dWarLight=count;
		return dWarLight+" "+warLight;
	}
	
	
	
	int war(){
		int count=0;
		boolean[] kused=new boolean[N];
		boolean[] nused=new boolean[N];
		Arrays.fill(kused,false);
		Arrays.fill(nused,false);
		int i=0;
		while (i<N){
			int j=kwin(nao[i],kused);
			if (j==-1) {
				count++;
				nused[i]=true;
				i++;
			} else {
				while ((i<N)&&(kwin(nao[i],kused)==j))
					i++;
				if (i==N)
					return count;
				kused[j]=true;
			}
		}
		return count;
	}

	int dWar(){
		int count=0;
		boolean[] kused=new boolean[N];
		boolean[] nused=new boolean[N];
		Arrays.fill(kused,false);
		Arrays.fill(nused,false);
		int j=N-1;
		int i=0;
		while ((i<N)&&(j>=0)&&(nao[i]<ken[j])){
			i++;
			j--;
		}
		return N-i;
	}
	
	/*
	String solve(){
		//return dWar()+" "+war()+" "+warBourrin();
		return " "+warBourrin();
	}
	*/
	
	void process() throws Exception {

	//	File inputFile=new File(round+"/test_"+exercice+".in");
	//	PrintWriter outputFile= new PrintWriter(round+"/test_"+exercice+".out","UTF-8");


			File inputFile=new File(round+"/"+exercice+"-small-attempt0.in");
			PrintWriter outputFile= new PrintWriter(round+"/"+exercice+"-small-attempt0.out","UTF-8");
		//File inputFile=new File(round+"/"+exercice+"-large-practice.in");
		//PrintWriter outputFile= new PrintWriter(round+"/"+exercice+"-large-practice.out","UTF-8");
		//File inputFile=new File(round+"/"+exercice+"-large.in");
		//PrintWriter outputFile= new PrintWriter(round+"/"+exercice+"-large.out","UTF-8");


		Scanner scanner=new Scanner(inputFile);
		scanner.useLocale(Locale.US);
		int T = scanner.nextInt();
		System.out.println("Doing "+T+" cases");


		for (int t=1;t<=T;t++) {
			N=scanner.nextInt();
			nao=new double[N];
			ken=new double[N];
			for (int i=0;i<N;i++)
				nao[i]=scanner.nextDouble();
			for (int i=0;i<N;i++)
				ken[i]=scanner.nextDouble();
			Arrays.sort(nao);
			Arrays.sort(ken);
		/*
			log("Nao");
			
			for (int i=0;i<N;i++)
				log(nao[i]+"");
			
			
			log("Ken");
			
			for (int i=0;i<N;i++)
				log(ken[i]+"");
	*/		
	
			String ss=""+solveLight();
			System.out.println("Case #"+t+": "+ss);
			outputFile.println("Case #"+t+": "+ss);
			
			
			
		}
		scanner.close();
		outputFile.close();

	}



	public static void main(String[] args) throws Exception {
		DeceitfulWar J=new DeceitfulWar();
		J.process();
	}


}

