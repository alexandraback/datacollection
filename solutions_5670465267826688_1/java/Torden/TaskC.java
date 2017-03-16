import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;



public class TaskC {

	final int ZERO=0;
	final int ONE=1;
	final int M_ONE=2;
	final int I=3;
	final int J=4;
	final int K=5;
	final int M_I=6;
	final int M_J=7;
	final int M_K=8;
	
	long L,X;
	String line;
	int[][] mult={
		//  0       1       -1      i       j       k		-i		-j		-k
			{ZERO,	ZERO,	ZERO,	ZERO,	ZERO,	ZERO,	ZERO,	ZERO,	ZERO},//0
			{ZERO,	ONE,	M_ONE,	I,		J,		K,		M_I,	M_J,	M_K	},//1
			{ZERO,	M_ONE,	ONE,	M_I,	M_J,	M_K,	I,		J,		K	},//-1
			{ZERO,	I,		M_I,	M_ONE,	K,		M_J,	ONE,	M_K,	J	},//i
			{ZERO,	J,		M_J,	M_K,	M_ONE,	I,		K,		ONE,	M_I	},//j
			{ZERO,	K,		M_K,	J,		M_I,	M_ONE,	M_J,	I,		ONE	},//k
			{ZERO,	M_I,	I,		ONE,	M_K,	J,		M_ONE,	K,		M_J	},//-i
			{ZERO,	M_J,	J,		K,		ONE,	M_I,	M_K,	M_ONE,	I	},//-j
			{ZERO,	M_K,	K,		M_J,	I,		ONE,	J,		M_I,	M_ONE	},//-k
	};
	String result;
	
	public void parseCase(Scanner input) {
		L=input.nextLong();
		X=input.nextLong();
		input.nextLine();
		line=input.nextLine();
	}
	
	int[] makeQArray(String s){
		int len=s.length();
		int[] chars=new int[len]; 
		for(int i=0;i<len;i++)
			switch(s.charAt(i)){
			case 'i':chars[i]=I;break;
			case 'j':chars[i]=J;break;
			case 'k':chars[i]=K;break;
			}
		return chars;
	}
	
	public void solveCase() {
		String searchLine=line;
		int linesUsed=1;
		int[] Q;
		int pos;
		int val;
		
		//looking for i
		while(searchLine.length()<L*4+1 && linesUsed<X)
		{
			searchLine=searchLine+line;
			linesUsed++;
		}
		Q=makeQArray(searchLine);
		val=ONE;
		for(pos=0;pos<Q.length;pos++)
		{
			val=mult[val][Q[pos]];
			if(val==I) break;
		}
		if(val!=I){
			result="NO";
			return;
		}
			
		//looking for j
		searchLine=searchLine.substring(pos+1, searchLine.length());
		while(searchLine.length()<L*4+1 && linesUsed<X)
		{
			searchLine=searchLine+line;
			linesUsed++;
		}
		Q=makeQArray(searchLine);
		val=ONE;
		for(pos=0;pos<Q.length;pos++)
		{
			val=mult[val][Q[pos]];
			if(val==J) break;
		}
		if(val!=J){
			result="NO";
			return;
		}
		
		//checking if the residue is K
		searchLine=searchLine.substring(pos+1, searchLine.length());
		while((X-linesUsed)%4!=0)
		{
			searchLine=searchLine+line;
			linesUsed++;
		}
		Q=makeQArray(searchLine);
		val=ONE;
		for(pos=0;pos<Q.length;pos++)
		{
			val=mult[val][Q[pos]];
		}
		if(val==K)
			result="YES";
		else
			result="NO";
		
	}

	public String getSolution() {
		return result;
	}
	

	public void runTask(String[] args) {
		if(args.length<1)
		{
			System.out.println("Not enough parameters");
			return;
		}
		try{
			Scanner in=new Scanner(new File(args[0]));
			in.useLocale(Locale.ENGLISH);
			PrintWriter out=new PrintWriter(new File(args[1]));
			runCases(in,out);
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	public void runCases(Scanner in, PrintWriter out){
		int numOfCases=in.nextInt();
		in.nextLine();
		for(int i=1;i<=numOfCases;i++){
			parseCase(in);
			solveCase();
			out.println("Case #"+i+": "+getSolution());
			out.flush();
			System.out.println("Case #"+i+": "+getSolution());
		}
		
	}

	public static void main(String[] args) {
		new TaskC().runTask(args);
	}

}
