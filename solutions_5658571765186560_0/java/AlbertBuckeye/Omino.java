package Qualification;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class Omino {
	public static void main(String[] args) throws NumberFormatException, IOException {
		File inFile = new File("input.txt");
		File outFile = new File("output.txt");
		BufferedReader reader = new BufferedReader(new FileReader(inFile));
		PrintWriter pw = new PrintWriter(outFile);
		int numTest = Integer.parseInt(reader.readLine().trim());
		for(int i=1; i<=numTest; i++){
			String strSplit[] = reader.readLine().split(" ");
			pw.println("Case #"+i+": "+getResult(Integer.parseInt(strSplit[0]), Integer.parseInt(strSplit[1]), Integer.parseInt(strSplit[2])));
			System.out.println(Integer.parseInt(strSplit[0]) +" "+Integer.parseInt(strSplit[1])+" "+Integer.parseInt(strSplit[2]) +" ===> ");
			System.out.println("Case #"+i+": "+getResult(Integer.parseInt(strSplit[0]), Integer.parseInt(strSplit[1]), Integer.parseInt(strSplit[2])));
		}
		pw.flush();
		pw.close();
		reader.close();
	}
	public static String getResult(int omino, int length, int width){
		if(length*width % omino != 0)
			return "RICHARD";//you cannot fill...
		if(omino == 1 || omino == 2)
			return "GABRIEL";
		if(omino == 3){
			if(Math.min(length, width)>=2)
				return "GABRIEL";
			else return "RICHARD";
		}
		if(omino == 4){
			if(length*width >=12)
				return "GABRIEL";
			else
				return "RICHARD";
		}
		return "RICHARD";
	}
}
