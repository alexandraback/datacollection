import static java.lang.System.*;
import static java.lang.Math.*;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class B{
    public static Scanner sc = new Scanner(in);
    public static Random rand=new Random();

    public static PrintWriter out;
    static{
    	try {
			out=new PrintWriter(new BufferedWriter(new FileWriter("C:\\Users\\shimomire\\Dropbox\\Project\\ProgramContest\\java\\GCJ\\res.out")));
		} catch (IOException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}
    }

    public void run(){
    	int T=sc.nextInt();
    	StringBuilder sb=new StringBuilder();
    	Case:for(int i=1;i<=T;i++){
    		int H=sc.nextInt(),W=sc.nextInt();

    		int[][] map=new int[H][W];

    		int[] wmax=new int[H],hmax=new int[W];
    		for(int h=0;h<H;h++)
        		for(int w=0;w<W;w++)
    			map[h][w]=sc.nextInt();

    		for(int w=0;w<W;w++){
    			int mv=0;
    			for(int h=0;h<H;h++)
    				mv=max(mv,map[h][w]);
    			hmax[w]=mv;
    		}
    		for(int h=0;h<H;h++){
    			int mv=0;
    			for(int w=0;w<W;w++)
    				mv=max(mv,map[h][w]);
    			wmax[h]=mv;
    		}

    		for(int h=0;h<H;h++)
        		for(int w=0;w<W;w++){
        			if(map[h][w]!=min(wmax[h],hmax[w])){
        				sb.append("Case #"+i+": NO").append("\n");
        				continue Case;
        			}
        		}
    		sb.append("Case #"+i+": YES").append("\n");
    	}
    	ln(sb);
    	out.close();
    }

    public static void main(String[] _) {
        new B().run();
    }

    public int[] nextIntArray(int n){
        int[] res=new int[n];
        for(int i=0;i<n;i++){
            res[i]=sc.nextInt();
        }
        return res;
    }
    public static void pr(Object o) {
    	out.print(o);
    }
    public static void ln(Object o) {
        out.println(o);
    }
    public static void ln() {
    	out.println();
    }

}