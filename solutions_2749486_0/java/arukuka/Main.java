import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

class Main{
	Scanner sc;
	
	int T;
	int X;
	int Y;
	
	int INF = 1<<28;
	int[][] f;
	int ofs = 100;
	
	int dd[][] = {
			{ 0, 1 },
			{ 0, -1 },
			{ 1, 0 },
			{ -1, 0 },
	};
	
	String ds[] = {
			"N",
			"S",
			"E",
			"W"
	};
		
	String ans;
	int min;
	void solve(int x, int y, int depth, String res){
		if( depth > min ){
			return;
		}
		
		if( x == X && y == Y ){
			if( min > depth ){
				min = depth;
				ans = res;
			}
			return;
		}
		
		for(int i = x==X ? 2 : 0; i < (y==Y ? 2 : 4); ++i){
			solve( x + dd[i][0]*(depth+1), y + dd[i][1]*(depth+1), depth + 1, res + ds[i]);
		}
	}
	
	void run(){
		//sc = new Scanner(System.in);
		getFS("C:\\Users\\Ohtsuka\\Desktop\\in.txt");
		File fo;
		FileWriter fw = null;
		try{
			fo = new File("C:\\Users\\Ohtsuka\\Desktop\\out.txt");
			fw = new FileWriter(fo);
		}catch(IOException e){
			System.out.println(e);
		}
		
		f = new int[ ofs*2 + 1 ][ ofs*2 + 1 ];
		for(int i=0; i<=ofs*2; ++i){
			Arrays.fill(f[i], INF);
		}
		
		T = ni();
		for( int i = 0; i < T; ++i ){
			X = ni();
			Y = ni();
			
			min = (Math.abs(X)+Math.abs(Y))*2;
			ans = "";
			//solve(0,0,0,"");
			for( int j = 0; j < Math.abs(X); ++j ){
				if( X > 0 ){
					ans += "WE";
				}else{
					ans += "EW";
				}
			}
			for( int j = 0; j < Math.abs(Y); ++j ){
				if( Y > 0 ){
					ans += "SN";
				}else{
					ans += "NS";
				}
			}
			
			System.out.println("Case #" + Integer.toString(i + 1) + ": " + ans);
			try {
				fw.write("Case #" + Integer.toString(i + 1) + ": " + ans + "\n");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		try {
			fw.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		sc.close();
	}
	
	void getFS(String src){
		try {
			sc = new Scanner(new File(src));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	int ni(){ return Integer.parseInt(sc.next()); }
	
	
	public static void main(String args[]){
		new Main().run();
	}
}
