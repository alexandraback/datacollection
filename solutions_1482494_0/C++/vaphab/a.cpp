#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


int N;
vector<int> a,b;
vector<int> av,bv;

bool finish()
{
    for(int j=0; j<b.size(); j++){
		if(bv[j]==0){
			return false;
		}
	}
    return true;
}

int main(int argc, const char * argv[])
{
    ifstream input("input.txt");
    ofstream output("output.txt");
    int T;
    input >> T;
    for(int i=0;i<T;i++){
        cout << "Case: " <<  i+1 << endl;
        output << "Case #" << i+1 << ": ";

        input >> N;
        a.resize(N);
        b.resize(N);
        av.resize(N);
        bv.resize(N);
        for(int j=0;j<N;++j){
            input >> a[j] >> b[j];
            bv[j]=0;
            av[j]=0;

        }

        int stars = 0;
        int step = 0;
        bool ch = true;
        while(ch){
			ch = true;
			while(ch)
			{
				ch = false;
				for(int j=0; j<b.size(); j++){
					if(b[j]<=stars && bv[j]==0){
						stars++;
						step++;
						if(av[j]==0) stars++;
						bv[j]=1;
						av[j]=1;
						ch = true;
						break;
					}
				}
			}

			int select = 0;
			int max = -1;
			for(int j=0; j<a.size(); j++){
				if(a[j]<=stars && av[j]==0 && max<b[j]){
					select = j;
					max = b[j];
				}
			}

			if(max >= 0){
				stars++;
				step++;
				av[select]=1;
				ch = true;
			}
        }

        if(finish()){
            output << step << endl;
            cout << step << endl;
        }else{
            output << "Too Bad" << endl;
            cout << "Too Bad" << endl;
        }

    }
    input.close();
    output.close();

    return 0;
}

