import java.util.Scanner;


public class Main {
	public static void main (String[] args) {
		 Scanner in = new Scanner(System.in);
		 int cases = in.nextInt(); in.nextLine();
		 char[] buff;
		 byte[] tab = new byte[16];
		 int winner;
		 int count;
		 boolean freespot;
		 for(int T=0; T<cases; T++) {
			 freespot = false;
			 winner = 0;
			 for(int i=0; i<4; i++) {
				 count = 0;
				 buff = in.nextLine().toCharArray();
				 for(int j=0; j<4; j++) {
					 switch(buff[j]) {
					 case 'O' :
						 tab[i*4+j] = 1;
						 break;
					 case 'X' :
						 tab[i*4+j] = -1;
						 break;
					 case 'T' :
						 tab[i*4+j] = 0;
						 break;
					 case '.' :
						 tab[i*4+j] = 42;
						 break;
				     default :
				    	 System.err.println("Unrecognized character");
					 }
					 count += tab[i*4+j];
				 }
				 if(count > 33)
					 freespot = true;
				 else if(count > 2)
					 winner = 1;
				 else if(count < -2)
				 	winner = -1;
			 }
			 if(winner == 0) {
				 for(int i=0; i<4; i++) {
					 count = tab[i] + tab[i+4] + tab[i+8] + tab[i+12];
					 if(count > 33)
						 freespot = true;
					 else if(count > 2)
						 winner = 1;
					 else if(count < -2)
					 	winner = -1;
				 }
			 }
			 if(winner == 0) {
				 count = tab[0] + tab[5] + tab[10] + tab[15];
				 if(count > 33)
					 freespot = true;
				 else if(count > 2)
					 winner = 1;
				 else if(count < -2)
				 	winner = -1;
			 }
			 if(winner == 0) {
				 count = tab[3] + tab[6] + tab[9] + tab[12];
				 if(count > 33)
					 freespot = true;
				 else if(count > 2)
					 winner = 1;
				 else if(count < -2)
				 	winner = -1;
			 }
			 System.out.print("Case #" + (T+1) + ": ");
			 if(winner == 1)
				 System.out.println("O won");
			 else if(winner == -1)
				 System.out.println("X won");
			 else if(freespot)
				 System.out.println("Game has not completed");
			 else
				 System.out.println("Draw");
			 in.nextLine();
		 }
	}
}
