import java.util.Scanner;
import java.util.StringTokenizer;


public class DancingWiththeGooglers {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in =new Scanner(System.in);
		int cases=Integer.parseInt(in.nextLine())+1;
		for(int tt=1;tt<cases;tt++){
			StringTokenizer cmd=new StringTokenizer(in.nextLine());
			int players=Integer.parseInt(cmd.nextToken());
			int surprise=Integer.parseInt(cmd.nextToken());
			int best=Integer.parseInt(cmd.nextToken());
			int count=0;
			for(int i=0;i<players;i++){
				int score=Integer.parseInt(cmd.nextToken());
				if(score>=best+Math.max(best-1, 0)*2){
					count++;
				}else if(score>=best+Math.max(best-2,0)*2&&surprise>0){
					count++;
					surprise--;
				}
			}
			System.out.printf("Case #%d: %d\n",tt,count);
		}
	}

}
