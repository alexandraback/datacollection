/**
ejp mysljylc kd kxveddknmc re jsicpdrysi
our language is impossible to understand

rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
there are twenty six factorial possibilities

de kr kd eoya kw aej tysr re ujdr lkgc jv
so it is okay if you want to just give up
**/
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;
import java.util.Arrays;

/**
 *
 * @author CuteCoke
 */
public class A {
    final String TASK_NAME = "A-small-attempt0";
    //final String TASK_NAME = "A-large-practice";
    //final String TASK_NAME = "sample";
    final String IN_FILE = TASK_NAME+".in";
    final String OUT_FILE = TASK_NAME+".out";

    public String solve(String G){
		String res = "";
		for(int i=0; i<G.length(); i++){
			char ch = G.charAt(i);
			if 		(ch=='a') res += "y";//
			else if (ch=='b') res += "h";//
			else if (ch=='c') res += "e";//
			else if (ch=='d') res += "s";//
			else if (ch=='e') res += "o";//
			else if (ch=='f') res += "c";//
			else if (ch=='g') res += "v";//
			else if (ch=='h') res += "x";//
			else if (ch=='i') res += "d";//
			else if (ch=='j') res += "u";//
			else if (ch=='k') res += "i";//
			else if (ch=='l') res += "g";//
			else if (ch=='m') res += "l";//
			else if (ch=='n') res += "b";//
			else if (ch=='o') res += "k";//
			else if (ch=='p') res += "r";//
			else if (ch=='q') res += "z";
			else if (ch=='r') res += "t";//
			else if (ch=='s') res += "n";//
			else if (ch=='t') res += "w";//
			else if (ch=='u') res += "j";//
			else if (ch=='v') res += "p";//
			else if (ch=='w') res += "f";//
			else if (ch=='x') res += "m";//
			else if (ch=='y') res += "a";//
			else if (ch=='z') res += "q";
			else if (ch==' ') res += " ";
			else res += (ch+"");
		}
        return res;
    }

    public void doMain() throws Exception{
    try{

        Scanner sc1 = null;
        BufferedReader br = new BufferedReader(new FileReader(IN_FILE));
        BufferedWriter bw = new BufferedWriter(new FileWriter(OUT_FILE));

        int T = Integer.parseInt(br.readLine());

        for (int a=0; a<T; a++){
            bw.write("Case #"+(a+1)+": ");
            String G = br.readLine();
            String ans = solve(G);
            bw.write(ans+"\n");
        }
        br.close();
        bw.close();

    }catch(FileNotFoundException e){
        System.err.println("In File: "+(new File(IN_FILE)).getAbsolutePath());
        System.err.println("Out File: "+(new File(OUT_FILE)).getAbsolutePath());
        e.printStackTrace(System.err);
    }
    }

    public static void main(String[] s) throws Exception{
        try{
            A test = new A();
            test.doMain();
        }catch(Exception e){
            e.printStackTrace(System.err);
        }


    }
}
