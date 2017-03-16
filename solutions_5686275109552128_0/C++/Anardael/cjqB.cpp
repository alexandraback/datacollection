#include <fstream>
#include<iostream>
#include <string>
#include<algorithm>
#include<list>
using namespace std;

int solve(list<int>p){
        int maxe=0;
        for (list<int>::iterator i=p.begin();i!=p.end();i++)
            if (*i>maxe)maxe=*i;

        if (maxe<=3) return maxe;
        int ans=999999;
        //cout<<maxe;
        for (int j=1;j<=maxe/2+1;j++){
            int addans=0;
            list<int> q;
            for (list<int>::iterator i=p.begin();i!=p.end();i++)
                if (*i==maxe)
                {
                    q.push_back(j);
                    q.push_back(*i-j);
                    addans++;
                    //break;
                } else q.push_back(*i);

            ans=min(ans,solve(q)+addans);
        }
        return min(maxe,ans);
}


int main(){
    int t;
    ifstream f("input.txt");
    ofstream w("output.txt");
    f>>t;
    for (int tests=0;tests<t;tests++)
    {
        int d;
        f>>d;
        list<int>p;
        for (int i=0;i<d;i++)
        {
            int tmp;
            f>>tmp;
            p.push_back(tmp);
        }
        w<<"Case #"<<(tests+1)<<": "<<solve(p)<<endl;
    }
    f.close();
    w.close();


    return 0;
}

