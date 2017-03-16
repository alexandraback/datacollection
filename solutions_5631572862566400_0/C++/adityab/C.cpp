#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_in(int* F, int N, int val, int done)
{
    for(int i=0; i<N; i++)
    {
        if(F[i] == val && i+1 != done)
            return i;
    }
    
    return -1;
}

int main()
{
    int T, N;
    cin >> T;
    for(int i=0; i<T; i++)
    {
        cout << "Case #" << i+1 << ": ";
        cin >> N;
        int F[N];
        int neighbour = 1;
        for(int j=0; j<N; j++)
            cin >> F[j];
        vector<int> links[N];
        for(int k=0; k<N; k++)
        {
            neighbour = k+1;
            while(find(links[k].begin(), links[k].end(), neighbour)==links[k].end())
            {
                links[k].push_back(neighbour);
                neighbour = F[neighbour-1];
            }
            links[k].push_back(neighbour);
        }
        
        vector<int> circle;

        int max_length = 0;

        for(int j=0; j<N; j++)
        {
            if(links[j].back() == links[j][links[j].size()-3])
            {
                if(links[j].size() > max_length)
                {
                    circle = links[j];
                    max_length = circle.size();
                }
            }
            else if(links[j].front() == links[j].back())
            {
                if(links[j].size() > max_length)
                {
                    circle = links[j];
                    max_length = circle.size();
                }
            }
        }

        if(circle.back() == circle[circle.size()-3])
        {
            int temp = find_in(F, N, circle[circle.size()-2], circle.back());
            if(temp < 0)
                circle.pop_back();
        }
        else
        {
            circle.pop_back();
        }

        cout << circle.size() << endl;

    }
}

