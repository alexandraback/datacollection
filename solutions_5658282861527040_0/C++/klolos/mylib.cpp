#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

// returns the number of 1's in num
int count_ones(long long num)
{
    int count = 0;
    for (int i = 0; i < 64; ++i)
        if ((num >> i) & 1)
            count++;
    return count;
}

// returns true if the array contains the given number
template <class T>
bool contains(T element, T *array, int size)
{
    for (int i = 0; i < size; ++i)
        if (element == array[i])
            return true;
    return false;
}
bool contains(char c, char *s)
{
    while(*s != '\0') {
        if (*s == c)
            return true;
        s++;
    }
    return false;
}

// min and max
template <class T>
bool min(T a, T b) { return a < b ? a : b; }
template <class T>
bool max(T a, T b) { return a > b ? a : b; }

// mallocs
template<class T>
T **malloc_2d(int rows, int columns)
{
    T **a = (T **) malloc(rows * sizeof(*a));
    for (int i = 0; i < rows; ++i)
        a[i] = (T *) malloc(columns * sizeof(*a[i]));
    return a;
}
template <class T>
void free_2d(T **matrix, int rows)
{
    for (int i = 0; i < rows; ++i)
        free(matrix[i]);
    free(matrix);
}
template <class T>
T ***malloc_3d(int X, int Y, int Z)
{
    T ***a = (T ***) malloc(X * sizeof(*a));
    for (int i = 0; i < Y; ++i)
        a[i] = malloc_2d<T>(Y, Z);
    return a;
}
template <class T>
void free_3d(T ***matrix, int X, int Y)
{
    for (int i = 0; i < X; ++i)
        free_2d(matrix[i], Y);
    free(matrix);
}

// read N elements from stdin into an array
template <class T>
T *read(int N)
{
    T *a = (T *) malloc(N * sizeof(*a));
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    return a;
}

// Read up to N words from stdin
vector<string> read_words(int count)
{
    vector<string> v;
    string s;
    while (cin >> s) v.push_back(s);
    return v;
}
string read_word(void)
{
    string s;
    cin >> s;
    return s;
}

