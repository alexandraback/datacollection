#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin>>T;
    int c =0;
    while(c<T)
    {
        vector<int> judgepts;
        int totpoints =0 ;
        int n;
        int minval=101;
        int maxval=0;
        cin>>n;
        for (int i=0;i <n;++i)
        {
            int val;
            cin>>val;
            totpoints+=val;
            judgepts.push_back(val);
        }
        double med = (2.0*totpoints);
        double sum = med;
        med = med/n;

        ++c;
        cout <<"Case #"<< c <<": " ;
        int splitn = n;
        for(int i=0; i<n; ++i)
        {
            if(med <= judgepts[i])
            {
                --splitn;
                sum  -= judgepts[i];
            }
        }
        double newmed = sum/splitn;
        for(int i=0; i<n; ++i)
        {
            double val =0;
            if(med > judgepts[i])
            {
                val = ((newmed -judgepts[i])/totpoints )*100;
            }
            printf("%2.6f ", val);
        }
        cout<<endl;
    }
}
