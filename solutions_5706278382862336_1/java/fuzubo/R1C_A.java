import java.io.*;

public class R1C_A {

	public static void main(String[] args) {
		try{
			//引数の数が２なら計算実行
			if(args.length == 2){
				exec(args[0],args[1],1,1);
			}else{
				System.out.println("usage : java CodeJam2011P_A [input filename] [output filename]");
			}
		}catch(Exception ex){
			ex.printStackTrace();
		}
	}

	public final static void exec(String inFileName , String outFileName,int inDataPackRows , int loggingCycle) throws Exception{
		//入力ファイルのリーダー
		BufferedReader	inReader	= new BufferedReader(new FileReader(inFileName));
		//出力ファイルのライター
		PrintWriter		outWriter	= new PrintWriter(new BufferedWriter(new FileWriter(outFileName)));

		//ローカル変数の定義
		String lineStr="",packStr="";
		int packRowCount=0,caseCount=0,caseNums=0;
		boolean isFirst=true;
		String outStr = null;
		int n = 0;
		boolean win = false;

		String[] stringArray = null;
	//ｓ	String[] stringArray2 = new String[4];

		//入力ファイルを１行読み込む（最後まで行くと抜ける）
		while((lineStr = inReader.readLine()) != null){

			if(isFirst){
				//最初の行はケース数
				caseNums = Integer.parseInt(lineStr);
				isFirst=false;
				win = false;
			}else{
				
				/*
				
				//2行目以降
				if ( packRowCount == 0 ){
					n = Integer.parseInt(lineStr);
					stringArray = new String[n];
				} else if ( packRowCount < n+1 ){
					stringArray[packRowCount - 1] = lineStr;
					//System.out.println(stringArray[packRowCount - 1]);
				}
				//読み込んだテキストをバッファに追加
				//packStr += lineStr +" ";
				packRowCount++;

				*/

				//読み込んだ行数が１ケース分の行数に達すると計算を実行
				if( packRowCount == 0 ){
					
					int sep = lineStr.indexOf("/");
					long a = Long.parseLong(lineStr.substring(0,sep));
					long b = Long.parseLong(lineStr.substring(sep + 1));
					
					int first = born(0, 0, a, b);
					//System.out.println(first);
									
					//繰越処理
					packStr="";
					packRowCount=0;
					caseCount++;
					
					String fmtOutStr;
					if (first == -1) {
						fmtOutStr="Case #" + String.valueOf(caseCount) + ": impossible";
					} else {
						fmtOutStr="Case #" + String.valueOf(caseCount) + ": " + first;
					}
					//ファイルに書き込む
					outWriter.println(fmtOutStr);
					
					//途中経過を表示
					if(caseCount % loggingCycle == 0){
						System.out.println(fmtOutStr);
					}
				}
			}
		}
		
		outWriter.close();
		inReader.close();
		
		System.out.println("cases " + String.valueOf(caseCount) + " / " + String.valueOf(caseNums));
		if( caseCount != caseNums){
			System.out.println("cases unmatched");
		}
	}
	
	public static int born (int count, int first, long a, long b) {
		//System.out.println(a + "      " + b);
		count++;
		a = a * 2;
		if (a == b) {
			if (first == 0) {
				first = count;
			}
			return first;
		} else if (a >= b) {
			a = a - b;
			if (first == 0) {
				first = count;
			}
		}
		if (count > 40) {
			return -1;
		}
		return born(count, first, a, b);
	}

}
