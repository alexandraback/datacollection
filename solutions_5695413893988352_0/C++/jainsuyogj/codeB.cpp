#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define mat 1000006
char arr[26],brr[26];
int mn;
string a,b;
int l;
void rec(int ind)
{
    if(ind==l){
        int fir,sec;
        string st(brr),ft(arr);
       // cout<<ft<<" "<<st<<endl;
        fir=stoi(ft);
        sec=stoi(st);
        int diff=abs(fir-sec);
        if(diff<mn){
            mn=diff,a=ft,b=st;
            return ;
        }
        return ;
    }
    if(arr[ind]=='?'){
        if(brr[ind]=='?'){
            for(int i=0;i<10;i++){
                for(int j=0;j<10;j++){
                    arr[ind]='0'+i;
                    brr[ind]='0'+j;
                    rec(ind+1);
                }

            }
            brr[ind]='?';
        }
        else{
            for(int i=0;i<10;i++){
                arr[ind]='0'+i;
                rec(ind+1);
            }
        }
        arr[ind]='?';
    }
    else if(brr[ind]=='?'){
        for(int i=0;i<10;i++){
            brr[ind]='0'+i;
            rec(ind+1);
        }
        brr[ind]='?';
    }
    else{
        rec(ind+1);
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int ii=1;ii<=t;ii++)
    {
        cin>>arr>>brr;

        l=0;
        while(arr[l]!='\0')
            l++;
        //cout<<arr<<" "<<brr<<" "<<l<<endl;
        mn=2000;
        rec(0);
        cout<<"Case #"<<ii<<": "<<a<<" "<<b<<endl;
    }
}
