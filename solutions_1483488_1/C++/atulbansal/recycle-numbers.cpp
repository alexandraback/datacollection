#include "../jam.h"

int get_cycle(long long num, int shift, int digit_count) {
    long long rem = num % int(pow(10,digit_count-shift));
    long long rest = num / int(pow(10,digit_count-shift));
    long long ret = rem * int(pow(10,shift)) + rest; 
    // cout << num << " shifted by " << shift << " is " << ret << endl;
    // cout << num << " " << rest << " " << rem << endl;
    return ret;
}

int num_valid_cycles(long long num, int A, int B) {
   int ret = 0;
   long long temp = num;
   int digit_count = int(log10(num))+1;
   set<int> valid;
   // cout << "digit_cout " << digit_count << " for " << num << endl;
   for(int i=1;i<digit_count;i++) {
      // if digit i is 0 the continue
      temp = get_cycle(num, i, digit_count);
      if(temp < A) continue;
      
      

      // if a valid cycle is found s.t. it is < num return 0
      // so that we return something only for smallest among the cycles
      if (temp >= A && temp < num) return 0;

      else if(temp >=A && temp <= B && temp != num) { 
         valid.insert(temp);
      }
   }

   return valid.size();
}


void solve(int casenum) {
   int A,B;
   in >> A >> B;

   unsigned long long ans=0;
   for(int i=A;i<=B;i++) {
      int count = num_valid_cycles(i,A,B);
      // if(count >0 && casenum == 4) cout << "adding " << (count * (count+1)) / 2 << "for " << i << "\n";
      ans += (count * (count+1)) / 2;
   }

   out << "Case #" << casenum << ": " << ans << endl;
}




int main() {
	cout << "!!!Hello World!!!" << endl;

	in.open("C-large.in");
	out.open("output.txt");
	int T;
	in >> T;
	for (int i=0;i<T;i++) {
        solve(i+1);
    }
    
    system ("pause");
	return 0;
}
