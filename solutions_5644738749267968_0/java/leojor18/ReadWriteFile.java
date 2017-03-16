package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ReadWriteFile {
	
	private String directorio = "/home/miguel/casa/casa/archivos/";
//	private String directorio = "/home/jorge/git/casa/archivos/";
	
	private BufferedReader reader;
	private BufferedWriter writer;
	private String outFileName;
	private String inFileName;
	private Scanner scanner;
	
	public void setFileReaderName(String fileName) throws FileNotFoundException {
		inFileName = directorio+fileName;
		scanner = new Scanner(new File(inFileName));
		FileReader fileReader = new FileReader(directorio+fileName);
		reader = new BufferedReader(fileReader);
	}

	public void setFileWriterName(String fileName) throws IOException {
		outFileName = directorio+fileName;
		FileWriter fileWriter = new FileWriter(outFileName);
		writer = new BufferedWriter(fileWriter);
	}
	
	public String readLine() throws IOException {
		return reader.readLine();
	}

	public String[] readLineSeparateBy(String separator) throws IOException {
		return reader.readLine().split(separator);
	}

	public void closeReader() throws IOException {
		if(reader != null ){
			reader.close();
		}
	}

	public void append(String primeraLinea) throws IOException {
		writer.append(primeraLinea);
	}
	public void newLine() throws IOException {
		writer.newLine();
	}

	public void closeWriter() throws IOException {
		writer.close();
	}
	
	public File outFile(){
		return new File(outFileName);
	}
	public File inFile(){
		return new File(inFileName);
	}

	public void closeFiles() throws IOException{
		closeReader();
		closeWriter();
	}

	public Scanner getScanner() {
		return scanner;
	}

}
