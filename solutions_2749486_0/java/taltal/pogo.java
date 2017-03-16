import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;


public class pogo {
	static String _way;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{
			FileInputStream fin=new FileInputStream(new File(args[0]));
			FileWriter fo=new FileWriter(new File("results.out"));
			BufferedReader reader=new BufferedReader(new InputStreamReader(new DataInputStream(fin)));
			BufferedWriter writer=new BufferedWriter(fo);
			int testsNum=Integer.parseInt(reader.readLine());
			for (int i=1;i<=testsNum;i++){
				_way="";
				
				String[] coordinate=reader.readLine().split(" ");
				int X=Integer.parseInt(coordinate[0]);
				int Y=Integer.parseInt(coordinate[1]);
				calc(X,Y);
				writeOutput(writer,i);
			}
			writer.close();
			fin.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}
	
	private  static void calc(int x, int y){
		for (int i=1;i<500;i++){
			if (isPossible(x, y, i)){
				break;
			}
			else{
				_way="";
			}
		}
	}
	
	private static boolean isPossible(int x, int y, int steps){
		if (x==0 && y==0 && steps==0){
			return true;
		}
		if (steps==0){
			return false;
		}
		if (count(steps)<Math.abs(x)||count(steps)<Math.abs(y)){
			return false;
		}
		if (isPossible(x+steps, y, steps-1)){
			_way=_way+ 'W';
			return true;
		}
		else if (isPossible(x-steps, y, steps-1)){
			_way=_way+ 'E';
			return true;
		}
		else if (isPossible(x, y+steps, steps-1)){
			_way=_way+ 'S';
			return true;
		}
		else if (isPossible(x, y-steps, steps-1)){
			_way=_way+ 'N';
			return true;
		}
		else {
			return false;
		}
		
	}
	
	private static int count(int n){
		int sum=0;
		for (int i=1;i<=n;i++){
			sum+=i;
		}
		return sum;
	}
	private static void writeOutput(BufferedWriter writer,int tc) throws IOException{
		writer.write("Case #"+tc+": "+_way);
	//	System.out.println(_way+"\n");
		writer.write("\n");
	}
}
