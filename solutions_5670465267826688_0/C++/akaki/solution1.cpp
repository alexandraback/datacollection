#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

int i,j,k,l,m,n, ans, cur , test,t, mx, a,d, ii,x,r,c;
string str;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w", stdout);
    cin>>t;
    while(t--){
        string s;
        cin>>l>>x;
        cin>>str;
        for (i=0;i<x;i++){
            s+=str;
        }
        test++;
        cout<<"Case #"<<test<<": ";
        char prev = s[0];
        int sign = 1;
        int i_ind=-1, k_ind=-1;
        for (i=1;i<x*l;i++){
            char cur = s[i];
            if (prev=='i' && sign==1 && i_ind==-1){
                i_ind = i-1;
            }
            if (cur == prev){
                prev = '0';
                sign*=-1;
            } else 
            {
                if (prev=='i' && cur == 'j'){
                    prev = 'k';
                } else
                if (prev=='i' && cur == 'k'){
                    prev = 'j';
                    sign*=-1;
                } else
                if (prev=='j' && cur == 'i'){
                    prev = 'k';
                    sign*=-1;
                } else
                if (prev=='j' && cur == 'k'){
                    prev = 'i';
                } else
                if (prev=='k' && cur == 'i'){
                    prev = 'j';
                } else
                if (prev=='k' && cur == 'j'){
                    prev = 'i';
                    sign*=-1;
                } else
                if (prev=='0'){
                    prev = cur;
                }                                                                                                                             
            }
        }
        //cout<<prev<<" "<<sign<<" "<<i_ind<<"\n";
        if (prev!='0' || sign!=-1 || i_ind==-1){
            cout<<"NO\n";
            continue;
        }
        prev = s[x*l-1];
        sign = 1;
        for (i=x*l-2;i>=0;i--){
            char cur = s[i];
            if (prev=='k' && sign==1){
                k_ind = i+1;
                break;
            }
            if (cur == prev){
                prev = '0';
                sign*=-1;
            } else 
            {
                if (cur=='i' && prev == 'j'){
                    prev = 'k';
                } else
                if (cur=='i' && prev == 'k'){
                    prev = 'j';
                    sign*=-1;
                } else
                if (cur=='j' && prev == 'i'){
                    prev = 'k';
                    sign*=-1;
                } else
                if (cur=='j' && prev == 'k'){
                    prev = 'i';
                } else
                if (cur=='k' && prev == 'i'){
                    prev = 'j';
                } else
                if (cur=='k' && prev == 'j'){
                    prev = 'i';
                    sign*=-1;
                } else
                if (prev=='0'){
                    prev = cur;
                }                                                              
            }
        }
        if (i_ind<k_ind) cout<<"YES\n"; else cout<<"NO\n";        
    } 
    return 0;
}
