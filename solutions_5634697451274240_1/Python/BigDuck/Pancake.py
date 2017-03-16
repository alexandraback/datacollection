with open("B-large.in.txt") as f:
    x = f.read().splitlines()

nOfCase = int(x[0])
testCases = x[1:]



file = open('output','w') 

for i,a in enumerate(testCases):
    before = a[0]
    cnt = 1
    for j in a:
        if j != before:
            cnt += 1
            before = j
    if a[-1] == '+':
        cnt -= 1
    file.write("Case #%d: %d\n" % (i+1,cnt))




