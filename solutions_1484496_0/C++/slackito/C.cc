#include <iostream>
#include <vector>

using namespace std;

vector<int> set;
vector<int> candidate_solution;

int N;
 
bool check_candidate_solution()
{
    int sum_A = 0;
    int sum_B = 0;
    for (int i=0; i<N; ++i)
    {
        if (candidate_solution[i] == 1) sum_A += set[i];
        else if (candidate_solution[i] == 2) sum_B += set[i];
    }

    if ((sum_A == sum_B) && (sum_A > 0)) return true;
    else return false;
}

bool generate_next_solution()
{
    for (int i=0; i<N; ++i) {
        if (candidate_solution[i] < 2) {
            candidate_solution[i]++;
            return true;
        }
        else { // if (candidate_solution[i] == 2) {
            candidate_solution[i] = 0;
            for (int j=i+1; j<N; j++) {
                if (candidate_solution[j] < 2) {
                    candidate_solution[j]++;
                    return true;
                }
                else {
                    candidate_solution[j] = 0;
                }

            }
            return false;
        }
    }
}

void print_candidate()
{
    /*
    for (int i=0; i<N; i++)
        cout << candidate_solution[i] <<",";
    cout << endl;
    */
}

int main()
{

    int T;

    cin >> T;

    for(int test_case=1; test_case <= T; ++test_case)
    {
        cin >> N;

        set.clear();
        candidate_solution.clear();

        for (int i=0; i<N; ++i)
        {
            int n;
            cin >> n;
            set.push_back(n);
            candidate_solution.push_back(0);
        }
        
        cout << "Case #" << test_case << ":" << endl;

        print_candidate();
        while(check_candidate_solution() == 0)
        {
            if (!generate_next_solution()) {
                cout << "Impossible";
                goto end;
            }
            print_candidate();
        }

        for (int i=0; i<N; ++i)
            if (candidate_solution[i] == 1) cout << set[i] << " ";

        cout << endl;

        for (int i=0; i<N; ++i)
            if (candidate_solution[i] == 2) cout << set[i] << " ";

end:
        cout << endl;

    }
    

}


