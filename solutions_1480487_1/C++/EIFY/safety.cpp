#include <iostream>
#include <sstream>

#include <algorithm>
#include <string>
#include <iomanip>

#include <vector>

typedef std::pair<int,int> mypair;
bool comparator ( const mypair& l, const mypair& r)
{ return l.first < r.first; }

using namespace std;

int main()
{
    int T;
    
    cin>>T;
    
    cout << setprecision(10);
    
    for(int i=0; i<T; ++i)
    {
        
        int N;
        cin>>N;
        
        //vector<double> safe_fracs(N);
        int X=0;
        
        vector<mypair> data(N);
        //int lowest = 101;
        //int n_lowest=0;
        
        vector<int> scores(N);
        
        
        for(int j=0; j<N; ++j)
        {
            int score;
            
            cin>>score;
            
            X+=score;
            
            data[j].first = score;
            data[j].second = j;
            
            scores[j] = score;
            /*
            if(score < lowest)
            {
                n_lowest = 1;
                lowest = score;
            }
            else if (score == lowest)
            {
                n_lowest++;
            }
            */
        }
        
        cout<<"Case #"<<i+1<<":";
        
        sort(data.begin(), data.end(), comparator);
        
        data.resize(N+1);
        
        //vector<double> temp(N);
        
        //int j=0;
        //int sum=0;
        
        //bool back_fill = false;
        /*
        while(j<N)
        {
            int score = data[j].first;
            int current = j;
            sum += score;
            
            while(data[++j].first == score)
            {
                sum+=data[j].first;
            }
            
            int accu = j - current;
            
            cout<<"accu: "<<accu<<" sum: "<<sum<<" j: "<<j<<endl;
            
            double safe_frac;
            
            if(back_fill)
            {
                temp[0] = ((sum - data[0].first)/double(j-1) - data[0].first + X/double(j-1))/(X + X/double(j-1));
                back_fill = false;
            }
            
            if(j>1)
                safe_frac = ((sum - score)/double(j-1) - score + X/double(j-1))/(X + X/double(j-1));
            else
            {
                back_fill = true;
            }
            
            if(safe_frac < 0)
                safe_frac = 0;
            
            for(int k=current; k<j; ++k)
                temp[k] = safe_frac;
        }*/
        /*
        j=N-1;
        sum=X;
        
        while(j>=0)
        {
            sum -= data[j].first;
            
            
        
        }
        
        
        for(int j=0; j<N; ++j)
        {
            double safe_frac = temp[j];
            
            safe_fracs[data[j].second] = safe_frac;
        }
        
        for(int j=0; j<N; ++j)
        {
            cout<<' '<<100 * safe_fracs[j];
        }
        */
        
        for(int j=0; j<N; ++j)
        {
            double safe_frac;
            
            safe_frac = ((X - scores[j])/double(N-1) - scores[j] + X/double(N-1))/(X + X/double(N-1));
            
            
            //cout<<data[j].first<<endl;
            
            int SUM = X;
            
            for(int k=N-1; k>1; --k)
            {
                SUM -= data[k].first;
                
                double temp = ((SUM - scores[j])/double(k-1) - scores[j] + X/double(k-1))/(X + X/double(k-1));
                
                
                //cout<<"SUM: "<<SUM<<" temp: "<<temp<<endl;
                
                if(temp < safe_frac)
                    safe_frac = temp;
                
            }
            /*
            if(scores[j] == lowest && n_lowest > 1)
            {
                safe_frac = 1.0/double(n_lowest);
            }
            else
            {
                safe_frac = (lowest - scores[j] + X/double(n_lowest))/(double(X) * (1 + 1/double(n_lowest)));
                
                if(safe_frac < 0)
                    safe_frac = 0;
            }
            */
            
            if(safe_frac < 0)
                safe_frac = 0;
            
            cout<<' '<<100 * safe_frac;
            
        }
        
        cout<<endl;
    
        
    }
	return 0;
}
