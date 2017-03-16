import java.io.*;
import java.util.*;
public class QR_A {
    static char[][] board = new char[4][4];
    public static boolean check_board(char X){
	boolean result=false;
	//rowcheck
	for (int i = 0; i < 4; i++) {
	    boolean check = true;
	    for (int j = 0; j < 4; j++) {
		if(board[i][j]!=X&&board[i][j]!='T')
		    check = false;
	    }
	    if(check) return true;
	}
	for (int i = 0; i < 4; i++) {
	    boolean check = true;
	    for (int j = 0; j < 4; j++) {
		if(board[j][i]!=X&&board[j][i]!='T')
		    check = false;
	    }
	    if(check) return true;
	}

	boolean check = true;
	for (int j = 0; j < 4; j++) {
	    if(board[j][j]!=X&&board[j][j]!='T')
		    check = false;
	}
	if(check) return true;
	check = true;
	for (int j = 0; j < 4; j++) {
	    if(board[3-j][j]!=X&&board[3-j][j]!='T')
		    check = false;
	}
	if(check) return true;

	return false;
    }
	public static void main (String [] args) throws IOException {
	    // Use BufferedReader rather than RandomAccessFile; it's much faster
	    BufferedReader f = new BufferedReader(new FileReader("A-large.in"));
	    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("a.out")));
	    StringTokenizer st = new StringTokenizer(f.readLine());
	    
	    int testn = Integer.parseInt(st.nextToken());    
	    int caseno=1;
	    while(testn-->0) {
		String result="";
	    	boolean board_fool=true;
	    	for (int i = 0; i < 4; i++) {
	    	    String row = f.readLine();
	    	    for (int j = 0; j < 4; j++) {
			board[i][j] = row.charAt(j);
			if(board[i][j]=='.')	
			    board_fool = false;
		    }
		}
	    	    if(check_board('X')) result = "X won";
	    	else
	    	    if(check_board('O')) result = "O won";
	    	else
	    	    if(board_fool) result = "Draw";
	    	else
	    	    result ="Game has not completed";
	    	System.out.println(result);
	    
	    out.println("Case #"+caseno+++": "+result);
	    f.readLine();
	    }                           
	    
	    out.close();                                  
	    System.exit(0);                              
	  }
}