def checkNextC(k, c, start):  #will output a number that checks start, (start+1)%k, ..., (start+c-1)%k
    location = 1
    for i in range(start, start+c):
        check = (i % k) + 1
        location = location*k-k + check
    return location
    
#f = open('C:\\Users\\djspence\\Documents\\Miscellaniety\\codejam2016\\civfile.txt', 'r')
f = open('C:\\Users\\djspence\\Downloads\\D-large.in', 'r')

tries = int(f.readline())

for i in range(0, tries):
    vals = f.readline().split()
    k = int(vals[0])
    c = int(vals[1])
    s = int(vals[2])
    if k == 1:
        if s == 0:
            print("Case #" + str(i + 1) + ": IMPOSSIBLE")
        else:
            print("Case #" + str(i + 1) + ": 1")
        continue
    if s*c >= k:
        toCheck = ":"
        for j in range(0, (k+c-1)/c):
            toCheck = toCheck + " " + str(checkNextC(k, c, j*c))
        print("Case #" + str(i + 1) + toCheck)
    else:
        print("Case #" + str(i + 1) + ": IMPOSSIBLE")
        