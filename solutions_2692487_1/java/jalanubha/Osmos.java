/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package contests.googleJam.code2013;

import java.io.*;

/**
 *
 * @author
 * Kisna
 */
public class Osmos
{
    public static void iSort(int[] arr)
    {
        int k;
        for(int i=1; i<arr.length; i++)
        {
        k = arr[i];
        int j;
            for(j=i-1; j>=0; j--)
            if(k<arr[j])
                arr[j+1] = arr[j];
            else
                break;
        arr[j+1] = k;
        }
    }
    
    public static void main(String[] args) 
    {
       BufferedReader br = null;
 
		try {
                        FileWriter fstream = new FileWriter("output.out");
                        BufferedWriter out = new BufferedWriter(fstream);
			String sCurrentLine;
 
			br = new BufferedReader(new FileReader("A-large.in"));
                        sCurrentLine = br.readLine();
                        int i = 1;
                        int A,N;
                        int[] sizes;
                        boolean[] eaten;
                        int had;
                        int op;
                        int remove;
                        boolean wasPerformed;
                        while ((sCurrentLine = br.readLine()) != null) 
                        {  
                            String temp[] = sCurrentLine.split(" ");
                            A = Integer.parseInt(temp[0]);
                            N = Integer.parseInt(temp[1]);
                            sizes = new int[N];
                            op = 0;
                            wasPerformed = false;
                            boolean came = false;
                            remove = 0;
                            temp = br.readLine().split(" ");
                            for (int j = 0; j < N; j++) {
                                sizes[j] = Integer.parseInt(temp[j]);
                            }
                            
                            //sorting
                            iSort(sizes);
                            //eat small
                            int k = 0;
                            while(k < N) {
                                if(sizes[k] < A) {
                                    A += sizes[k];
                                    k++;
                                    wasPerformed = false;
                                } else {
                                //add one less
                                //keep eating
                                //add more if not possible
                                    if(wasPerformed && !came) {
                                        remove = op + N - (k+1);
                                        came = true;
                                    }
                                    A = A + (A-1);
                                    op++;
                                    if(came && op >= remove)
                                        break;
                                    wasPerformed = true;
                                //if still not possible add the remainging to the op
                                //done
                                }
                            }
                                                        
                            if(!came)
                                remove = Integer.MAX_VALUE;
                            
                            out.write("Case #" + i++ + ": " + Math.min(op, remove));
                            
                            out.write("\n");
                        }
                        out.close();
 
		} catch (IOException e) {
		} finally {
			try {
				if (br != null)
                                    br.close();
			} catch (IOException ex) {
			}
		} 
    }
    
}
