import sys
import time

MAX = 763040848953891663257299797619


def isprime2(n, maxi):
    montemps=time.time()
    '''
    check if integer n is a prime, return True or False
    '''
    # 2 is the only even prime
    if n == 2:
        return -1
    # integers less than 2 and even numbers other than 2 are not prime
    elif n < 2 or not n & 1:
        return 2
    # loop looks at odd numbers 3, 5, 7, ... to sqrt(n)
    for i in range(3, int(n**0.5)+1, 2):
        if i > maxi:
            return -1
        y = time.time()-montemps
        if y > 8:
            return -1
        if n % i == 0:
            return i
    return -1



N = 32
J = 500

cases = pow(2,N-2)
count = 0
i = -1
maxi = 10000

print("Case #1:")

i=-1
while i < cases-1:
    i +=1

    
    string = "{0:b}".format(i).zfill(N-2)
    string = "1" + string + "1"

    li = []
    for base in reversed(range(2,11)):
        v = int(string, base)
        n = isprime2(v, maxi)
        if n == -1:
            break
        else:
            li.append(n)
    
    if len(li) != 9:
        continue
    li = list(reversed(li))
    print(string + " " + str(li[0]) + " "+ str(li[1]) + " "+ str(li[2]) + " "+ str(li[3]) + " "+ str(li[4]) + " "+ str(li[5]) + " "+ str(li[6]) + " "+ str(li[7]) + " "+ str(li[8]))
    count += 1
    if count == J:
        break

    

    
