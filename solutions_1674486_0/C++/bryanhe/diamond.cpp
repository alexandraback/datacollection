#include <iostream>
#include <stdlib.h>
#include <vector>

#define INFINITY 99999999
using namespace std;

int main(int argc, char *argv[])
{

    int T;
    cin >> T;

    for(int counter = 1; counter <= T; counter++)
    {
        int N;
        cin >> N;

        vector<vector<int> > inherit;
        for(int n = 0; n <= N; n++)
        {
            vector<int> blank;
            inherit.push_back(blank);
        }

        for(int n = 1; n <= N; n++)
        {
            int M;
            cin >> M;
            for(int m = 0; m < M; m++)
            {
                int i;
                cin >> i;
                inherit[n].push_back(i);
            }
        }

        bool hasMultiple = false;
        for(int start = 1; start <= N; start++)
        {
            vector<int> ways;
            vector<int> distance;
            vector<bool> processed;
            for(int c = 0; c <= N; c++)
            {
                ways.push_back(0);
                distance.push_back(INFINITY);
                processed.push_back(false);
            }
            ways[start] = 1;
            distance[start] = 0;

            for(int c = 0; c < N; c++)
            {
                int index = -1;
                for(int n = 1; n <= N; n++)
                {
                    if(!processed[n])
                    {
                        if(index == -1)
                        {
                            index = n;
                        }
                        else if(distance[n] < distance[index])
                        {
                            index = n;
                        }
                    }
                }

                for(int n = 0; n < (int)inherit[index].size(); n++)
                {
                    distance[inherit[index][n]] = min(distance[inherit[index][n]], distance[index]+1);
                    ways[inherit[index][n]] += ways[index];
                    if(ways[inherit[index][n]] > 1)
                    {
                        hasMultiple = true;
                        break;
                    }
                }
                if(hasMultiple)
                {
                    break;
                }
                processed[index] = true;
            }
            if(hasMultiple)
            {
                break;
            }
        }

        cout << "Case #" << counter << ": ";
        if(hasMultiple)
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }

        cout << "\n";
    }

    return 0;
}
