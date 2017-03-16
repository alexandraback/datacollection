import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.StreamTokenizer;


public class MySolution {
	public static void main(String[] a) throws IOException {
		sumfile("C-small-attempt0.in");
	}

	static void sumfile(String filename) throws IOException {
		int tests=0;
		int A=0;
		int B=0;
		int count=0;
		Reader r = new BufferedReader(new FileReader(filename));
		StreamTokenizer stok = new StreamTokenizer(r);
		stok.parseNumbers();
		stok.nextToken();
		if (stok.ttype == StreamTokenizer.TT_NUMBER) {
			tests=(int)stok.nval;
		}
		FileWriter fw = new FileWriter("result.txt");
		fw.write("");
		fw.close();
		for(int i=0;i<tests;i++){
			stok.nextToken();
			if (stok.ttype == StreamTokenizer.TT_NUMBER) {
				A=(int)stok.nval;
			}
			stok.nextToken();
			if (stok.ttype == StreamTokenizer.TT_NUMBER) {
				B=(int)stok.nval;
			}
			for(int ii=A;ii<=B;ii++){
				String tmp = ii+"";
				int size=tmp.length();
				int[] allchange=new int[size-1];
				for(int j=1;j<size;j++){
					String tmp2=tmp.substring(j, tmp.length())+tmp.substring(0, j);
					int change=Integer.parseInt(tmp2);
					allchange[j-1]=change;
					int sign=0;
					for(int k=0;k<j-1;k++){
						if(allchange[k]==change){
							//System.out.println("Bingo"+ii);
							sign=1;
						}
					}
					if(change>ii&&change<=B&&sign!=1){
						count++;
						//System.out.print("("+ii+","+change+") ");
					}
				}
				
				
			}
			
			fw = new FileWriter("result.txt",true);  
			String s ="Case #"+(i+1)+": "+count+"\n";  
			fw.write(s,0,s.length());  
			fw.flush();
			System.out.println("Case #"+(i+1)+": "+count);
			count=0;
		}
	}
}
