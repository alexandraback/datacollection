import java.util.*;
import java.io.*;
import java.text.DecimalFormat;

public class Diamond{
  
  public static void main(String[] args){
    try{
      FileReader fin = new FileReader(args[0]);
      BufferedReader txtFile = new BufferedReader(fin);
    
      //FileWriter fout = new FileWriter(args[1]);
      //BufferedWriter out = new BufferedWriter(fout);
			
      String line = null;     
      line = txtFile.readLine();
      int T = Integer.parseInt(line);
      //System.out.println(T);
      for(int i = 0; i < T; i ++){
        line = txtFile.readLine();        
        int N = Integer.parseInt(line);
        
        ArrayList<ArrayList<Integer>> rel = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> pars = new ArrayList<Integer>();
        rel.add(pars);
        for(int j = 1; j <= N; j ++){
            line = txtFile.readLine();
            StringTokenizer st = new StringTokenizer(line, " ");
            int M = Integer.parseInt(st.nextToken());
            pars = new ArrayList<Integer>();
            for(int k = 0; k < M; k ++)
               pars.add(Integer.parseInt(st.nextToken()));
            rel.add(pars);
        }
        
        boolean[] isVisited = new boolean[N+1];
        for(int j = 0; j <= N; j ++) isVisited[j] = false;
        ArrayList<Integer> queue = new ArrayList<Integer>();
        queue.add(1); isVisited[1] = true; boolean next = false;
        while(true){
            ArrayList<Integer> visited = new ArrayList<Integer>();
            while(queue.size() > 0){
                //System.out.println(queue);
                /*try {
    		    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    		    String str = in.readLine();
		} catch (IOException e) {
		}*/
                int cur = queue.get(0);
                queue.remove(0);
                pars = rel.get(cur); next = false;
                for(int j = 0; j < pars.size(); j ++)
                {
                    int par = pars.get(j);
                    isVisited[par] = true; 
                    if(visited.contains(par) == false)
                    {   queue.add(par); visited.add(par);  }
                    else{
                        System.out.println("Case #"+Integer.toString(i+1)+": Yes");
                        next = true; break;
                    }
                }//for
                if(next) break;
            }//while(queue.size() > 0)
            if(next) break;
            int j = 0;
            for(j = 1; j <= N; j ++)
                if(isVisited[j] == false) { isVisited[j] = true;  queue.clear(); queue.add(j); break; }
            if(j > N)
            {
                System.out.println("Case #"+Integer.toString(i+1)+": No");
                break;
            }
            /*for(int k = 1; k <= N; k ++)
                if(k != j) isVisited[k] = false;*/
        }//while(true)

      }//for(int i = 0; i < T; i ++)
    }//try
    catch(IOException e) {
	e.printStackTrace();
    }    
  }
}
