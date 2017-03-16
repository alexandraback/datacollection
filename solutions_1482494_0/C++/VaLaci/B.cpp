#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void swap(int &x,int &y)
{
    int cs=x;
    x=y;
    y=cs;
}
int main()
{
    ifstream be("jamB.be");
    ofstream ki("jamB.ki");
    int t;
    be>>t;
    for(int testcase=1;testcase<=t;testcase++)
    {
        //cout<<endl;
        int n;
        be>>n;
        int f[n],s[n];
        bool done[n][2];
        for(int i=0;i<n;++i)
            be>>f[i]>>s[i];
        for(int i=0;i<n;++i)
            for(int j=0;j<i;++j)
                if(s[i]>s[j])
                {
                    swap(s[i],s[j]);
                    swap(f[i],f[j]);
                }
        for(int i=0;i<n;++i)
        {
            done[i][0]=false;
            done[i][1]=false;
        }
//        bool end=false;
        int stars=0,l=0;
        bool comp=true;
        while(comp)
        {
            comp=false;
            for(int i=0;i<n;++i)
                if(!comp && !done[i][1] && s[i]<=stars)
                {
                    comp=true;
                    if(done[i][0])
                        stars+=1;
                    else
                        stars+=2;
                    done[i][1]=true;
                    done[i][0]=true;
                    //cout<<f[i]<<s[i]<<" 2"<<endl;
                }
            //cout<<stars<<" "<<f[0]<<endl;
            for(int i=0;i<n;++i)
                if(!comp && !done[i][0] && f[i]<=stars)
                {
                    comp=true;
                    stars+=1;
                    done[i][0]=true;
                    //cout<<f[i]<<s[i]<<" 1"<<endl;
                }
            l++;
        }
        bool end=true;
        for(int i=0;i<n;++i)
            end=end && done[i][1];
        if(end)
            ki<<"Case #"<<testcase<<": "<<l-1<<endl;
        else
            ki<<"Case #"<<testcase<<": Too Bad"<<endl;

    }
    be.close();
    ki.close();
    return 0;
}
