import java.util.Scanner;


public class Lawnmower {

	public void solve(int caseNo, int[][] input){
		for(int i = 0; i < input.length; i++)
			for(int j = 0; j < input[0].length; j++){
				int current = input[i][j];
				boolean cPos = true;
				boolean lPos = true;
				for(int k = 0; k < input.length; k++)
					if(current < input[k][j]){
						cPos = false;
						break;
					}
				
				for(int k = 0; k < input[0].length; k++)
					if(current < input[i][k]){
						lPos = false;
						break;
					}
				
				if(!cPos && !lPos){
					System.out.println("Case #"+caseNo+": "+"NO");
					return;
				}
			}
		System.out.println("Case #"+caseNo+": "+"YES");
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Lawnmower l = new Lawnmower();
		Scanner sc = new Scanner(System.in);
		int totalCase = Integer.parseInt(sc.nextLine());
		for(int i =1; i <= totalCase; i++){
			String s = sc.nextLine();
			int n = Integer.parseInt(s.split(" ")[0]);
			int m = Integer.parseInt(s.split(" ")[1]);
			int[][] input = new int[n][m];
			for(int j = 0; j < n; j++){
				String line = sc.nextLine();
				for(int k = 0; k < m; k++){
					input[j][k] = Integer.parseInt(line.split(" ")[k]);
				}
			}
			l.solve(i, input);
		}

	}

}
