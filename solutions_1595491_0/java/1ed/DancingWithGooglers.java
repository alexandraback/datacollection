import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class DancingWithGooglers {

	public static void main(String[] args) {
		PrintStream theOut=null;
		try {
			FileOutputStream o = new FileOutputStream("./output.txt", false);
			theOut = new PrintStream(o);
		}
		catch (Exception e) {
			e.printStackTrace();
			return;
		}


		Scanner sc=null;
		try {
			//sc = new Scanner(new File("./A-small.in"));
			sc = new Scanner(new File("/home/duck/Downloads/B-small-attempt0.in"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		int NbGooglers;
		int max;
		int surprising;
		int nbCases = sc.nextInt();

		mainloop: for(int curCase=1; curCase <= nbCases ;++curCase) {
			sc.nextLine();
			NbGooglers = sc.nextInt();
			surprising = sc.nextInt();
			max = sc.nextInt();
			int res=0;
			for (int i = 0; i < NbGooglers; i++) {
				int tot = sc.nextInt();
				if(tot%3 == 0) {
					if(tot/3 >= max) {res++;continue;}
					if(tot/3+1 >= max && tot >= 3 && surprising >0) {res++;surprising--;continue;}
				}
				else if (tot%3 == 1) {
					if(tot/3+1>= max) res++;
				}
				else if (tot%3 == 2) {
					if(tot/3+1 >= max) {res++;continue;}
					if(tot/3+2 >= max && surprising >0) {res++;surprising--;continue;}
				}
			}


			/*******************************************************************/
			theOut.format("Case #%d: %d\n",curCase,res);
			System.out.format("Case #%d: %d\n",curCase,res);





		}

	}
}
