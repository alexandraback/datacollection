import java.util.Scanner;

public class MainC {
    public static void main(String[] args){
        long[] list=new long[]{1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001l,10221412201l,12102420121l,12345654321l,40000800004l,1000002000001l,1002003002001l,1004006004001l,1020304030201l,1022325232201l,1024348434201l,1210024200121l,1212225222121l,1214428244121l,1232346432321l,1234567654321l,4000008000004l,4004009004004l};
        Scanner in=new Scanner(System.in);
        int N=Integer.parseInt(in.nextLine());
        for (int round=0;round<N;round++){
            String line=in.nextLine();
            long a=Long.parseLong(line.split(" ")[0]);
            long b=Long.parseLong(line.split(" ")[1]);
            int count=0;
            for(int i=0;i<list.length;i++){
                if((list[i]>=a)&&(list[i]<=b))
                    count++;
            }
            System.out.println("Case #"+(round+1)+": "+count);
        }
    }
}
