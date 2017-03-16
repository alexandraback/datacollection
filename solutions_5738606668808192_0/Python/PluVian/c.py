import sys
import math
import itertools

def r():
    return sys.stdin.readline()

def find_divisor(N):
    end = int(math.sqrt(N)) + 1
    for i in range(2, end):
        if N % i == 0:
            return int(N / i)
    return -1

def main(n, j):
    found = 0
    for t in itertools.product('01', repeat=n - 2):
        if found == j:
            break
        s = '1' + ''.join(t) + '1'
        st = []
        is_coin = True
        for i in range(2, 11):
            num = int(s, base=i)
            d = find_divisor(num)
            if d < 0:
                is_coin = False
                break
            st.append(d)

        if is_coin:
            print('{} {}'.format(s, ' '.join([str(x) for x in st])))
            found += 1

t = int(r())

for i in range(t):
    n, j = map(int, r().split())
    print('Case #{}:'.format(i + 1))
    main(n, j)
