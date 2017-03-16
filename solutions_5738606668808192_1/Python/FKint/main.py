import sys
T = sys.stdin.readline()
N, J = map(int, sys.stdin.readline().split())


def interpret_base(s, base):
    n = 0
    for x in s:
        n *= base
        n += int(x)
    return n

nums = N//2-2
#print(nums, J)
print("Case #1:")
found = set()
for i in range(1, J+1):
    s = ('{0:0'+str(nums)+'b}').format(i) 
    num = "1" + s+"1"
    num = num+num
    #print(num)
    answer = [num]
    assert(len(num) == N)
    assert(num not in found)
    found.add(num)
    for b in range(2, 11):
        n = interpret_base(num, b)
        #print("{} in base {} = {}".format(num, b, n))
        d = interpret_base("1"+("0"*(N//2-1))+"1", b)
        q = n // d
        assert(d != 1 and d != n)
        assert(n % d == 0)
        #print(n==q*d)
        answer.append(str(d))
    print(" ".join(answer))

