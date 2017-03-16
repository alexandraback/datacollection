import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Main main = new Main();
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            int ans = 0;
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
                if(v[j] == maxVal)    {
                    ans += e * v[j];
                    e = 0;
                }
                else if(v[j] > v[j + 1])    {
                    if(e>=(2*r))   {
                        ans += 2*r * v[j];
                        e -= 2*r;
                    }
                    else    {
                        ans += e * v[j];
                        e = 0;
                    }
                }
                else    {
                    int tempTotal = e+r;
                    if(tempTotal>=max)  {
                        ans += (tempTotal - max) * v[j];
                    }
                }
                e +=r;
                if(e > max)
                    e=max;
            }
            ans += v[v.length-1]*e;
            e=0;
            System.out.println("Case #"+i+": "+ans);
        }
    }


    public void Sort(int arr[]) {
        for (int i = 1; i < arr.length; i++) {
            int hold = arr[i];
            int idx = i;
            for (int j = i-1; j >= 0; j--) {
                int k = arr[j];
                if(hold>k)  {
                    arr[idx]=k;
                    idx = j;
                }
                else    {
                    break;
                }
            }
            arr[idx]=hold;

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