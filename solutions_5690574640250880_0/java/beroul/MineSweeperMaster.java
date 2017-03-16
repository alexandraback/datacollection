import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Locale;
import java.util.Scanner;


public class MineSweeperMaster {


	String round="Qualification";
	String exercice="C";

	// global var
	int R,C,M;
	char[][] map;
	int ccount;
	
	void log(String s) {
	//	System.out.println(s);
	}
	
	void info(String s) {
		System.out.println(s);
	}
	
	void error(String s) {
		System.out.println(s);
	}

	
	
	void update(char[][] map,int x,int y){
		map[x][y]='X';
		boolean goon=true;
		for (int i=-1;i<=1;i++)
			for (int j=-1;j<=1;j++){
				if ((x+i>=0)&&(y+j>=0)&&(x+i<R)&&(y+j<C)) {
					if (map[x+i][y+j]=='*')
						goon=false;
				}
			}
		if (goon==true){
			map[x][y]='0';
			for (int i=-1;i<=1;i++)
				for (int j=-1;j<=1;j++){
					if (((i!=0)||(j!=0))&&((x+i>=0)&&(y+j>=0)&&(x+i<R)&&(y+j<C))) {
						if (map[x+i][y+j]=='.')
							update(map,x+i,y+j);
					}
				}
		}
		return;
		
	}
	
	boolean check (char[][] map){
		int cfound=0;
		boolean result=true;
		for (int i=0;i<R;i++)
			for (int j=0;j<C;j++){
				if (map[i][j]=='.')
					result=false;
			/*	if (map[i][j]=='c')
					cfound++;*/
			}
	/*	if (cfound!=1)
			result=false;*/
		return result;
	}
	
	String affiche(char[][] map){
		int count=0;
		ccount=0;
		for (int i=0;i<R;i++)
			for (int j=0;j<C;j++){
				if (map[i][j]=='*')
					count++;
				if ((map[i][j]=='X')||(map[i][j]=='0'))
					ccount++;
			}
		if (count!=M)
			error("------------> M problem");
		
		String res="";
	
		for (int i=0;i<R;i++) {
			res=res+new String(map[i]);
			if (i<R-1)
				res=res+"\n";
		}
		return res;
	}

	class Position{
		int x;
		int y;
		
		Position(int x,int y){
			this.x=x;
			this.y=y;
		}
	}
	
	class Game{
		ArrayList<Position> list;
		
		Game(){
			list=new ArrayList<Position>();
		}
		
