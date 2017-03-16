#include <fstream>
#include <string>
#include <map>
using namespace std;
typedef pair<int,char> mt;

pair<int,char> calc(pair<int,char> a, pair<int,char> b){
 pair<int,char> res;
 res.first = a.first*b.first;
 if (a.second=='1'||b.second=='1') res.second=(a.second=='1')?b.second:a.second;
 else
     if (a.second==b.second) res.second='1',res.first*=-1; else
         if (a.second=='j'){
             if (b.second=='i') res.second='k',res.first*=-1; else res.second='i';
         } else
             if (a.second=='i'){
                 if (b.second=='k') res.second='j',res.first*=-1; else res.second='k';
             } else
                 if (a.second=='k'){
                     if (b.second=='j') res.second='i',res.first*=-1; else res.second='j';
                 }
 return res;
}
mt st[10001],fs[10001];
int main(){
    int t;
    ifstream f("input.txt");
    ofstream w("output.txt");
    f>>t;
    for (int tests=0;tests<t;tests++)
    {
        long long int L,X;
        f>>L>>X;
        string s;
        f>>s;
        int ans;
        st[0]={1,s[0]};
        for (int i=1;i<L;i++){
            st[i]=calc(st[i-1],{1,s[i]});
        }
        if (X%2&&st[L-1].second!='1'){
            w<<"Case #"<<(tests+1)<<": "<<"NO"<<endl;
            continue;
        }
        if (st[L-1].second=='1'&&st[L-1].first==1){
            w<<"Case #"<<(tests+1)<<": "<<"NO"<<endl;
            continue;
        } else
        if (st[L-1].second=='1'&&st[L-1].first==-1){
            if (X%2==0){
                w<<"Case #"<<(tests+1)<<": "<<"NO"<<endl;
                 continue;
            }
        } else
        if (X==1){
            if (X%2&&st[L-1].first!=-1){
                w<<"Case #"<<(tests+1)<<": "<<"NO"<<endl;
                continue;
            }
        }else
        if (X%2){
            if (X/2%2&&st[L-1].first!=1){
                w<<"Case #"<<(tests+1)<<": "<<"NO"<<endl;
                continue;
            } else
                if (X/2%2==0&&st[L-1].first!=-1){
                    w<<"Case #"<<(tests+1)<<": "<<"NO"<<endl;
                    continue;
                }
        } else{
                if (X/2%2==0){
                    w<<"Case #"<<(tests+1)<<": "<<"NO"<<endl;
                    continue;
                }
        }
        string sml="ijk";
        int i=0;
        int k=0;
        mt cur={1,s[0]};
        int step=0;
        while (X&&k<3&&step<3){
            i++;
            if (i==L){
                X--;
                step++;
                i=0;
            }
            if (sml[k]==cur.second){
                k++;
                cur={cur.first,s[i]};
                step=0;
            } else cur=calc(cur,{1,s[i]});
        }
        if (step>2){
            w<<"Case #"<<(tests+1)<<": "<<"NO"<<endl;
            continue;
        }
        i++;
        while (i<L){
            cur=calc(cur,{1,s[i]});i++;
        }
        X--;
        if (X%2&&calc(cur,st[L-1]).second!='1'){
            w<<"Case #"<<(tests+1)<<": "<<"NO"<<endl;
            continue;
        }
        if (X%2==0&&cur.second!='1'){
            w<<"Case #"<<(tests+1)<<": "<<"NO"<<endl;
            continue;
        }

        w<<"Case #"<<(tests+1)<<": "<<"YES"<<endl;
    }
    f.close();
    w.close();


    return 0;
}

