package commons;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;

public class FileUtilities {
    
    public static void writeFile(List<String> strings, File file) 
            throws IOException {
        
        file.createNewFile();
        FileWriter writer = new FileWriter(file);
        for (int i = 1; i <= strings.size(); i++) {
            writer.write("Case #");
            writer.write(i + ": ");
            writer.write(strings.get(i-1).replace(',', '.'));
            writer.write("\n");
        }
        
        writer.close();
    }
    
    public static List<String> readFile(File file) throws IOException {
        
        BufferedReader reader = new BufferedReader(new FileReader(file));
        
        String input = reader.readLine();
        List<String> result = new LinkedList<String>();
        
        while (!(input == null)) {
            result.add(input);
            input = reader.readLine();
        }
        
        reader.close();
        
        return result;
    }
}
