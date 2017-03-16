import java.util.*;
import java.math.*;

class C{

//

static int SIZE = 10000000;

static int  a[] = new int[SIZE+1];
static int prime[] = new int[SIZE+1];
static int prefactor[] = new int[SIZE+1];

static int p=1;
static void generate(int y)
    {int i,j;
     prime[0]=2;
     for(i=2;i<=y;i+=2)
      prefactor[i]=2;
     prefactor[1]=1;
     
     for(i=3;i*i<=y;i+=2)
        {if(a[i]!=0)
          continue;
         prime[p++]=i;
         prefactor[i]=i;
        for(j=i*i;j<=y;j+=2*i)
           {a[j]=1;
            prefactor[j]=i;
           }
        }
        for(;i<=y;i+=2)
          if(a[i]==0)
            {
             prime[p++]=i;
             prefactor[i]=i;
            } 
    }


static int BITS;

static String getBin(long x){
    int bit = BITS;
    int a[] = new int[bit];
    a[0]=a[bit-1]=1;
    long one = 1;
    for(int i=bit-2;i>0;i--){
        a[i]=(int)(x & one);
        x/=2;
    }
    String s="";
    for(int i=0;i<bit;i++){
        if(a[i]!=0)
            s+="1";
        else
            s+="0";
    }
    return s;
}

static long primeHash[] = new long [11];
static long checkPrime(BigInteger v){
//    if(v.isProbablePrime(100))
  //      return -1;
    
    for(int i=0;i<p;i++){
          if(v.equals(new BigInteger(Integer.toString(prime[i])))==true)
            return -1;
        if(v.mod(new BigInteger(Integer.toString(prime[i])))==BigInteger.ZERO)
            return prime[i];
    }
     return -1;
}

static boolean test(String s){
    int bits = BITS;
    for(int base = 2;base<=10;base++){
        BigInteger number = new BigInteger("0");
        BigInteger v = new BigInteger("1");
        //System.out.println(number+ " " + v + "ok");
        for(int i=bits-1;i>=0;i--){
            
            if(s.charAt(i)=='1'){
                number = number.add(v);//+=v;
         //      System.out.println("Found 1");
            }
            
            v=v.multiply(new BigInteger(Integer.toString(base)));//*=base;
        }
        //System.out.println(s+" in base " + base+" is "+number);
        long  pr = checkPrime(number);
        if(pr==-1)
            return false;
        primeHash[base] = pr;
    }
    return true;
}

public static void main(String args[])
{

 generate(SIZE);
Scanner sc = new Scanner(System.in);    
 int t,J;
 t=sc.nextInt();
 BITS=sc.nextInt();
 J=sc.nextInt();
    int c=0;
    long one = 1;
    long max = one<<(BITS-2);
    System.out.println("Case #1: ");
    
    for(long i=0;i<max;i++){
        String binary = getBin(i);
        if(c<J && test(binary)){
            System.out.print(binary+" ");
            for(int base = 2;base<=10;base++)
                System.out.print(primeHash[base]+" ");
           System.out.println();

            c++;
            if(c==J)
               break;
        }

    }

}
}