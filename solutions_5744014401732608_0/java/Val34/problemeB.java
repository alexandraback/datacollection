package mypackage;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class problemeB {
  private static InputReader in;
  private static PrintWriter out;
  public static boolean SUBMIT = true;
  public static final String CHEMIN = "C:\\Users\\dev\\workspace\\GoogleJamDream\\src\\";
  public static final String NAME = "B-small-attempt0";

  private static void main2() throws IOException {
   //Char
   /* char[] s = in.next().toCharArray();
    int n = s.length; */
	//Integer
	int b = in.nextInt();
	char[] s = in.next().toCharArray();
	String ss = new String(s);
	BigInteger m = new BigInteger(ss);
	//int m = in.nextInt();
	int[][] matrix = new int [b][b];
	int i =0,j=0;
	BigInteger nbrChemin = new BigInteger("0");
	BigInteger sDeb = BigInteger.valueOf(somme(b-1)-1);
	if (sDeb.compareTo(m)==-1) {
		out.println("IMPOSSIBLE");
	} else {
		out.println("POSSIBLE");
		int compteurB = 1;
		int compteurC = 1;
		matrix[0][b-1]=1;
		boolean reverse = false;
		nbrChemin = nbrChemin.add(new BigInteger("1"));
		while (nbrChemin.compareTo(m)!=0) {
		if(!reverse) {
				compteurB++;
				if(compteurB== b) {
					compteurC++;
					compteurB=2;
				}
				if(compteurB !=compteurC && compteurC!=b) {
			matrix[0][b-compteurB]=1;
			matrix[b-compteurB][b-compteurC]=1;
			nbrChemin = nbrChemin.add(new BigInteger("1"));
			//System.out.println(nbrChemin);
				}
			} 
		}
		
		for(i=0;i<b;i++) {
			for(j=0;j<b;j++) {
			out.print(matrix[i][j]);
			}
			out.println();
		}
	}

	
	//Possibilité out.print(ans.get(i));
	//avec ArrayList<Long> ans = new ArrayList<>()
    //out.println();
  }
  
  public static BigInteger factorielle (int n) {
	  int i=0;
	  BigInteger f = new BigInteger("1");
	  for (i=1;i<=n;i++) {
		  f=f.multiply(BigInteger.valueOf(i));
	  }
	  return f;
  }
  
  public static int somme (int n) {
	  return (n*(n+1))/2;
  }

  public static void main(String[] args) throws IOException {
    if (SUBMIT) {
      in = new InputReader(new FileInputStream(new File(CHEMIN+NAME + ".in")));
      out = new PrintWriter(new BufferedWriter(new FileWriter(CHEMIN+NAME + ".out")));
    } else {
      in = new InputReader(System.in);
      out = new PrintWriter(System.out, true);
    }

    int numCases = in.nextInt();
    for (int test = 1; test <= numCases; test++) {
      out.print("Case #" + test + ": ");
      main2();
    }

    out.close();
    System.exit(0);
  }

  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }

    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }
  }
}
