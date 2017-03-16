package round1c;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class problemB {
	
	private static int inst;

	public static void main(String[] args) {

        //String input = "/home/nikos/input";
        String input = "/home/nikos/B-small-attempt1.in";
        String output = "/home/nikos/output";
		try {
            Scanner sc = new Scanner(new FileReader(input));
			PrintWriter pw = new PrintWriter(output);

            int n = sc.nextInt();
            sc.nextLine();
            for (int c = 0; c < n; c++) {
                System.out.println("Test case " + (c + 1) + "...");
                pw.print("Case #" + (c + 1) + ": ");
                checkInsatnce(sc, pw);
                pw.println();
            }
            pw.println();
            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException ex) {
        	ex.printStackTrace();
        } catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static void checkInsatnce(Scanner sc, PrintWriter pw) throws IOException {
		int x = sc.nextInt();
		int y = sc.nextInt();
		String res="";
		System.out.println(x+" "+y);
		int jump=1, xt=0, yt=0;
		boolean movedx=false, north=true;
		int k=0;
		while(true){
			if(k>=500){
				System.out.println("error 500");
				System.exit(1);
				break;
			}
			//System.out.println(xt+" "+yt);
			if(x==jump){
				//movedy=true;
				res+="E";
				xt+=jump;
				if(yt>y)
					north=true;
				else
					north = false;
				movedx=true;
			}
			else if(x==-jump){
				//movedy=true;
				res+="W";
				xt-=jump;
				if(yt>y)
					north=true;
				else
					north = false;
				movedx=true;
			}
			else if(north){
				res+="N";
				yt+=jump;
				north =false;
			}
			else{
				res+="S";
				yt-=jump;
				north =true;
			}
			jump++;
			/*if(Math.abs(yt)>Math.abs(y)){
				System.out.println("error");
				System.exit(1);
				break;
			}*/
			
			if(xt==x && yt==y){//found
				break;
			}
			k++;
		}
		
    	//System.out.println(res);
    	pw.print(res);
    	
    	
    		
        
		
	}

	private static boolean isConsonants(char c) {
		return (c!='a' && c!='e' && c!='i' && c!='o' &&c!='u') ;
	}

}
