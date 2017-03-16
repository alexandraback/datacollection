#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long A[101];
long long B[101];

long long a[101];
long long b[101];



int main()
{
    ios_base::sync_with_stdio(0);
    
    int Z;
    cin >> Z;
    
    for(int z=1; z<=Z; z++)
    {
        
        int n;
        cin >> n;
        
        int m;
        cin >> m;
        
        for(int i=1; i<=n; i++)
        {
            cin >> a[i];
            cin >> A[i];
        }
        
        for(int i=1; i<=m; i++)
        {
            cin >> b[i];
            cin >> B[i];
        }
        
        
        
        
        unsigned long long result=0;
        unsigned long long R=0;
        
        for(int x=1; x<=n; x++)
        {
            int i=x;
            long long wart=a[i];
            result=0;
            
            for(int j=1; j<=m; j++)
            {
                if(A[i]==B[j] && wart>b[j])
                {
                    result+=b[j];
                    wart-=b[j];
                }
                
                else if(A[i]==B[j])
                {
                    result+=wart;
                    i++;
                    wart=a[i];
                    if(i>3)
                        break;
                }
                
//                cout << "x " << x << endl;
//                cout << "i " << i << endl;
//                cout << "j " << j << endl;
//                cout << "wart " << wart << endl;
//                cout << "result " << result << endl << endl;
            }
            
            R=max(result, R);
        }
        
        
        for(int x=1; x<=n; x++)
        {
            int i=x;
            long long wart=a[i];
            result=0;
            
            for(int j=1; j<=m; j++)
            {
                if(A[i]==B[j] && wart>b[j])
                {
                    result+=b[j];
                    if(i<3)
                    {
                        i++;
                        wart=a[i];
                    }
                    
                    else
                        wart-=b[j];
                }
                
                else if(A[i]==B[j])
                {
                    result+=wart;
                    i++;
                    wart=a[i];
                    if(i>3)
                        break;
                }
                
//                cout << "x " << x << endl;
//                cout << "i " << i << endl;
//                cout << "j " << j << endl;
//                cout << "wart " << wart << endl;
//                cout << "result " << result << endl << endl;
            }
            
            R=max(result, R);
        }
        

        for(int x=1; x<=n; x++)
        {
            int i=x;
            long long wart=a[i];
            result=0;
            
            for(int j=1; j<=m; j++)
            {
                if(A[i]==B[j] && wart>b[j])
                {
                    result+=b[j];
                    if(i<2)
                    {
                        i++;
                        wart=a[i];
                    }
                    else
                        wart-=b[j];
                }
                
                else if(A[i]==B[j])
                {
                    result+=wart;
                    i++;
                    wart=a[i];
                    if(i>3)
                        break;
                }
                
//                cout << "x " << x << endl;
//                cout << "i " << i << endl;
//                cout << "j " << j << endl;
//                cout << "wart " << wart << endl;
//                cout << "result " << result << endl << endl;
            }
            
            R=max(result, R);
        }
        
        
        
        
        
        
        
        
        
        
        int i=1;
        int wart=a[i];
        result=0;
        
        for(int j=1; j<=m; j++)
        {
            if(A[i]==B[j] && wart>b[j])
            {
                result+=b[j];
                wart-=b[j];
            }
                
            else if(A[i]==B[j])
            {
                result+=wart;
                b[j]-=wart;
                
                if(b[j])
                    j--;
                
                i+=2;
                wart=a[i];
                
                if(i>3)
                    break;
            }
            
        }
        
        R=max(R,result);
        
        
        
        cout << "Case #" << z << ": " << R << endl;;
    }

return 0;
}
