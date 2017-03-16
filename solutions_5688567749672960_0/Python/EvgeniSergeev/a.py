import sys
stdin = sys.stdin

def to10001(k):
    if 1 == k: return 1
    if 2 == k: return 11
    half = (k-1)/2
    rr = to10001(k-1) + int('9'*half)-1 + 1 + int('9'*(k-1-half))-1 + 2
    return rr

T = int(stdin.readline())
for icase in range(1, T+1):
    print 'Case #%d:' % icase,
    N = stdin.readline().strip()

    if int(N) <= 19:
        print N
        continue

    rr = to10001(len(N))
    if N == '1' + '0'*(len(N)-1):
        rr -= 1
    else:
        if '0' == N[-1]:
            rr += 1
            N = ''.join(str(int(N)-1))
        k = (len(N))/2
        first_part = int(''.join(reversed(N[:k])))-1
        rr += first_part + int(N[k:])-1
        if first_part != 0:
            rr += 1

    print rr

                             

    

