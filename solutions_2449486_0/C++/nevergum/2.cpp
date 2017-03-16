
#include<fstream>
#include<vector>
using namespace std;

int main(){

    ifstream infile("file.in");
    ofstream outfile("file.out");

    int t;
    infile>>t;

    for(int k=0; k<t; k++){
        int n;
        int m;
        infile >> n >> m;

        vector<vector<int> > grass;
        vector<int> rowMax;
        vector<int> columnMax;

        rowMax.resize(n, 0);
        columnMax.resize(m, 0);
        grass.resize(n);

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int h;
                infile >> h;
                grass[i].push_back(h);
                rowMax[i] = max(rowMax[i], h);
                columnMax[j] = max(columnMax[j], h);
            }
        }
        
        bool ret = true;
        for (int i=0; i<n && ret; i++) {
            for (int j=0; j<m && ret; j++) {
                if (grass[i][j] < min(rowMax[i], columnMax[j])) {
                    ret = false;
                }
            }
        }

        outfile<<"Case #"<<k+1<<": "<<(ret ? "YES" : "NO")<<endl;
    }

}
    
