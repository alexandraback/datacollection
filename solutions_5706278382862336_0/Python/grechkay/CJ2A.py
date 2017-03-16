import fileinput

def div2(x):
    c = 0
    temp = x
    while temp % 2 == 0:
        temp = temp // 2
        c = c+1
    return [c, temp]

def numGen(num,denum):
    ans = 1
    while num < denum/2:
        num = num*2
        ans = ans+1
    return ans


i = 0
n=0
cases = []
for line in fileinput.input():
    if i ==0:
        n = int(line)
        i+=1
    else:
        cases.append([int(i) for i in line.split('/')])


for i in range(n):
    nums=cases[i]
    testlist = div2(nums[0])
    testlist2 = div2(nums[1])
    if (testlist[1]%testlist2[1]!=0):
        print("Case #" + str(i+1) + ": impossible")
    else:
        ans = numGen(cases[i][0]//testlist2[1],cases[i][1]//testlist2[1])
        print("Case #" + str(i+1) + ": " + str(ans))







