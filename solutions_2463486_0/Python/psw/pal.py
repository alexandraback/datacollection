def isPalindrome(n):
    q = str(n)
    for i in range(len(q)/2):
        if (q[i] != q[len(q)-1-i]):
            return False
    return True

l = []
for i in range(10000000):
    if isPalindrome(i):
        sq = i * i;
        if isPalindrome(sq):
            l.append(sq)

n = input()
for i in range(n):
    a, b = raw_input().split()
    a = int(a)
    b = int(b)
    j = 0
    for k in l:
        if (a <= k) and (k <= b):
            j += 1
    print("Case #" + str(i+1) + ": " + str(j))
