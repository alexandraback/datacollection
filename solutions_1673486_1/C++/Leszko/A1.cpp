#include<iostream>
#include<algorithm>
using namespace std;

double tab[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    
    int z;
    cin >> z;
    
    for(int Z=1; Z<=z; Z++)
    {
        int A;
        cin >> A;
        
        int B;
        cin >> B;
        
        double right=1;
        
        for(int i=0; i<A; i++)
        {
            cin >> tab[i];
            right*=tab[i];
        }
        
        double res=B+2;
        
        res=min(res, (B-A+1)*right+(2*B-A+2)*(1-right));
        
        right=1;
        
        for(int i=0; i<A-1; i++)
        {
            right*=tab[i];
            
            //cout << right*((A-i-1)*2+(B-A)+1)+(1-right)*((A-i-1)*2+(B-A)+2+B) << endl;
            res=min(res, right*((A-i-1)*2+(B-A)+1)+(1-right)*((A-i-1)*2+(B-A)+2+B));
        }
        
        cout << "Case #" << Z << ": ";
        
        cout.setf(ios::fixed);
        cout.precision(6);
        cout << res << endl;
        
        
        
        
        
    }

return 0;
}
