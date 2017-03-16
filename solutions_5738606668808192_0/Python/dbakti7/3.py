from copy import deepcopy
counter = 0
answer = []
def count(i, lim, ans):
    global answer
    a = []
    for x in range(20):
        a.append(0)
    global counter
    if(counter == 50):
        return
    flag = True
    for x in range(2, 11):
        a[x] = 0
        for y in range(16):
            if(ans[y] == 1):
                a[x] += x ** y
    divisor = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    
    for x in range(2, 11):
        localFlag = False
        for y in range(3, 10000, 2):
            if(a[x] % y == 0):
                localFlag = True
                divisor[x] = y
                break
        if(localFlag == False):
            flag = False
    if(flag and ans not in answer):
        counter += 1
        answer.append(ans)
        for j in range(15, -1, -1):
            print(ans[j], end = "")
        for j in range(2, 11):
            print(" ", end = "")
            print(divisor[j], end = "")
        print("")
    if(i < lim):
        ans[i+1] = 0
        count(i+1, lim, deepcopy(ans))
        ans[i+1] = 1
        count(i+1, lim, deepcopy(ans))

num = [0, 1]
for x in range(2, 11):
    num.append(x ** 15 + 1)
ans = [1]
for x in range(14):
    ans.append(0)
ans.append(1)

count(1, 14, ans)
ans[1] = 1
count(1, 14, ans)
