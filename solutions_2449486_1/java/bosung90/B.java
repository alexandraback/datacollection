import java.util.Scanner;


public class B {
	static Scanner scan;
	
	public static void main(String[] args) {
		scan = new Scanner(System.in);
		int testCases = scan.nextInt();
		int n = 0;
		while(testCases>0){
			testCases--;
			n++;

			int N = scan.nextInt();
			int M = scan.nextInt();
			//create 2d-array int
			
			int lawn[][] = new int[N][M];
			for(int j=0; j<N; j++){
				for(int i=0; i<M; i++){
					lawn[j][i] = scan.nextInt();
				}
			}
			boolean valid = true;
			
			//for each meter space, check if its horizontal or vertical
			//has height smaller or equal to itself.
			//if any meter space fail, output NO
			
			for(int j=0; j<N; j++){
				for(int i=0; i<M; i++){
					if(!checkValidLawn(lawn,i,j, N, M))
						valid = false;
				}
			}
			
			System.out.print("Case #"+n+": ");
			if(valid)
				System.out.println("YES");
			else
				System.out.println("NO");
			
		}
		
//		for(int a = 0; a<cases; a++){
//			System.out.println("Case #"+(a+1)+": ");
//		}
	}
	
	public static boolean checkValidLawn(int[][] lawn, int i, int j, int N, int M){
		int current = lawn[j][i];
		
		//check horizontal
		boolean validHori = true;
		for(int h=0; h<M; h++){
			if(h!=i && current<lawn[j][h])
				validHori = false;
		}
		
		//check vertical
		boolean validVerti = true;
		for(int v=0; v<N; v++){
			if(v!=j && current<lawn[v][i])
				validVerti = false;
		}
		
		return (validHori || validVerti);
	}

}
