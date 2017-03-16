#include <iostream>

using namespace std;

int T,Case,X,R,C;

int enum_all[4][4][4]={
    //1
    {
        {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}
    },
    //2
    {
        {1,0,1,0},{0,0,0,0},{1,0,1,0},{0,0,0,0}
    },
    //3
    {
        {1,1,1,1},{1,1,0,1},{1,0,0,0},{1,1,0,1}
    },
    //4
    {
        {1,1,1,1},{1,1,1,1},{1,1,1,0},{1,1,0,0}
    }
};

int main(int argc, char const *argv[])
{
    cin>>T;
    string ans[2]={"GABRIEL","RICHARD"};
    for(Case=1;Case<=T;++Case){
        cin>>X>>R>>C;
        cout<<"Case #"<<Case<<": "<<ans[enum_all[X-1][R-1][C-1]]<<endl;
    }
    return 0;
}
