def isprime2(n):
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
        if n % i == 0:
            return i
    return -1



N = 16
J = 50

cases = pow(2,N-2)
count = 0
i = -1
print("Case #1:")
while i < cases-1:
    i +=1
    string = "{0:b}".format(i).zfill(N-2)
    string = "1" + string + "1"

    li = []
    for base in range(2,11):
        v = int(string, base)
        n = isprime2(v)
        if n == -1:
            break
        else:
            li.append(n)
            
    if len(li) != 9:
        continue
    print(string + " " + str(li[0]) + " "+ str(li[1]) + " "+ str(li[2]) + " "+ str(li[3]) + " "+ str(li[4]) + " "+ str(li[5]) + " "+ str(li[6]) + " "+ str(li[7]) + " "+ str(li[8]))
    count += 1
    if count == J:
        break

    

    
