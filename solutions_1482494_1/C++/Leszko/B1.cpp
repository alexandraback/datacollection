#include<iostream>
#include<algorithm>
using namespace std;

struct lev
{
    int a;
    int b;
    int i;
};

lev A[1001];
lev B[1001];

bool level[1001][2];

bool sorta(lev a, lev b)
{
    if(a.a!=b.a)
        return a.a<b.a;
    
    return
        a.b>b.b;
}

bool sortb(lev a, lev b)
{
    return a.b<b.b;
}



int main()
{
    ios_base::sync_with_stdio(0);
    
    int Z;
    cin >> Z;
    
    for(int z=1; z<=Z; z++)
    {
        int n;
        cin >> n;
        
        for(int i=0; i<n; i++)
        {
            level[i][0]=level[i][1]=false;
            
            cin >> A[i].a;
            cin >> A[i].b;
            A[i].i=i;
            
            B[i]=A[i];
        }
        
//        cout << "sth" << endl;
        sort(A, A+n, sorta);
        sort(B, B+n, sortb);

        int stars=0;
        
        int i=0;
        int j=0;
        bool flag=true;
        int res=0;
        
        while(stars<2*n)
        {
            while(j<n && stars>=B[j].b)
            {
                //cout << i << " " << A[i].a << "   " << j << " " << B[j].b << endl;
                
                
                if(level[B[j].i][1])
                    j++;
                
                else
                {
                    if(level[B[j].i][0])
                        stars++;
                    
                    else
                        stars+=2;
                    
                    level[B[j].i][1]=level[B[j].i][0]=true;
                    j++;
                    res++;
                }
            }
            
            if(i<n)
            {
                while(i<n && level[A[i].i][0])
                    i++;
                
                if(j<n && i>=n)
                {
                    flag=false;
                    break;
                }
                
                else if(i>=n)
                    break;
                
                if(stars<A[i].a)
                {
                    flag=false;
                    break;
                }
                
                else
                {
                    stars++;
                    level[A[i].i][0]=true;
                    i++;
                    res++;
                }
            }
            
            else if(j<n && i>=n)
            {
                flag=false;
                break;
            }
        }
        
        
        cout << "Case #" << z << ": ";
        
        if(!flag)
            cout << "Too Bad" << endl;
        
        else
            cout << res << endl;
        
        

        
    }

return 0;
}
