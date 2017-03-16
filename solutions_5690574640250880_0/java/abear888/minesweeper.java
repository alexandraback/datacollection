import java.io.*;
import java.util.*;

public class minesweeper {

	public static void main(String[] args) throws IOException {
		BufferedReader x = new BufferedReader(new FileReader("C:/Documents and Settings/alvin/My Documents/alvin/Computer Science/Code Jam/minesweeper.in"));
		PrintWriter out=new PrintWriter(new BufferedWriter(new FileWriter("C:/Documents and Settings/alvin/My Documents/alvin/test.out.txt")));
		int numcases=Integer.parseInt(x.readLine());
		for (int a=1; a<=numcases; a++){
			out.println("Case #"+a+":");
			StringTokenizer st=new StringTokenizer(x.readLine());
			int r=Integer.parseInt(st.nextToken());
			int c=Integer.parseInt(st.nextToken());
			int m=Integer.parseInt(st.nextToken());
			int[][]matrix=new int[r][c];
			matrix[0][0]=2; //assign top left hand to be always clicked
			//click is two, mine is one, empty is zero
			//it always works with no mines
			//works with dimensions of one
			if (m==0){
				for (int i=0; i<r; i++){
					for (int j=0; j<c; j++){
						if (matrix[i][j]==2){
							out.print("c");
						}
						if (matrix[i][j]==1){
							out.print("*");
						}
						if (matrix[i][j]==0){
							out.print(".");
						}
					}
					out.println();
				}
				continue;
			}
			if (r==1){for (int i=0; i<m; i++){matrix[0][c-i-1]=1;}}
			else if (c==1){for (int i=0; i<m; i++){matrix[r-i-1][0]=1;}}
			if (r==2){
				if (m==r*c-1){
					for (int i=0; i<r; i++){
						for (int j=0; j<c; j++){
							matrix[i][j]=1;
						}
					}
					matrix[0][0]=2;
				}
				else if (m%2==1 || m==r*c-2){
					out.println("IMPOSSIBLE");
					continue;
				}
				else{
					for (int i=0; i<m/2; i++){
						matrix[0][c-i-1]=1;
						matrix[1][c-i-1]=1;
					}
				}
			}
			else if (c==2){
				if (m==r*c-1){
					for (int i=0; i<r; i++){
						for (int j=0; j<c; j++){
							matrix[i][j]=1;
						}
					}
					matrix[0][0]=2;
				}
				else if (m%2==1 || m==r*c-2){
					out.println("IMPOSSIBLE");
					continue;
				}
				else{
					for (int i=0; i<m/2; i++){
						matrix[r-i-1][0]=1;
						matrix[r-i-1][1]=1;
					}
				}
			}
			if (r>=3 && c>=3){
				if (r*c-m==2 || r*c-m==3 || r*c-m==5 || r*c-m==7){
					out.println("IMPOSSIBLE");
					continue;
				}
				else{
					int tempm=m;
					int rowcounter=r-1;
					while (tempm>=c && rowcounter>2){
						for (int i=0; i<c; i++){
							matrix[rowcounter][i]=1;
							
						}
						rowcounter--;
						tempm=tempm-c;
					}
					if (rowcounter!=2){//if it didn't reach the top three rows and you're just finishing the row
						if (tempm!=c-1){
							for (int i=0; i<tempm; i++){
								matrix[rowcounter][i]=1;
							}
						}
						else{
							for (int i=0; i<c-2; i++){
								matrix[rowcounter][i]=1;
							}
							matrix[rowcounter-1][0]=1;
						}
					}
					else{
						int columncounter=c-1;
						while (tempm>=3){
							matrix[0][columncounter]=1;
							matrix[1][columncounter]=1;
							matrix[2][columncounter]=1;
							columncounter--;
							tempm=tempm-3;
						}
						if (tempm==1){
							matrix[2][columncounter]=1;
						}
						if (tempm==2){
							if (columncounter!=0){
								matrix[2][columncounter]=1;
								matrix[2][columncounter-1]=1;
							}
							else{
								matrix[2][columncounter]=1;
								matrix[1][columncounter]=1;
							}
						}
					}
				}
			}
			for (int i=0; i<r; i++){
				for (int j=0; j<c; j++){
					if (matrix[i][j]==2){
						out.print("c");
					}
					if (matrix[i][j]==1){
						out.print("*");
					}
					if (matrix[i][j]==0){
						out.print(".");
					}
				}
				out.println();
			}
		}
		out.close();
		System.exit(0);
	}

}
