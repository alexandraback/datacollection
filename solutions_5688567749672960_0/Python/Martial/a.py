import sys
sys.stdin = open('A-small-attempt1.in')
sys.stdout = open('out.txt', 'w')

def check(n):

    d = {1:1}
    done = {}
    s = set([1])
    for i in range(n):
        next_s = set()
        # print(i+1,'\t', len(d),'\t', sorted(s))
        for j in s:
            dd = d[j]

            jj = j+1
            if jj not in d:
                next_s.add(jj)
                d[jj] = dd+1

            digits = list(str(j))
            digits.reverse()
            jj = int(''.join(digits))
            if jj not in d:
                next_s.add(jj)
                d[jj] = dd+1

            done[j] = True

        s = next_s

    return d

#keys = sorted(list(d.keys()))
#for key in keys:
#    print(key,'\t',d[key])

n= 3436
d = check(n)
# for i in range(7):
#    print(d[10**i])


def solve(n):
    res = 1
    for i in range(20):
        if n == 10 **i:
            return res


n_cases = int(input())
for case in range(n_cases):
    i = int(input())
    res = d[i]
    print('Case #{}: {}'.format(case+1, res))

