from math import pi, sqrt, floor
from test.test_decorators import memoize
            
filename = 'input.in'
f = open(filename)
o = open('solution.out', 'w')

T = int(f.readline().strip())
R, N, M, K = map(int, f.readline().strip().split())
o.write("Case #1:\n")
print T, "Cases"
from collections import defaultdict
from itertools import combinations
from random import choice
from operator import mul
answers=[]
for _ in range(int(R)):
    products = map(int, f.readline().strip().split())
    sols = defaultdict(lambda:0)
    for prod in products:
        if prod <= 1:
            continue
        for i in range(2,M+1):
            j = 0
            while True:
                j += 1
                if prod % i**j == 0:
                    sols[i] = max(j, sols[i])
                else:
                    break
    print sols, sum(sols.values()) == N
    if sum(sols.values()) != N:
        nums = []
        ans=''
        for num, times in sols.iteritems():
            nums.extend([num] * times)
        for comb in combinations(nums, N):
            die = False
            for prod in products:
                if prod <= 1:
                    continue
                if float(prod)/reduce(mul, comb, 1) > 1:
                    die = True
                    break
            if not die:
                ans= comb
                break
        if ans != '':
            answers.append(''.join(map(str,ans)))
        else:
            ans = combinations(range(2,M+1), N)
            ans = "".join(map(str, choice(map(tuple, ans))))
            print ans
            answers.append(ans)
    else:
        nums = []
        for num, times in sols.iteritems():
            nums.extend([num] * times)
        answers.append(''.join(map(str,nums)))
            
o.write('\n'.join(answers))
f.close()

o.close()
