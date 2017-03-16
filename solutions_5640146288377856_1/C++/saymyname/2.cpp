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

    int T,W,R,C;
    fin>>T;
    int cases=1;
    while(T--) {
            fin>>R>>C>>W;


            int ans=C/W;
            if(C%W) ans++;
            ans=ans*R;
            ans+=(W-1);
            fout<<"Case #"<<cases++<<": "<<ans<<endl;




    }
    return 0;
}
