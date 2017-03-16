#include <iostream>
#include <queue>
using namespace std;

const int N=1000+20;
const int M=10+2;
int m[N],a[N][M];

    bool usd[N];
bool has_dia(int n,int v0)
{int i;
    for(i=0;i<n;++i)usd[i]=false;
    std::queue<int> q;//q.clear();
    q.push(v0);
    while(!q.empty())
    {
        int vn=q.front();
        for(i=0;i<m[vn];++i)
        {
            if(usd[a[vn][i]])
                return true;
            usd[a[vn][i]]=true;
            q.push(a[vn][i]);
        }
        q.pop();
    }
    return false;
}

int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;++t)
    {int i,j;
        int n;
        cin>>n;
        for(i=0;i<n;++i)
        {
            cin>>m[i];
            for(j=0;j<m[i];++j)
                cin>>a[i][j],--a[i][j];
        }

        bool diamond=false;
        for(i=0;i<n;++i)
            if(has_dia(n,i)){diamond=true;break;}

        cout<<"Case #"<<t<<": ";
        cout<<(diamond?"Yes":"No");
        cout<<endl;
    }
    return 0;
}