		Game(Position p){
			list=new ArrayList<Position>();
			list.add(p);
		}
	}
	
	
	
	
	void randomSolve(){
		int ROUND=1000000;
		int[] chosen=new int[M];
		for (int r=0;r<ROUND;r++){
			int count=0;
			for (int m=0;m<M;m++) {
				boolean goon=true;
				while (goon) {
				boolean collision=false;
				double X=(R*C-1)*Math.random();
				int x=(int)Math.round(X);
				for (int u=0;u<m;u++) {
					if (chosen[u]==x)
						collision=true;
				}
				if (!collision){
					goon=false;
					chosen[m]=x;
				}
				}
			}
		
		map=new char[R][C];
		for (int i=0;i<R;i++) 
			for (int j=0;j<C;j++) {
				map[i][j]='.';
			}
		for (int m=0;m<M;m++){
			int j=chosen[m]%C;
			int i=chosen[m]/C;
			map[i][j]='*';
		}
		int px=-1;
		int py=-1;
		for (int x=0;x<R;x++) 
			for (int y=0;y<C;y++) {
				int sum=0;
				for (int i=-1;i<=1;i++)
					for (int j=-1;j<=1;j++){
						if ((x+i>=0)&&(y+j>=0)&&(x+i<R)&&(y+j<C)) {
							if (map[x+i][y+j]=='*')
								sum++;
						}
					}
				if (map[x][y]!='*') {
					map[x][y]=(char)(sum+'0');
					if (sum==0) {
						px=x;
						py=y;
					}
				}
			}
		if (px==-1){
			log("No free cell");
		} else {
			for (int x=0;x<R;x++) 
				for (int y=0;y<C;y++) {
					if ((map[x][y]!='*')&&((x!=px)||(y!=py)))
							map[x][y]='.';
				}
			update(map,px,py);
		}
		
		log(affiche(map)+"\n");
		log("cc:"+ccount);
		if (ccount!=R*C-M)
			log("KO");
		else {
			info(affiche(map)+"\n");
			info ("------------------>OK");return;}
		}
		info("KO");
	}
	
	
	String solve(){
		String res="";
		 map=new char[R][C];
		int X=R*C-M;
		if ((M==3)&&(R==4)&&(C==4)){
			for (int i=0;i<R;i++) 
				for (int j=0;j<C;j++) 
					map[i][j]='.';
			map[3][3]='*';
			map[2][3]='*';
			map[3][2]='*';
			map[0][0]='c';
			return "\n"+affiche(map);
		}
		
		int amax=3;
		int bmax=3;
		
		for (int i=0;i<R;i++) 
			for (int j=0;j<C;j++)
				map[i][j]='*';
		if (X==1){
			map[0][0]='c';
			return "\n"+affiche(map);
			/*
			 for (int i=0;i<R;i++) {
					res=res+new String(map[i]);
					if (i<R-1)
						res=res+"\n";
				}
				return "\n"+res;
				*/
		}
		if ((X==0)&&(R*C==1)) {
			log("=================");
			map[0][0]='c';
			return "\n"+affiche(map);
		}
		
		if ((R==1)||(C==1)) {
			for (int i=0;i<Math.min(R,R*C-M);i++) 
				for (int j=0;j<Math.min(C,R*C-M);j++)
					map[i][j]='.';
			map[0][0]='c';
			return "\n"+affiche(map);
			/*
			char[] s=new char[R*C];
			Arrays.fill(s,'.');
			for (int i=0;i<M;i++)
				s[i]='*';
			s[R*C-1]='c';
			if (R==1) {
				res=new String(s);
			} else {
				for (int i=0;i<R;i++) {
					res=res+s[i];
					if (i<R-1)
						res=res+"\n";
				}
			}
			return "\n"+res;
			*/
		}
		// maintenant R & C sont supérieurs à 2
		
		/*
		if ((R==3)&&(C==3)&&(M==2)){
			return("\n..*\n.c.\n*..");
		}
		*/
		int saved=8;
		/*
		if ((R==2)&&(C==2)) {
			amax=2;
			bmax=2;
			saved=3;
		}
		if ((Math.min(R,C)==2)&&(Math.max(R,C)>2)){
			if (R==2) {
				amax=2;
				bmax=3;
			} else {
				amax=3;
				bmax=2;
			}
			
			saved=5;
		}
		if (X<=saved){
			info("We can save for R:"+R+" C:"+C+" M:"+M);
			 int count=0;
			 for (int i=0;i<amax;i++)
				 for (int j=0;j<bmax;j++) {
					 if (count<X){
						 map[i][j]='.';
						 count++;
					 }
				 }
			 map[1][1]='c';
			 for (int i=0;i<R;i++) {
					res=res+new String(map[i]);
					if (i<R-1)
						res=res+"\n";
				}
				return "\n"+res;
		}
		*/
		
		int max=-1;


	
		
		for (int a=2;a<=R;a++)
			for (int b=2;b<=C;b++) {
				if ((a*b<=X) && (a*b>=max) && ((X-a*b)!=1)) {
					
					
					amax=a;
					bmax=b;
					max=a*b;
				}
			}
		log("max="+max);
		boolean wrong=false;
		if (max==-1) {
			log("wrong - Problem pour faire rentrer le rectangle");
			wrong=true;
		}
		
		/*
		{
			info("R:"+R+" C:"+C+" M:"+M);
			if (X>6) {
				log("=====Very strange");
			}
			return "\n"+"Impossible";
		}
		*/
		
		int d=0;
		if (!wrong){
		for (int i=0;i<amax;i++)
			for (int j=0;j<bmax;j++) 
				map[i][j]='.';
		d=X-max;
		// normalement d<amax et d<bmax
		if ((d>=amax)&&(d>=bmax)) {
			log("wrong - Problem with dmax");
			wrong=true;
		}
		}
		
		if (wrong)
		
		{
		//	error("Problem with d:"+d+" amax:"+amax+" bmax:"+bmax+ "R:"+R+" C:"+C+" M:"+M);
		//	info("R:"+R+" C:"+C+" M:"+M);
			// we got a situation - on va essyer à l'envers 
			log("Trying super technique");
			for (int u=1;u<=R-2;u++)
				for (int v=1;v<=C-2;v++) 
					for (int u2=R-1;u2>=u+1;u2--)
						for (int v2=C-1;v2>=v+1;v2--) {
							//if ((u2>=u+1)||(v2>=v+3)){
							{
							int zone1=u*v;
							int zone2=(R-u2)*(C-v2);
							if (zone1+zone2==M) {
								if ((u2==u+1)&&(v2==v+1))
									log("Ze case");
								for (int i=0;i<R;i++) 
									for (int j=0;j<C;j++)
										map[i][j]='.';
								for (int i=0;i<u;i++)
									for (int j=0;j<v;j++) 
										map[i][j]='*';
								for (int i=u2;i<R;i++)
									for (int j=v2;j<C;j++) 
										map[i][j]='*';
								map[u-1][v+1]='c';
								return "\n"+affiche(map);
							}
						}
						}
						
					
			return "\n"+"Impossible";
		}
		if (amax==R) {
			// il faut rajouer en colonne
			for (int i=0;i<d;i++)
				map[i][bmax]='.';
		} else {
			if (bmax==C) {
				for (int j=0;j<d;j++)
					map[amax][j]='.';
			} else {
				// on rajoute au max
				if (amax>bmax) {
					for (int i=0;i<d;i++)
						map[i][bmax]='.';
				} else {
					for (int j=0;j<d;j++)
						map[amax][j]='.';
				}
			}
		}
		map[0][0]='c';
		
		return "\n"+affiche(map);
	}



