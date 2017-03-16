import sys
from collections import Counter
read = lambda t=int: list(map(t,sys.stdin.readline().split()))
array = lambda *ds: [array(*ds[1:]) for _ in range(ds[0])] if ds else 0

english = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
key = ['Z', 'O', 'W', 'T', 'U', 'F', 'X', 'S', 'G', 'N']
levels = [[0,2,4,6,8], [1,3,7], [5,9]]

T, = read()
for testCase in range(T):
   s, = read(str)
   c = Counter(s)
   cnt = array(10)
   for level in levels:
      for digit in level:
         while c[key[digit]]:
            cnt[digit] += 1
            c -= Counter(english[digit])
   res = ''.join(str(i)*cnt[i] for i in range(10))
   print('Case #{}: {}'.format(testCase+1, res))


