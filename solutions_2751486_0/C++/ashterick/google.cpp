#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int t,n;
    scanf("%d",&t);
    string a;
    for(int q=1;q<=t;q++)
    {
            cin>>a;
            scanf("%d",&n);
            int l=a.length();
            int count=0;
            string tmp;
            for(int i=0;i<l;i++)
            {
                    for(int j=i;j<l;j++)
                    {
                            int len=j-i+1;
                            int ct=0;
                            tmp=a.substr(i,len);
                            for(int k=0;k<len;k++)
                            {
                                    
                                    if(tmp[k]=='a'||tmp[k]=='e'||tmp[k]=='i'||tmp[k]=='o'||tmp[k]=='u')
                                               ct=0;
                                    else
                                               ct++;
                                    
                                    if(ct>=n)
                                    {
                                             count++;
                                             break;
                                    }                                                                                                                                         
                            }
                            //cout<<tmp<<" "<<count<<endl;
                    }
            }
            printf("Case #%d: %d\n",q,count);
    }
    return 0;
}
