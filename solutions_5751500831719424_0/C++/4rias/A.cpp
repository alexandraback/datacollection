#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define MAX 1000000


template<class T>
int toInt(T t){stringstream ss;ss<<t;int r;ss>>r;return r;}
template<class T>
string toStr(T t){stringstream ss;ss<<t;string r;ss>>r;return r;}

vector<string> con(string a){
    vector<string> r;
    
    for(int i=0;i<a.size();i++){
        string t;
        //t+=a[i];
        char at = a[i];
        while(i<a.size() and a[i]==at){
            t += a[i];
            i++;
            
        }
       
        i--;
        r.pb(t);
    }
   /* cout<<"Conver"<<endl;
    for(int i=0;i<r.size();i++){
        cout<<r[i]<<endl;
    }
    */
    return r;
    
}

int main(){
    int n,nc=0,np;cin>>n;
    string s;
    while(n--){
        cin>>np;
        vector<vector<string> > palabras;
        for(int i=0;i<np;i++){
            cin>>s;
            palabras.pb(con(s));
        }
        int sol = 0;
        bool bb = 0;
        
        for(int i=0;i<palabras.size() and !bb;i++){
            //int solt=0;
            for(int j=i+1;j<palabras.size() and !bb;j++){
                if(i==j)continue;
                if(palabras[i].size()!= palabras[j].size()){
                    bb=1;
                    break;
                }
                for(int k=0;k<palabras[i].size() and !bb;k++){
                    if(palabras[i][k][0] != palabras[j][k][0]){
                        bb=1;
                        break;
                    }
                }
            }       
            
        }
        cout<<"Case #"<<++nc<<": ";
        if(bb){
            cout<<"Fegla Won"<<endl;
        }else{
            for(int k=0;k<palabras[0].size();k++){
                int mint = MAX;
                for(int i=0;i<palabras.size();i++){
                    int mi = 0;
                    for(int j=0;j<palabras.size();j++){
                        if(i!=j){
                            int s1 = palabras[i][k].size();
                            int s2 = palabras[j][k].size();
                            mi += abs(s1-s2);
                        }
                    }
                    mint = min (mint,mi);
                }
                sol+=mint;
            }
            cout<<sol<<endl;
        }
    }
}
