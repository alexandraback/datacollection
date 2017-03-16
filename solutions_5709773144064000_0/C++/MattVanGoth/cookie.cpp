#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        long double c,f,x,i=2,w=0;
        cin>>c>>f>>x;
        cout<<fixed;
        cout.precision(7);
        while(true)
        {
            long double t1,t2;
            t1=x/i;
            t2=x/(i+f)+c/i;
            if(t2<t1)
            {
                w+=c/i;
                i+=f;
            }
            else
            {
                w+=t1;
                break;
            }
        }
        cout<<"Case #"<<z+1<<": ";
        cout<<w<<endl;
    }
    return 0;
}
