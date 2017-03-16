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
		new A();
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
}
