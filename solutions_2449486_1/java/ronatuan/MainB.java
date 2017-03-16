import java.util.Scanner;

public class MainB {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        int T=Integer.parseInt(in.nextLine());
        String line="";
        for(int count=0;count<T;count++){
            line=in.nextLine();
            int a=Integer.parseInt(line.split(" ")[0]);
            int b=Integer.parseInt(line.split(" ")[1]);
            int[][] matrix=new int[a+1][b+1];
            for(int i=0;i<a;i++){
                line=in.nextLine();
                int max=0;
                for(int j=0;j<b;j++){
                    matrix[i][j]=Integer.parseInt(line.split(" ")[j]);
                    if(matrix[i][j]>max)
                        max=matrix[i][j];
                }
                matrix[i][b]=max;
            }
            for(int i=0;i<b;i++){
                int max=0;
                for(int j=0;j<a;j++){
                    if(matrix[j][i]>max)
                        max=matrix[j][i];
                }
                matrix[a][i]=max;
            }
            boolean ifOk=true;
            for(int i=0;i<a;i++){
                for(int j=0;j<b;j++){
                    if(matrix[i][j]!=matrix[i][b]&&matrix[i][j]!=matrix[a][j]){
                        System.out.println("Case #"+(count+1)+": NO");
                        ifOk=false;
                        break;
                    }
                }
                if(!ifOk)
                    break;
            }
            if(ifOk)
                System.out.println("Case #"+(count+1)+": YES");
        }
    }
}
