import java.util.Scanner;


public class pogoJump {

	/**
	 * @param args
	 */
	private static int nextJump = 1;
	private static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int loops = sc.nextInt();
		for (int i = 0;i <loops;i++){
			int x = sc.nextInt();
			int y = sc.nextInt();
			String moves =moveX(x)+ moveY(y);
			System.out.println("Case #"+(i+1)+": "+moves);
		}

	}
	private static String moveX(int x) {
			int cx =0;
			String directions = "";
			while (cx !=x){
				if (cx>x){
					cx -=1;
					nextJump++;
					directions= directions+"E";
					nextJump++;
					directions= directions+"W";
				}
				else {
					cx +=1;
					nextJump++;
					directions= directions+"W";
					nextJump++;
					directions= directions+"E";
				}
			}
		return directions;
	}
	private static String moveY(int x) {
		int cx =0;
		String directions = "";
		while (cx !=x){
			if (cx>x){
				cx -=1;
				nextJump++;
				directions= directions+"N";
				nextJump++;
				directions= directions+"S";
			}
			else {
				cx +=1;
				nextJump++;
				directions= directions+"S";
				nextJump++;
				directions= directions+"N";
			}
		}
	return directions;
}

}
