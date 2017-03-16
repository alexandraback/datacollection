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
	String str;
	int n;
	
	int[] list;
	int[] prev;
	
	HashSet<Character> set;
	
	int ans;
	void solve(){
		ans = 0;
		
		if( !set.contains(str.charAt(0)) ){
			list[ 0 ] = 1;
		}else{
			list[ 0 ] = 0;
		}
		if( list[ 0 ] >= n ){
			int left = 0 - n + 1 - (prev[0] + 1);
			int right = list.length-1 -0;
			ans += left;
			ans += 1;
			ans += right;
			
			ans += left*right;
			
			prev[ 0 ] = 0 - n + 1;
		}
		
		for( int i = 1; i < list.length; ++i ){
			char c = str.charAt(i);
			if( !set.contains(c) ){
				list[ i ] = list[ i - 1 ] + 1;
			}else{
				list[ i ] = 0;
			}
			prev[ i ] = prev[ i -1 ];
			
			if( list[ i ] >= n ){
				int left = i - n + 1 - (prev[i] + 1);
				int right = list.length-1 -i;
				ans += left;
				ans += 1;
				ans += right;
				
				ans += left*right;
				
				prev[ i ] = i - n + 1;
			}
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
		
		set = new HashSet<Character>();
		set.add('a');
		set.add('e');
		set.add('i');
		set.add('o');
		set.add('u');
		
		T = ni();
		for( int i = 0; i < T; ++i ){
			str = sc.next();
			list = new int[str.length()];
			Arrays.fill(list, 0);
			prev = new int[str.length()];
			Arrays.fill(prev, -1);
			
			n = ni();
			
			solve();
			System.out.println("Case #" + Integer.toString(i + 1) + ": " + Integer.toString(ans));
			try {
				fw.write("Case #" + Integer.toString(i + 1) + ": " + Integer.toString(ans) + "\n");
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
