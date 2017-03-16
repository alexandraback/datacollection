import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        int N=Integer.parseInt(in.nextLine());
        String line="";
        int[][] matrix=new int[4][4];
        for(int round=0;round<N;round++){
            boolean ifTerm=false;
            boolean ifDot=false;
            for(int i=0;i<4;i++){
                line=in.nextLine();
                for(int j=0;j<4;j++){
                    if(line.charAt(j)=='X')
                        matrix[i][j]=1;
                    else if(line.charAt(j)=='O')
                        matrix[i][j]=-1;
                    else if(line.charAt(j)=='.'){
                        matrix[i][j]=100;
                        ifDot=true;
                    }
                    else
                    {
                        matrix[i][j]=0;
                        ifTerm=true;
                    }
                }
            }
            if(round!=N-1)
                line=in.nextLine();
            boolean ifEnd=false;
            for(int i=0;i<4;i++){
                int sum=0;
                for(int j=0;j<4;j++){
                    sum=sum+matrix[i][j];
                }
                if(sum==3||sum==4||sum==-3||sum==-4){
                    System.out.println("Case #"+(round+1)+": "+num2char(sum/3)+" won");
                    ifEnd=true;
                    break;
                }
            }
            if(ifEnd)
                continue;
            for(int i=0;i<4;i++){
                int sum=0;
                for(int j=0;j<4;j++){
                    sum=sum+matrix[j][i];
                }
                if(sum==3||sum==4||sum==-3||sum==-4){
                    System.out.println("Case #"+(round+1)+": "+num2char(sum/3)+" won");
                    ifEnd=true;
                    break;
                }
            }
            if(ifEnd)
                continue;
            int sum=0;
            for(int i=0;i<4;i++)
                sum=sum+matrix[i][i];
            if(sum==3||sum==4||sum==-3||sum==-4){
                System.out.println("Case #"+(round+1)+": "+num2char(sum/3)+" won");
                continue;
            }
            sum=0;
            for(int i=0;i<4;i++)
                sum=sum+matrix[i][3-i];
            if(sum==3||sum==4||sum==-3||sum==-4){
                System.out.println("Case #"+(round+1)+": "+num2char(sum/3)+" won");
                continue;
            }
            if(ifDot){
                System.out.println("Case #"+(round+1)+": Game has not completed");
                continue;
            }
            System.out.println("Case #"+(round+1)+": Draw");
        }
    }
    static char num2char(int a){
        if(a==1)
            return 'X';
        return 'O';
    }
}
