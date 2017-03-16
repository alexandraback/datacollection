#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

#define iterate(_i, _c) _i = _c.begin(); _i != _c.end(); ++_i
#define existsIn(_k, _c) (_c.find(_k) != _c.end())

#if 0
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using namespace boost::multiprecision;
#define Integer cpp_int
#define Rational cpp_rational
#define Float cpp_dec_float_50
#endif

struct BlockInfo {
  int pMin, pMax, sMin, sMax;
  int row, col;
  int count;
};

bool operator<(const BlockInfo &i0, const BlockInfo &i1) { return (i0.count > i1.count); }

int main(void) {
  int T; cin >> T;
  
  for (int iCase = 1; iCase <= T; ++iCase) {
    cout << "Case #" << iCase << ":";
    cerr << "[" << iCase << "] " << flush;
    
    int J, P, S, K;
    cin >> J >> P >> S >> K;

    int total = 0;
    
    for (int pass = 0; pass <= 1; ++pass) {
      multiset<BlockInfo> blocks;
      int nPBlocks = (P+K-1)/K, nSBlocks = (S+K-1)/K;
      for (int iPBlock = 0; iPBlock < nPBlocks; ++iPBlock)
	for (int iSBlock = 0; iSBlock < nSBlocks; ++iSBlock) {
	  BlockInfo info;
	  info.pMin = K*iPBlock; info.pMax = info.pMin+K; if (info.pMax > P) info.pMax = P;
	  info.sMin = K*iSBlock; info.sMax = info.sMin+K; if (info.sMax > S) info.sMax = S;
	  info.row = iPBlock;
	  info.col = iSBlock;
	  info.count = (info.pMax-info.pMin)*(info.sMax-info.sMin);
	  blocks.insert(info);
	}
      
      if (0)
	for (auto it=blocks.begin(); it != blocks.end(); ++it)
	  cerr << it->count << " (" << it->row << "," << it->col << ")\n";

      for (int j0 = 0; j0 < J; j0 += K) {
	int jMin = K*j0, jMax;
	jMax = jMin+K; if (jMax > J) jMax = J;
	
        int rowBits = 0, colBits = 0;

	multiset<BlockInfo>::iterator iBlock;
	for (iBlock = blocks.begin(); iBlock != blocks.end(); ) {
	  if (rowBits & (1 << iBlock->row)) { ++iBlock; continue; }
	  if (colBits & (1 << iBlock->col)) { ++iBlock; continue; }

	  rowBits |= (1 << iBlock->row);
	  colBits |= (1 << iBlock->col);
	  total += (jMax-jMin)*iBlock->count;

	  if (pass==1)
	    for (int j = jMin; j < jMax; ++j)
	      for (int p = iBlock->pMin; p < iBlock->pMax; ++p)
		for (int s = iBlock->sMin; s < iBlock->sMax; ++s)
		  cout << j+1 << " " << p+1 << " " << s+1 << "\n";

	  blocks.erase(iBlock++);
	}
	
      }
      
      if (pass==0) cout << " " << total << "\n";
    }
  }

  return 0;
}
