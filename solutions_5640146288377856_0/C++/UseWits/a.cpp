#include <iostream>
#include <vector>

using namespace std;

vector<int> hit;
vector<int> nohit;
int r,c,w;

int getnohit(int size) {
    if(nohit[size] != -1) return nohit[size];
    if(size < w) return 0;
    if(size == 0) return 0;
    if(w == 1) return size;
    int result = 1000;
    for(int l=0; l<size; l++) {
        int r = size-l-1;
        int local_res = getnohit(l)+getnohit(r);
        if(getnohit(r)+getnohit(l) > local_res)
            local_res = getnohit(r)+getnohit(l);
        if(local_res < result)
            result = local_res;
    }
    result++;
    nohit[size] = result;
    return result;
}

int gethit(int size) {
    if(hit[size] != -1) return hit[size];
    if(size < w) return hit[1000];
    if(size == w) return w;
    if(size < 2*w) return w+1;
    if(size == 0) return 0;
    if(w == 1) return size;
    int result = 1000;
    for(int l=0; l<size; l++) {
        int r = size-l-1;
        if(r < w) 
            if(gethit(l) < result)
                result = gethit(l);
        else {
            int local_res = gethit(l)+getnohit(r);
            if(getnohit(r)+gethit(l) > local_res)
                local_res = getnohit(r)+gethit(l);
            if(local_res < result)
                result = local_res;
        }
    }
    result++;
    hit[size] = result;
    return result;
}



void run() {
    cin >> r >> c >> w;

    hit = vector<int>(21,-1);
    nohit = vector<int>(21,-1);

/*
    cout << endl;
    for(int i=1; i<=c; i++) {
        cout << "width " << i << "   hit: " << gethit(i) << endl;
        cout << "width " << i << " nohit: " << getnohit(i) << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;
*/
    
    cout << (r-1)*getnohit(c)+gethit(c);
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cout << "Case #" << (i+1) << ": ";
        run();
        cout << endl;
    }
}
