import java.util.*;


public class Main {

	Scanner sc = new Scanner(System.in);

	private void doit(){
		new AS();
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

}
