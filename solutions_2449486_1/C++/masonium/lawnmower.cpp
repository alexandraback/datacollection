#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

using std::cin;

template <typename T>
class Array2D
{
public:
  Array2D(int M, int N) : n1(M), n2(N)
  {
    assert(M > 0);
    assert(N > 0);

    _data = new T[M*N];
  }

  /// accessors
  T& operator()(int m, int n)
  {
    return _data[ idx(m, n) ];
  }
  const T& operator()(int m, int n) const
  {
    return _data[ idx(m, n) ];
  }

  bool operator==(const Array2D<T>& arr) const
  {
    if (arr.n1 != n1  || arr.n2 != n2)
      return false;
    
    for (int i = 0; i < n1*n2; ++i)
      if (_data[i] != arr._data[i])
        return false;

    return true;
  }

  bool operator !=(const Array2D<T>& arr) const
  {
    return !(*this == arr);
  }
  
  /** fill **/
  void fill(const T& filler)
  {
  int size = n1 * n2;
  for (int i = 0; i < size; ++i)
    _data[ i ] = filler;
  }
  
  int size() const
  {
    return n1 * n2;
  }

  ~Array2D()
  {
    delete [] _data;
  }
  
  Array2D<T>& operator =(const Array2D<T>& rhs) = delete;
  
  int idx(int m, int n) const
  {
    assert(0 <= m && m < n1);
    assert(0 <= n && n < n2);
    return m * n2 + n;
  }
  
  T* _data;
  int n1, n2;
};


Array2D<int> read_lawn()
{
  int M, N;
  cin >> M;
  cin >> N;

  int h;
  Array2D<int> arr(M, N);
  for (int i = 0; i < M; ++i)
    for (int j = 0; j < N; ++j)
    {
      cin >> h;
      arr(i, j) = h;
    }

  return arr;
}

template <typename T>
void print(const Array2D<T>& arr)
{
  for (int i = 0; i < arr.n1; ++i)
  {
    for (int j = 0; j < arr.n2; ++j)
      cout << arr(i, j) << " ";
    cout << "\n";
  }
}

void solve_case(int casenum)
{
  Array2D<int> arr = read_lawn();
  
  Array2D<int> potential(arr.n1, arr.n2);
  potential.fill(100);
  
  vector<int> max_row(arr.n1), max_col(arr.n2);
  fill(max_row.begin(), max_row.end(), 0);
  fill(max_col.begin(), max_col.end(), 0);

  for (int i = 0; i < arr.n1; ++i)
    for (int j = 0; j < arr.n2; ++j)
    {
      max_row[i] = max(max_row[i], arr(i, j));
      max_col[j] = max(max_col[j], arr(i, j));
    }

  // cut the lawn based on the max row
  for (int i = 0; i < arr.n1; ++i)
    for (int j = 0; j < arr.n2; ++j)
      potential(i, j) = min(max_row[i], max_col[j]);
  
  cout << "Case #" << casenum << ": ";
  if (arr == potential)
  {
    cout << "YES";
  }
  else
  {
    cout << "NO";
  }

  cout << "\n";
}

int main(int argc, char ** args)
{
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i)
  {
    solve_case(i);
  }

  return 0;
}
