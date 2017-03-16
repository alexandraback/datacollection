import java.io.File;
import java.io.FileWriter;
import java.io.IOException;



public class FileOut {

	/**
	 * コンストラクタ.
	 * @param filename 書き出すファイル名
	 * @param s 書き出す文字列
	 */
	public FileOut(String filename, String s) {
		File f = new File(filename);
		FileWriter fw = null;
		try {
			fw = new FileWriter(f);
			fw.write(s);

		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				fw.close();
			} catch (IOException e) {
				e.printStackTrace();
			}

		}

	}


}