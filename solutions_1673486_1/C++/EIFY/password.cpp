#include <iostream>
#include <sstream>

#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    long int T, A, B;
    
    cin>>T;
    
    cout << setprecision(10);
    
    istringstream instream;
    
    for(int i=0; i<T; ++i)
    {
    
        cin>>A>>B;
        
        double option3 = B+2;
        double option2 = A + B + 1;
        
        //cout<< option3 <<' '<< option2<<endl;;
        
        double ans = min(option2, option3);
        
        double corr = 1;
        
        string s;
        
        do getline(cin,s);
        while (s.length()==0);
        
        instream.clear();
        
        instream.str(s);
        
        for(long int j=1; j<=A; ++j)
        {
            if(corr * (B+1) < 2) break;
            
            double pi;
            instream >> pi;
            
            //cout<<pi<<endl;
            
            corr *= pi;
            
            //cout<<corr<<endl;
            
            
            option2 = A+B+1 - 2*j + (1 - corr)*(B+1);
            
            //diff = -2 + (corr_prev - corr)*(B+1)
            //diff > 0 : 2 > (corr_prev - corr)*(B+1)
            //2 > (corr_prev - corr)*(B+1)
            
            if (option2 < ans) ans = option2;
        }
    
        cout<<"Case #"<<i+1<<": "<<ans<<endl;
        
    }
	return 0;
}
