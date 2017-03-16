#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int TEST;
long long arr[] = {121LL,1LL,484LL,4LL,9LL,1002001LL,10201LL,1234321LL,12321LL,14641LL,4008004LL,40804LL,44944LL,10000200001LL,100020001LL,10221412201LL,102030201LL,104060401LL,12102420121LL,121242121LL,12345654321LL,123454321LL,125686521LL,40000800004LL,400080004LL,404090404LL,1000002000001LL,1002003002001LL,1004006004001LL,1020304030201LL,1022325232201LL,1024348434201LL,1210024200121LL,1212225222121LL,1214428244121LL,1232346432321LL,1234567654321LL,4000008000004LL,4004009004004LL};


int main()
{
    long long A,B;
	freopen("C-large-1.in","r",stdin);
	freopen("test.out","w",stdout);
	cin >> TEST;
	for(int T = 1; T <= TEST; ++T)
	{       
            cin >> A >> B;
            int ans = 0;
            for(int i = 0 ; i < 39; i++)
                    if(arr[i] >= A && arr[i] <= B)
                              ans++;
            printf("Case #%d: %d\n",T,ans);
	}
    return 0;
}
