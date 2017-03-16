
import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.*;

/**
 *
 * @author
 */
public class Q2{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
    	Q2 p = new Q2();
        p.start();

    }

    public void start() throws Exception{
        // TODO code application logic here
        Scanner inFile = new Scanner(new File("B-small-practice.in"));
        PrintWriter outFile = new PrintWriter(new File("smallout.file"));
        //Scanner inFile = new Scanner(new File("B-large-practice.in"));
        //PrintWriter outFile = new PrintWriter(new File("largeout.file"));

        int caseN =inFile.nextInt();
        System.out.println("Number of Case  "+caseN);

 		for(int i = 1; i<caseN+1; i++){

 			int N =inFile.nextInt();
 			int a[] = new int[N];
 			int b[] = new int[N];
 			ArrayList<Integer> []numA = new ArrayList[2002];
 			ArrayList<Integer> []numB = new ArrayList[2002];
 			int star =0;
 			int levels =0;
 			int flag = 1;  //ok

 			for(int j=0;j<2002;j++){
 				numA[j]=new ArrayList<Integer>();
                numB[j] =new ArrayList<Integer>();
 			}

 			for(int j = 0; j<N ; j++){
 				a[j] = inFile.nextInt();
 				numA[a[j]].add(j);
 				b[j] = inFile.nextInt();
 				numB[b[j]].add(j);
 			}

            done: for(int j=0; j<2002; j++){
            	while(!numB[j].isEmpty()){
					//need to compete
					if (star>=j){
						star +=numB[j].size()*2;
						levels += numB[j].size();
						for(int t=0;t<numB[j].size();t++){
						 Integer temp = numB[j].get(t);
                         int k = temp.intValue(); // index of level complete  delete the 1-star rating
                         	for(int l=0;l<numA[a[k]].size();l++){
                              	temp = (Integer)numA[a[k]].get(l);
                         		if (temp.intValue()==k) {
                         			numA[a[k]].remove(l);
                         			break;
                         		}
                              }

						}

						numB[j].clear();
					}
					else{
						// go back and check
						for (int t=0;t<=star; t++){
							while(!numA[t].isEmpty()&&star<j){
								 Integer temp = numA[t].get(0);
        		                 int k = temp.intValue();
        		                 star ++;
        		                 levels ++;
        		                 numA[t].remove(0);
							}

							if(star >=j ) break;

						}

						if(star <j){
							flag = 0;
							break done;
						}

					}




            	}




            }


			if(flag!=0){


            System.out.println("Case #"+i+": "+levels);
            outFile.println("Case #"+i+": "+levels);}
            else{
            	System.out.println("Case #"+i+": Too Bad ");
            outFile.println("Case #"+i+": Too Bad");
            }
        }

        //close the file
         inFile.close();
         outFile.close();


      }
}
