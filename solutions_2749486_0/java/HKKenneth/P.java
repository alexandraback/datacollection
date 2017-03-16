import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;


public class P {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		String[][] arr = new String[250][250];
		for (int i = 0; i < 250; i++) {
			for (int j = 0; j < 250; j++) {
				arr[i][j] = "";
			}	
		}
		Queue<Integer> x_q = new LinkedList<Integer>();
		Queue<Integer> y_q = new LinkedList<Integer>();
		Queue<Integer> n_q = new LinkedList<Integer>();
		Queue<String> d_q = new LinkedList<String>();
		x_q.add(110);
		y_q.add(110);
		n_q.add(0);
		d_q.add(" ");
		int update = 0;
		while (!x_q.isEmpty()) {
			int x = x_q.poll();
			int y = y_q.poll();
			int n = n_q.poll();
			String d = d_q.poll();
			if ((x < 0) || (x >= 250)) {
				continue;
			}
			if ((y < 0) || (y >= 250)) {
				continue;
			}
			if (arr[x][y].length() > 0) {
				continue;
			}
			update += 1;
			arr[x][y] = d;
			x_q.add(x + n + 1);
			y_q.add(y);
			n_q.add(n + 1);
			d_q.add(d + "E");
			
			x_q.add(x - n - 1);
			y_q.add(y);
			n_q.add(n + 1);
			d_q.add(d + "W");
			
			x_q.add(x);
			y_q.add(y + n + 1);
			n_q.add(n + 1);
			d_q.add(d + "N");
			
			x_q.add(x);
			y_q.add(y - n - 1);
			n_q.add(n + 1);
			d_q.add(d + "S");
			if (update > 4000000){
				break;
			}
		}
		for (int k = 1 ; k <= t; k++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			System.out.println("Case #" + k + ":" + arr[x+110][y+110]);
		}
	}

}
