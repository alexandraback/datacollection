from copy import deepcopy
counter = 0
answer = []
f = open('output', 'w')
def count(i, lim, ans):
    global answer
    a = []
    for x in range(20):
        a.append(0)
    global counter
    if(counter == 500):
        return
    flag = True
    for x in range(2, 11):
        a[x] = 0
        for y in range(32):
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
        for j in range(31, -1, -1):
            f.write(str(ans[j]))
        for j in range(2, 11):
            f.write(" ")
            f.write(str(divisor[j]))
        f.write("\n")
    if(i < lim):
        ans[i+1] = 0
        count(i+1, lim, deepcopy(ans))
        ans[i+1] = 1
        count(i+1, lim, deepcopy(ans))

num = [0, 1]
for x in range(2, 11):
    num.append(x ** 31 + 1)
ans = [1]
for x in range(30):
    ans.append(0)
ans.append(1)

count(1, 30, ans)
ans[1] = 1
count(1, 30, ans)
f.close()
