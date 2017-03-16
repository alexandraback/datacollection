#include <iostream>

using namespace std;
typedef long long LL;
int main()
{
    int T;
    freopen("D:\\in.txt","r",stdin);
    freopen("D:\\out.txt","w",stdout);
    cin>>T;
    for (int t=1;t<=T;t++){
        LL a,b,k;
        cin>>a>>b>>k;
        /*LL f[50][2][2]={0};
        f[40][1][1]=1;
        for (int len=40;len>=1;len--){
            int pa=(((1LL<<(len-1))&a)>0);
            int pb=(((1LL<<(len-1))&b)>0);
            int pk=(((1LL<<(len-1))&k)>0);


            if (pk){
                f[len-1][0][0]+=f[len][0][0];
                if (pa&&pb){
                    f[len-1][]+=f[len][1][1];
                }
            }
            else
                f[len-1][0][0]+=3*f[len][0][0];


        }*/
        int ans=0;
        for (int i=0;i<a;i++)
            for (int j=0;j<b;j++){
                //cout<<i<<" "<<j<<" "<<(i&j)<<endl;
                if ((i&j)<k) ans++;
            }
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
}

