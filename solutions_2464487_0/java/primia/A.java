import java.util.Scanner;
import java.math.BigDecimal;

public class A{
    A()
    {
        
    }

    private static BigDecimal bisqrt(BigDecimal t){
        BigDecimal a = BigDecimal.ONE;
        BigDecimal _2 = BigDecimal.valueOf(2);
        BigDecimal b = t.divide(_2,20,BigDecimal.ROUND_HALF_EVEN);

        
        BigDecimal m;
        int cnt = 0;
        while(cnt++<300){
            m = a.add(b).divide(_2,20,BigDecimal.ROUND_HALF_EVEN);
            if(m.multiply(m).compareTo(t)>0){
                b = m;
            }else{
                a = m;
            }
        }
        return a;
    }

    public void solve()
    {
        Scanner sc = new Scanner(System.in);
        int T;

        T = sc.nextInt();
        for(int tc=1;tc<=T;++tc){
            BigDecimal r = sc.nextBigDecimal();
            BigDecimal t = sc.nextBigDecimal();
            BigDecimal _12 = BigDecimal.valueOf(12);
            BigDecimal _4 = BigDecimal.valueOf(4);
            BigDecimal _8 = BigDecimal.valueOf(8);
            BigDecimal _9 = BigDecimal.valueOf(9);
            BigDecimal _3 = BigDecimal.valueOf(3);
            BigDecimal _2 = BigDecimal.valueOf(2);
            
            BigDecimal f = (_4.multiply(r).multiply(r)).
                subtract(
                    _4.multiply(r)).
                add(
                    _8.multiply(t)).
                add( BigDecimal.ONE );
            
            f = A.bisqrt(f);
            BigDecimal ans = 
                ( f.subtract( _2.multiply(r) ).
                  add( BigDecimal.ONE )
                  ).divide(_4,0,BigDecimal.ROUND_FLOOR);
            
            System.out.println("Case #"+tc+": "+ans);
        }
        
    }
    
    public static void main(String [] args)
    {
        A solver = new A();
        solver.solve();
        
    }
}
