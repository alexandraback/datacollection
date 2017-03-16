#include "../jam.h"

void solve(int casenum) {
     int mote;
     in >> mote;
     int size;
     in >> size;
     int temp;
     vector<int> motes;
     for(int i=0;i<size;i++)
     {
            in >> temp;
            motes.push_back(temp);
     }
     sort(motes.begin(), motes.end());

     if (mote == 1)
     {
    	 out << "Case #" << casenum << ": " << size << endl;
    	 return;
     }

     int i = 0;
     int ans = size;
     int consumed = 0;
     while(i<size)
     {
    	 int curr = motes[i];
    	 int left = size - i - 1; // number of moats to the right of i
    	 if (curr < mote)
    	 {

    	 }
    	 else
    	 {
    		 int count = 0;
             while (mote <= curr)
             {
                   mote  = mote + mote - 1;
                   count ++;
             }

    		 consumed += count;
    	 }

    	 mote += curr;
    	 i++;
    	 ans = min(ans, left+consumed);
     }


     out << "Case #" << casenum << ": " << ans << endl;
}

int main() {
	cout << "!!!Hello World!!!" << endl;
	in.open("A-large.in");
//	in.open("input.txt");
	out.open("output.txt");
	int T;
	in >> T;

	for (int i=0;i<T;i++) {
        solve(i+1);
    }
    
    system ("pause");
	return 0;
}
