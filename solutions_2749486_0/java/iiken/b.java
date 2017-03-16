import java.util.Scanner;
import java.io.FileWriter;
import java.io.File;
import java.util.*;
import java.math.BigInteger;
public class b{
	static int encode( int x, int y){
		return (x+200)* 1000 + y+200 ;
	}
	static int[] decode(int key){
		int[] res = new int[2];
		res[0] = key /1000-200;
		res[1] = key %1000-200;
		return res;
	}
	static int [][] d = new int[][]{ {1,0},{-1,0},{0,1},{0,-1}};
	static String [] dir = new String[]{"E","W","N","S"};
	static String getStr(String s , int k){
		return new String(s + dir[k]);
	}
	static String solve( int x, int y ){
		Queue<Integer> q = new LinkedList<Integer>();
		int start = encode(0, 0);
		q.add(start);
		Hashtable<Integer, String> h = new Hashtable<Integer,String>();
		h.put(start,"");
		while ( q.size() > 0){
			int top = q.poll();
			//int xt = top[0];
			//int yt = top[1];
			String str = h.get(top);
			
			int step = str.length() +1;
			int[] xytop = decode(top);
			for ( int i =0; i < 4; i++){
				int xn = xytop[0] + d[i][0]*step;
				int yn = xytop[1] + d[i][1]*step;
				int nkey = encode(xn,yn);
				if ( !h.containsKey(nkey) ){
					String nValue = getStr(str,i);
					//System.out.println(nValue+ " " + ""+" "+xn + " " + yn + " " + xytop[0]+ "  " + xytop[1] + " " + "");
					if ( x == xn && y == yn ) return nValue;
					h.put(nkey, nValue);
					q.add(nkey);
				}
			}
		}
		return null;
	}
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("b.in"));
		FileWriter fw = new FileWriter("b.out");
		int T = sc.nextInt();
		for ( int t = 0 ; t <T ; t++){
			int x = sc.nextInt();
			int y = sc.nextInt();
			String str = solve(x,y);
			//....Do sth here
			fw.write("Case #" + (t+1) + ": " + str);
			fw.write("\n");
		}
		fw.close();
	}
}	
