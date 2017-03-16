#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int get_max(vector<int>&a, vector<int>& f){

    int ans = 0;
    int N = a.size();

    for(int i=0; i<a.size(); i++){

        if(f[a[i]] == (a[(i+1)%N]) || f[a[i]] == (a[(i-1+N)%N])){
            continue;
        } else{
            return 0;
        }
    }

    return 1;
}


void test_small(){

    int T;
    cin>>T;

    for(int c=1; c<=T; c++){

        int N;
        cin>>N;
        int rep = 0;
        int rep_ans = 0;
        vector<int> f(N+1, -1);

        for(int i=1; i<=N; i++) cin>>f[i];

        for(int j = 2; j<=N; j++){

            int r= j;
            int n = N;
            vector<int> a(j, 0);
            std::vector<bool> v(N);
            std::fill(v.begin(), v.end() - n + r, true);

            // http://stackoverflow.com/questions/9430568/generating-combinations-in-c
            do {
                int k = 0;
                //std::cout << "\n";
                for (int i = 0; i < n; ++i) {
                    if (v[i]) {
                        //std::cout << (i+1) << " ";
                        a[k] = i+1;
                        k++;
                    }
                }

                sort(a.begin(), a.end());

                do{

                    int tmp = get_max(a, f);
                    if( tmp){
                        //rep = tmp;
                        rep_ans = max(j, rep_ans);
                    }

                } while(next_permutation(a.begin(), a.end()));


                //std::cout << "\n";
            } while (std::prev_permutation(v.begin(), v.end()));


            //vector<int> a(j, 0);

//            for(int i=0; i<j; i++) a[i] = i;

//            do{
//                int tmp = get_max(a, f);
//                if( tmp){
//                    //rep = tmp;
//                    rep_ans = max(j, rep_ans);
//                }


//            } while(next_permutation(a.begin(), a.end()));

        }




        cout<<"Case #"<<c<<": "<<rep_ans<<endl;
    }
}

int main()
{
    test_small();
    return 0;
}

