import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.TreeSet;

public class EN2013QB {
	public static void main(String[] args) {
		File inputFile = new File("c:/tmp/B-small-attempt1.in");
		File outputFile = new File("c:/tmp/B-small-attempt1.out");
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
				lineStr = br.readLine();
				String NM[] = lineStr.split(" ");

				int N = Integer.parseInt(NM[0]);
				int M = Integer.parseInt(NM[1]);
				System.out.println("N=" + N + ", M=" + M);

				// 登場する数字（=高さ）を保持する
				TreeSet<Integer> numSet = new TreeSet<Integer>();

				// 最終形を保持するマップ（問題のInputと同じ）
				int nm[][] = new int[N][M];

				for(int n=0; n<N; n++){
					lineStr = br.readLine();
					String mList[] = lineStr.split(" ");

					for(int m=0; m<M; m++){
						nm[n][m] = Integer.parseInt(mList[m]);
						numSet.add(nm[n][m]);
					}
				}

				// 登場する数字（=高さ）を保持する配列に変更
				int numList[] = new int[numSet.size()];
				System.out.print("num : ");
				int index = 0;
				for (int i : numSet) {
					System.out.print(i + " ");
					numList[index++] = i;
				}
				System.out.println();


				// 答え
				// 各squareは、縦と横から刈ることができる。
				// 満たさないといけない条件
				// 1.全体に含まれる値のリスト（numList）から、小さい順に値を決定する
				//   値を i とする
				// 2.全体を操作し、その値iに一致するマス（square）を特定する
				//   ※ 必ず1つは見つかるはず
				// 3.以下のいずれかを満たしているかチェックする
				//   選択されているsquareを含む横のラインは、全て選択値以下
				//   選択されているsquareを含む縦のラインは、全て選択値以下
				//   → 満たさないものが1つでもあれば、「不可能」と判定
				// 4.値がiのマス（square）を全て、numListで次に大きな値に置き換える
				//   1に戻る
				//   numListで一番大きな値の場合は、全ての値でチェックが完了したので、
				//   「可能」と判定

				// 全体に含まれる値のリスト（numList）でループ
				boolean impossibleFlag = false;

				// 現在の高さ（=i）でチェック対象とするマップ（最終形から時間を遡っていく）
				int[][] map = nm;
				for (index = 0 ; index < numList.length-1; index++) {  // 配列の最後はチェック不要であるため（-1）
//					// 表示
//					for(int n=0; n<N; n++){
//						for(int m=0; m<M; m++){
//							System.out.print(map[n][m] + " ");
//						}
//						System.out.println();
//					}

					int i = numList[index];

					// 刈り込みの1歩手前の状態を再現するためのマップ
					int passedMap[][] = new int[N][M];

					int nextValue = numList[index+1];
//					System.out.println("i=" + i + ", next=" + nextValue);

					for(int n=0; n<N; n++){
						boolean lineChacked = false;  // 横の判定結果がOKの場合その行の判定はもう行う必要はないためフラグで管理する
						for(int m=0; m<M; m++){
							if(map[n][m] == i){
//								System.out.print("n=" + n + ", m=" +m);

								// passedMap[n][m]を更新
								passedMap[n][m] = nextValue;

								if(!lineChacked){
									// 横判定
									boolean lineFlag = true;
									for(int k=0; k < M; k++){
										if(map[n][k] != i) {
											lineFlag = false;
//											System.out.print(" line:NG");

											// 横の判定がNGだった場合のみ縦をチェックする
											for(int l=0; l < N; l++){
												if(map[l][m] != i) {
													impossibleFlag = true;
//													System.out.print(" row:NG");
													break;
												}
											}
											break;
										}
									}

									if(lineFlag){
//										System.out.print(" line:OK");
										lineChacked = true;
									}
								}
							} else {
								// passedMap[n][m]を更新
								passedMap[n][m] = map[n][m];
							}
//							System.out.println();
						}
					}

					// 不可能な場合は次の高さのチェックは行わない
					if(impossibleFlag){
						break;
					}

					// 次のチェック対象のマップを刈り込みの1歩手前の状態に置き換える
					map = passedMap;
				}

				String caseAnser = "YES";
				if(impossibleFlag){
					caseAnser = "NO";
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
