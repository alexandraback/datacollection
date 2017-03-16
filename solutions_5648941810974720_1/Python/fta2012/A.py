import sys
from collections import Counter
T = int(raw_input())

sys.setrecursionlimit(5000)


for t in xrange(T):
    S = raw_input()

    c = Counter(S)

    chars = [ "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

    out = ''
    for num, char in [
        (0, 'Z'),
        (2, 'W'),
        (4, 'U'),
        (6, 'X'),
        (8, 'G'),
        (1, 'O'),
        (3, 'H'),
        (5, 'F'),
        (7, 'S'),
        (9, 'I')
    ]:
      for i in xrange(c[char]):
        out += str(num)
        c.subtract(chars[num])


        
    print 'Case #' + str(t + 1) + ': ' + ''.join(sorted(out))
