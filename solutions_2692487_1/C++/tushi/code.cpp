#include<iostream>
using namespace std;
#include<algorithm>
#include<set>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<cstdio>
#include<map>

typedef long long lli;

#define fi(i,a,b,d) for(i=a;i<=b;i+=d)
#define fir(i,a,b,d) for(i=a;i>=b;i-=d)

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

#define vi vector<int>
#define all(v) v.begin(), v.end()

#define mp make_pair
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front


#define inpi(i) scanf("%d", &i)
#define inplli(i) scanf("%lld", &i)
#define inpc(ch) scanf("%c", &ch)
#define printi(i) printf("%d\n", i)
#define printlli(i) printf("%lld\n", i)
#define printc(ch) printf("%c\n", ch)
#define inpfl(fl) scanf("%f", &fl)
#define printfl(fl) printf("%f", fl)


class className
{
    public:

};

int main()
{
    int t, k, i,a, n, arr[105], ans, temp, cur, j, temp2;

    cin>>t;

    fi(k,1,t,1)
    {
        cin>>a>>n;
        fi(i,0,n-1,1)
        {
            cin>>arr[i];
        }
        cout<<"Case #"<<k<<": ";
        ans=0;

        sort(arr,arr+n);

        i=0;

        while(i<n && arr[i]<a)
        {
            a+=arr[i];
            ++i;
        }
//cout<<"1\n";
        if(i==n)
        {
            cout<<ans<<'\n';
            continue;
        }
//cout<<"2\n";
        if(a==1)
        {
            cout<<n<<'\n';
            continue;
        }
//cout<<"3\n";
        ans = n-i;
        cur = 0;

        while(i<n)
        {
            if(a<=arr[i])
            {
                temp=0;
                j=i;
                while(a<=arr[j])
                {
                    a = 2*a-1;
                    ++temp;
                }

                while(j<n && a>arr[j])
                {
                    a += arr[j];
                    ++j;
                }

                temp2 = n-j;

cout<<"  "<<cur<<" "<<temp<<" "<<temp2<<'\n';
cout<<"  "<<i<<" "<<j<<" "<<a<<'\n'<<'\n';

                ans = min(ans, cur + temp + temp2);

                cur = cur + temp;
                if(cur>ans)
                break;
                i = j;
            }
            else
            {
                a+=arr[i];
                ++i;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
