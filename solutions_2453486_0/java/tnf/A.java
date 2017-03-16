import java.util.*;

class A{

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		sc.nextLine();		
		for(int kase = 1; kase<=T; kase++){
			char[][] brd = new char[4][4];
			boolean draw = true;
			int x = 0;
			for(int i = 0; i<4; i++){
				String s = sc.nextLine();
				for(int j = 0; j<4; j++){
					brd[i][j] = s.charAt(j);
					if(brd[i][j]=='X') x++;
					else if(brd[i][j]=='O') x--;
					else if(brd[i][j]=='.')draw=false;
				}
			}
			boolean X = false;
			boolean O = false;
			//rows
			for(int i = 0; i<4; i++){
				if(is('O',i,0,brd)&&is('O',i,1,brd)&&is('O',i,2,brd)&&is('O',i,3,brd))O = true;
				if(is('O',0,i,brd)&&is('O',1,i,brd)&&is('O',2,i,brd)&&is('O',3,i,brd))O = true;
				if(is('X',i,0,brd)&&is('X',i,1,brd)&&is('X',i,2,brd)&&is('X',i,3,brd))X = true;
				if(is('X',0,i,brd)&&is('X',1,i,brd)&&is('X',2,i,brd)&&is('X',3,i,brd))X = true;
				if(is('O',0,0,brd)&&is('O',1,1,brd)&&is('O',2,2,brd)&&is('O',3,3,brd))O = true;
				if(is('O',0,3,brd)&&is('O',1,2,brd)&&is('O',2,1,brd)&&is('O',3,0,brd))O = true;
				if(is('X',0,0,brd)&&is('X',1,1,brd)&&is('X',2,2,brd)&&is('X',3,3,brd))X = true;
				if(is('X',0,3,brd)&&is('X',1,2,brd)&&is('X',2,1,brd)&&is('X',3,0,brd))X = true;
			}
			if(O && X && x==1) System.out.println("Case #"+kase+": X won");
			else if(O && X && x==0) System.out.println("Case #"+kase+": O won");
			else if(O) System.out.println("Case #"+kase+": O won");
			else if(X) System.out.println("Case #"+kase+": X won");
			else if(draw) System.out.println("Case #"+kase+": Draw");
			else System.out.println("Case #"+kase+": Game has not completed");
			if(sc.hasNext())sc.nextLine();
		}
	}
	static boolean is(char c, int i,int j, char[][] b){
		return b[i][j]==c || b[i][j]=='T';
	}
}
