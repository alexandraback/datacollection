#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<fstream>

using namespace std;

int main(){
    ifstream fin("B-small-4.in");
    ofstream fout("B-small-4.out");

    int t;
    fin>>t;
    for(int e=1;e<=t;e++){
        string key,target;
        int k,l,s;
        fin>>k>>l>>s;
        fin>>key;
        fin>>target;
        //if(s<l){fout<<"Case #"<<e<<": 0.0\n";continue;}

        int in[27]={0};
        bool done=0;
        for(int i=0;i<key.size();i++){
            in[key[i]-'A']++;
        }
        for(int i=0;i<target.size();i++){
            if(in[target[i]-'A']==0){
                fout<<"Case #"<<e<<": 0.0\n";done=1;break;
            }
        }
        if(done)continue;
        // p = in[i]/key.size()
        double ocur=s-l+1;

        for(int i=0;i<target.size();i++){
            ocur=(ocur/k)*in[target[i]-'A'];
        }
        //cout<<key<<endl;
        //cout<<ocur<<endl;
        //divide me keysize^target.size
        //k^l
        int x=0;
        for(int i=1;i<l;i++){
            //check if 2 words same
            int len=l-1;
            bool ok=1;
            while(len>=i){
                if(target[len]!=target[len-i]){ok=0;break;}
                len--;
            }
            if(ok){
                x=l-i;break;
            }
        }
        //
        //cout<<x<<endl;
        //if(x==0)x=l;
        double Max=floor((double)(s-x)/(l-x));
        fout<<"Case #"<<e<<": ";
        fout.precision(7);
        //if(abs((Max-ocur)-(int)(Max-ocur))<1e-7)fout<<Max-ocur<<".0\n";
        double intpart;
        if(modf(Max-ocur, &intpart) <1e-7)fout<<Max-ocur<<".0\n";
        else fout<<Max-ocur<<"\n";

    }

    fin.close();
    fout.close();
    return 0;
}
