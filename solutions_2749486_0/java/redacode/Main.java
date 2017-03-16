import java.util.*;


public class Main {

	Scanner sc = new Scanner(System.in);

	private void doit(){
		new B();
	}

	private void debug(Object... o) {
		System.out.println("debug = " + Arrays.deepToString(o));
	}

	public static void main(String[] args) {
		new Main().doit();
	}

	class AS{
		AS(){
			int dataset = sc.nextInt();
			int datasetC = 1;
			while(dataset-- > 0){
				System.out.printf("Case #%d: ", datasetC++);
				String str = sc.next();
				int n = sc.nextInt();
				int count = 1;
				int ans = 0;
				for(int i = 0; i < str.length(); i++){
					if(isB(str.charAt(i))){
						count++;
					}
					else{
						int nowcount = 0;
						int j;
						for(j = i; j < str.length(); j++){
							if(! isB(str.charAt(j))){
								nowcount++;
								if(nowcount >= n){
									break;
								}
							}
							else{
								break;
							}
						}
						if(nowcount >= n){
							ans += count * (str.length() - j);
							count = 1;
						}
						else{
							count++;
						}
					}
				}
				System.out.println(ans);
			}
		}

		private boolean isB(char c) {
			if(c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o'){
				return true;
			}
			return false;
		}
	}

	class B{

		int vx[] = {0,1,0,-1};
		int vy[] = {1,0,-1,0};
		String [] table = {"N", "E", "S", "W"};

		class State{
			int x,y,step;
			String route;

			public State(int x, int y, int step, String route) {
				this.x = x;
				this.y = y;
				this.step = step;
				this.route = route;
			}

			@Override
			public String toString() {
				return "State [x=" + x + ", y=" + y + ", step=" + step
						+ ", route=" + route + "]";
			}


		}
		B(){
			int dataset = sc.nextInt();
			int datasetC = 1;
			while(dataset-- > 0){
				System.out.printf("Case #%d: ", datasetC++);
				int gx = sc.nextInt();
				int gy = sc.nextInt();
				HashMap<Integer, HashSet<Integer>> close = new HashMap<Integer, HashSet<Integer>>();
				for(int i = -1000; i <= 1000; i++){
					close.put(i, new HashSet<Integer>());
				}
				LinkedList<State> open = new LinkedList<State>();
				open.add(new State(0, 0, 0, ""));
				close.get(0).add(0);
				String ans = null;
				while(! open.isEmpty()){
					State now = open.poll();
					if(now.x == gx && now.y == gy){
						ans = now.route;
						break;
					}

					for(int i = 0; i < 4; i++){
						int xx = now.x + vx[i] * (now.step + 1);
						int yy = now.y + vy[i] * (now.step + 1);
						if(close.containsKey(xx) && close.get(xx).contains(yy)) continue;
						StringBuilder sb = new StringBuilder(now.route);
						sb.append(table[i]);
						close.get(xx).add(yy);
						open.add(new State(xx, yy, now.step + 1, sb.toString()));
					}
				}
				System.out.println(ans);

			}
		}
	}

}
