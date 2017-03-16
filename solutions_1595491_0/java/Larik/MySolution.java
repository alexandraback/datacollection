import java.io.*;

public class MySolution {
	public MySolution() {

	}

	public static void main(String[] a) throws IOException {
		sumfile("B-small-attempt0.in");
	}

	static void sumfile(String filename) throws IOException {
		int tests=0;
		int N=0;
		int S=0;
		int p=0;
		int ti=0;
		int count=0;
		Reader r = new BufferedReader(new FileReader(filename));
		StreamTokenizer stok = new StreamTokenizer(r);
		stok.parseNumbers();
		stok.nextToken();
		if (stok.ttype == StreamTokenizer.TT_NUMBER) {
			tests=(int)stok.nval;
		}
		for(int i=0;i<tests;i++){
			stok.nextToken();
			if (stok.ttype == StreamTokenizer.TT_NUMBER) {
				N=(int)stok.nval;
			}
			stok.nextToken();
			if (stok.ttype == StreamTokenizer.TT_NUMBER) {
				S=(int)stok.nval;
			}
			stok.nextToken();
			if (stok.ttype == StreamTokenizer.TT_NUMBER) {
				p=(int)stok.nval;
			}
			for(int j=0;j<N;j++){
				stok.nextToken();
				ti=(int)stok.nval;
				if(ti>=p*3-2){
					count++;
				}
				else if(ti>=p*3-4&&S>0&&p*3-4>=0){
					count++;
					S--;
				}
			}
			System.out.println("Case #"+(i+1)+": "+count);
			count=0;
		}
	}
}
