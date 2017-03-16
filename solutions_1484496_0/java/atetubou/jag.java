import java.util.*;


class Main{
    Scanner cin;

    int solve(){
        int n=cin.nextInt();
        long[] in=new long[n];
        
        for(int i=0;i<n;++i)
            in[i]=cin.nextLong();
        Map<Long,Long> app=new HashMap<Long,Long>();

        for(Long i=1L;i<(1<<n);++i){
            long sum=0;
            for(int j=0;j<n;++j)
                if(((i>>j)&1)!=0)
                    sum+=in[j];
            if(app.containsKey(sum)){
                long k1=app.get(sum);
                for(int j=0;j<n;++j)
                    if(((k1>>j)&1)!=1)
                        System.out.printf("%d ",in[j]);
                System.out.println();
                for(int j=0;j<n;++j)
                    if(((i>>j)&1)!=1)
                        System.out.printf("%d ",in[j]);
                System.out.println();                
                break;
            }
            app.put(sum,i);
        }
        
        return 0; 
    }
    
    void run(){
        cin=new Scanner(System.in);
        int t=cin.nextInt();
        for(int i=0;i<t;++i){
            System.out.printf("Case #%d:\n",i+1);
            solve();
        }
    }
    
    public static void main(String[] args){
        new Main().run();
    }
}