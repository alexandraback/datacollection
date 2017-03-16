#include<iostream>
#include<fstream>
#include<set>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int main(){
    ifstream  fin("/Users/anupsing/Desktop/GCJ/input.txt");
    ofstream  fout("/Users/anupsing/Desktop/GCJ/output.txt");

    long long T,C,D,V;
    fin>>T;
    int cases=1;
    while(T--) {
            fin>>C>>D>>V;
            set<long long>S;
            for(int i=0;i<D;i++)
               {
                 long long num;
                 fin>>num;
                 S.insert(num);
               }

            long long tot=0;
            long long start=0;
            long long ans=0;
            while(tot<V) {
               //     cout<<start<<" "<<V<<endl;
                bool flag=true;
                start=tot+1;
                if(S.find(start)!=S.end())
                {
                    S.erase(start);
                }
                else ans++;

                tot+=C*start;

                while((S.empty()==false)&&(*S.begin())<=tot)
                {
                    tot+=C*(*S.begin());
                    S.erase(*S.begin());
                }
            }
            fout<<"Case #"<<cases++<<": "<<ans<<endl;




    }
    return 0;
}
