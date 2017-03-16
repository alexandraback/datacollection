import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;


public class td {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/test1")); 

        String line;
        int T = Integer.parseInt(""+in.readLine().charAt(0));

        int i=0;
        
        
        while ((line=in.readLine())!=null) {
            i++;
            int N = Integer.parseInt(line.split("\\s+")[0]);
            //int N = Integer.parseInt(""+line.charAt(0));
            //System.out.println(N);
            solve(in, N, i);
            
            
            //String[] splitline = line.split("\\s+");          
            //int A = Integer.parseInt(splitline[0]);
            //int B = Integer.parseInt(splitline[1]);
            //String[] prob = in.readLine().split("\\s+");
            
            
            //System.out.println("Case #" + i + ": " + min);

            //StringBuilder subs = new StringBuilder();
            //subs.append("Case #" + i + ": ");
 


        }
        

    }
    
    public static void solve(BufferedReader in, int x, int c) throws IOException {
        ArrayList<Integer> one=new ArrayList<Integer>();
        ArrayList<Integer> two=new ArrayList<Integer>();
        int stars = 0;
        int moves = 0;
        int failed = 0;
        
        for (int j=0;j<x;j++) {
            String[] splitline = in.readLine().split("\\s+");
            one.add(Integer.parseInt(splitline[0]));
            two.add(Integer.parseInt(splitline[1]));
        }
        int[] starsone = new int[one.size()];
        int[] starstwo = new int[one.size()];
        for (int z=0;z<starsone.length;z++) {
            starsone[z] = 1;
            starstwo[z]=1;
        }


        
        
        while (stars < 2*one.size()) {
            int found = 0;
            for (int j=0;j<one.size();j++) {
                
                if (stars >= two.get(j) && starstwo[j]==1) {
                    stars = stars + starstwo[j]+starsone[j];
                    starstwo[j] = 0;
                    starsone[j] = 0;
                    found = 1;
                    moves++;
                } 
            }
            
            if (found==0) {
                for (int k=0;k<one.size();k++) {
                   
                    if (stars >= one.get(k) && starsone[k]==1) {
                        
                        stars = stars +starsone[k];;
                        starsone[k] = 0;
                        found = 1;
                        moves++;
                        break;
                    } 
                    
                }
            }
            
            if (found==0) {
                failed=1;
                break;
            }
            
        
        }
        
        if (failed==1) {
            System.out.println("Case #" + c + ": "+"Too Bad");
        } else {
            System.out.println("Case #" + c + ": "+moves);
        }

        
        
        
        
        
        
    }
}
