#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,t;
    cin>>n;
    t=1;
    int i,j,k;
    int len;
    while(t<=n)
    {
        vector<double> nao,ken;
        double tmp;
        cin>>len;
        int war=0;
        int dece=0;
        for(i=0;i<len;i++)
        {
            cin>>tmp;
            nao.push_back(tmp);
        }
        for(i=0;i<len;i++)
        {
            cin>>tmp;
            ken.push_back(tmp);
        }
        sort(nao.begin(),nao.end());
        sort(ken.begin(),ken.end());
        i=0;
        j=ken.size()-1;
        for(k=nao.size()-1;k>=0;k--)
        {
            if(nao[k]>ken[j])
            {
                war+=1;
                i++;
            } else {
                j--;
            }
        }
        i=0;
        j=nao.size()-1;
        for(k=ken.size()-1;k>=0;k--)
        {
            if(nao[j]<ken[k])
            {
                i++;
            } else {
                dece++;
                j--;
            }
        }
        cout<<"Case #"<<t<<": "<<dece<<" "<<war<<endl;
        t++;
    }
    return 0;
}
