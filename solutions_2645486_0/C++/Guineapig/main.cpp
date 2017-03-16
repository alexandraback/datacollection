#include "my_header.h"


class solver
{
public:
    
	int solve(int E, int R, int N, int_v vs)
	{
        // gain_table[i][e] = max gain after activity i with energy left e
        
        int gain_table[100][100];
        for (int i=0 ; i < 100 ; i++)
            for (int j=0 ; j < 100 ; j++)
                gain_table[i][j] = 0;
        
        for (int ia=0 ; ia < N ; ia++)
        {
            int v = vs[ia];
            for (int en_left=min(E, R) ; en_left <= E ; en_left++)
            {
                int gain_so_far = ia == 0 ? 0 : gain_table[ia-1][en_left];
                for (int en_spent=0 ; en_spent <= en_left ; en_spent++)
                {
                    int gain = v * en_spent;
                    int total_gain = gain_so_far + gain;
                    int en_left_after = en_left - en_spent + R;
                    if (en_left_after > E)
                        en_left_after = E;
                    int best_total_gain = gain_table[ia][en_left_after];
                    if (total_gain > best_total_gain)
                        gain_table[ia][en_left_after] = total_gain;
                }
            }
        }
        
        for (int ia=0 ; ia < N ; ia++)
        {
            for (int e=0 ; e <= E ; e++)
                cout << gain_table[ia][e] << " ";
            cout << endl;
        }
        
        
        int best_gain = 0;
        for (int en=0 ; en <= E ; en++)
        {
            int gain = gain_table[N-1][en];
            if (gain > best_gain)
                best_gain = gain;
        }
        
		return best_gain;
	}

	int ref_solve(int E, int R, int N, int_v vs)
    {
        int best_gain = 0;
        int_v en_spent(N);
        search(E, R, N, vs, en_spent, 0, best_gain);
        return best_gain;
    }
    
    void search(int E, int R, int N, int_v &vs, int_v &en_spent, int activity_idx, int &best_gain)
    {
        if (activity_idx == N)
        {
            int e_left = E;
            int gain = 0;
            for (int ia=0 ; ia < N ; ia++)
            {
                int es = en_spent[ia];
                if (es > e_left)
                    return;
                gain += es * vs[ia];
                e_left += R - es;
                if (e_left > E)
                    e_left = E;
            }
            if (gain > best_gain)
            {
                best_gain = gain;
                cout << "*** ";
                for (int i=0 ; i < N ; i++)
                    cout << en_spent[i] << " ";
                cout << endl;
            }
        }
        else
        {
            for (int e_s=0 ; e_s <= E ; e_s++)
            {
                en_spent[activity_idx] = e_s;
                search(E, R, N, vs, en_spent, activity_idx+1, best_gain);
            }
        }
    }
};


int main_(int argc, char **argv)
{
    int_v vs(1);
    vs[0] = 6;
    solver().solve(4, 5, 1, vs);
    return 0;
}

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
    int E, R, N;
    ifs >> E >> R >> N;
    
    int_v vs(N);
    for (int i=0 ; i < N ; i++)
        ifs >> vs[i];
    
	int res = solver().solve(E, R, N, vs);
//    int ref_res = solver().ref_solve(E, R, N, vs);
//    
//    if (res != ref_res)
//    {
//        cout << "Error: res = " << res << ", ref_res = " << ref_res << endl;
//        cout << "E = " << E << ", R = " << R << "N = " << N << endl;
//        for (int i=0 ; i < N ; i++)
//            cout << vs[i] << " ";
//        cout << endl;
//        exit(-1);
//    }
    
	cout << "Case #" << case_num << ": " << res << endl;
	ofs << "Case #" << case_num << ": " << res << endl;
}

/*************************************************************************************/

int main(int argc, char **argv)
{
	ifstream ifs(argv[1], ifstream::in);
	ofstream ofs(argv[2]);
    
	ofs.precision(7);
	ofs << fixed;
    
	int n = to_int(get_line(ifs));
    
	assert(n > 0 && n < 200);
    
	for (int i=0 ; i < n ; i++)
	{
		if (i > 0)
			cout << "\n---------------------------------------------\n\n";
		process_test_case(i+1, ifs, ofs);
	}
    
    return 0;
}
