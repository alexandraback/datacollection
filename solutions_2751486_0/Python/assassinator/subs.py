def checkCon(sub,n):
    count =0
    for i in sub:
        if i not in ['a','e','i','o','u']:
            count=count+1
        else:
            count=0
        if count>=n:
            return True
    if count>=n:
        return True
    else:
        return False
def getNvalue(name,n):
    strlen = len(name)
    totcount = 0
    for indexOfFirstLetter in range(0,strlen+1):
        for indexOfLastLetter in range(indexOfFirstLetter + n,strlen+1):
            check = name[indexOfFirstLetter:indexOfLastLetter]
            if len(check) >= n :
                if checkCon(check, n):
                    totcount = totcount + 1
    return totcount

num = raw_input()
for i in range(0,int(num)):
    inp = raw_input().split()
    print 'Case #'+str(i+1)+': '+str(getNvalue(inp[0],int(inp[1])))

"""

4
quartz 3
straight 3
gcj 2
tsetse 2

"""