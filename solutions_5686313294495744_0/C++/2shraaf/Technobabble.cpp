

#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fs first
#define sc second
typedef long long ll;
bool isthi(vector<pair<string,string> > org , pair<string,string>thi){
    for(int i = 0 ;i<org.size();i++){
        if(org[i].fs.compare(thi.fs)==0 ){
            for(int j = 0 ;j<org.size();j++){
                    if(org[j].sc.compare(thi.sc)==0 && i!=j)
                        return 1;


            }

        }

    }
    return 0;

}


bool validate(vector<pair<string,string> > org , vector<pair<string,string> > thi){
    bool tr = 1;
    for(int i = 0 ; i< thi.size();i++){
        tr&=isthi(org ,thi[i]);
    }
//    for(int i = 0 ; i< org.size();i++){
//        tr&= !isthi(org ,org[i]);
//    }
    return tr;

}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
        freopen ("file.out","w",stdout);
        freopen ("file.in","r",stdin);
        int t ;
        string s1,s2;

        cin>>t;
        for(int p =1 ; p<=t ;p++){
            int n ,ans = 0;
            cin>>n;
            vector<pair<string ,string> > v;
            for(int i = 0 ;i<n;i++){
                cin>>s1>>s2;
                v.push_back(make_pair(s1,s2));
            }
            for(int i = 0 ;i<(1<<n);i++){
                vector<pair<string ,string> > org ;
                vector<pair<string ,string> > thi ;
                for(int j = 0 ; j<n ; j++){
                    if((1<<j)&i){
                        thi.push_back(v[j]);

                    }else{
                        org.push_back(v[j]);
                    }

                }
                bool vl =validate(org,thi);
                if(vl){
                    ans = max(ans,(int)thi.size());
                }



            }
            cout<<"Case #"<<p<<": ";
            cout<<ans<<'\n';



        }

    return 0;

}

