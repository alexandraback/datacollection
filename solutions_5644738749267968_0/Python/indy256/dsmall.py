import sys

name = "D-small-attempt0"
path = ""

sys.stdin = open(path + name + ".in")
sys.stdout = open(path + name + ".out", "w")

def f(a, b):
    res = 0
    for i in range(n):
    	if a[i] > b[res]:
    		res += 1
    return res

testCases = int(input())

for testCase in range(1, testCases + 1):
    n = int(input())
    a = [float(x) for x in input().split()]
    b = [float(x) for x in input().split()]
    a.sort()
    b.sort()

    print("Case #" + str(testCase) + ": " + str(f(a, b)) + " " + str(n - f(b, a)))
