import java.io.*;
import java.math.*;
import java.util.*;

public class Sortlist
{
    private static ArrayList<BigInteger> N = new ArrayList<BigInteger>();
    private static int T, i, j, BatasKiri, BatasKanan;
	private BigInteger A, B;
	private int C[] = new int [10001];
	
public void readNumberFile(String fileName) {

  FileReader file = null; 
  try {
    file = new FileReader(fileName);
    BufferedReader reader = new BufferedReader(file);
    String line = "";
    while ((line = reader.readLine()) != null) {
      N.add(new BigInteger(line).multiply(new BigInteger (line)));
    }
  } catch (Exception e) {
      throw new RuntimeException(e);
  } finally {
    if (file != null) {
      try {
        file.close();
      } catch (IOException e) {
        // Ignore issues during closing 
      }
    }
  }

}

public void readTextFile(String fileName) {

  FileReader file = null; 
  try {
    file = new FileReader(fileName);
    BufferedReader reader = new BufferedReader(file);
    String line = "";
	i = 0;
    while ((line = reader.readLine()) != null) {
	  if (i == 0)  T = Integer.parseInt(line);
	  else {
	  /* Read Input */
	  	String[] parts = line.split(" ");
		A = new BigInteger(parts[0].trim());
		B = new BigInteger(parts[1].trim());
	  /* Process */
	   BatasKiri = 0;
	   BatasKanan = 0;

	   for (int j = 0; j < N.size(); j++) {
           if ((N.get(j).compareTo(A) == -1) && (N.get(j+1).compareTo(A) != -1)) {BatasKiri = j+1;
		   break;}

		}
	   for (int j = 0; j < N.size(); j++) {
           if ((N.get(j).compareTo(B) != 1) && (N.get(j+1).compareTo(B) == 1)) {BatasKanan = j;
		   break;}
		}		
		C[i-1] = BatasKanan - BatasKiri + 1;
		//System.out.println(BatasKiri + " " + BatasKanan);
		System.out.println("Case #" + i + ": " + C[i-1]);
	  }
	  i++;
    }
  } catch (Exception e) {
      throw new RuntimeException(e);
  } finally {
    if (file != null) {
      try {
        file.close();
      } catch (IOException e) {
        // Ignore issues during closing 
      }
    }
  }

}

    public static void main(String[] args) 
    {
		Sortlist myFile = new Sortlist();
		myFile.readNumberFile("numberlist.txt");
		Collections.sort(N);
		//read Dataset
		myFile.readTextFile("C-large-1.in");
    }
}