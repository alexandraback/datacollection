#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int dig(int n){
    int ans=0;
    if(n==0)
        return 1;
    while(n>0){
        ans++;
        n/=10;
    }
    return ans;
}

int main(){
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t;
    cin>>t;


    for(int k=1; k<=t; k++){

        string S, T;
        cin>>S>>T;
        //vector<int>ans1, ans2;
        int l=0, r=0, ans1, ans2;
        for(int i=0; i<S.size(); i++)
            if(S[i]=='?') l++;
        for(int i=0; i<T.size(); i++)
            if(T[i]=='?') r++;
        if(r==1)
            r=10;
        else if(r==100){
            r=100;
        }
        else r=1000;
        if(l==1)
            l=10;
        else if(l==2) l=100;
        else l=1000;
        //cout<<l<<endl;
        int ans=INT_MAX;
        for(int i=0; i<l; i++){
            int d1=(i%100)/10, d2=i%10, d3, d4, d5, d6;
            d5=i/100;
            for(int j=0; j<r; j++){
                d3=(j%100)/10; d4=j%10;
                int num1=0, num2=0, c=0;
                d6=j/100;
               // cout<<d1<<" "<<d2<<" "<<d3<<" "<<d4<<endl;

                for(int p=0; p<S.size(); p++){
                    if(S[p]=='?'){
                        if(c==0 && l==1000)
                        {
                            num1=num1*10+d5, c=1;
                        }
                        else if(c==0 && l==100 || c==1)
                            num1=num1*10+d1, c=2;
                        else{
                            num1=num1*10+d2;
                            //cout<<"aa\n";
                        }
                    }
                    else{
                        num1=num1*10+S[p]-'0';
                    }
                }
                c=0;
                for(int p=0; p<T.size(); p++){
                    if(T[p]=='?'){
                        if(c==0 && r==1000)
                        {
                            num2=num2*10+d6, c=1;
                        }
                        else if(c==0 && r==100 || c==1)
                        {
                            //cout<<"in\n";
                            num2=num2*10+d3, c=2;
                        }
                        else{
                            num2=num2*10+d4;

                        }
                    }
                    else{
                        num2=num2*10+T[p]-'0';
                    }
                }
                if(abs(num1-num2)<ans){
                    ans1=num1; ans2=num2;
                    ans=abs(num1-num2);
                }
                else if(abs(num1-num2)==ans){
                    if(num1<ans1){
                        ans1=num1; ans2=num2;
                    }
                    else if(num1==ans1){
                        ans2=min(ans2, num2);
                    }
                }
                //cout<<num1<<" "<<num2<<endl;
            }

        }
        cout<<"Case #"<<k<<": ";
        if(dig(ans1)<S.size()){
            for(int i=0; i<S.size()-dig(ans1); i++)
                cout<<"0";
        }
        cout<<ans1<<" ";
        if(dig(ans2)<T.size()){
            for(int i=0; i<T.size()-dig(ans2); i++)
                cout<<"0";
        }
        cout<<ans2;

        cout<<endl;
    }

    return 0;
}
