import java.util.Scanner;


public class TicTacToeTomek {

	public void solve(int caseNo, String[] input){
		boolean containsDot = false;
		for(String s : input)
			if(s.contains("."))
				containsDot = true;
		
		for(int i = 0; i < 4; i++){
			int xcount = 0;
			int ocount = 0;
			int tcount = 0;
			for(int j = 0; j < 4; j++){
				if(input[i].charAt(j) == 'X')
					xcount++;
				if(input[i].charAt(j) == 'O')
					ocount++;
				if(input[i].charAt(j) == 'T')
					tcount++;
			}
			if(xcount + tcount == 4){
				System.out.println("Case #"+caseNo+": "+"X won");
				return;
			} else if(ocount + tcount == 4){
				System.out.println("Case #"+caseNo+": "+"O won");
				return;
			}
		}
		
		for(int i = 0; i < 4; i++){
			int xcount = 0;
			int ocount = 0;
			int tcount = 0;
			for(int j = 0; j < 4; j++){
				if(input[j].charAt(i) == 'X')
					xcount++;
				if(input[j].charAt(i) == 'O')
					ocount++;
				if(input[j].charAt(i) == 'T')
					tcount++;
			}
			if(xcount + tcount == 4){
				System.out.println("Case #"+caseNo+": "+"X won");
				return;
			} else if(ocount + tcount == 4){
				System.out.println("Case #"+caseNo+": "+"O won");
				return;
			}
		}
		
		int xcount = 0;
		int ocount = 0;
		int tcount = 0;
		for(int i = 0; i < 4; i++){
			if(input[i].charAt(i) == 'X')
				xcount++;
			if(input[i].charAt(i) == 'O')
				ocount++;
			if(input[i].charAt(i) == 'T')
				tcount++;
		}
		if(xcount + tcount == 4){
			System.out.println("Case #"+caseNo+": "+"X won");
			return;
		} else if(ocount + tcount == 4){
			System.out.println("Case #"+caseNo+": "+"O won");
			return;
		}
		
		xcount = 0;
	 	ocount = 0;
	 	tcount = 0;
		for(int i = 0; i < 4; i++){
			if(input[3-i].charAt(i) == 'X')
				xcount++;
			if(input[3-i].charAt(i) == 'O')
				ocount++;
			if(input[3-i].charAt(i) == 'T')
				tcount++;
		}
		if(xcount + tcount == 4){
			System.out.println("Case #"+caseNo+": "+"X won");
			return;
		} else if(ocount + tcount == 4){
			System.out.println("Case #"+caseNo+": "+"O won");
			return;
		}
		
		if(containsDot){
			System.out.println("Case #"+caseNo+": "+"Game has not completed");
		} else {
			System.out.println("Case #"+caseNo+": "+"Draw");
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TicTacToeTomek t = new TicTacToeTomek();
		Scanner sc = new Scanner(System.in);
		int totalCase = Integer.parseInt(sc.nextLine());
		for(int i =1; i <= totalCase; i++){
			String[] input = new String[4];
			for(int j = 0; j <4; j++)
				input[j] = sc.nextLine();
			t.solve(i, input);
			sc.nextLine();
		}
	}

}
