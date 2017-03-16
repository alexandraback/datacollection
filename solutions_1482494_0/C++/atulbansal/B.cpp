#include "../jam.h"

int get2star(vector<int> &a, vector<int> &b, vector<int> &status, int star_count) {
    int N=a.size();
    for(int i=0;i<N;i++) {
            if(status[i] == 0 && (star_count >= b[i])) return i;
    }
    return -1;
}

int get1star(vector<int> &a, vector<int> &b, vector<int> &status, int star_count) {
    int N=a.size();
    int ret = -1;
    int maxb = 0;
    for(int i=0;i<N;i++) {
            if(status[i] == 0 && (star_count >= a[i])) {
                if ( b[i] > maxb) { ret=i; maxb = b[i]; }
            }
    }
    return ret;
}

int get21star(vector<int> &a, vector<int> &b, vector<int> &status, int star_count) {
    int N=a.size();
    for(int i=0;i<N;i++) {
            if(status[i] == 1 && (star_count >= b[i])) return i;
    }
    return -1;
}

void solve(int casenum) {
   int N;
   in >> N;
   vector<int> a;
   vector<int> b;
   vector<int> status;
   int ta,tb;
   for (int i=0 ; i<N; i++) {
      in >> ta >> tb;
      a.push_back(ta);
      b.push_back(tb);
      status.push_back(0);
   }

   // status 0--mean nothing done; 1-- 1 star reached ; 2--2 star reached
   int level_count = 0; // # 2 stars reached
   int star_count = 0;  // # stars
   int play_count=0;    // #games played
   while(level_count < N) {
       // cout << casenum << " " << star_count << "\n";
       int l = get2star(a,b,status,star_count);
       if (l>=0) {
          star_count+=2;
          status[l]=2;
          play_count++;
          level_count++;
          continue;
       }

       l = get21star(a,b,status,star_count);
       if (l>=0) {
          star_count+=1;
          status[l]=2;
          play_count++;
          level_count++;
          continue;
       }

       l = get1star(a,b,status,star_count);
       if (l>=0) {
          star_count+=1;
          status[l]=1;
          play_count++;
          // no change to level_count
          continue;
       }

       out << "Case #" << casenum << ": " << "Too Bad" << endl;
       return;
   }

   out << "Case #" << casenum << ": " << play_count << endl;
}




int main() {
	cout << "!!!Hello World!!!" << endl;

	in.open("B-small-attempt1.in");
	out.open("output1.txt");
	int T;
	in >> T;

	for (int i = 0; i < T; i++) {
        solve(i+1);
    }
    
    system ("pause");
	return 0;
}
