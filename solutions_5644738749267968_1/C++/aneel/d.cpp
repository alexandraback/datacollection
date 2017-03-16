#include <iostream>
#include <algorithm>
using namespace std;

float nomi[1002];
float ken[1002];

int main()
{
    int T, n;
    cin>>T;
    for(int ti = 1; ti <= T; ++ti)
    {
        cout<<"Case #"<<ti<<": ";
        cin>>n;
        
        for(int i = 0; i < n; ++i) cin>>nomi[i];
        for(int i = 0; i < n; ++i) cin>>ken[i];
        
        sort(nomi,nomi+n);
        sort(ken,ken+n);
        
        //for(int i = 0; i < n; ++i) cout<<nomi[i]<<" ";
        //cout<<endl;
        //for(int i = 0; i < n; ++i) cout<<ken[i]<<" ";
        
        
        int score1=0;
        for(int i = 0, j = n-1,k=0; i < n; i++)
        {   
            if(nomi[i]>ken[k]) {
                ++score1;
                ++k;
            }
            else {
                --j;
            }
        }
        int score2=0;
        int i = 0;
        for(int j = 0; i < n && j < n;)
        {
            while(j < n && ken[j] < nomi[i]) {
                ++j;
            }
            if(j!=n) {
                ++j;
                i++;
            }
        }
        score2 = n - i;
        cout<<score1<<" "<<score2<<endl;

    }
    return 0;
}
