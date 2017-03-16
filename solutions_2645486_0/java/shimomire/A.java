import static java.lang.System.*;
import static java.lang.Math.*;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class A{
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
    	int c=sc.nextInt();
    	StringBuilder sb=new StringBuilder();
    	for(int i=1;i<=c;i++){
    		int E=sc.nextInt(),e=E,r=sc.nextInt();
    		int n=sc.nextInt();
    		int[] vs=new int[n];
    		for(int j=0;j<n;j++){
    			vs[j]=sc.nextInt();
    		}
    		int l=0;
    		int res=0;
    		while(l<n){
    			int mind=-1;
    			for(int j=l+1;j<n;j++){
    				if(vs[l]<=vs[j]){
    					mind=j;
    					break;
    				}
    			}
    			if(mind>0){
    				//mindが来るはずなので減らすだけ減らす。
    				int use=Math.min(E,Math.max(e+r*(mind-l) -E,0));
    				res+=vs[l]*use;
    				e-=use;
    			}else{
    				//all
    				res+=vs[l]*e;
    				e=0;
    			}
				l++;
				e+=r;
    		}
    		ln("Case #"+i+": "+res);
    	}

    	ln(sb);
    	out.close();
    }

    public static void main(String[] _) {
        new A().run();
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