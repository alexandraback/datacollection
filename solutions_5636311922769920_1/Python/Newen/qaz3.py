f = open("C:\\Downloads\\D-large.in","r")
lines = f.readlines()
for i in range(1,int(lines[0])+1):
    k,c,s = [int (x) for x in lines[i].split()]
    res = "Case #" + str(i) + ": "
    if k == s:
        res += ' '.join(str(j) for j in range(1,s+1))
    elif s == k - 1 and k -1 != 1:
        res += ' '.join(str(j) for j in range(2, s + 1))
    else:
        res += "IMPOSSIBLE"
    print res