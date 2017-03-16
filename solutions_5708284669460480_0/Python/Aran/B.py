def maximum(s, string):
  telescope = max(i for i in range(len(string)) if i == 0 or string[:i] == string[-i:])

  return (s - telescope) // (len(string) - telescope)

def prod(c):
  i = 1
  for x in c:
    i *= x
  return i

def prob(string, board):
  return prod(board[i] for i in string)

def expected(m, string, board):
  return prob(string, board) * m

def solve(s,board,string):
  if s < len(string):
    return 0
  if not all(c in board for c in string):
    return 0
  board = count(board)
  m = maximum(s, string)
  return m - expected(m, string, board)
  

#  print(solve1(r,c,w), solve2(r,c,w), solve3(r,c,w))
  return solve1(r,c,w) + solve2(r,c,w) + solve3(r,c,w)

def count(s):
  x = set(s)
  y = {}
  for c in x:
    y[c] = 0
  for c in s:
    y[c] += 1 / len(s)
  return y

def read_solve():
  k,l,s = map(int,input().split())
  board = input();
  string = input()
  return '{}'.format(solve(s,board,string))


def main():
  cases = int(input())
  for i in range(1, cases+1):
    print('Case #{}: {}'.format(i, read_solve()))

main()
