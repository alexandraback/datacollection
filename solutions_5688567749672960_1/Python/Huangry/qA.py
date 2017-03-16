__author__ = 'Tom'
import copy

def ansdigits (n):
    if n == 1:
        return 1
    if n == 2:
        return 10
    sum = 0
    n2 = n-1
    if n2%2 == 1:
        sum += 9*(10**(int(n2/2)))
    for i in range(int(n2/2)):
        if i == 0:
            sum += 8 + 9
        else:
            sum+= 18*(10**(i))
    sum+=2
    return sum + ansdigits (n-1)


print(ansdigits(5))

with open ('A-large (5).in', 'r') as f:
    with open ('Asolution.txt', 'w') as solution:

        T = int(f.readline())
        for case in range(T):
            N = int(f.readline())
            answer = 0
            strN = str(N)
            digits = len(strN)
            if digits == 1:
                answer = N
            else:
                sum = ansdigits(digits)
                print(sum)
                needswap = False
                if int(strN[digits-1]) == 0 :
                    strcopy = str(int(strN)-1)
                    if len(strcopy) == digits:
                        sum+=1
                        strN = copy.deepcopy(strcopy)
                if case == 99:
                    pass
                for i in range(digits):
                    value = int(strN[i])
                    if i == 0:
                        if value !=1:
                            needswap = True
                    elif i +1< digits - i:
                        if value != 0:
                            needswap = True


                    if i == 0:
                        value -=1
                    position = min(i, digits-1-i)
                    sum += value*(10**position)
                if needswap:
                    sum+=1
                answer = sum


            solution.write('Case #' + str(case+1) + ': ' + str(answer) + '\n')
    solution.closed
f.closed
