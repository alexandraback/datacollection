import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class CoinJam {
    static Scanner in;
    static PrintStream out;

    // generate
    public static void main(String[] args) throws IOException {
	int limit = 50;
	for (int i = 0; i < 1<<14; i++) {
	    String bin = String.format("1%1$14s1", Integer.toBinaryString(i))
		    .replace(' ', '0');
	    String bases = "";
	    boolean all = true;
	    for (int b = 2; b <= 10; b++) {
		long parsed = Long.parseLong(bin, b);
		/** Trick to factorize fast using linux factor**/
		Process p = Runtime.getRuntime().exec("factor " + parsed);
		String[] res = new BufferedReader(new InputStreamReader(p.getInputStream())).readLine().split(" ");
		if(res.length>2){
		    bases+=" "+res[1];
		}else{
		    all = false;
		    break;
		}
	    }
	    if(all){
		System.out.println(bin+bases);
		limit--;
	    }
	    if(limit==0){
		break;
	    }
	}
    }

}