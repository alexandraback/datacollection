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
			int X = Integer.parseInt(nLine.split(" ")[0]);
			int R = Integer.parseInt(nLine.split(" ")[1]);
			int C = Integer.parseInt(nLine.split(" ")[2]);
			if (X>=7){

				fw.write("Case #"+(i+1)+": RICHARD\n");
			}
			else if ((R*C)%X!=0){

				fw.write("Case #"+(i+1)+": RICHARD\n");
			}
			else if (R<X && C<X){

				fw.write("Case #"+(i+1)+": RICHARD\n");
			}
			else if (R<X||C<X){

				int min = Math.min(R, C);
				
				
				if (min<(X+1)/2||(X==4&&min==2&&R*C==8)){

					fw.write("Case #"+(i+1)+": RICHARD\n");
				}
				else if (min>(X+1)/2|| X==2||X==3){

					fw.write("Case #"+(i+1)+": GABRIEL\n");
				}
				else {

					fw.write("Case #"+(i+1)+": TODO\n");
				}
			}
			else {
			fw.write("Case #"+(i+1)+": GABRIEL\n");
			}
			System.out.println(""+i);
		}
		fw.close();
		System.out.println("finished");
	}

}
