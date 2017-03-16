import static java.lang.System.*;
import static java.lang.Math.*;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
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

    public boolean Xwin(char[][] map){
    	for(int y=0;y<4;y++){
    		boolean ok=true;
    		for(int x=0;x<4;x++){
    			if(!(map[y][x]=='X' ||map[y][x]=='T')){
    				ok=false;
    			}
    		}
    		if(ok)return true;
		}
    	for(int x=0;x<4;x++){
    		boolean ok=true;
    		for(int y=0;y<4;y++){
    			if(!(map[y][x]=='X' ||map[y][x]=='T')){
    				ok=false;
    			}
    		}
    		if(ok)return true;
		}
    	{
    		boolean ok=true;
    		for(int i=0;i<4;i++){
    			if(!(map[i][i]=='X' ||map[i][i]=='T')){
    				ok=false;
    			}
    		}
    		if(ok)return true;
    	}
    	{
    		boolean ok=true;
    		for(int i=0;i<4;i++){
    			if(!(map[i][3-i]=='X' ||map[i][3-i]=='T')){
    				ok=false;
    			}
    		}
    		if(ok)return true;
    	}
    	return false;
    }

    public boolean Owin(char[][] map){
    	for(int y=0;y<4;y++){
    		boolean ok=true;
    		for(int x=0;x<4;x++){
    			if(!(map[y][x]=='O' ||map[y][x]=='T')){
    				ok=false;
    			}
    		}
    		if(ok)return true;
		}
    	for(int x=0;x<4;x++){
    		boolean ok=true;
    		for(int y=0;y<4;y++){
    			if(!(map[y][x]=='O' ||map[y][x]=='T')){
    				ok=false;
    			}
    		}
    		if(ok)return true;
		}
    	{
    		boolean ok=true;
    		for(int i=0;i<4;i++){
    			if(!(map[i][i]=='O' ||map[i][i]=='T')){
    				ok=false;
    			}
    		}
    		if(ok)return true;
    	}
    	{
    		boolean ok=true;
    		for(int i=0;i<4;i++){
    			if(!(map[i][3-i]=='O' ||map[i][3-i]=='T')){
    				ok=false;
    			}
    		}
    		if(ok)return true;
    	}
    	return false;
    }

    public boolean fill(char[][] map){
    	for(int y=0;y<4;y++){
    		for(int x=0;x<4;x++){
    			if(map[y][x]=='.')return false;
    		}
		}
    	return true;
     }


    public void run(){
    	int n=sc.nextInt();

    	StringBuilder sb=new StringBuilder();
    	for(int c=1;c<=n;c++){
    		char[][] map=new char[4][4];
    		for(int i=0;i<4;i++){
    			map[i]=sc.next().toCharArray();
    		}
    		//xwin?
    		if(Xwin(map)){
        		sb.append("Case #"+c+": X won\n");
    		}else if(Owin(map)){
        		sb.append("Case #"+c+": O won\n");
    		}else if(fill(map)){
        		sb.append("Case #"+c+": Draw\n");
    		}else{
        		sb.append("Case #"+c+": Game has not completed\n");
    		}
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