#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
        int T,L,i;
        char str[1005];
        
        cin>>T;
        for(int t=1;t<=T;t++)
        {       cin>>str;
                L=strlen(str);
                int first=1010;
                char S[2020]={0};
                
                S[first]=str[0];
                
                for(i=1 ; i<L ; i++)
                {       if(str[i]<S[first])
                                S[first+i]=str[i];
                        else 
                        {       first--;
                                S[first]=str[i];
                        }
                
                }
                cout<<"Case #"<<t<<": ";
                for(i=first;i<L+first;i++)
                        cout<<S[i];
                cout<<endl;
        }
        return 0;
}
