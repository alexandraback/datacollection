#include<fstream>
#include<vector>
using namespace std;

int main()
{
    ifstream in("A-small-attempt2.in");
    ofstream out("out.txt");
    int T;
    in>>T;
    for(int x=0;x<T;x++)
    {
        out<<"Case #"<<x+1<<": ";
        int n;
        in>>n;
        vector<int> inherit[n+1];
        for(int i=0;i<n;i++)
        {
            int m;
            in>>m;
            for(int j=0;j<m;j++)
            {
                int p;
                in>>p;
                inherit[p].push_back(i+1);
            }
        }
        bool dia=false;
        for(int m=1;m<=n;m++){
            
        int a[500];
        for(int k=0;k<=n;k++) 
        {a[k]=0;}
        int head=1,tail=1;
        a[head]=m; 
        while(head<=tail)
        {
            for(int i=0;i<inherit[a[head]].size();i++)
            {
               // if(a[head]==2) for(int i=1;i<4;i++) out<<a[i]<<" ";
                for(int j=1;j<=n;j++) if(a[j]==inherit[a[head]][i]) {dia=true;break;}
                a[tail+1]=inherit[a[head]][i];
                //pre[tail+1]=a[head];
                tail++;
            }
            head++;
        }
        if(dia) break;
    }
        if(dia) out<<"Yes"; else out<<"No";
        out<<endl;
    }
    in.close();
    out.close();
    return 0;
}
