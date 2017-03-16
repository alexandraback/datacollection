import java.math.BigInteger;
import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Main main = new Main();
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            BigInteger ans = new BigInteger(0+"");
            int e = sc.nextInt();
            int max = e;
            int r = sc.nextInt();
            int n = sc.nextInt();
            int v[] = new int[n];
            for (int j = 0; j < v.length; j++) {
                v[j] = sc.nextInt();
            }
            int maxVal = main.max(v);
            for (int j = 0; j < v.length-1; j++) {
                BigInteger V = new BigInteger(v[j]+"");
                if(v[j] == maxVal)    {
                    ans = ans.add(V.multiply(new BigInteger(e+"")));
//                    ans = ans.add(new BigInteger((e * v[j])+""));
                    e = 0;
                }
                else if(v[j] > v[j + 1])    {
                    if(e>=(2*r))   {
                        ans = ans.add(new BigInteger((V.multiply(new BigInteger(2*r+"")))+""));
//                        ans = ans.add(new BigInteger((2 * r * v[j])+""));
                        e -= 2*r;
                    }
                    else    {
                        ans = ans.add(new BigInteger((V.multiply(new BigInteger(e+"")))+""));
//                        ans = ans.add(new BigInteger((e * v[j])+""));
                        e = 0;
                    }
                }
                else    {
                    int tempTotal = e+r;
                    if(tempTotal>=max)  {
                        ans = ans.add(V.multiply(new BigInteger((tempTotal - max)+"")));
//                        ans = ans.add(new BigInteger(((tempTotal - max) * v[j])+""));
                    }
                }
                if(e+r >= max)
                    e=max;
                else    {
                    e += r;
                }
            }
            ans = ans.add(new BigInteger(v[v.length-1]+"").multiply(new BigInteger(e+"")));
//            ans = ans.add(new BigInteger((e * v[v.length-1])+""));
            e=0;
            System.out.println("Case #"+i+": "+ans);
        }
    }

    public int max(int arr[])  {
        int ans =-1;
        for (int i = 0; i < arr.length; i++) {
            int j = arr[i];
            if(ans<j)
                ans = j;
        }
        return ans;
    }
}