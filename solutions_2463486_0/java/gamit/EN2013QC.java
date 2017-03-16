import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class EN2013QC {
	public static void main(String[] args) {
		File inputFile = new File("c:/tmp/C-small-attempt0.in");
		File outputFile = new File("c:/tmp/C-small-attempt0.out");
		FileReader filereader = null;
		BufferedReader br = null;
		FileWriter filewriter = null;
		BufferedWriter bw = null;

		try {
			// 入力
			filereader = new FileReader(inputFile);
			br = new BufferedReader(filereader);

			// 出力
			filewriter = new FileWriter(outputFile);
			bw = new BufferedWriter(filewriter);

			// 事前に15桁までで、条件を満たす全要素を抽出
			long i = 1;
			long square = 1;
			ArrayList<Long> palindromeList = new ArrayList<Long>();

			int index = 0;
			while (square <= 1000000000000000l) {
				// 根が、palindrome であるかチェック
				String rootStr = String.valueOf(i);
				String rootReverseStr = new StringBuffer(rootStr).reverse().toString();
				if(rootStr.equals(rootReverseStr)){
					String squareStr = String.valueOf(square);
					String reverseStr = new StringBuffer(squareStr).reverse().toString();

					if(squareStr.equals(reverseStr)){
						System.out.println(i + " " + square);
						palindromeList.add(index++, square);
					}
				}

				i++;
				square = i * i;
			}

//			// 事前に100桁までで、条件を満たす全要素を抽出
//			// 0～2の組み合わせを全部抽出する
//			ArrayList<Long> palindromeList = new ArrayList<Long>();
//
//			int radix = 2;
//			BigInteger pattern = new BigInteger("0");
//			for(long j=562949953421312l; j<Math.pow(radix, 50); j++){
//				String patternStr = pattern.toString(radix);  // パターンを生み出すためのもの実際の値は利用せず、radix進数表記時の並びを抽出する
//				String patternReverseStr = new StringBuffer(patternStr).reverse().toString();
//
//				if(patternStr.equals(patternReverseStr)){
//					// radix進数表記の「文字列」がpalindrome
//					// よって「文字列」から、BigIntegerを生成する。
//
//					BigInteger num = new BigInteger(patternStr);
//
//					String numSquareStr = num.multiply(num).toString();
//					String numReverseSquareStr = new StringBuffer(numSquareStr).reverse().toString();
//
//					if(numSquareStr.equals(numReverseSquareStr)){
//						System.out.println(j + ", " + patternStr + ", " + numSquareStr);
//					}
//				}
//
//				pattern = pattern.add(new BigInteger("1"));
//			}

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
				String AB[] = lineStr.split(" ");

				long A = Long.parseLong(AB[0]);
				long B = Long.parseLong(AB[1]);
				System.out.println("A=" + A + ", B=" + B);

				int counter = 0;
				for(long n : palindromeList){
					if(A <= n){
						if(n <= B){
							System.out.print(n + " - ");
							counter++;
						} else {
							System.out.println();
							break;
						}
					}
				}


				int caseAnser = counter;

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
