# The misses to exclude all but one row.
def solve1(r,c,w):
  row = c // w
  return row * (r-1)

# How many misses before the next miss will tell me the complete position.
def solve2(r,c,w):
  return max(0, ((c - 1) // w) - 1)

def solve3(r,c,w):
  # Special case: w == c, then I can't miss at all.
  # Otherwise I can miss once.
  return w + (c > w)

  

def solve(r,c,w):
#  print(solve1(r,c,w), solve2(r,c,w), solve3(r,c,w))
  return solve1(r,c,w) + solve2(r,c,w) + solve3(r,c,w)

def read_solve():
  r,c,w = map(int,input().split())
  return '{}'.format(solve(r,c,w))


def main():
  cases = int(input())
  for i in range(1, cases+1):
    print('Case #{}: {}'.format(i, read_solve()))

main()
