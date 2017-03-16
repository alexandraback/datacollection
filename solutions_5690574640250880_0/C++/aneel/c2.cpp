#include <iostream>
#include <cstring>
using namespace std;

char ms[51][51];
char ms1[51][51];

int r, c, m,
    r1,c1;

void cleanIt() {
    for(int i = 0; i < r; ++i) {
        memset(ms[i],0,sizeof(char)*c);
    }
}
void printIt(char arr[51][51]) {
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            cout<<(int)arr[i][j];
        }
        cout<<endl;
    }
}

void printItCh(char arr[51][51]) {
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}
void copyIt(char ms1[51][51]) {
    for(int i = 0; i < r; ++i)
    {
        memcpy(ms1[i],ms[i],sizeof(char)*c);
    }
}
void zeroToNegR(int i, int j, char arr[51][51])
{
    if(i > 0 && arr[i-1][j] == 0)   {arr[i-1][j]=-1;zeroToNegR(i-1,j,arr);}
    if(i < r1 && arr[i+1][j] == 0)  {arr[i+1][j]=-1;zeroToNegR(i+1,j,arr);}
    if(j > 0 && arr[i][j-1] == 0)   {arr[i][j-1]=-1;zeroToNegR(i,j-1,arr);}
    if(j < c1 && arr[i][j+1] == 0)  {arr[i][j+1]=-1;zeroToNegR(i,j+1,arr);}
    if(i > 0 && j > 0 && arr[i-1][j-1] == 0)    {arr[i-1][j-1]=-1;zeroToNegR(i-1,j-1,arr);}
    if(i < r1 && j < c1 && arr[i+1][j+1] == 0)  {arr[i+1][j+1]=-1;zeroToNegR(i+1,j+1,arr);}
    if(i > 0 && j < c1 && arr[i-1][j+1] == 0)   {arr[i-1][j+1]=-1;zeroToNegR(i-1,j+1,arr);}
    if(i < r1 && j > 0 && arr[i+1][j-1] == 0)   {arr[i+1][j-1]=-1;zeroToNegR(i+1,j-1,arr);}
}
void zeroToNeg(char arr[51][51])
{
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            if(arr[i][j]==0)
            {
                arr[i][j]=-1;
                zeroToNegR(i,j,arr);
                return ;
            }
        }
    }
}
void negToZero(char arr[51][51])
{
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            if(arr[i][j]==-1)
            { 
                arr[i][j]=0;
            }
        }
    }
}
bool verify(char arr[51][51]) {
    zeroToNeg(arr);
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            if(arr[i][j]==0)
            {
                return false;
            }
        }
    }
    negToZero(arr);
    
    bool zeroFound = false;
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            if(arr[i][j]==1)
            {
                bool res=
                (i > 0 && arr[i-1][j] == 0) ||
                (i < r1 && arr[i+1][j] == 0) ||
                (j > 0 && arr[i][j-1] == 0) ||
                (j < c1 && arr[i][j+1] == 0) ||
                (i > 0 && j > 0 && arr[i-1][j-1] == 0) ||
                (i < r1 && j < c1 && arr[i+1][j+1] == 0) ||
                (i > 0 && j < c1 && arr[i-1][j+1] == 0) ||
                (i < r1 && j > 0 && arr[i+1][j-1] == 0) ;
                //cout<<endl<<i<<" "<<j<<endl;
                if(!res) return false;
                //cout<<"("<<res<<")";
            }
            else if(!zeroFound && arr[i][j]==0) zeroFound = true;
        }//cout<<endl;
    }//cout<<endl;
    if(!zeroFound) return false;
    
    return true;
}
void decorate(char arr[51][51]) {
    bool zeroFound = false;
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            if(arr[i][j]==2)arr[i][j]='*';
            else if(arr[i][j]==1)arr[i][j]='.';
            else if(arr[i][j]==0) {
                if(!zeroFound) {
                    arr[i][j]='c';
                    zeroFound = true;
                }
                else arr[i][j]='.';
            }
        }
    }
}
void revealR(int i, int j, char arr[51][51])
{   
    //cout<<i<<" "<<j<<endl;
    arr[i][j]='_';
    int weight=0;
	if(i > 0){
        if(arr[i-1][j] == '*') weight++;
        else if(arr[i-1][j]=='.') revealR(i-1,j,arr);
    }
    if(i < r1){
        if(arr[i+1][j] == '*') weight++;
        else if(arr[i+1][j]=='.') revealR(i+1,j,arr);
    }
    if(j > 0){
        if(arr[i][j-1] == '*') weight++;
        else if(arr[i][j-1]=='.') revealR(i,j-1,arr);
    }
    if(j < c1) {
        if(arr[i][j+1] == '*') weight++;
        else if(arr[i][j+1]=='.') revealR(i,j+1,arr);
    }
    if(i > 0 && j > 0 ){
        if(arr[i-1][j-1] == '*') weight++;
        else if(arr[i-1][j-1]=='.') revealR(i-1,j-1,arr);
    }
    if(i < r1 && j < c1){
        if(arr[i+1][j+1] == '*') weight++;
        else if(arr[i+1][j+1]=='.') revealR(i+1,j+1,arr);
    }
    if(i > 0 && j < c1){
        if(arr[i-1][j+1] == '*') weight++;
        else if(arr[i-1][j+1]=='.') revealR(i-1,j+1,arr);
    }
    if(i < r1 && j > 0){
        if(arr[i+1][j-1] == '*') weight++;
        else if(arr[i+1][j-1]=='.') revealR(i+1,j-1,arr);
    }
    arr[i][j] = weight;
}
void reveal(char arr[51][51])
{
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            if(arr[i][j]=='c')
            {
                arr[i][j]=-1;
                revealR(i,j,arr);
                j=c;
                i=r;
            }
        }
    }
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            if(arr[i][j]=='*') arr[i][j]=9;
        }
    }
}
bool recursive(int k, int mines) {
    if(k>=c*r)return false;
    if(mines == m)
    {
        copyIt(ms1);
		for(int i = 0; i < r; ++i)
        {
            for(int j = 0; j < c; ++j)
            {
                if(ms1[i][j]==2) {
                    if(i > 0 && ms1[i-1][j] == 0) {ms1[i-1][j]=1;}
                    if(i < r1 && ms1[i+1][j] == 0) ms1[i+1][j]=1;
                    if(j > 0 && ms1[i][j-1] == 0) ms1[i][j-1]=1;
                    if(j < c1 && ms1[i][j+1] == 0) ms1[i][j+1]=1;
                    if(i > 0 && j > 0 && ms1[i-1][j-1] == 0) ms1[i-1][j-1] = 1;
                    if(i < r1 && j < c1 && ms1[i+1][j+1] == 0) ms1[i+1][j+1] = 1;
                    if(i > 0 && j < c1 && ms1[i-1][j+1] == 0) ms1[i-1][j+1] = 1;
                    if(i < r1 && j > 0 && ms1[i+1][j-1] == 0) ms1[i+1][j-1] = 1;
                }
                //cout<<(int)ms1[i][j];
            }//cout<<endl;
        }//cout<<endl;
        if( verify(ms1) )
        {
            decorate(ms1);
            printItCh(ms1);
            
            return true;
        }
        return false;
    }

    int i=k/c, j = k%c;
    ms[i][j] = 2;
    if( recursive(k+1,mines+1) ) return true;
    ms[i][j] = 0;
    if( recursive(k+1,mines) ) return true;
    
    return false;
}
int main()
{
    int T;
    cin>>T;
    for(int ti = 1; ti <= T; ++ti) 
    {
        cout<<"Case #"<<ti<<":\n";
        cin>>r>>c>>m;
        r1 = r-1;
        c1 = c-1;
        cleanIt();

       // 
        if(!recursive(0,0)) {
            //cout<<"Case #"<<ti<<": ";
            //cout<<r<<" "<<c<<" "<<m<<"\n";
            cout<<"Impossible\n";
        }
        else {
            //reveal(ms1);
            //printIt(ms1);
            //cout<<endl;
        }
    }
}
