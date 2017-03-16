import java.io.*;
import java.util.*;


public class Solution {
	public static boolean isCleared(int N, boolean[] clearedB){
		for(int i=0; i<N; i++){
			if(!clearedB[i]){
				return false;
			}
		}
		return true;
	}
	
	public static String calc(int N, int[] a, int[] b){
		boolean[] clearedA = new boolean[N];
		boolean[] clearedB = new boolean[N];
		for(int i=0; i<N; i++){
			clearedA[i] =false;
			clearedB[i] =false;
		}
		
		// bの降順にソート
		for(int i=0; i<N-1; i++){
			for(int j=1; j<N-i; j++){
				if(b[j] > b[j-1]){
					int tmpA = a[j-1];
					int tmpB = b[j-1];
					a[j-1] = a[j];
					b[j-1] = b[j];
					a[j] = tmpA;
					b[j] = tmpB;
				}
			}
		}
		
		int stars = 0;
		int ret = 0;

		while(true){
			if(isCleared(N, clearedB)){
				return Integer.toString(ret);
			}
			
//			System.out.println("###############");
//			for(int i=0; i<N; i++){
//				if(clearedA[i] && clearedB[i]){
//					continue;
//				}
//				System.out.println(i + ": " + a[i] + " " + b[i] + " " + Boolean.toString(clearedA[i]) + " " + Boolean.toString(clearedB[i]));
//			}
//			System.out.println("###############");
			
			int preCount = ret;
			
			// まず 2-stars ratingでearn 2できるものから探す
			for(int i=0; i<N; i++){
				if(b[i] <= stars){
					if(!clearedA[i] && !clearedB[i]){
						//System.out.println("clear b[" + i + "] first with stars : " + stars);

						stars += 2;
						clearedA[i] = true;
						clearedB[i] = true;
						ret ++;
						break;
					}
				}
			}
			
			if(preCount != ret){
				//System.out.println("complete 2-stars rating and earn 2 stars with stars : " + stars);
				continue;
			}
			
			// 次に 2-stars ratingでearn 1できるものから探す
			for(int i=0; i<N; i++){
				if(b[i] <= stars){
					if(clearedA[i] && !clearedB[i]){
						//System.out.println("clear b[" + i + "] second with stars : " + stars);

						stars += 1;
						clearedB[i] = true;
						ret ++;
						break;
					}
				}
			}
			
			if(preCount != ret){
				//System.out.println("complete 2-stars rating and earn 1 star with stars : " + stars);
				continue;
			}
			// なければ 1-star ratingから探す
			for(int i=0; i<N; i++){
				if(!clearedA[i] && a[i] <= stars){
					//System.out.println("clear a[" + i + "] first with stars : " + stars);

					clearedA[i] = true;
					stars += 1;
					ret ++;
					break;
				}
			}
			
			if(preCount != ret){
				//System.out.println("complete 1-star rating with stars : " + stars);
				continue;
			}
			
			// 何もできない状態ならbreak
			//System.out.println("cannot complete any levels with stars : " + stars);
			return "Too Bad";
		}
	}
	
	public static void main(String[] args){
        if(args.length == 0){
            System.exit(1);
        }

        try{
            FileReader fr = new FileReader(args[0]);
            BufferedReader br = new BufferedReader(fr);
            
            FileOutputStream fos = new FileOutputStream(args[0] + ".out");
            OutputStreamWriter osw = new OutputStreamWriter(fos , "UTF-8");
            BufferedWriter bw = new BufferedWriter(osw);
            
            String tmp_str;
            
            tmp_str = br.readLine();
            
            int numOfCases = Integer.parseInt(tmp_str);
            int caseIndex = 0;
            
            while((tmp_str = br.readLine()) != null){
            	caseIndex++;
            	
                int N = Integer.parseInt(tmp_str);

                int[] a = new int[N];
                int[] b = new int[N];
                
                for(int i=0; i<N; i++){
                    tmp_str = br.readLine();
                    StringTokenizer st = new StringTokenizer(tmp_str, " ");
                    int numOfTokens = st.countTokens();
                    String[] tokenOfLine = new String[numOfTokens];
                    for(int j=0; j<numOfTokens; j++){
                    	tokenOfLine[j] = st.nextToken();
                    }
                    
                    a[i] = Integer.parseInt(tokenOfLine[0]);
                    b[i] = Integer.parseInt(tokenOfLine[1]);
                }
                
                String ret = calc(N, a, b);
                
                System.out.println("Case #" + caseIndex + ": " + ret);
                
            	if(caseIndex==numOfCases){
                	bw.write("Case #" + caseIndex + ": " + ret);
            	}else{
                	bw.write("Case #" + caseIndex + ": " + ret + "\n");
            	}
            }
            br.close();
            bw.close();
            osw.close();
            fos.close();

 
        }
        catch(IOException e){
            e.printStackTrace();
            System.exit(1);
        }

	}
}
