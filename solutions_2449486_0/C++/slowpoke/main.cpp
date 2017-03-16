#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const int SIZE = 101;
static int lawn[SIZE][SIZE];

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    for(int t=1; t<=T; ++t){
        int N, M;
        cin >> N >> M;
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                cin >> lawn[i][j];
            }
        }
        
        bool done[SIZE][SIZE] = {};
        
        bool found;
        do{
            found = false;
            for(int i=0; i<N; ++i){
                bool ok = true;
                int maxDone = 0;
                int num = 0;
                for(int j=0; j<M; ++j){
                    if(done[i][j]){
                        maxDone = max(maxDone, lawn[i][j]);
                    }else{
                        if(num==0){
                            num = lawn[i][j];
                        }else if(num != lawn[i][j]){
                            ok = false;
                            break;
                        }
                    }
                }
                if(ok && num != 0 && num >= maxDone){
                    found = true;
                    for(int j=0; j<M; ++j){
                        lawn[i][j] = num;
                        done[i][j] = true;
                    }
                }
            }
            
            for(int j=0; j<M; ++j){
                bool ok = true;
                int maxDone = 0;
                int num = 0;
                for(int i=0; i<N; ++i){
                    if(done[i][j]){
                        maxDone = max(maxDone, lawn[i][j]);
                    }else{
                        if(num==0){
                            num = lawn[i][j];
                        }else if(num != lawn[i][j]){
                            ok = false;
                            break;
                        }
                    }
                }
                if(ok && num != 0 && num >= maxDone){
                    found = true;
                    for(int i=0; i<N; ++i){
                        lawn[i][j] = num;
                        done[i][j] = true;
                    }
                }
            }
        }while(found);
        
        bool result = true;
        
        for(int i=0; i<N && result; ++i){
            for(int j=0; j<M; ++j){
                if(!done[i][j]){
                    result = false;
                    break;
                }
            }
        }
        
        cout << "Case #" << t << ": " << (result? "YES" : "NO") << endl;
        
    }
    
    return 0;
}

