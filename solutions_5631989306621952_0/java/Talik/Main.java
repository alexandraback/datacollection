import java.io.*;
import java.nio.file.Path;
import java.nio.file.Paths;

/**
 * Created by talik on 16.04.16.
 */
public class Main {


    public static String changeOrder(String name){
        StringBuffer buff = new StringBuffer(String.valueOf(name.charAt(0)));
        for (int i = 1; i <name.length() ; i++) {
            if(name.charAt(i)<buff.charAt(0))
                buff.append(name.charAt(i));
            else
                buff = new StringBuffer(name.charAt(i)+buff.toString());

        }
        return buff.toString();
    }

    public static void main(String[] args) {
        String line;
        try {
            BufferedReader reader = new BufferedReader(new FileReader(new File("/home/talik/Dokumenty/1Round/A-small-attempt0.in")));
            Path path = Paths.get("/home/talik/Dokumenty/1Round/output.txt");
            // Path file = Files.createFile(path);
            PrintWriter writer = new PrintWriter(path.toString());
            int numberOfLines = Integer.parseInt(reader.readLine());
            for(int i=1;i<=numberOfLines;i++){
                line = reader.readLine();

                writer.println("Case #"+i+": "+changeOrder(line));

            }
            writer.flush();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException io){
            io.printStackTrace();
        }


    }

}
