import sys
from itertools import combinations_with_replacement

N = 12
M = 8
K = 12

def all_combs():
    for i in range(0, N+1):
        comb = combinations_with_replacement(range(2,M+1), i)
        for e in comb:
            yield e

def product(c):
    acc = 1
    for e in c:
        acc *= e
    return acc

def main():
    # We. Brute. Force. This. Shit.
    ht = {}
    for comb in all_combs():
        p = product(comb)
        cl = list(comb)
        if not ht.has_key(p):
            ht[p] = [cl]
        else:
            ht[p].append(cl)
#    for k,v in ht.iteritems():
#        print k,v


    # We. Solve. This. Shit.
    data = sys.stdin.readlines()
    data.pop(0) # T
    line = data.pop(0) # R N M K
    R = int(line.split(' ')[0])
    print "Case #1:"
    for test in range(0,R):
        line = data.pop(0).strip()
        numbers = line.split(' ')
        numbers = map(lambda x:int(x), numbers)
        numbers = sorted(numbers,reverse=True)
        #print numbers
        sol = [1 for i in range(0,N)]
        sure = False
        must_be_there = []
        for number in numbers:
            if number == 1:
                continue
            try:
                if len(ht[number]) == 1:
                    x = ht[number]
                    x = x[0]
                    if len(x) == N:
                        sol = x
                        sure = True
                        break
                    elif len(x) == 1:
                        must_be_there.append(x[0])
            except:
                pass

        if sure:
            print ''.join(map(lambda x:str(x),sol))
        elif must_be_there != []:
            s = ''.join(map(lambda x:str(x), must_be_there))
            if len(s) > N:
                s = s[0:N]
            elif len(s) < N:
                x = len(s)
                s += (N-x) * '2'
            print s
        else:
            print '2' * N

if __name__ == '__main__':
    main()
