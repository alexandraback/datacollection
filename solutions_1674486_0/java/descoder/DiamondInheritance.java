package googleCodeJam;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class DiamondInheritance {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		//System.out.println("size of map: " + map.size());
		try{
			
			FileInputStream fstream = new FileInputStream("/Users/mkay/Documents/input_31.txt");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine;
			
			int input1, input2;
			String [] str1, str2;
			int [][] arr;
			int t,count = 0,a,b,n,m;
			
			int i,j,k;
			
			t=Integer.parseInt(br.readLine());
			String result;
			int p1,p2,p3,x,s;
			
			  while (t>0)
			  {
				  t--;
				  count++;
				  n = Integer.parseInt(br.readLine());
				  arr = new int[n][11];
				  for(i=0;i<n;i++){
					  str1 = br.readLine().split(" ");
					  m=Integer.parseInt(str1[0]);
					  arr[i][0]=m;
					  for(j=0;j<m;j++)
						  arr[i][j+1]=Integer.parseInt(str1[j+1])-1;
				  }
				  result = "No";
				  int path=0;
				  for(i=0;i<n&&result.equalsIgnoreCase("No");i++){
					  
					if(arr[i][0]>1){
						ArrayList<HashMap<Integer, Integer>> list = new ArrayList<HashMap<Integer,Integer>>();
						//System.out.println("i="+i+" arr[i][0]="+arr[i][0]);
						path = 0;
						for(j=1;j<=arr[i][0];j++){
							ArrayList<Integer> q = new ArrayList<Integer>();
							HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
							q.add(arr[i][j]);
							list.add(map);
							while(q.size()>0){
								x = q.get(0);
								map.put(x, x);
								q.remove(0);
								//System.out.println("queue is: " + q + " x="+x + " arr[x][0]="+arr[x][0]);
								for(k=1;k<=arr[x][0];k++){
									//System.out.println("queue is: " + q + " x="+x + " arr[x][k]="+arr[x][k]);
									if(!map.containsKey(arr[x][k]))
										q.add(arr[x][k]);
								}
								//System.out.println("queue is: " + q + " x="+x);
							}
							//System.out.println("map is: " + map);
							if(path>0){
								for(k=0;k<path&&result.equalsIgnoreCase("No");k++){
									for(Integer key: map.keySet()){
										if(list.get(k).containsKey(key))
										{
											result = "Yes";
											break;
										}
									}
								}
							}	
							path++;
						}
						
					} 
				  }
				  System.out.println("Case #"+ count +": " + result);
				  
			  }			  
			  in.close();
			}catch (IOException e)
		    {
				System.err.println("Error: " + e.getMessage());
		    }		
	}

}