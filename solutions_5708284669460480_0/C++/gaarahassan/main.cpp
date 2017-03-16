#include <bits/stdc++.h>
#define mp make_pair
#define ll long long

using namespace std;
vector <int> vv;
bool vs[100];
int k , l , s ;
string ks , ss;
int ansrep ;
int arr[100];
int tot;
void solve ( int i , int e , string x)
{
    if(i==e)
    {
        tot++;
        int rep = 0;
        for(int j = 0 ; j < x.size() ; j++)
        {
            bool flag = true;
            int xr=0;
            for(int c = j , xl = 0; c < x.size() && xl< l ; xl++, c++)
            {
                if(x[c]!=ss[xl])
                {
                    flag = false;
                    break;
                }
                else
                    xr++;
            }
            if(x.length() < l || xr < l)
                flag = false;
            if(flag)
            {
                rep++;
            }
        }
        ansrep = max(rep , ansrep);
        arr[rep]++;
        return ;
    }
    for(int j = 0 ; j < k ; j++)
    {
        string t = x;
        t+=ks[j];
        solve(i+1 , e , t );
    }

}



int main()
{
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int t;
    cin >> t;
    int a = 1;
    while(a <= t)
    {
        tot=0;
        memset(arr,0,sizeof(arr));
        ansrep = 0;
        cin >> k >> l >> s;
        cin >> ks ;
        cin >> ss;
        string x;
        solve(0 , s , x );
        double ans = 0;
        for(int i = 0 ; i <= ansrep ; i++)
        {
            ans +=  (((double)arr[i])/tot) * (ansrep-i);
            //cout <<  (  ((double)arr[i])/tot) << " " << ansrep-i << endl;
        }
        printf("Case #%d: %llf\n" ,a++,  ans);

    }
}
