#include <iostream>
#include <cassert>
#include <vector>
#include <sstream>
#include <tuple>
#include <algorithm>
#include <iterator>
#include <list>

typedef std::vector<std::vector<char>> matrix_t;

matrix_t create_matrix(size_t R, size_t C, char ch = '\0')
{
  matrix_t result(R, std::vector<char>(C, ch));

  assert(result.size() == R);
  for (std::vector<char> const & row: result)
    assert(row.size() == C);

  return result;
}

matrix_t transposed(matrix_t const & m)
{
  if (m.size() == 0)
    return m;

  matrix_t result = create_matrix(m[0].size(), m.size());
  for (size_t r = 0; r < m.size(); ++r)
  {
    for (size_t c = 0; c < m[r].size(); ++c)
    {
      result[c][r] = m[r][c];
    }
  }
  return result;
}

matrix_t solve(size_t R, size_t C, size_t M)
{
  assert(R >= 1 && C >= 1 && M >= 0 && R * C > M);

  if (R > C)
  {
    return transposed(solve(C, R, M));
  }

  assert(R <= C);

  if (R * C - M == 1)
  {
    matrix_t result = create_matrix(R, C, '*');
    result[0][0] = 'c';
    return result;
  }


  matrix_t result = create_matrix(R, C);

  if (R == 1)
  {
    for (size_t c = 0; c != C; ++c)
    {
      if (c < R * C - M)
      {
        result[0][c] = '.';
      }
      else
      {
        result[0][c] = '*';
      }
    }
  }
  else if (R == 2)
  {
    if (R * C - M < 4 || (R * C - M) % 2 == 1)
    {
      return matrix_t();
    }
    else
    {
      for (size_t c = 0; c != C; ++c)
      {
        if (c < (R * C - M) / 2)
        {
          result[0][c] = '.';
          result[1][c] = '.';
        }
        else
        {
          result[0][c] = '*';
          result[1][c] = '*';
        }
      }
    }
  }
  else
  {
    if (R * C - M < 4 || R * C - M == 5 || R * C - M == 7)
    {
      return matrix_t();
    }
    else if (R * C - M == 4)
    {
      result = create_matrix(R, C, '*');
      result[0][0] = '.';
      result[0][1] = '.';
      result[1][0] = '.';
      result[1][1] = '.';
    }
    else if (R * C - M == 6)
    {
      result = create_matrix(R, C, '*');
      result[0][0] = '.';
      result[0][1] = '.';
      result[1][0] = '.';
      result[1][1] = '.';
      result[2][0] = '.';
      result[2][1] = '.';
    }
    else
    {
      result = create_matrix(R, C, '*');
      result[0][0] = '.';
      result[0][1] = '.';
      result[0][2] = '.';
      result[1][0] = '.';
      result[1][1] = '.';
      result[1][2] = '.';
      result[2][0] = '.';
      result[2][1] = '.';

      size_t remains = R * C - M - 8;
      if (remains > 1 && R >= 4)
      {
        size_t const rows_to_fill = std::min(remains / 2, R - 3);
        for (size_t i = 0; i != rows_to_fill; ++i)
        {
          result[3 + i][0] = '.';
          result[3 + i][1] = '.';
          remains -= 2;
        }
      }
      if (remains > 1 && C >= 4)
      {
        size_t const cols_to_fill = std::min(remains / 2, C - 3);
        for (size_t i = 0; i != cols_to_fill; ++i)
        {
          result[0][3 + i] = '.';
          result[1][3 + i] = '.';
          remains -= 2;
        }
      }
      if (remains > 0)
      {
        for (size_t r = 2; r < R && remains > 0; ++r)
        {
          for (size_t c = 2; c < C && remains > 0; ++c)
          {
            result[r][c] = '.';
            --remains;
          }
        }
      }
      assert(remains == 0);
    }
  }

  result[0][0] = 'c';

  return result;
}

std::string to_string(matrix_t const & m)
{
  if (m.size() == 0)
  {
    return "Impossible\n";
  }

  assert(m.size() > 0 && m[0].size() > 0);

  std::ostringstream ostr;

  for (std::vector<char> const & row: m)
  {
    for (char ch: row)
    {
      ostr << ch;
    }

    ostr << "\n";
  }

  return ostr.str();
}

size_t num_bombs_in_neighbour(matrix_t const & m, size_t r, size_t c)
{
  size_t result = 0;

  for (int dr = -1; dr <= 1; ++dr)
  {
    for (int dc = -1; dc <= 1; ++dc)
    {
      if (dr == 0 && dc == 0)
        continue;

      int new_r = static_cast<int>(r) + dr;
      if (new_r < 0 || static_cast<size_t>(new_r) >= m.size())
        continue;

      int new_c = static_cast<int>(c) + dc;
      if (new_c < 0 || static_cast<size_t>(new_c) >= m[0].size())
        continue;

      if (m[new_r][new_c] == '*')
        ++result;
    }
  }

  return result;
}

size_t num_chars(matrix_t const & m, char ch)
{
  size_t result = 0;

  for (std::vector<char> const & row: m)
  {
    result += std::count(std::begin(row), std::end(row), ch);
  }

  return result;
}

void verify(matrix_t const & result, size_t R, size_t C, size_t M)
{
  if (result.size() == 0)
  {
    return;
  }

  assert(result[0][0] == 'c');
  assert(num_chars(result, '*') == M);
  assert(num_chars(result, '.') == R * C - M - 1);

  matrix_t visited = result;
  size_t num_opened = 0;

  std::list<std::tuple<size_t, size_t>> queue = {std::make_tuple<size_t, size_t>(0, 0)};
  while (!queue.empty())
  {
    size_t r, c;
    std::tie(r, c) = queue.front();
    queue.pop_front();

    if (visited[r][c] == 'v')
      continue;

    visited[r][c] = 'v';
    ++num_opened;

    if (num_bombs_in_neighbour(result, r, c) == 0)
    {
      for (int dr = -1; dr <= 1; ++dr)
      {
        for (int dc = -1; dc <= 1; ++dc)
        {
          if (dr == 0 && dc == 0)
            continue;

          int new_r = static_cast<int>(r) + dr;
          if (new_r < 0 || static_cast<size_t>(new_r) >= result.size())
            continue;

          int new_c = static_cast<int>(c) + dc;
          if (new_c < 0 || static_cast<size_t>(new_c) >= result[0].size())
            continue;

          if (visited[new_r][new_c] == 'v')
            continue;

          queue.push_back(std::make_tuple(
              static_cast<size_t>(new_r), static_cast<size_t>(new_c)));
        }
      }
    }
  }

  assert(num_opened + M == result.size() * result[0].size());
}

int main()
{
  size_t T;
  std::cin >> T;

  for (size_t case_idx = 0; case_idx != T; ++case_idx)
  {
    size_t R, C, M;
    std::cin >> R >> C >> M;

    matrix_t const & result = solve(R, C, M);

    std::cout << "Case #" << (case_idx + 1) << ":\n" << to_string(result);

    verify(result, R, C, M);
  }
}
