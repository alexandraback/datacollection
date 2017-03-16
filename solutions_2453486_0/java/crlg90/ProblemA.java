import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;


public class ProblemA {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{
		String fileName = "A-small-attempt0";
		BufferedReader br = new BufferedReader(new FileReader(fileName + ".in"));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(fileName + ".out"));
		int t = Integer.valueOf(br.readLine());
		for (int i=1; i<=t; i++){
			String board[] = new String[4];
			for (int j=0; j<4; j++){
				board[j]= br.readLine();
			}
			boolean xwon, owon, finished;
			xwon = owon = false;
			finished = true;
			int contx, conto;
			contx = conto = 0;
			//horizontal x
			for (int j=0; j<4; j++){
				for (int k=0; k<4; k++){
					if (board[j].charAt(k) == 'X' || board[j].charAt(k) == 'T'){
						contx ++;
					}else{
						break;
					}
				}
				if (contx == 4){
					xwon = true;
					contx = 0;
					break;
				}
				contx = 0;
			}
			//horizontal o
			for (int j=0; j<4; j++){
				for (int k=0; k<4; k++){
					if (board[j].charAt(k) == 'O' || board[j].charAt(k) == 'T'){
						conto ++;
					}else{
						break;
					}
				}
				if (conto == 4){
					owon = true;
					break;
				}
				conto = 0;
			}
			//vertical x
			for (int j=0; j<4; j++){
				for (int k=0; k<4; k++){
					if (board[k].charAt(j) == 'X' || board[k].charAt(j) == 'T'){
						contx ++;
					}else{
						break;
					}
				}
				if (contx == 4){
					xwon = true;
					break;
				}
				contx = 0;
			}
			//vertical o
			for (int j=0; j<4; j++){
				for (int k=0; k<4; k++){
					if (board[k].charAt(j) == 'O' || board[k].charAt(j) == 'T'){
						conto ++;
					}else{
						break;
					}
				}
				if (conto == 4){
					owon = true;
					break;
				}
				conto = 0;
			}
			//diagonal derecha x 
			for (int j=0; j<4; j++){
				if (board[j].charAt(j) == 'X' || board[j].charAt(j) == 'T'){
					contx ++;
				}else{
					break;
				}
			}
			if (contx == 4){
				xwon = true;
			}
			contx = 0;
			//diagonal izquierda x 
			for (int j=0; j<4; j++){
				if (board[j].charAt(3-j) == 'X' || board[j].charAt(3-j) == 'T'){
					contx ++;
				}else{
					break;
				}
			}
			if (contx == 4){
				xwon = true;
			}
			contx = 0;
			//diagonal derecha o 
			for (int j=0; j<4; j++){
				if (board[j].charAt(j) == 'O' || board[j].charAt(j) == 'T'){
					conto ++;
				}else{
					break;
				}
			}
			if (conto == 4){
				owon = true;
			}
			conto = 0;
			//diagonal izquierda o 
			for (int j=0; j<4; j++){
				if (board[j].charAt(3-j) == 'O' || board[j].charAt(3-j) == 'T'){
					conto ++;
				}else{
					break;
				}
			}
			if (conto == 4){
				owon = true;
			}
			conto = 0;
			// empate o enjuego
			if (!xwon && !owon){
				for (int j=0; j<4; j++){
					for (int k=0; k<4; k++){
						if (board[j].charAt(k) == '.'){
							finished = false;
							break;
						}
					}
				}
			}
			String resp;
			if (xwon){
				resp = "X won";
						
			}else if (owon){
				resp = "O won";
			}else if (finished){
				resp = "Draw";
			}else{
				resp = "Game has not completed";
			}
			bw.write("Case #"+i+": "+resp+'\n');
			br.readLine();
		}
		br.close();
		bw.close();
	}

}
