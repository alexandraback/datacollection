#include<fstream>
#include<string>
using namespace std;
ifstream cin ("temp.in");
int main ()
{
    freopen ("temp.out","w",stdout);
    int t;
    cin>>t;
    for (int tt=1;tt<=t;tt++)
    {
        int k,l,s;
        cin>>k>>l>>s;
        string keyboard;
        string model;
        cin>>keyboard>>model;
        int num,max;
        double ans;
        for (num=model.size()-1;num>0;num--)
        {
            int i;
            for (i=0;i<num;i++)
                if (model[i]!=model[model.size()-num+i]) break;
            if (i==num) break;
        }
        max=0;
        bool can=true;
        ans=1;
        for (int i=0;i<model.size();i++)
        {
            double count=0;
            for (int j=0;j<keyboard.size();j++)
                if (model[i]==keyboard[j]) count++;
            if (count==0) can=false;
            ans*=count/k;
        }
        if (can) max=(s-l)/(l-num)+1;
        ans*=(s-l+1);
        printf ("Case #%d: %.6lf\n",tt,max-ans);
    }
}
