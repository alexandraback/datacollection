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
       	int t=sc.nextInt();
    	StringBuilder sb=new StringBuilder();
    	for(int i=1;i<=t;i++){
    		int a=sc.nextInt(),n=sc.nextInt();
    		int[] mo=new int[n];
    		for(int j=0;j<n;j++){
    			mo[j]=sc.nextInt();
    		}
    		Arrays.sort(mo);


    		int[] use=new int[n+1];
    		int s=0;
    		for(int j=0;j<n;j++){
    			if(a==1){
    				s++;
    			}else{
					while(a<=mo[j]){
	    				a+=a-1;
	    				s++;
					}
	    			a+=mo[j];
    			}
    			use[j+1]=s;
    		}
    		int m=Integer.MAX_VALUE;
    		for(int j=0;j<=n;j++){
    			m=min(use[j]+n-j,m);
    		}
    		sb.append("Case #"+i+": "+m+"\n");
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