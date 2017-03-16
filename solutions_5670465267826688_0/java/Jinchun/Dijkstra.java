import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Dijkstra {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("D:\\javaspace\\codjam\\C-small-attempt0.in"));//B-large.in
		int n = in.nextInt();
		PrintWriter out = new PrintWriter("D:\\javaspace\\Practise\\src\\out.txt");
		int[][] map = new int[5][5];
		map[1][0]=1;
		map[2][0]=2;
		map[3][0]=3;
		map[4][0]=4;
		map[0][1]=1;
		map[1][1]=1;
		map[2][1]=2;
		map[3][1]=3;
		map[4][1]=4;
		map[0][2]=2;
		map[1][2]=2;
		map[2][2]=-1;
		map[3][2]=-4;
		map[4][2]=3;
		map[0][3]=3;
		map[1][3]=3;
		map[2][3]=4;
		map[3][3]=-1;
		map[4][3]=-2;
		map[0][4]=4;
		map[1][4]=4;
		map[2][4]=-3;
		map[3][4]=2;
		map[4][4]=-1;
		for(int i=1;i<=n;i++){
			int L = in.nextInt();
			int X = in.nextInt();
			String s = in.next();
			s=switchString(s);
			String str = s;
			for(int j=1;j<X;j++){
				str+=new String(s);
			}
			if(str.length()<3||!isPossible(str,map)){
				out.println("Case #"+i+": NO");
			}
			else{
				out.println("Case #"+i+": YES");
			}
		}
		out.close();
		in.close();

	}
	
	private static String switchString(String s){
		String res = new String();
		for(int i=0;i<s.length();i++){
			if(s.charAt(i)=='i'){
				res+='2';
			}
			else if(s.charAt(i)=='j'){
				res+='3';
			}
			else{
				res+='4';
			}
		}
		return res;
	}
	
	private static boolean isPossible(String str, int[][] map){
		int n = str.length();
		int[] left = new int[n];
		int[] right = new int[n];
		left[0] = str.charAt(0)-'0';
		int lsign=1;
		right[n-1] = str.charAt(n-1)-'0';
		int rsign=1;
		for(int i=1;i<n;i++){
			left[i] = lsign*map[left[i-1]*lsign][str.charAt(i)-'0'];
			right[n-1-i] = map[str.charAt(n-1-i)-'0'][right[n-i]*rsign]*rsign;
			lsign=left[i]>0?1:-1;
			rsign=right[n-1-i]>0?1:-1;
		}
		for(int i=0;i<n-2;i++){
			if(left[i]==2){
				for(int j=i+1;j<n-1;j++){
					if(map[2][3]==left[j]&&right[j+1]==4){
						return true;
					}
				}
			}
		}
		return false;
	}

}
