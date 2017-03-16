import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class EN2013QA {
	public static void main(String[] args) {
		File inputFile = new File("c:/tmp/A-large.in");
		File outputFile = new File("c:/tmp/A-large.out");
		FileReader filereader = null;
		BufferedReader br = null;
		FileWriter filewriter = null;
		BufferedWriter bw = null;

		int board1[][] = new int[4][4]; // TをXとした場合（Xを1, Oを-1とする）
		int board2[][] = new int[4][4]; // TをOとした場合（Xを1, Oを-1とする）

		try {
			// 入力
			filereader = new FileReader(inputFile);
			br = new BufferedReader(filereader);

			// 出力
			filewriter = new FileWriter(outputFile);
			bw = new BufferedWriter(filewriter);

			/**************************************************************************************
			// 全体パラメータの読み込み
			 **************************************************************************************/
			int T;

			// テストケースの個数
			String lineStr = br.readLine();
			T = Integer.parseInt(lineStr);
			System.out.println("T = " + T + "\n");

			/**************************************************************************************
			// Caseを1つづつ処理
			 **************************************************************************************/
			long caseIndex = 1;
			for(int t=0; t < T; t++) {
				int turn = 0; // 何手終えているか

				for(int j=0; j < 4; j++) {
				/**************************************************************************************
				// Caseを処理
				 **************************************************************************************/
					lineStr = br.readLine();

					char[] charArray = lineStr.toCharArray();

					for(int i=0; i<charArray.length; i++){
						switch (charArray[i]) {
						case 'X':
							board1[j][i]=1;
							board2[j][i]=1;
							turn++;
							break;

						case 'O':
							board1[j][i]=-1;
							board2[j][i]=-1;
							turn++;
							break;

						case 'T':
							board1[j][i]=1;
							board2[j][i]=-1;
							turn++;
							break;

						default:
							board1[j][i]=0;
							board2[j][i]=0;
							break;
						}

						System.out.println(charArray[i] + ", " + board1[j][i] + ", " + board2[j][i] + ", turn=" + turn);
					}
				}

				// 答え
				String caseAnser = null;

				// 横をチェック
				for(int j=0; j<4; j++){
					// TがX扱いの場合
					int sum1 = board1[j][0] + board1[j][1] + board1[j][2] + board1[j][3];
					// TがO扱いの場合
					int sum2 = board2[j][0] + board2[j][1] + board2[j][2] + board2[j][3];

					if(sum1 == 4 || sum2 == 4){
						caseAnser = "X won";
						break;
					} else if (sum1 == -4 || sum2 == -4){
						caseAnser = "O won";
						break;
					}
				}

				if(caseAnser == null){
					// 縦をチェック
					for(int i=0; i<4; i++){
						// TがX扱いの場合
						int sum1 = board1[0][i] + board1[1][i] + board1[2][i] + board1[3][i];
						// TがO扱いの場合
						int sum2 = board2[0][i] + board2[1][i] + board2[2][i] + board2[3][i];

						if(sum1 == 4 || sum2 == 4){
							caseAnser = "X won";
							break;
						} else if (sum1 == -4 || sum2 == -4){
							caseAnser = "O won";
							break;
						}
					}
				}

				if(caseAnser == null){
					// 左斜め上から右斜め下への並びをチェック
					// TがX扱いの場合
					int sum1 = board1[0][0] + board1[1][1] + board1[2][2] + board1[3][3];
					// TがO扱いの場合
					int sum2 = board2[0][0] + board2[1][1] + board2[2][2] + board2[3][3];

					if(sum1 == 4 || sum2 == 4){
						caseAnser = "X won";
					} else if (sum1 == -4 || sum2 == -4){
						caseAnser = "O won";
					}
				}

				if(caseAnser == null){
					// 右斜め上から左斜め下への並びをチェック
					// TがX扱いの場合
					int sum1 = board1[0][3] + board1[1][2] + board1[2][1] + board1[3][0];
					// TがO扱いの場合
					int sum2 = board2[0][3] + board2[1][2] + board2[2][1] + board2[3][0];

					if(sum1 == 4 || sum2 == 4){
						caseAnser = "X won";
					} else if (sum1 == -4 || sum2 == -4){
						caseAnser = "O won";
					}
				}

				if(caseAnser == null){
					// 引き分けか、対戦中であることをチェック
					if(turn == 16){
						caseAnser = "Draw";
					} else {
						caseAnser = "Game has not completed";
					}
				}

				/**************************************************************************************
				// Caseを出力
				 **************************************************************************************/
				String output = "Case #" + caseIndex + ": " + caseAnser;
				caseIndex++;
				System.out.println(output);
				bw.write(output);
				bw.newLine();
				bw.flush();

				/**************************************************************************************
				// 次のCaseの読み込み
				 **************************************************************************************/
				lineStr = br.readLine();
				System.out.println();
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null) {
					br.close();
				}
			} catch (IOException e) {
				e.printStackTrace();
			}

			try {
				if (filereader != null) {
					filereader.close();
				}
			} catch (IOException e) {
				e.printStackTrace();
			}

			try {
				if (bw != null) {
					bw.close();
				}
			} catch (IOException e) {
				e.printStackTrace();
			}

			try {
				if (filewriter != null) {
					filewriter.close();
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
