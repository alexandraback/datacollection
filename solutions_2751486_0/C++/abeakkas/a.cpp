//Google codeJam 2013 Round 1C Problem A
//Abdurrahman Akkas
//recursive fonksiyon yazmayacagima yemin ederim
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int T,i,n,j,k,l,min,ii;
    char ch;
    int cs[100];
    int ls[100];
    int N;
    cin >> T;
    for(i=1;i<=T;i++)
    {
        N=0;
        j=0;
        cin>>ch;
        while(ch!=' '){
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
                cs[j]=0;
            else
                cs[j]=1;
            j++;
            cin>> noskipws >>ch;
        }
        cin>>n;
        l=0;
        min=-1;
        for(k=0;k<j;k++){
            if(cs[k])
                l++;
            else
                l=0;
            if(l>=n)
                min=k-n+1;
            if(min!=-1){
                N+=min+1;
            }
        }
        cout<<"Case #"<<i<<": "<<N<<"\n";
        cin>>ch; 
    }
    cin>>T;
    cin>>T;
    return 0;
}
