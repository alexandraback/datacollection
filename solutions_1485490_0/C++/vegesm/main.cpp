#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

vector<long long> boxes;
vector<int> bt,tt;
vector<long long> toys;

map<long long, long long> tnul[100][100];
map<long long, long long> bnul[100][100];

long long maxv(int ts, long long tid, int bs, long long bid )
{
    //cout<<"ts="<<ts<<" tid="<<tid<<" bs="<<bs<<" bid="<<bid<<endl;

    if(bs>=bt.size() || ts>=tt.size()) return 0;

    if(tid==0) {
        if(tnul[ts][bs].count(bid)>0){
            return tnul[ts][bs][bid];
        }
    }
    if(bid==0) {
        if(bnul[ts][bs].count(tid)>0) return bnul[ts][bs][tid];
    }
    //nem találta
    long long maxc=0;
    //játék ill
    for(int i=bs;i<bt.size();i++)
    {
        if(bt[i]==tt[ts])
        {
            long long ujbid=(i==bs ? bid : 0);
            long long bleft=boxes[i]-ujbid ;
            long long tleft=toys[ts]-tid;
            long long val=0;
            //cout/*<<"ts="<<ts<<" tid="<<tid<<" bs="<<bs<<" bid="<<bid*/<<"i="<<i<<endl;
            if(bleft<tleft) val=bleft+maxv(ts,tid+bleft,i+1,0);
            if(bleft==tleft) val=bleft+maxv(ts+1,0,i+1,0);
            if(bleft>tleft) val=tleft+maxv(ts+1,0,i, ujbid+tleft);
            //cout<<"ts="<<ts<<" tid="<<tid<<" bs="<<bs<<" bid="<<bid<<" i"<<endl;
            maxc=max(maxc,val);
            break;
        }
    }

    //doboz ill
    for(int i=ts;i<tt.size();i++)
    {
        if(tt[i]==bt[bs])
        {
            long long ujtid=(i==ts ? tid : 0);
            long long bleft=boxes[bs]-bid ;
            long long tleft=toys[i]-ujtid;
            long long val=0;
            //cout/*<<"ts="<<ts<<" tid="<<tid<<" bs="<<bs<<" bid="<<bid*/<<"i="<<i<<endl;
            if(bleft<tleft) val=bleft+maxv(i,ujtid+bleft,bs+1,0);
            if(bleft==tleft) val=bleft+maxv(i+1,0,bs+1,0);
            if(bleft>tleft) val=tleft+maxv(i+1,0,bs, bid+tleft);
            //cout<<"ts="<<ts<<" tid="<<tid<<" bs="<<bs<<" bid="<<bid<<" i"<<endl;
            maxc=max(maxc,val);
            break;
        }
    }


    //egyéb
    maxc=max(maxc,maxv(ts+1,0,bs+1,0));
    if(tid==0) {
        tnul[ts][bs][bid]=maxc;
    }
    if(bid==0) {
        bnul[ts][bs][tid]=maxc;
    }
    return maxc;
}

void megold(istream& in, ostream &out)
{
    int n,m;
    in>>n>>m;
    bt.clear(); tt.clear();
    boxes.clear(); toys.clear();
    boxes.resize(n); bt.resize(n);
    for(int i=0;i<n;i++)
    {
        in>>boxes[i];
        in>>bt[i];
    }

    toys.resize(m); tt.resize(m);
    for(int i=0;i<m;i++)
    {
        in>>toys[i];
        in>>tt[i];
    }

    /*for(int i=0;i<toys.size();i++)
    {
        cout<<toys[i]<<' ';
    }*/

    for(int i=0;i<toys.size();i++)
    {
        for(int j=0;j<boxes.size();j++)
        {
            tnul[i][j].clear();
            bnul[i][j].clear();
        }
    }
    out<<maxv(0,0,0,0);
}

int main()
{
    ifstream in("C-small-attempt0.in");
    ofstream out("box.out");
    int n;
    in>>n;
    //out<<setprecision(9);
    for(int i=1; i<=n; i++)
    {
        out<<"Case #"<<i<<": ";
        megold(in, out);
        out<<endl;
    }
    in.close();
    out.close();
    return 0;
}
