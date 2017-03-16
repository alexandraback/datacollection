def score(first,second):
    """first tells second zher choices, returns # points second scores"""
    first = sorted(first); second = sorted(second)
    n = len(first); assert n == len(second)
    firstI = 0
    for i in range(n):
        if second[i] > first[firstI]: firstI += 1
    return firstI

def solve(testNum):
    n = int(input())
    a = [float(x) for x in input().split()];
    b = [float(x) for x in input().split()];
    assert len(a) == len(b) == n
    print("Case #%d: %d %d"%(testNum,score(b,a),n-score(a,b)))

for i in range(1,int(input())+1): solve(i)
