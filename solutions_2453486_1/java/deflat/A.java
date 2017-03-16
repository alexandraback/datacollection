import java.util.*;
import java.io.*;
public class A {
	
	String[] in;
	
	char check(int x,int y,int dx,int dy){
		char tg='.';
		for(int i=0;i<4;i++){
			if(in[x].charAt(y)=='.') return '.';
			if(in[x].charAt(y)!='T'){
				if(tg=='.') tg=in[x].charAt(y);
				else if(in[x].charAt(y)!=tg) tg='-';

			}
			x+=dx;
			y+=dy;
		}
		return tg;
	}
	void run(String inputfile){
	try{
		/**************************************/
		Scanner s;
		File file=new File("output.txt");
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(file)));
		if(inputfile.equals("test")) s=new Scanner(System.in);
		else s=new Scanner(new FileInputStream(new File(inputfile)));
		/**************************************/
		int cases=s.nextInt();
		for(int X=0;X<cases;X++){
			s.nextLine();
			pw.print("Case #"+(X+1)+": ");
			this.in=new String[4];
			for(int i=0;i<4;i++){
				in[i]=s.nextLine();
			}
			int t=0;
			boolean anyblank=false;
			boolean end=false;
			while(t<4&&!end){
				char ret=check(t,0,0,1);
				if(ret=='.') anyblank=true;
				else if(ret!='-'){
					pw.println(ret+" won");
					end=true;
				}
				t++;
			}
			t=0;
			while(t<4&&!end){
				char ret=check(0,t,1,0);
				if(ret=='.') anyblank=true;
				else if(ret!='-'){
					pw.println(ret+" won");
					end=true;
				}
				t++;
			}
			if(!end){
				char ret=check(0,0,1,1);
				if(ret=='.') anyblank=true;
				else if(ret!='-'){
					pw.println(ret+" won");
					end=true;
				}
			}
			if(!end){
				char ret=check(3,0,-1,1);
				if(ret=='.') anyblank=true;
				else if(ret!='-'){
					pw.println(ret+" won");
					end=true;
				}
			}
			if(!end){
				if(anyblank) pw.println("Game has not completed");
				else pw.println("Draw");
			}
		}
		pw.close();
	/**************************************/
	}catch(IOException e){
		System.out.println(e);
		System.exit(0);
	}
	/**************************************/
	}
	public static void main(String[] args){
		
		new A().run(args[0]);
	}
}
