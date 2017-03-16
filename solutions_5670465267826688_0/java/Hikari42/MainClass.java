import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;


public class MainClass {

	public static void main(String[] args) throws IOException, InterruptedException {
		BufferedReader fr = new BufferedReader(new FileReader(new File("input.txt")));
		FileWriter fw = new FileWriter(new File("result.txt"));
		String firstLine = fr.readLine();
		int nbCases = Integer.parseInt(firstLine);

		for (int i =0; i<nbCases; i++){

			String nLine = fr.readLine();
			int nLetter = Integer.parseInt(nLine.split(" ")[0]);

			int nRepet = Integer.parseInt(nLine.split(" ")[1]);
			nLine = fr.readLine();
			StringBuilder sb = new StringBuilder();
			for (int j = 0; j<nRepet; j++){
			sb.append(nLine);
				
			}
			nLine = sb.toString();
			nLetter = nRepet*nLetter;
			
			int cursor =0;
			int current = 1;
			while (current !=2 && cursor<nLetter){
				current = mulQuat(current, toQuat(nLine,cursor));
				cursor++;
			}
			if (cursor==nLetter){

				fw.write("Case #"+(i+1)+": NO\n");
				continue;
			}
			current = 1;
			while (current !=3 && cursor<nLetter){
				current = mulQuat(current, toQuat(nLine,cursor));
				cursor++;
			}
			if (cursor==nLetter){

				fw.write("Case #"+(i+1)+": NO\n");
				continue;
			}
			current = 1;
			while ( cursor<nLetter){
				current = mulQuat(current, toQuat(nLine,cursor));
				cursor++;
			}
			if (current!=4){

				fw.write("Case #"+(i+1)+": NO\n");
				continue;
			}

			fw.write("Case #"+(i+1)+": YES\n");
			System.out.println(""+i);
		}
		fw.close();
		System.out.println("finished");
	}

	private static int toQuat(String nLine, int cursor) {
		if (nLine.charAt(cursor)=='i'){
			return 2;
		}
		if (nLine.charAt(cursor)=='j'){
			return 3;
		}
		if (nLine.charAt(cursor)=='k'){
			return 4;
		}
		return 0;
	}

	private static int mulQuat(int q1, int q2){
		boolean signe = (q1<0)^(q2<0);
		int res =0;
		q1=Math.abs(q1);
		q2=Math.abs(q2);
		if (q1==1){
			res = q2;
			
		}
		if (q1==2){
			if(q2==1){
				res = 2; 
			};

			if(q2==2){
				res = -1; 
			};

			if(q2==3){
				res = 4; 
			};
			if(q2==4){
				res = -3; 
			};
		}
		if (q1==3){
			if(q2==1){
				res = 3; 
			};

			if(q2==2){
				res = -4; 
			};

			if(q2==3){
				res = -1; 
			};
			if(q2==4){
				res = 2; 
			};
		}
		
		if (q1==4){
			if(q2==1){
				res = 4; 
			};

			if(q2==2){
				res = 3; 
			};

			if(q2==3){
				res = -2; 
			};
			if(q2==4){
				res = -1; 
			};
		}
		if (signe){
		res=-res;	
		}
		if (res==0|| Math.abs(res)>4){
			System.out.println("q1 = "+q1+" q2 = "+q2+" res = "+res);
		}
		return res;
	}
}
