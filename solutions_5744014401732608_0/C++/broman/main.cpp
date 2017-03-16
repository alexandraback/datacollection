#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void _fill(vector<vector<int>> & xs, int B,int seed)
{
    int dig;
        for(int i=0;i<B-1;i++)
        {
            for(int j=0;j<B-1-i;j++)
            {
                dig=seed%2;
                seed/=2;
                xs[i][j]=dig;
            }
        }
}
int pow2(int p)
{
    int res=1;
    for(int i=0;i<p;i++)
    {
        res*=2;
    }
    return res;
}
vector<vector<int>> mat_prod(vector<vector<int>>& m1,vector<vector<int>>& m2, int B)
{
    vector<vector<int>> res(B-1);
    for(int i=0;i<B-1;i++)
    {
        res[i]=vector<int>(B-1-i,0);
    }
    for(int i=0;i<B-1;i++)
    {
        for(int j=0;j<B-1-i;j++)
        {
            int tmp=0;
            for(int k=i+2;k<=j+i+1;k++)
            {
                tmp+= (m1[i][k-i-2])*(m2[k-1][j+i-k+1]);
            }
            res[i][j]=tmp;
        }
    }
    return res;
}

bool check(vector<vector<int>>& xs, int B, int M)
{
    int numways=0;
    vector<vector<int>> powr(B-1);
    for(int i=0;i<B-1;i++)
    {
        powr[i]=vector<int>(B-1-i);
        for(int j=0;j<B-1-i;j++)
        {
            powr[i][j]=xs[i][j];
        }
    }
    numways+=xs[0][B-2];
    for(int p=2;p<=B-1;p++)
    {
        powr=mat_prod(powr,xs,B);
        numways+=powr[0][B-2];
    }
    return numways==M;
}

pair<bool,int> is_possible(int B, int M)
{
    int dim=(B*(B-1))/2;
    vector<vector<int>> xs(B-1);
    for(int i=0;i<B-1;i++)
    {
        xs[i]=vector<int>(B-1-i);
    }
    for(int seed=0;seed<pow2(dim+1)-1;seed++)
    {
        _fill(xs,B,seed);
        if(check(xs,B,M))
        {
            return make_pair(true,seed);
        }
    }
    return make_pair(false,0);
}

int main()
{
    ifstream in;
    ofstream out;
    in.open("in.in");
    out.open("out.txt");
    int T,B,M;
    in>>T;
    for(int t=1;t<=T;t++)
    {
        in>>B;
        in>>M;
        pair<bool,int> res=is_possible(B,M);
        if(res.first)
        {
            int seed=res.second;
            vector<vector<int>> xs(B-1);
            for(int i=0;i<B-1;i++)
            {
                xs[i]=vector<int>(B-1-i);
            }
            _fill(xs,B,seed);
            out<<"Case #"<<t<<": POSSIBLE"<<endl;
            for(int i=0;i<B-1;i++)
            {
                for(int j=1;j<=B;j++)
                {
                    if(j-i-2>=0)
                        out<<xs[i][j-i-2];
                    else
                        out<<0;

                }
                out<<endl;
            }
            for(int j=0;j<B;j++)
            {
                out<<0;
            }
            out<<endl;
        }
        else
            out<<"Case #"<<t<<": IMPOSSIBLE"<<endl;

    }
//     B=3;
//    vector<vector<int>> xs(B-1);
//    for(int i=0;i<B-1;i++)
//    {
//        xs[i]=vector<int>(B-1-i);
//    }
//    _fill(xs,B,7);
//    cout<<check(xs,B,2)<<" check"<<endl;
//    vector<vector<int>> powr=mat_prod(xs,xs,B);
//    for(int i=0;i<B-1;i++)
//        {
//            for(int j=0;j<B-1-i;j++)
//            {
//                cout<<powr[i][j]<<endl;
//            }
//        }
    in.close();
    out.close();

}
