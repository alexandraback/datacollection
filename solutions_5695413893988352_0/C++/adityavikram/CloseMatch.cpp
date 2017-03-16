#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> cv,jv;

void genC(string init)
{
    if (init.find('?')==string::npos) {
        cv.push_back(init);
        return;
    }
    int pos = init.find('?');
    for (int i=0; i<10; i++) {
        init[pos] = '0'+i;
        genC(init);
    }
    
}

void genJ(string init)
{
    if (init.find('?')==string::npos) {
        jv.push_back(init);
        return;
    }
    int pos = init.find('?');
    for (int i=0; i<10; i++) {
        init[pos] = '0'+i;
        genJ(init);
    }
    
}


int main()
{
    std::ios::sync_with_stdio(false);
    int t,T;
    cin >> T;
    for (t=0; t<T; t++)
    {
        cv = vector<string>();
        jv = vector<string>();
        string c,j;
        cin>>c>>j;
        int sz = c.size(),i;
        genC(c);
        genJ(j);
        bool first = true;
        pair<string,string> ans;
        int bd,bc,bj;
        for (string x:cv)
        {
            for (string y:jv)
            {
                //cout<<x<<':'<<y<<endl;
                if (first)
                {
                    ans = make_pair(x,y);
                    bd = abs(stoi(x)-stoi(y));
                    bc = stoi(x);
                    bj = stoi(y);
                    first = false;
                }
                else
                {
                    int cd,cc,cj;
                    cd = abs(stoi(x)-stoi(y));
                    cc = stoi(x);
                    cj = stoi(y);
                    //cout<<x<<':'<<y<<':'<<cd<<":"<<bd<<endl;
                    if (cd<bd) {
                        ans = make_pair(x,y);
                        bd = abs(stoi(x)-stoi(y));
                        bc = stoi(x);
                        bj = stoi(y);
                    }
                    else if((cd==bd)&&(cc<bc))
                    {
                        ans = make_pair(x,y);
                        bd = abs(stoi(x)-stoi(y));
                        bc = stoi(x);
                        bj = stoi(y);
                    }
                    else if((cd==bd)&&(cc==bc)&&(cj<bj))
                    {
                        ans = make_pair(x,y);
                        bd = abs(stoi(x)-stoi(y));
                        bc = stoi(x);
                        bj = stoi(y);
                    }
                    
                    
                }
            }
        }
        cout <<"Case #"<<t+1<<": "<< ans.first<<' '<<ans.second <<endl;
    }
    return 0;
}

