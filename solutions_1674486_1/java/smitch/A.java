import java.util.*;
import java.io.*;

public class A {
  private static boolean isDiamond(int[][] vortex, boolean[] isVisited, int current){
    if(isVisited[current]) return true;
    else isVisited[current]=true;
    for(int i: vortex[current]){
      if(isDiamond(vortex, isVisited, i-1)) return true;
    }
    return false;
  }

	private static void GcjMethod(int[][] input){
    int N=input.length;
    //    System.out.println(Arrays.toString(input));
    // for(int i=0; i<input.length; i++){
    //   for(int j=0; j<input[i].length; j++)
    //     System.out.print(input[i][j]+" ");
    //   System.out.println();
    // }

    for(int i=0; i<N; i++){
      boolean[] isVisited=new boolean[N];
      for(int j=0; j<N; j++) isVisited[j]=false;
      if(isDiamond(input, isVisited, i)){
        System.out.println("Yes");
        return;
      }
    }

      System.out.println("No");
      return;
	}

	public static final void main(final String[] args) {
		String line;
		int numCase;
		int[][] input;

		BufferedReader d = new BufferedReader(new InputStreamReader(System.in));
		try{
			numCase=Integer.parseInt(d.readLine());
			for(int i=0; i<numCase; i++){
				line=d.readLine();
        int N=Integer.parseInt(line);
        input = new int[N][];
        for(int j=0; j<N; j++){
          line=d.readLine();
          String[] tmp=line.split(" ");
          int M=Integer.parseInt(tmp[0]);
          input[j]=new int[M];
            for(int k=0; k<M; k++) input[j][k]=Integer.parseInt(tmp[k+1]);
            
          // System.out.println(input[i]);
        }
				System.out.print(String.format("Case #%d: ", i+1));

       // System.out.println(Arrays.toString(input));
        // for(int j=0; j<N; j++){
        //   System.out.println(input[i]);
        // }
				GcjMethod(input);
			}
		}
		catch(Exception e){
      System.err.println(e);
		}
	}
}
