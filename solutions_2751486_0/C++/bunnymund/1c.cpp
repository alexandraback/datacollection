#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int main(){
    // freopen("C:\\Users\\DELL\\Desktop\\input.txt","r",stdin); 
    // freopen("C:\\Users\\DELL\\Desktop\\output.txt","w",stdout);
    int test,c=1,ans,n,count;
    string s;   
    scanf("%d",&test);
    while(test--){
        ans=0;
        cin>>s;
        scanf("%d",&n);
        for(int i=0;i<s.length();i++)
            for(int j=i+n;j<=s.length();j++){
                count=0;
                for(int m=i;m<j;m++)
                {
                    if(s[m]=='a' || s[m]=='e' || s[m]=='i'|| s[m]=='o' || s[m]=='u')
                        count=0;
                    else
                        count++;
                    if(count>=n){
                        ans++;
                        break;
                    }
                }
            }
 
        printf("Case #%d: %d\n",c++,ans);
    }
}
 
