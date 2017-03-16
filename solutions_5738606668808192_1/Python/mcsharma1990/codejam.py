def seive(n):
    p = [1]*n
    for i in range(2, n):
        for j in range(2*i, n, i):
            p[j] = 0
            
    ans = []
    for i in range(2, n):
        if p[i]:
            ans.append(i)
    return ans


global l;
l = seive(10000)
def isComposite(n):
    i = 0
    while i < len(l) and l[i]*l[i] <= n:
        if n % l[i] == 0:
            return 1, l[i]
        i += 1
    return (0, 0)

def interpret(x, b):
	ans = 0;
	while x > 0:
		ans = ans * b + (x % 2);
		x /= 2;
	return ans;
        

N = 32
J = 500

lo = 2**(N-1) + 1
hi = 2**N 
c = 0
ans = []
for i in range(lo, hi, 2):
    isJam = 1
    d = {}
    for b in range(2, 11):
         isCompo, div = isComposite(interpret(i, b))
         if isCompo:
             d[b] = div
         else:
             isJam = 0
             break
    if isJam:
        c += 1
        binStr = ''
        num = i
        while num:
            binStr += ('0' if num % 2 == 0 else '1')
            num /= 2;
        line = binStr
        for key in d:
            line += " " + str(d[key])
        print line
        if c == J:
            break
