import static java.lang.System.*;
import static java.lang.Math.*;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class D{
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

    class Box{
    	int key;
    	int[] trekeys;
    	public Box(int key,int size){
    		this.key=key;
    		this.trekeys=new int[size];
    	}
    }


    boolean[] opened=new boolean[201];
    int[] keys=new int[401];
    Box[] boxes=new Box[201];
    int K,N;
    private String dfs(int size,String res){
    	if(size==N){
    		return res;
    	}
    	for(int i=1;i<=N;i++){
    		if(!opened[i] && keys[boxes[i].key]>0){
    			opened[i]=true;
    			keys[boxes[i].key]--;
    			for(int val :boxes[i].trekeys){
    				keys[val]++;
    			}
    			String r=dfs(size+1,res+(res.length()>0?" ":"")+i);
    			if(r!=null)return r;
    			opened[i]=false;
    			keys[boxes[i].key]++;
    			for(int val :boxes[i].trekeys){
    				keys[val]--;
    			}
    		}
    	}
    	return null;
    }


    public void run(){
    	int T=sc.nextInt();
    	StringBuilder sb=new StringBuilder();
    	for(int i=1;i<=T;i++){
    		K=sc.nextInt();
    		N=sc.nextInt();
    		Arrays.fill(opened, false);
    		for(int k=0;k<K;k++){
    			keys[sc.nextInt()]++;
    		}
    		for(int b=1;b<=N;b++){
    			Box box=new Box(sc.nextInt(),sc.nextInt());
    			for(int k=0;k<box.trekeys.length;k++){
    				box.trekeys[k]=sc.nextInt();
    			}
    			boxes[b]=box;
    		}

    		String res=dfs(0,"");
    		if(res!=null)
    			sb.append("Case #"+i+": ")
    			.append(res).append("\n");
    		else
    			sb.append("Case #"+i+": ")
    			.append("IMPOSSIBLE").append("\n");
    	}
    	ln(sb);
    	out.close();
    }

    public static void main(String[] _) {
        new D().run();
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