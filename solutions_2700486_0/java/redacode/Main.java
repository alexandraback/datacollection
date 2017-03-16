import java.io.*;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.*;


public class Main {

	Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		new Main().doit();
	}

	 private void debug(Object... o) {
	        System.out.println("debug = " + Arrays.deepToString(o));
	    }

	//メイン関数
	private void doit(){
		new B();
	}

	class A{
		A(){
			int dataset = sc.nextInt();
			int datasetC = 1;
			while(dataset-- > 0){
				System.out.printf("Case #%d: ", datasetC++);
				long a = sc.nextInt();
				int n = sc.nextInt();
				int [] data = new int[n];
				for(int i = 0; i < n; i++){
					data[i] = sc.nextInt();
				}
				if(a == 1){
					System.out.println(n);
					continue;
				}
				Arrays.sort(data);
				int nowcount = 0;
				int mincount = n;

				for(int i = 0; i < n; i++){
					while(a <= data[i]){
						a = a + (a - 1);
						nowcount++;
					}
					a += data[i];
					int temp = nowcount + n - i - 1;
					mincount = Math.min(mincount, temp);
				}
				System.out.println(mincount);
			}
		}
	}

	class B{
		int n;
		HashMap<Integer, HashSet<Integer>> cor;
		int count, allcount;
		int ansx,ansy;

		B(){
			int dataset = sc.nextInt();
			int datasetC = 1;
			while(dataset-- > 0){
				System.out.printf("Case #%d: ", datasetC++);
				n = sc.nextInt();
				ansx = sc.nextInt();
				ansy = sc.nextInt();
				cor = new HashMap<Integer, HashSet<Integer>>();
				count = 0;
				allcount = 0;
				for(int i = -50; i <= 50; i++){
					cor.put(i, new HashSet<Integer>());
				}
				dfs(0, 0,0,0,0);
				System.out.println((double)count / allcount);
			}
		}

		private void dfs(int deep, int x1, int y1, int x2, int y2) {
			if(deep == n){
				allcount++;
				if(cor.containsKey(ansx) && cor.get(ansx).contains(ansy)){
					count++;
				}
				return;
			}

			if(x1 == 0 && x2 == 0){
				cor.get(0).add(y1);
				dfs(deep + 1, (y1 + 2) * -1 , 0, (y1 + 2) , 0);
				cor.get(0).remove(y1);
				return;
			}

			if(x1 != 0){
				cor.get(x1).add(y1);
				dfs(deep + 1, x1 + 1, y1 + 1, x2, y2);
				cor.get(x1).remove(y1);
			}
			if(x2 != 0){
				cor.get(x2).add(y2);
				dfs(deep + 1, x1, y1, x2 - 1, y2 + 1);
				cor.get(x2).remove(y2);
			}
		}
	}
}
