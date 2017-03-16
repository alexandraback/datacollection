import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class main {
	public static int[] tab1 = {1,2,3,4};
	public static int[] tab2 = {2,-1,4,-3};
	public static int[] tab3 = {3,-4,-1,2};
	public static int[] tab4 = {4,3,-2,-1};
	public static int[][] tab = {tab1,tab2,tab3,tab4} ;
	
	
	public static void write(PrintWriter file, int idx, String str){
		file.println("Case #"+idx+": "+str);
	}
	public static void write(PrintWriter file, int idx, int ans){
		file.println("Case #"+idx+": "+ans);
	}
	public static int multiply(int a, int b){
		int signe=1;
		if (a<0)
			signe=-signe;
		if (b<0)
			signe=-signe;
		return signe*tab[Math.abs(a)-1][Math.abs(b)-1];
	}
	
	
	public static void main(String[] args) throws IOException {
     	String epreuve="C-small-attempt0.in";
		File entry = new File(epreuve);
		Scanner scin= new Scanner(entry);
		File out = new File("Output"+epreuve);
		out.createNewFile();
		PrintWriter scout= new PrintWriter(out);	
		// Set up of the problem
		int T = scin.nextInt();
		char[] basic;
		int[] totalProduct;
		int[] formattedString;
		for (int i=1; i<= T; i++){
		    int L=scin.nextInt(); int X=scin.nextInt(); totalProduct=new int[L]; formattedString=new int[L];
		    basic=scin.next().toCharArray();
		    for (int j=0; j<L; j++){
		    	if(basic[j]=='i')
		    		formattedString[j]=2;
		    	else if (basic[j]=='j')
		    		formattedString[j]=3;
		    	else if (basic[j]=='k')
		    		formattedString[j]=4;
		    }
		    totalProduct[0]=formattedString[0];
		    for(int j=1; j<L; j++)
		    		totalProduct[j]=multiply(totalProduct[j-1], formattedString[j]);
		    int temp=totalProduct[L-1];
		    for (int j=1; j<X%4;j++)
		    	temp=multiply(temp, totalProduct[L-1]);
		    if (X%4==0 || temp!=-1)
		    	write(scout,i,"NO");
		    else{
		    	while(X>=14)
		    		X=X-4;
		    	int runningProduct=formattedString[0];
		    	int step=1;
		    	for (int j=1; j<L*X; j++){
		    		if(step==1 && runningProduct==2){
		    			step=2;
		    			runningProduct=formattedString[j%L];
		    		}
		    		else if(step==2 && runningProduct==3){
		    			step=3;
		    			break;
		    		}
		    		else
		    			runningProduct=multiply(runningProduct, formattedString[j%L]);
		    	}
		    	if(step==3)
		    		write(scout, i, "YES");
		    	else
		    		write(scout, i, "NO");
		    }
			
		}
		scin.close();
		scout.close();
	}

}
