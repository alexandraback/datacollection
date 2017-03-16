import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;


public class Pogo {

  public static void main(String[] args) throws IOException {
     BufferedReader br = new BufferedReader(new FileReader(new File("B-small-attempt0.in")));
//     BufferedReader br = new BufferedReader(new FileReader(new File("test.txt")));
//    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    String line = br.readLine();
    int t = Integer.parseInt(line);
    for (int i = 0; i < t; i++) {
      line = br.readLine();
      String[] arr = line.split(" ");
      StringBuilder res = new StringBuilder();

      int x = Integer.parseInt(arr[0]);
      int y = Integer.parseInt(arr[1]);

      boolean xPositive = x>0;
      boolean yPositive = y>0;

      if(!xPositive) x=-x;
      if(!yPositive) y=-y;

      for (int j = 0; j < x; j++) {
        if(xPositive){
          res.append("WE");
        }else{
          res.append("EW");
        }
      }

      for (int j = 0; j < y; j++) {
        if(yPositive){
          res.append("SN");
        }else{
          res.append("NS");
        }
      }

      System.out.println("Case #" + (i+1) + ": " + res);
    }

  }




}
