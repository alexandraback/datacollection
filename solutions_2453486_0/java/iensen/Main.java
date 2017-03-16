import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task solver = new Task();
		solver.solve(1, in, out);
		out.close();
	}
}

class Task {
    boolean checkWin(String[]board,char C) {
        //check rows
        char oppositeChar=(C=='O'?'X':'O');
        for(int i=0;i<board.length;i++) {
            boolean won=true;
            for(int j=0;j<board[i].length();j++) {
               if(board[i].charAt(j)==oppositeChar || board[i].charAt(j)=='.') {
                   won=false;
               }
            }
            if(won)
                return true;
        }
        //check columns
        for(int i=0;i<board.length;i++) {
            boolean won=true;
            for(int j=0;j<board[i].length();j++) {
                if(board[j].charAt(i)==oppositeChar || board[j].charAt(i)=='.') {
                    won=false;
                }
            }
            if(won)
                return true;
        }

        //check diagonals:
       boolean won=true;
        for(int i=0;i<board.length;i++) {
            if(board[i].charAt(i)==oppositeChar || board[i].charAt(i)=='.') {
              won=false;
            }
        }
        if(won)
            return true;

       won=true;
        for(int i=0;i<board.length;i++) {
            if(board[i].charAt(3-i)==oppositeChar || board[i].charAt(3-i)=='.') {
                won=false;
            }
        }
        return won;


    }

    boolean isComplete(String[]board) {
        for(int i=0;i<board.length;i++ ){
            for(int j=0;j<board[i].length();j++) {
                if(board[i].charAt(j)=='.')
                    return false;
            }
        }
        return true;
    }

	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int t=in.nextInt();
        for(int i=0;i<t;i++) {
            String []board=new String[4];
            for(int j=0;j<4;j++) {
               board[j]=in.nextLine();
            }
            if(checkWin(board,'O')) {
                out.println("Case #"+(i+1)+": O won");
            }
            else if(checkWin(board,'X')) {
                out.println("Case #"+(i+1)+": X won");
            }
            else if(!isComplete(board)) {
                out.println("Case #"+(i+1)+": Game has not completed");
            }
            else  out.println("Case #"+(i+1)+": Draw");
            in.nextLine();
        }
	}
}

class InputReader {
    StringTokenizer st;
    BufferedReader in;
    public InputReader(InputStream ins)
    {
        in = new BufferedReader(new InputStreamReader(ins));
    }

    public String nextToken()
    {
        while(st==null || !st.hasMoreTokens())
        {
            try {
                st=new StringTokenizer(in.readLine());
            } catch (IOException e) {
                e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
            }
        }
        return st.nextToken();
    }
    public int nextInt()
    {

        return Integer.parseInt(nextToken());
    }

    public String nextLine()  {
        try {
            return in.readLine();
        } catch (IOException e) {
           // e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
            return null;
        }

    }

}