	void process() throws Exception {

	//	File inputFile=new File(round+"/test_"+exercice+".in");
	//	PrintWriter outputFile= new PrintWriter(round+"/test_"+exercice+".out","UTF-8");
	//	File inputFile=new File(round+"/vbTest.in");
	//	PrintWriter outputFile= new PrintWriter(round+"/vbTest","UTF-8");

		

			File inputFile=new File(round+"/"+exercice+"-small-attempt12.in");
			PrintWriter outputFile= new PrintWriter(round+"/"+exercice+"-small-attempt12.out","UTF-8");
		//File inputFile=new File(round+"/"+exercice+"-large-practice.in");
		//PrintWriter outputFile= new PrintWriter(round+"/"+exercice+"-large-practice.out","UTF-8");
		//File inputFile=new File(round+"/"+exercice+"-large.in");
		//PrintWriter outputFile= new PrintWriter(round+"/"+exercice+"-large.out","UTF-8");


		Scanner scanner=new Scanner(inputFile);
		scanner.useLocale(Locale.US);
		int T = scanner.nextInt();
		System.out.println("Doing "+T+" cases");

		

		for (int t=1;t<=T;t++) {
			R=scanner.nextInt();
			C=scanner.nextInt();
			M=scanner.nextInt();
			info("R:"+R+" C:"+C+" M:"+M);		
			//randomSolve();
	
			
			String ss=""+solve();
		
		//	if (!ss.equals("\nImpossible")&&(R!=1)&&(C!=1)) {
			if (!ss.equals("\nImpossible")) {
				
			log("////////////");
				int x0=-1;
				int y0=-1;
				for (int i=0;i<R;i++)
					for (int j=0;j<C;j++) {
						if (map[i][j]=='c'){
							x0=i;
							y0=j;
						}
					}
				
				if ((x0==-1)&&(y0==-1))
					error("-----------> problem with c");
				update(map,x0,y0);
				
				log(affiche(map));
				if (!check(map)) {
					error("problem with map");
					ss="\nImpossible";
				}
			}
			System.out.println("Case #"+t+": "+ss);
			outputFile.println("Case #"+t+": "+ss);
			
		}
		scanner.close();
		outputFile.close();

	}



	public static void main(String[] args) throws Exception {
		MineSweeperMaster J=new MineSweeperMaster();
		J.process();
	}


}

