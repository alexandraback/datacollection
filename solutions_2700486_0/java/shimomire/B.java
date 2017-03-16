package round1B;
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
    	int c=sc.nextInt();
    	StringBuilder sb=new StringBuilder();
    	for(long i=1;i<=c;i++){
    		int n=sc.nextInt();
    		int x=sc.nextInt(),y=sc.nextInt();

    		int r=n;
    		//nから三角数を引く
    		int p=0;
    		while(r>2*p+1){
    			r-=2*p+1;
    			p+=2;
    		}
    		double res=0;
    		//残りのrの値を見て
    		if(x+y<p){
    			res=1;
    		}else if(x+y>p){
    			res=0;
    		}else{
    			if(r>p){
    				if(y<=(r-p)/2){
    					res=1;
    				}else if(y-1==(r-p)/2){
    					if(y>=p)
    						res=1;
    					else
    						res=0.5;
    				}else{
    					res=0;
    				}
    			}else{
    				double s=0,a=1;
    				for(int j=r,o=1;j>y;j--,o++){
    					s+=a;
    					a*=j;
    					a/=o;
    				}
    				for(int j=0;j<r;j++){
    					s/=2;
    				}
    				res=s;
    			}
    		}
     		ln("Case #"+i+": "+res);
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