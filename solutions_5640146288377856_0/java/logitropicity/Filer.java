package competition;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class Filer {
	private String folder;
	
	public Filer(String folderName){
		folder = folderName;
	}
	
	public BufferedReader reader(String fileName) throws IOException{
		Path p = getPath(fileName);
		BufferedReader reader =
				Files.newBufferedReader(p);
		return reader;
	}
	
	public BufferedWriter writer(String fileName) throws IOException{
		Path p = create(fileName);
		BufferedWriter writer = Files.newBufferedWriter(p);
		return writer;
	}
	
	private Path getPath(String fileName){
		return Paths.get(folder+fileName);
	}
	
	private Path create(String fileName) throws IOException{
		String name = folder+fileName+".txt";
		Path path = Paths.get(name);
		int n = 0;
		while(Files.exists(path)){
			n++;
			name = folder+fileName
					+"("+n+").txt";
			path = Paths.get(name);
		}
		return Files.createFile(path);
	}
}
