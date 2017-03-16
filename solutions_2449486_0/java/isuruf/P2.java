
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class P2 {

    public static void main(String[] args) {
        Scanner scanner;
        try {
            scanner = new Scanner(new File("2.in"));
            int t=scanner.nextInt();
            System.out.println(t);
            int k=0,i,j;
            while(k<t)
            {
                int m=scanner.nextInt();
                int n=scanner.nextInt();
                int[][] arr=new int[m][n];
                for(i=0;i<m;i++)
                    for(j=0;j<n;j++)
                        arr[i][j]=scanner.nextInt();
                int[] col = new int[n];
                int[] row = new int[m];
                for(i=0;i<m;i++)
                    for(j=0;j<n;j++)
                        if(arr[i][j]>row[i])
                            row[i]=arr[i][j];
                for(j=0;j<n;j++)
                    for(i=0;i<m;i++)
                        if(arr[i][j]>col[j])
                            col[j]=arr[i][j];
                int check=1;
                for(i=0;i<m;i++)
                    for(j=0;j<n;j++)
                        if(arr[i][j]!=col[j]&&arr[i][j]!=row[i])
                            check=0;
                k++;
                if(check==1)
                    System.out.println("Case #"+k+": YES");
                else
                    System.out.println("Case #"+k+": NO");
            }
        } 
        catch (FileNotFoundException ex) {
            
        }
    }
}
