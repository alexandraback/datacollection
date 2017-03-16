import math

def dec_to_bin(n):
    return bin(n)[2:]

def isPrime(num):
    #print "inside",
    l = int(math.sqrt(int(math.sqrt(num)) + 1)) + 1
    #print l
    i = 2
    while i < 10000:
        if num % i == 0:
            return 0
        i += 1
    return 1


def is_jam_coin(n, siz):
    num = 0
    #print n
    for base in range(2, 11):
        num = 0
        for i in range(siz):
            num = num * base + int(n[i])
        #print num
        if isPrime(num) == 1:
            return 0
    return 1

def get_div(n, siz):
    li = []
    for base in range(2, 11):
        num = 0
        for i in range(siz):
            num = num * base + int(n[i])
        j = 2
        while j <= num/2:
            if num % j == 0:
                li.append(j)
                break
            j += 1
    return li

f1 = open('C:\\vivek\\googleCoding\\codeJam16\\out3s.txt', 'w')
f1.write('Case #1:\n')
J = 500
N = 32
siz = 32
cnt = 0
start = 2 ** (N-1) + 1
end = (2 ** N) - 1
num = []
li = []
i = start
while i < end+1:
    i += 2
    num = dec_to_bin(i)
    #print num
    if cnt == 500:
        break
    if is_jam_coin(num, siz) == 1:
        #print num
        li = []
        cnt += 1
        li = get_div(num, siz)
        print cnt
        f1.write(num)
        for j in range(len(li)):
            f1.write(" " + str(li[j]))
        f1.write("\n")