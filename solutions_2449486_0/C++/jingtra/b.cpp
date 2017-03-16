#include<iostream>
#include<vector>

using namespace std;

void print(vector<vector<int> > vec){
    for(int i=0; i<vec.size(); ++i){
        for(int j=0; j<vec[i].size(); ++j)
            cout << vec[i][j] << " ";
        cout << endl;

    }

}

int main(){
    int T; cin >> T;
    for(int t=0; t<T; ++t){
        int N, M; cin >> N >> M;
        vector<vector<int> >map(N, vector<int>(M, 100)),clip(N, vector<int>(M, 100));
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j)
                cin >>clip[i][j];

        }
        //clip x-direction
        for(int i=0; i<N; ++i){
            //find min to clip
            int m = 0;
            for(int j=0; j<M; ++j)
                m = max(clip[i][j], m);
            
            //clip it
            for(int j=0; j<M; ++j)
                map[i][j] = min(map[i][j], m);
        }

        //clip y-direction
        for(int i=0; i<M; ++i){
            //find min to clip
            int m = 0;
            for(int j=0; j<N; ++j)
                m = max(clip[j][i], m);

            //clip it
            for(int j=0; j<N; ++j)
                map[j][i] = min(map[j][i], m);
        }

        //check if diff
        bool diff = false;

        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j)
                if(clip[i][j] != map[i][j])
                        diff = true;

        }
        //cout << "Map" << endl;
        //print(map);
        //cout << "clip" << endl;
        //print(clip);

        cout << "Case #" << t+1 << ": ";
        if(diff) cout << "NO" << endl;
        else cout << "YES" << endl;

    }


    return 0;
}
