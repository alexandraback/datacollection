#include <iostream>
#include <fstream>
#include <algorithm>
#define long long long

#define cin in
#define cout out

using namespace std;
ifstream in("input.in");
ofstream out("output.txt");
long t,n,a,b[200];

int main()
{
    cin>>t;
    for (long i=1;i<=t;i++){
    cout<<"Case #"<<i<<": ";
    cin>>a>>n;
    for (long j=0;j<n;j++)
        cin>>b[j];
    sort(b,b+n);
    long ans=n;
    long ans1=n;
    if (a!=1){
        for (long k=0;k<n;k++){
            if (b[k]<a){
                a+=b[k];
                ans1--;
            }
            else{
                a=2*a-1;
                while (a<=b[k]){
                    ans1++;
                    a=2*a-1;
                }
            a+=b[k];
            }
            ans=min(ans,ans1);
        }


    cout<<ans<<endl;
    }
    else{
    cout<<n<<endl;
    }
    }
    return 0;
}
