#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include<stack>

using namespace std;

int main (void)
{
    ifstream in("Cin.txt");
    cin.rdbuf(in.rdbuf());
    ofstream out("Cout.txt");
    cout.rdbuf(out.rdbuf()); 

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
      
        int N;
        cin >> N;

        vector<int> BFFs(N+1);
        vector<int> BFF_counts(N+1, 0);
        vector<int> longest_path_to(N+1, 0);

        for (int i = 1; i <= N; i++)
        {
            int F;
            cin >> F;
            BFFs[i] = F;
            BFF_counts[F]++;
        }

        vector<bool> checked_indices(N+1, false);
        stack<int> no_friend_indices;

        for (int i = 1; i <= N; i++)
        {
            if (BFF_counts[i] == 0)
            {
                no_friend_indices.push(i);
            }
        }

        // remove non-cycles and count longest paths to nodes
        while(!no_friend_indices.empty())
        {
            int i = no_friend_indices.top();
            no_friend_indices.pop();

            checked_indices[i] = true;
            BFF_counts[BFFs[i]]--;
            int path_length = longest_path_to[i] + 1;
            if (path_length > longest_path_to[BFFs[i]])
                longest_path_to[BFFs[i]] = path_length;
            
        
            if (BFF_counts[BFFs[i]] == 0)
                no_friend_indices.push(BFFs[i]);
        }

        // indentify mutual BFFs
        int max_cycle = 0;

        vector<bool> checked_mutual(N+1, false);

        for (int i = 1; i <= N; i++)
        {
        
            if (checked_mutual[i] || checked_mutual[BFFs[i]]) continue;

            if (BFFs[BFFs[i]] == i)
            {                
                checked_mutual[BFFs[i]] = true;
                checked_mutual[i] = true;
                max_cycle += 2 + longest_path_to[i] + longest_path_to[BFFs[i]];
            }
        }

        // count cycle sizes

        for (int i = 1; i <= N; i++)
        {
            if (checked_indices[i]) continue;

            int cycle_size = 1;
            int next_index = BFFs[i];
            checked_indices[i] = true;

            while(next_index != i)
            {
                cycle_size++;
                checked_indices[next_index] = true;
                next_index = BFFs[next_index];
            }

            if (cycle_size > max_cycle)
                max_cycle = cycle_size;
        }

       cout << max_cycle << endl;
        
    }
    return 0;
}
