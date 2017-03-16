#include<cstdio>
#include<iostream>
#include<string>

 using namespace std;
int main(){


    string s;
	int i,T,cmp,n,c;
    cin>>T;
   for(i=1;i<=T;i++)
    {
        cin>>s;
        cin>>n;
        cmp=0;
        for(int i=0;i<s.length();i++)
            for(int j=i+n;j<=s.length();j++){
                c=0;
                for(int k=i;k<j;k++){
                    if(s[k]=='a' || s[k]=='e' || s[k]=='i'|| s[k]=='o' || s[k]=='u')
                        c=0;
                    else
                        c++;
                    if(c>=n){
                        cmp++;
                        break;
                    }
                }
            }

       cout<<"Case #"<<i<<": "<<cmp<<endl;
    }
}
