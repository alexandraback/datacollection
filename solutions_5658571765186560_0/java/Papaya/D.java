import java.util.Scanner;

public class D {
	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.nextLine(); //remove empty line
		
		String line;
		String[] linesplit;
		int j,k,l,s,a;
		String G = "Richard";
		String R = "Gabriel";
		String win;
		for (int i=1;i<n+1;i++){
			line = in.nextLine();
			linesplit = line.split(" ");
			j = Integer.parseInt(linesplit[0]);
			k = Integer.parseInt(linesplit[1]);
			l = Integer.parseInt(linesplit[2]);
			a = k*l;
			if(k>l){
				s = l;
			}
			else{
				s = k;
			}
			win = G;
			switch(j){
				case 0:
					win = R;
					break;
				case 1:
					win = R;
					break;
				case 2:
					if(a%2==0){
						win = R;
					}
					break;
				case 3:
					if(s>1 && a%3==0){
						win = R;
					}
					break;
				case 4:
					if(s>2 && a%4==0){
						win = R;
					}
					break;
				case 5:
					if(s>2 && a%5==0){
						win = R;
					}
					break;
				case 6:
					if(s>3 && a%6==0){
						win = R;
					}
					break;
				default:
					break;
			}
			
			
			System.out.printf("Case #%d: %s\n",i,win);
		}
		in.close();
		
	}
}
