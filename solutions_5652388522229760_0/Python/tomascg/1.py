def addDigits(S, n):
    for j in str(n):
        S.add(j)

def lastNumber(n):
    if n == 0 :
        return "INSOMNIA"
    s = set()
    addDigits(s,n)
    count = 1
    curr = n
    while len(s) < 10:
        count += 1
        curr = n* count
        addDigits(s,curr)
    return curr

f = open('a.in', 'r')
g = open('a.out', 'w')

t = int(f.readline())

for i in range(1,t+1):
    numb = int(f.readline())
    ans = lastNumber(numb)
    pr = "Case #"+str(i)+ ": " + str(ans)
    print pr
    g.write(pr + '\n')


f.close()
g.close()
