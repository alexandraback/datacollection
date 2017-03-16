import java.io.File;
import java.io.FileReader;
import java.io.IOException;


public class FileIn {

	private StringBuilder sb = new StringBuilder("");
	
	/**
	 * コンストラクタ.
	 * @param filename 読み込むファイル名
	 */

	public FileIn(String filename) {
		File f = new File(filename);
		FileReader fr = null;
		try {
			fr = new FileReader(f);
			int c;
			while ((c = fr.read()) != -1) {
				this.sb.append((char)c);
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				fr.close();
			} catch (IOException e) {
				e.printStackTrace();
			}

		}

	}
	
	/**
	 * ファイルの文字列を返す.
	 * @return
	 */
	public String getString() {
		return this.sb.toString();
	}
}